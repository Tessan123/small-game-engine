#include "shader.h"
#include "openGLLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

static std::string ReadFile(const char *path)
{
    std::ifstream file(path);

    if (!file)
    {
        std::cerr << "Failed to open shader file: "
                  << path
                  << std::endl;

        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
    std::string vertexSource = ReadFile(vertexPath);
    std::string fragmentSource = ReadFile(fragmentPath);

    const char *vertexSourceC = vertexSource.c_str();
    const char *fragmentSourceC = fragmentSource.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSourceC, nullptr);
    glCompileShader(vertexShader);

    GLint vertexSuccess;

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertexSuccess);
    if (!vertexSuccess)
    {
        char infolog[512];
        glGetShaderInfoLog(vertexShader, 512, nullptr, infolog);
        std::cerr << "Vertex shader compilation failed:\n"
                  << infolog << std::endl;
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSourceC, nullptr);
    glCompileShader(fragmentShader);

    GLint fragmentSuccess;

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentSuccess);
    if (!fragmentSuccess)
    {
        char infolog[512];
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infolog);
        std::cerr << "Fragment shader compilation failed:\n"
                  << infolog << std::endl;
    }

    rendererID = glCreateProgram();
    glAttachShader(rendererID, vertexShader);
    glAttachShader(rendererID, fragmentShader);

    glLinkProgram(rendererID);

    GLint linkSuccess;

    glGetProgramiv(rendererID, GL_LINK_STATUS, &linkSuccess);
    if (!linkSuccess)
    {
        char infolog[512];

        glGetProgramInfoLog(rendererID, 512, nullptr, infolog);
        std::cerr << "shader program linking failed:\n"
                  << infolog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
    glDeleteProgram(rendererID);
}

void Shader::Bind() const
{
    glUseProgram(rendererID);
}

void Shader::Unbind() const
{
    glUseProgram(0);
}
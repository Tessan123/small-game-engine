#include "OpenGLLoader.h"

#include <iostream>

GLGenBuffersProc glGenBuffers = nullptr;
GLBindBufferProc glBindBuffer = nullptr;
GLBufferDataProc glBufferData = nullptr;
GLDeleteBuffersProc glDeleteBuffers = nullptr;
GLGenVertexArraysProc glGenVertexArrays = nullptr;
GLBindVertexArrayProc glBindVertexArray = nullptr;
GLDeleteVertexArraysProc glDeleteVertexArrays = nullptr;
GLVertexAttribPointerProc glVertexAttribPointer = nullptr;
GLEnableVertexAttribArrayProc glEnableVertexAttribArray = nullptr;
GLCreateShaderProc glCreateShader = nullptr;
GLShaderSourceProc glShaderSource = nullptr;
GLCompileShaderProc glCompileShader = nullptr;

GLCreateProgramProc glCreateProgram = nullptr;
GLAttachShaderProc glAttachShader = nullptr;
GLLinkProgramProc glLinkProgram = nullptr;
GLUseProgramProc glUseProgram = nullptr;

GLDeleteShaderProc glDeleteShader = nullptr;
GLDeleteProgramProc glDeleteProgram = nullptr;
GLGetShaderivProc glGetShaderiv = nullptr;
GLGetShaderInfoLogProc glGetShaderInfoLog = nullptr;
GLGetProgramivProc glGetProgramiv = nullptr;
GLGetProgramInfoLogProc glGetProgramInfoLog = nullptr;

bool InitializeOpenGLFunctions()
{
    glGenBuffers =
        reinterpret_cast<GLGenBuffersProc>(
            glfwGetProcAddress("glGenBuffers"));

    glBindBuffer =
        reinterpret_cast<GLBindBufferProc>(
            glfwGetProcAddress("glBindBuffer"));

    glBufferData =
        reinterpret_cast<GLBufferDataProc>(
            glfwGetProcAddress("glBufferData"));

    glDeleteBuffers =
        reinterpret_cast<GLDeleteBuffersProc>(
            glfwGetProcAddress("glDeleteBuffers"));

    glGenVertexArrays =
        reinterpret_cast<GLGenVertexArraysProc>(
            glfwGetProcAddress("glGenVertexArrays"));

    glBindVertexArray =
        reinterpret_cast<GLBindVertexArrayProc>(
            glfwGetProcAddress("glBindVertexArray"));

    glDeleteVertexArrays =
        reinterpret_cast<GLDeleteVertexArraysProc>(
            glfwGetProcAddress("glDeleteVertexArrays"));

    glVertexAttribPointer =
        reinterpret_cast<GLVertexAttribPointerProc>(
            glfwGetProcAddress("glVertexAttribPointer"));

    glEnableVertexAttribArray =
        reinterpret_cast<GLEnableVertexAttribArrayProc>(
            glfwGetProcAddress("glEnableVertexAttribArray"));

    glCreateShader =
        reinterpret_cast<GLCreateShaderProc>(
            glfwGetProcAddress("glCreateShader"));

    glShaderSource =
        reinterpret_cast<GLShaderSourceProc>(
            glfwGetProcAddress("glShaderSource"));

    glCompileShader =
        reinterpret_cast<GLCompileShaderProc>(
            glfwGetProcAddress("glCompileShader"));

    glCreateProgram =
        reinterpret_cast<GLCreateProgramProc>(
            glfwGetProcAddress("glCreateProgram"));

    glAttachShader =
        reinterpret_cast<GLAttachShaderProc>(
            glfwGetProcAddress("glAttachShader"));

    glLinkProgram =
        reinterpret_cast<GLLinkProgramProc>(
            glfwGetProcAddress("glLinkProgram"));

    glUseProgram =
        reinterpret_cast<GLUseProgramProc>(
            glfwGetProcAddress("glUseProgram"));

    glDeleteShader =
        reinterpret_cast<GLDeleteShaderProc>(
            glfwGetProcAddress("glDeleteShader"));

    glDeleteProgram =
        reinterpret_cast<GLDeleteProgramProc>(
            glfwGetProcAddress("glDeleteProgram"));

    glGetShaderiv =
        reinterpret_cast<GLGetShaderivProc>(
            glfwGetProcAddress("glGetShaderiv"));

    glGetShaderInfoLog =
        reinterpret_cast<GLGetShaderInfoLogProc>(
            glfwGetProcAddress("glGetShaderInfoLog"));

    glGetProgramiv =
        reinterpret_cast<GLGetProgramivProc>(
            glfwGetProcAddress("glGetProgramiv"));

    glGetProgramInfoLog =
        reinterpret_cast<GLGetProgramInfoLogProc>(
            glfwGetProcAddress("glGetProgramInfoLog"));


    if (!glGenBuffers ||
        !glBindBuffer ||
        !glBufferData ||
        !glDeleteBuffers ||
        !glGenVertexArrays ||
        !glBindVertexArray ||
        !glDeleteVertexArrays ||
        !glVertexAttribPointer ||
        !glEnableVertexAttribArray ||
        !glCreateShader ||
        !glShaderSource ||
        !glCompileShader ||
        !glCreateProgram ||
        !glAttachShader ||
        !glLinkProgram ||
        !glUseProgram ||
        !glDeleteShader ||
        !glDeleteProgram ||
        !glGetShaderiv ||
        !glGetShaderInfoLog ||
        !glGetProgramiv ||
        !glGetProgramInfoLog)
    {
        std::cerr << "Failed to load OpenGL functions."
                  << std::endl;

        return false;
    }

    return true;
}
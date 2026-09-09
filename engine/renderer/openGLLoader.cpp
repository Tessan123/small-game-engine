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

    if (!glGenBuffers ||
        !glBindBuffer ||
        !glBufferData ||
        !glDeleteBuffers ||
        !glGenVertexArrays ||
        !glBindVertexArray ||
        !glDeleteVertexArrays ||
        !glVertexAttribPointer ||
        !glEnableVertexAttribArray)
    {
        std::cerr << "Failed to load OpenGL functions."
                  << std::endl;

        return false;
    }

    return true;
}
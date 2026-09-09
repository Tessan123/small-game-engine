#pragma once

#include <windows.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <cstddef>

#define GL_ARRAY_BUFFER 0x8892
#define GL_STATIC_DRAW 0x88E4
#define GL_ELEMENT_ARRAY_BUFFER 0x8893

using GLGenBuffersProc = void (*)(GLsizei, GLuint *);

using GLBindBufferProc = void (*)(GLenum, GLuint);

using GLBufferDataProc = void (*)(GLenum, std::ptrdiff_t, const void *, GLenum);

using GLDeleteBuffersProc = void (*)(GLsizei, const GLuint *);

using GLGenVertexArraysProc = void (*)(GLsizei, GLuint *);

using GLBindVertexArrayProc = void (*)(GLuint);

using GLDeleteVertexArraysProc = void (*)(GLsizei, const GLuint *);

using GLVertexAttribPointerProc = void (*)(GLuint, GLint, GLenum, GLboolean, GLsizei, const void *);

using GLEnableVertexAttribArrayProc = void (*)(GLuint);

extern GLGenBuffersProc glGenBuffers;
extern GLBindBufferProc glBindBuffer;
extern GLBufferDataProc glBufferData;
extern GLDeleteBuffersProc glDeleteBuffers;
extern GLGenVertexArraysProc glGenVertexArrays;
extern GLBindVertexArrayProc glBindVertexArray;
extern GLDeleteVertexArraysProc glDeleteVertexArrays;
extern GLVertexAttribPointerProc glVertexAttribPointer;
extern GLEnableVertexAttribArrayProc glEnableVertexAttribArray;

bool InitializeOpenGLFunctions();
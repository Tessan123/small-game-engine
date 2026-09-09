#pragma once

#include <windows.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <cstddef>

#define GL_ARRAY_BUFFER 0x8892
#define GL_STATIC_DRAW 0x88E4
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_VERTEX_SHADER 0x8B31
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_TRIANGLES 0x0004
#define GL_UNSIGNED_INT 0x1405

using GLGenBuffersProc = void (*)(GLsizei, GLuint *);

using GLBindBufferProc = void (*)(GLenum, GLuint);

using GLBufferDataProc = void (*)(GLenum, std::ptrdiff_t, const void *, GLenum);

using GLDeleteBuffersProc = void (*)(GLsizei, const GLuint *);

using GLGenVertexArraysProc = void (*)(GLsizei, GLuint *);

using GLBindVertexArrayProc = void (*)(GLuint);

using GLDeleteVertexArraysProc = void (*)(GLsizei, const GLuint *);

using GLVertexAttribPointerProc = void (*)(GLuint, GLint, GLenum, GLboolean, GLsizei, const void *);

using GLEnableVertexAttribArrayProc = void (*)(GLuint);

using GLCreateShaderProc = GLuint (*)(GLenum);

using GLShaderSourceProc = void (*)(GLuint, GLsizei, const char *const *, const GLint *);

using GLCompileShaderProc = void (*)(GLuint);

using GLCreateProgramProc = GLuint (*)();

using GLAttachShaderProc = void (*)(GLuint, GLuint);

using GLLinkProgramProc = void (*)(GLuint);

using GLUseProgramProc = void (*)(GLuint);

using GLDeleteShaderProc = void (*)(GLuint);

using GLDeleteProgramProc = void (*)(GLuint);

using GLGetShaderivProc = void (*)(GLuint, GLenum, GLint *);

using GLGetShaderInfoLogProc = void (*)(GLuint, GLsizei, GLsizei *, char *);

using GLGetProgramivProc = void (*)(GLuint, GLenum, GLint *);

using GLGetProgramInfoLogProc = void (*)(GLuint, GLsizei, GLsizei *, char *);


extern GLGenBuffersProc glGenBuffers;
extern GLBindBufferProc glBindBuffer;
extern GLBufferDataProc glBufferData;
extern GLDeleteBuffersProc glDeleteBuffers;
extern GLGenVertexArraysProc glGenVertexArrays;
extern GLBindVertexArrayProc glBindVertexArray;
extern GLDeleteVertexArraysProc glDeleteVertexArrays;
extern GLVertexAttribPointerProc glVertexAttribPointer;
extern GLEnableVertexAttribArrayProc glEnableVertexAttribArray;
extern GLCreateShaderProc glCreateShader;
extern GLShaderSourceProc glShaderSource;
extern GLCompileShaderProc glCompileShader;

extern GLCreateProgramProc glCreateProgram;
extern GLAttachShaderProc glAttachShader;
extern GLLinkProgramProc glLinkProgram;
extern GLUseProgramProc glUseProgram;

extern GLDeleteShaderProc glDeleteShader;
extern GLDeleteProgramProc glDeleteProgram;

extern GLGetShaderivProc glGetShaderiv;
extern GLGetShaderInfoLogProc glGetShaderInfoLog;
extern GLGetProgramivProc glGetProgramiv;
extern GLGetProgramInfoLogProc glGetProgramInfoLog;


bool InitializeOpenGLFunctions();
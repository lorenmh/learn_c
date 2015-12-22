#include <string>
#include <sstream>
#include <iostream>
#include <chrono> /* C++11 functionality */
#include <random>
#include <cstdlib>

#include <SDL2/SDL.h>

#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shape.h"

/* Shader sources */
const GLchar* vertexSource =
"#version 300 es\n"
"attribute vec4 vPosition;"
"void main() {"
  "gl_Position = vPosition;"
"}";

const GLchar* fragmentSource =
"#version 300 es\n"
"precision mediump float;"
"void main() {"
"   gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);"
"}";

SDL_Window* initWindow()
{
  /* Initialize SDL library */
  SDL_Window* sdlWindow = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
      SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Unable to initalize SDL: %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
  }

  SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

  SDL_DisplayMode mode;
  SDL_GetDisplayMode(0, 0, &mode);
  int width = mode.w;
  int height = mode.h;

  SDL_Log("Width = %d. Height = %d\n", width, height);

  sdlWindow = SDL_CreateWindow(
    nullptr,
    0,
    0,
    width,
    height,
    SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN
  );

  if (sdlWindow == 0)
  {
      SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to create the sdlWindow: %s\n", SDL_GetError());
      SDL_Quit();
      exit(EXIT_FAILURE);
  }

  return sdlWindow;
}

/* Must use parameters here or else there will be an undefined reference to SDL_main */
int main(int argc, char** argv)
{
  SDL_Window* sdlWindow = initWindow();
  SDL_GLContext sdlGL = NULL;

    sdlGL = SDL_GL_CreateContext(sdlWindow);

    /* Query OpenGL device information */
    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* vendor = glGetString(GL_VENDOR);
    const GLubyte* version = glGetString(GL_VERSION);
    const GLubyte* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

    GLint major, minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);

    std::stringstream ss;
    ss << "\n-------------------------------------------------------------\n";
    ss << "GL Vendor    : " << vendor;
    ss << "\nGL GLRenderer : " << renderer;
    ss << "\nGL Version   : " << version;
    ss << "\nGL Version   : " << major << "." << minor;
    ss << "\nGLSL Version : " << glslVersion;
    ss << "\n-------------------------------------------------------------\n";
    SDL_Log(ss.str().c_str());
 
    glClearColor( 0.2, 0.1, 0.3, 0.0 );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, nullptr);
    glCompileShader(vertexShader);

    GLint success = 0;
    glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &success );
    if ( success == GL_FALSE ) {
      SDL_Log( "Failure to load vertex shader" );
      GLint logSize = 0;
      glGetShaderiv( vertexShader, GL_INFO_LOG_LENGTH, &logSize );
      GLchar errorMessage[ logSize ];
      glGetShaderInfoLog( vertexShader, logSize, NULL, errorMessage );
      SDL_Log( "Gufed: %s", errorMessage );
    } else {
      SDL_Log( "Vertex shader loaded" );
    }

    /* Create and compile the fragment shader */
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
    glCompileShader(fragmentShader);

    success = 0;
    glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &success );
    if ( success == GL_FALSE ) {
      SDL_Log( "Failure to load fragment shader" );
      GLint logSize = 0;
      glGetShaderiv( fragmentShader, GL_INFO_LOG_LENGTH, &logSize );
      GLchar errorMessage[ logSize ];
      glGetShaderInfoLog( fragmentShader, logSize, NULL, errorMessage );
      SDL_Log( "Gufed: %s", errorMessage );
    } else {
      SDL_Log( "Fragment shader loaded" );
    }

    /* Link the vertex and fragment shader into a shader program */
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


  GLuint VertexArrayID;
  glGenVertexArrays( 1, &VertexArrayID );
  glBindVertexArray( VertexArrayID );

  glm::vec2 points[] = {
    glm::vec2(-0.1f, -0.1f),
    glm::vec2(0.0f,0.1f),
    glm::vec2(0.1f,-0.1f)
  };
  Shape shape(points, 3);


  // static const GLfloat g_vertex_buffer_data[] = {
  //   -0.1f, -0.1f,
  //   0.1f, -0.1f,
  //   0.0f, 0.1f
  // };


  GLfloat lines[shape.sizeLines()];
  shape.lines(lines);

  for (auto &line : lines) {
    std::cout << line << "\n";
  }

  // GLfloat g_vertex_buffer_data[shape.sizeLines()] = lines;

  GLuint vertexBuffer;

  glGenBuffers( 1, &vertexBuffer );
  glBindBuffer( GL_ARRAY_BUFFER, vertexBuffer );
  glBufferData(
      GL_ARRAY_BUFFER,
      sizeof( lines ),
      lines,
      GL_STATIC_DRAW
  );

  glEnableVertexAttribArray( 0 );
  glBindBuffer( GL_ARRAY_BUFFER, vertexBuffer );
  glVertexAttribPointer(
      0,
      2,
      GL_FLOAT,
      GL_FALSE,
      0,
      (void *) 0
  );

  glDrawArrays( GL_LINES, 0, shape.sizeLines() );

  glDisableVertexAttribArray( 0 );

  SDL_GL_SwapWindow( sdlWindow );
  SDL_Delay( 2000 );
} /* main */

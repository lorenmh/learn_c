#include "iostream"
#include "GL/glew.h"
#include "SDL2/SDL.h"

#include "point.h"
#include "vec2.h"
#include "line.h"

int main( int argc, char* argv[] )
{
  Point p1 ( 0.0f, 0.0f );
  Point p2 ( 0.0f, 1.0f );

  Point p3 ( 2.0f, 2.0f );

  Line l ( p1, p2 );

  l.print();

  std::cout << '\n';
  std::cout << p3.distance( l ) << '\n';
  std::cout << l.distance( p3 ) << '\n';

  if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) return 1;

  SDL_Window *window = SDL_CreateWindow(
    "Asteroids",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    640,
    480,
    SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
  );

  SDL_GLContext glContext = SDL_GL_CreateContext( window );

  if ( glContext == NULL )
  {
    printf( "Error with OpenGL context\n" );
    return 1;
  }

  SDL_GL_MakeCurrent( window, glContext );

  SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );

  glewExperimental = GL_TRUE;
  GLenum glewStatus = glewInit();

  if ( glewStatus != 0 )
  {
    fprintf( stderr, "Error: %s\n", glewGetErrorString( glewStatus ) );
    return 1;
  }

  GLuint VertexArrayID;
  glGenVertexArrays( 1, &VertexArrayID );
  glBindVertexArray( VertexArrayID );

  static const GLfloat g_vertex_buffer_data[] = {
    -1.0f, -1.0f, 0.0f,
    1.0, -1.0f, 0.0f,
    0.0, 1.0f, 0.0f
  };

  GLuint vertexBuffer;

  glGenBuffers( 1, &vertexBuffer );
  glBindBuffer( GL_ARRAY_BUFFER, vertexBuffer );
  glBufferData(
      GL_ARRAY_BUFFER,
      sizeof( g_vertex_buffer_data ),
      g_vertex_buffer_data,
      GL_STATIC_DRAW
  );

  glEnableVertexAttribArray( 0 );
  glBindBuffer( GL_ARRAY_BUFFER, vertexBuffer );
  glVertexAttribPointer(
      0,
      3,
      GL_FLOAT,
      GL_FALSE,
      0,
      (void *) 0
  );

  glDrawArrays( GL_TRIANGLES, 0, 3 );

  glDisableVertexAttribArray( 0 );

  SDL_GL_SwapWindow( window );
  SDL_Delay( 2000 );
}

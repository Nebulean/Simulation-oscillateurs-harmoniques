#ifndef H_GLSPHERE
#define H_GLSPHERE

#include <QGLBuffer>
#include <QGLShaderProgram>

class GLSphere
{
public:
 GLSphere()
   : vbo(QGLBuffer::VertexBuffer), ibo(QGLBuffer::IndexBuffer)
 {}

  void initialize(GLuint slices = 25, GLuint stacks = 25);

  void draw(QGLShaderProgram& program, int attributeLocation);

  void bind();
  void release();

private:
  QGLBuffer vbo, ibo;
  GLuint vbo_sz;
  GLuint ibo_sz[3];
};

#endif // H_GLSPHERE

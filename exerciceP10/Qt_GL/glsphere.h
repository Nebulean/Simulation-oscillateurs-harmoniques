// Ce fichier provient (pouvant être modifié) du cours d'informatique pour physiciens et mathématiciens de l'EPFL.
// Lien: https://progmaph.epfl.ch/

#ifndef H_GLSPHERE
#define H_GLSPHERE

#include <QGLBuffer>
#include <QGLShaderProgram>

/*!
 * Implémentation de la sphère en OpenGL.
 */
class GLSphere
{
public:
  //! Constructeur de GLSphere.
 GLSphere()
   : vbo(QGLBuffer::VertexBuffer), ibo(QGLBuffer::IndexBuffer)
 {}

  //! Méthode d'initialisation des sphères.
  void initialize(GLuint slices = 25, GLuint stacks = 25);

  //! Méthodes dessinant les sphères.
  void draw(QGLShaderProgram& program, int attributeLocation);

  void bind(); //!< Méthode donné dans le tuto que nous ne comprenons pas en détail.
  void release(); //!< Méthode donné dans le tuto que nous ne comprenons pas en détail.

private:
  QGLBuffer vbo; //!< Attribut donné dans le tuto que nous ne comprenons pas en détail.
  QGLBuffer ibo; //!< Attribut donné dans le tuto que nous ne comprenons pas en détail.
  GLuint vbo_sz; //!< Attribut donné dans le tuto que nous ne comprenons pas en détail.
  GLuint ibo_sz[3]; //!< Attribut donné dans le tuto que nous ne comprenons pas en détail.
};

#endif // H_GLSPHERE

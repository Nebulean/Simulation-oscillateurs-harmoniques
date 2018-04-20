#include <iostream> // pour endl
#include "text_viewer.h"
#include "contenu.h"

void TextViewer::dessine(Contenu const& a_dessiner)
{
  flot << a_dessiner.infos() << std::endl;
}

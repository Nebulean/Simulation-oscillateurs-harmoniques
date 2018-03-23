#include <iostream>
#include "integrateur.h"
#include "../oscillateur/oscillateur.h"

using namespace std;

// on définit une petite sous-classe pour le test de la chute libre
class Chute : public Oscillateur{
public:
  Vecteur evolution(double const& dt){
    return {}
  }
};


int main(){


  return 0;
}

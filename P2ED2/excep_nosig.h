#ifndef EXCEP_NOSIG_H_INCLUDED
#define EXCEP_NOSIG_H_INCLUDED

#include "excepcion.h"

using namespace std;

class NoHaySiguienteMayor: public Excepcion {
  public:
     NoHaySiguienteMayor(): Excepcion("No hay Siguiente Mayor") {};
};

#endif // EXCEP_NOSIG_H_INCLUDED

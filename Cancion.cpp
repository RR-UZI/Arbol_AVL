//
//  Cancion.cpp
//  Arbol_AVL
//
//  Created by Uziel Cornejo olivares on 9/19/21.
//

#include "Cancion.h"
#include <stdlib.h>

int Cancion::getNumero() const
{
    return Numero;
}

void Cancion::setNumero(int value)
{
    Numero = value;
}

string Cancion::getNombre() const {
    return Nombre;
}

void Cancion::setNombre(const string &value)
{
    Nombre = value;
}

int Cancion::getAnio() const
{
    return Anio;
}

void Cancion::setAnio(int value)
{
    Anio = value;
}

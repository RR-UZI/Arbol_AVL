//
//  Cancion.h
//  Arbol_AVL
//
//  Created by Uziel Cornejo olivares on 9/19/21.
//

#ifndef Cancion_h
#define Cancion_h

#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

class Cancion
{
    int Numero;
    string Nombre;
    int Anio;
    
public:
    Cancion(){};
    int getNumero() const;
    void setNumero(int value);
    string getNombre() const;
    void setNombre(const string &value);
    int getAnio() const;
    void setAnio(int value);

friend ostream& operator<<(ostream &out, const Cancion &c)
{
    out << left;
    out << setw(25) << c.Numero;
    out << setw(25) << c.Nombre;
    out << setw(25) << c.Anio;
    out << endl;

    return out;
}

friend istream& operator>>(istream &in, Cancion &c) {
  
    cout << "Ingresa el numero de la cancion: " << endl;
    cin >> c.Numero;
    cin.ignore();
    
    cout << "Ingresa el nombre de la cancion: " << endl;
    getline(cin, c.Nombre);
    
    
    cout << "Ingresa el anio de creacion: " << endl;
    cin >> c.Anio;
    
    
    return in;
}
    
};





#endif /* Cancion_h */

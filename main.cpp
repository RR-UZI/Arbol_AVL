//
//  main.cpp
//  Arbol_AVL
//
//  Created by Uziel Cornejo olivares on 9/18/21.
//

#include <iostream>
#include "arbolAVL.h"
#include "Cancion.h"


using namespace std;
 

 
// Driver Code
int main()
{                                                                                                                                                                     
    Nodo *raiz = NULL;
    string op, temp;
    while (true) {
        cout << "---------- Menu ----------" << endl;
        cout << "1.-  Insertar " << endl;
        cout << "2.-  Pre-Order " << endl;
        cout << "3.-  In-Order " << endl;
        cout << "4.-  Post-Order " << endl;
        cout << "5.-  Respaldar " << endl;
        cout << "6.-  Cargar " << endl;
        cout << "7.-  Buscar " << endl;
        cout << "0.-  Salir" << endl;
        getline(cin,op);
        
        if (op == "1") {
            Cancion c;
            cin >> c;
            raiz = insert(raiz, c);
            cin.ignore();
        }
        else if (op == "2") {
            cout << "El pre-Order es el siguiente: " << endl;
            cout << left;
            cout << setw(25) << "Numero";
            cout << setw(25) << "Nombre";
            cout << setw(25) << "Anio";
            cout << endl;
            preOrder(raiz);
        }
        else if (op == "3") {
            cout << "El in-Order es el siguiente: " << endl;
            cout << left;
            cout << setw(25) << "Numero";
            cout << setw(25) << "Nombre";
            cout << setw(25) << "Anio";
            cout << endl;
            inOrder(raiz);
        }
        else if (op == "4") {
            cout << "El post-Order es el siguiente: " << endl;
            cout << left;
            cout << setw(25) << "Numero";
            cout << setw(25) << "Nombre";
            cout << setw(25) << "Anio";
            cout << endl;
            postOrder(raiz);
        }
        else if (op == "5") {
            respaldar(raiz);
        }
        else if (op == "6") {
            raiz = cargar();
        }
        else if (op == "7") {
            Cancion c;
            int numero;
            cout << "Que numero de cancion deseas buscar: ";
            cin >> numero;
            c.setNumero(numero);
            buscar(raiz, c);

        }
        else if (op == "0")
        {
            break;
        }
    }
     

    return 0;
}
 

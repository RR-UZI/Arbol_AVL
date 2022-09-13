//
//  arbolAVL.h
//  Arbol_AVL
//
//  Created by Uziel Cornejo olivares on 9/19/21.
//

#ifndef arbolAVL_h
#define arbolAVL_h

#include <iostream>
#include "Cancion.h"
#include <fstream>
#include <queue>

using namespace std;



class Nodo {
public:
    Cancion key;
    Nodo *izquierda;
    Nodo *derecha;
    int altura;
    
};


int max(int a, int b);

int altura(Nodo *N) {
    if (N == NULL){
        return 0;
    }
    return N->altura;
}

int max(int a, int b) {
    return (a > b)? a:b;
}

Nodo* newNodo(Cancion key) {
    Nodo* node = new Nodo();
    node->key = key;
    node->izquierda = NULL;
    node->derecha = NULL;
    node->altura = 1;
    
    return(node);
}

Nodo *rotacionDerecha(Nodo *y) {
    Nodo *x = y->izquierda;
    Nodo *T2 = x->derecha;
    
    x->derecha = y;
    y->izquierda = T2;
    
    y->altura = max(altura(y->izquierda), altura(y->derecha)) + 1;
    x->altura = max(altura(x->izquierda), altura(x->derecha)) + 1;
    
    return x;
}

Nodo *rotacionIzquierda(Nodo *x) {
    Nodo *y = x->derecha;
    Nodo *T2 = y->izquierda;
    
    y->izquierda = x;
    x->derecha = T2;
    
    x->altura = max(altura(x->izquierda), altura(x->derecha)) + 1;
    y->altura = max(altura(y->izquierda), altura(y->derecha)) + 1;
    
    return y;
}

int getBalance(Nodo *N)
{
    if (N == NULL)
        return 0;
    return altura(N->izquierda) - altura(N->derecha);
}
 

Nodo* insert(Nodo* nodo, Cancion key)
{

    if (nodo == NULL)
        return(newNodo(key));
 
    if (key.getNumero() < nodo->key.getNumero())
        nodo->izquierda = insert(nodo->izquierda, key);
    else if (key.getNumero() > nodo->key.getNumero())
        nodo->derecha = insert(nodo->derecha, key);
    else
        return nodo;
 
    
    nodo->altura = 1 + max(altura(nodo->izquierda),
                        altura(nodo->derecha));
 
    
    int balance = getBalance(nodo);
 
    // Left Left Case
    if (balance > 1 && key.getNumero() < nodo->izquierda->key.getNumero())
        return rotacionDerecha(nodo);
 
    // Right Right Case
    if (balance < -1 && key.getNumero() > nodo->derecha->key.getNumero())
        return rotacionIzquierda(nodo);
 
    // Left Right Case
    if (balance > 1 && key.getNumero() > nodo->izquierda->key.getNumero())
    {
        nodo->izquierda = rotacionIzquierda(nodo->izquierda);
        return rotacionDerecha(nodo);
    }
 
    // Right Left Case
    if (balance < -1 && key.getNumero() < nodo->derecha->key.getNumero())
    {
        nodo->derecha = rotacionDerecha(nodo->derecha);
        return rotacionIzquierda(nodo);
    }
 
    return nodo;
}

void preOrder(Nodo *raiz)
{
    if(raiz != NULL)
    {
        cout << raiz->key;
        preOrder(raiz->izquierda);
        preOrder(raiz->derecha);
    }
}

void inOrder(Nodo *raiz)
{
    if(raiz != NULL)
    {
        inOrder(raiz->izquierda);
        cout << raiz->key;
        inOrder(raiz->derecha);
    }
}

void postOrder(Nodo *raiz)
{
    if(raiz != NULL)
    {
        postOrder(raiz->izquierda);
        postOrder(raiz->derecha);
        cout << raiz->key;
    }
}

bool b = false;

bool buscar(Nodo *raiz, Cancion key)
{
    
    if(raiz != NULL)
    {
        if (raiz->key.getNumero() == key.getNumero())
        {
            b = true;
            cout << "Se a encontrado " << endl;
            cout << left;
            cout << setw(25) << "Numero";
            cout << setw(25) << "Nombre";
            cout << setw(25) << "Anio";
            cout << endl;
            cout << raiz->key << endl;
            
        }
        else if (raiz->key.getNumero() < key.getNumero())
        {
            buscar(raiz->derecha, key);
            
        }else
        {
            buscar(raiz->izquierda, key);
            
        }
        
    }
    else if (b == false)
    {
        cout << "No se encontro" << endl;
    }
    return b;
    
}


string serialize(Nodo* nodo) {
    if (nodo == nullptr) {
        return "#,";
        
    }
    string left = serialize(nodo->izquierda);
    string right = serialize(nodo->derecha);
    
    return  to_string(nodo->key.getNumero()) + "|" + nodo->key.getNombre() + "|" + to_string (nodo->key.getAnio()) + "|" + to_string(nodo->altura) +"|," + left + right;
    
}

vector<string> split(string s, string delimitador)
{
    size_t pos = 0;
    string token;
    vector<string> atributos;
    while ((pos = s.find(delimitador)) != string::npos) {
        token = s.substr(0, pos);
        atributos.push_back(token);
        s.erase(0, pos + delimitador.length());
    }
    return atributos;
}

queue<string> printQ(queue<string> cola)
{
    queue<string> copy;
    while (!cola.empty()) {
        cout << cola.front()<< endl;
        copy.push(cola.front());
        cola.pop();
    }
    return copy;
}

Nodo* deserialize(queue<string> &cola) {

    string registro = cola.front();
    cola.pop();
    if (registro == "#") {
        return nullptr;
    }
    vector<string> atributos = split(registro, "|");
    Cancion val;
    val.setNumero(stoi(atributos.at(0)));
    val.setNombre(atributos.at(1));
    val.setAnio(stoi(atributos.at(2)));
    Nodo* pNode = new Nodo();
    
    pNode->key = val;
    pNode->altura = stoi(atributos.at(3));
    pNode->izquierda = deserialize(cola);
    pNode->derecha = deserialize(cola);

    return pNode;
}

void respaldar(Nodo *raiz)
{
    ofstream archivo("file01.txt", ios::binary | ios::out);
//    int a = 500;
    if (archivo.is_open()) {
        string serializar = serialize(raiz);
        archivo.write(serializar.c_str(), serializar.length());
//        archivo.write(reinterpret_cast<const char *>(&a), sizeof(a));
        archivo.close();
    }

}

Nodo* cargar()
{
    queue<string> cola;
    string info;
    ifstream archivo("file01.txt", ios::binary | ios::in);
    if (archivo.is_open()) {
        while (getline(archivo, info, ',')) {
            cola.push(info);
        }
        
        archivo.close();
        return deserialize(cola);
    }
    return NULL;
}








#endif /* arbolAVL_h */

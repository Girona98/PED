#ifndef __TABBCALENDARIO__
#define __TABBCALENDARIO__
#include <iostream>
#include <string.h>
#include "tcalendario.h"
#include "tvectorcalendario.h"
using namespace std;

class TNodoABB;

class TABBCalendario{
    friend class TNodoABB;
    private:
        //Puntero al nodo
        TNodoABB *raiz;
        //AUXILIAR: devuelve el recorrido en INORDEN
        void InordenAux(TVectorCalendario &, int &)const;
        //AUXILIAR: devuelve el recorrido en PREORDEN
        void PreordenAux(TVectorCalendario&, int &)const;
        //AUXILIAR: devuelve el recorrido en POSTORDEN
        void PostordenAux(TVectorCalendario&, int &)const;
        //auxiliar para realizar la copia de tabbcalendarios
        void Copiar(const TABBCalendario &);
    public:
        //Constructor por defecto
        TABBCalendario();
        //Constructor de copia
        TABBCalendario(const TABBCalendario&);
        //Destructor
        ~TABBCalendario();
        //Sobrecarga del operador asignacion
        TABBCalendario &operator=(const TABBCalendario&);
        //Sobrecarga del operador igualdad
        bool operator==(TABBCalendario &) const;
        //devuelve true si el arbol esta vacio, false en caso contrario
        bool EsVacio()const;
        //inserta el elemento en el arbol
        bool Insertar(TCalendario&);
        //borra el elemento en el arbol
        bool Borrar(TCalendario&);
        //devuelve true si el lemeento esta en earbol, false si no
        bool Buscar(const TCalendario&)const;
        //devuelve el elemento de la raiz del arbol
        TCalendario Raiz();
        //devuelve la altura del arbol
        int Altura();
        //devuelve el numero de nodos del arbol
        int Nodos()const;
        //devuelve el numero de nodos hoja en el arbol, la raiz puede ser nodo hoja
        int NodosHoja();
        //devuelve el recorrido en inorden sobre un vector
        TVectorCalendario Inorden() const;
        //devuelve el recorrido en preorden sobre un vector
        TVectorCalendario Preorden()const;
        //devuelve el recorrido en postorden sobre un vector
        TVectorCalendario Postorden()const;
        //devuelve el recorrido en niveles sobre un vector
        TVectorCalendario Niveles()const;
        //sobrecarga del operador salida
        friend ostream &operator<<(ostream&, TABBCalendario&);
        //suma de dos ABB
        TABBCalendario operator+ (TABBCalendario&);
        // resta de dos ABB
        TABBCalendario operator-(TABBCalendario&);
};

class TNodoABB{
    friend class TABBCalendario;
    private:
        TCalendario item;   //elemento del nodo
        TABBCalendario iz, de; //subarbol izquierdo y derecho
    public:
        //Consturctor por defecto
        TNodoABB();
        //Constructor copia 
        TNodoABB(const TNodoABB &);
        //Destructor
        ~TNodoABB();
        //Sobrecarga del operador asignacion
        TNodoABB &operator=(TNodoABB &);
};
#endif
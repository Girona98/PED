#ifndef __tlistacalendario__
#define __tlistacalendario__
#include <iostream>
#include <tcalendario.h>
#include <tvectorcalendario.h>
using namespace std;

class TNodoCalendario{
    
    private:
        TCalendario c; //uso de layering sobre la clase
        TNodoCalendario *siguiente;
    public:
        TNodoCalendario(); //constructor por defecto
        TNodoCalendario(TNodoCalendario &); //constructor de copia
        ~TNodoCalendario(); //destructor
        TNodoCalendario &operator=(TNodoCalendario&);
};

class TListaPos{
    private:
        TNodoCalendario *pos;
    public:
        TListaPos(); //constructor por defecto
        TListaPos(TListaPos&); //constructor de copia
        ~TListaPos(); //destructor
        TListaPos& operator=(TListaPos&); //sobrecarga del operador asignacion
        bool operator==(TListaPos&); //sobrecarga del operador igualdad
        bool operator!=(TListaPos&); //sobrecarga del operador desigualdad
        TListaPos Siguiente(); //devuelve la posicion siguiente
        bool EsVacia(); //posicion vacia
};

class TListaCalendario{
    friend ostream& operator<<(ostream&, TListaCalendario&);
    private:
        TNodoCalendario *primero;
    public:
        TListaCalendario(); //constructor por defecto
        TListaCalendario(TListalendario&); //constructor de copia
        ~TListaCalendario(); //destructor
        TListaCalendario& operator=(TListaCalendario&); //sobrecarga del operador asingacion
        bool operator==(TListaCalendario&); //sobrecarga del operador igualdad
        TListaCalendario operator+(TListaCalendario&); //sobrecarga del operador suma
        TListaCalendario operator-(TListaCalendario&); //sobrecarga del operador resta
        bool Insertar(TCalendario &);// Inserta el elemento en la posición que le corresponda dentro de la lista
        bool Borrar(TCalendario &);        // Busca y borra el elemento
        bool Borrar (TListaPos &);// Borra el elemento que ocupa la posición indicada
        bool Borrar(int,int,int);//Borra todos los Calendarios con fecha ANTERIOR a la pasada.
        bool EsVacia();// Devuelve true si la lista está vacía, false en caso contrario
        TCalendario Obtener(TListaPos&); //obtiene el elemento que ocupa la posicion indicada
        bool Buscar(TCalendario&); //devuelve true si el calendario esta en la lista
        int Longitud(); //devuelve la longitud de la lista
        TListaPos Primera(); //devuelve la primera posicion en la lista
        TListaPos Ultima(); //devuelve la ultima posicion en la lista
        TListaCalendario SumarSubl(int, int, TListaCalendario&, int, int); //suma de dos sublistas en una nueva lista
        TListaCalendario ExtraerRango(int, int); //extraer un rango de nodos de la lista

        
};
#endif
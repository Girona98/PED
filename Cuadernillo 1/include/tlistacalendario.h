#ifndef __tlistacalendario__
#define __tlistacalendario__
#include <iostream>
#include <tcalendario.h>
#include <tvectorcalendario.h>
using namespace std;

class TNodoCalendario{
    friend class TListaCalendario;
    friend class TListaPos;
    
    private:
        TCalendario c; //uso de layering sobre la clase
        TNodoCalendario *siguiente;
    public:
        TNodoCalendario(); //constructor por defecto
        TNodoCalendario(const TNodoCalendario &); //constructor de copia
        ~TNodoCalendario(); //destructor
        TNodoCalendario &operator=(TNodoCalendario&);
};

class TListaPos{
    friend class TNodoCalendario;
    friend class TListaCalendario;
    private:
        TNodoCalendario *pos;
    public:
        TListaPos(); //constructor por defecto
        TListaPos(const TListaPos&); //constructor de copia
        ~TListaPos(); //destructor
        TListaPos& operator=(const TListaPos&); //sobrecarga del operador asignacion
        bool operator==(const TListaPos&); //sobrecarga del operador igualdad
        bool operator!=(const TListaPos&); //sobrecarga del operador desigualdad
        TListaPos Siguiente(); //devuelve la posicion siguiente
        bool EsVacia(); //posicion vacia
};

class TListaCalendario{
    friend class TListaPos;
    friend class TNodoCalendario;
    friend ostream& operator<<(ostream&, const TListaCalendario&);
    private:
        TNodoCalendario *primero;
    public:
        TListaCalendario();                                         //constructor por defecto
        TListaCalendario(const TListaCalendario&);                        //constructor de copia
        ~TListaCalendario();                                        //destructor
        TListaCalendario& operator=(const TListaCalendario&);             //sobrecarga del operador asingacion
        bool operator==(const TListaCalendario&);                         //sobrecarga del operador igualdad
        TListaCalendario operator+(const TListaCalendario&);        //sobrecarga del operador suma
        TListaCalendario operator-(const TListaCalendario&);        //sobrecarga del operador resta
        bool Insertar(const TCalendario &);                               // Inserta el elemento en la posición que le corresponda dentro de la lista
        bool Borrar(const TCalendario &);                                 // Busca y borra el elemento
        bool Borrar (const TListaPos &);                                  // Borra el elemento que ocupa la posición indicada
        bool Borrar(int,int,int);                                   //Borra todos los Calendarios con fecha ANTERIOR a la pasada.
        bool EsVacia() const;                                       // Devuelve true si la lista está vacía, false en caso contrario
        TCalendario Obtener(const TListaPos&) const;                       //obtiene el elemento que ocupa la posicion indicada
        bool Buscar(const TCalendario&);                            //devuelve true si el calendario esta en la lista
        int Longitud() const;                                       //devuelve la longitud de la lista
        TListaPos Primera() const;                                   //devuelve la primera posicion en la lista
        TListaPos Ultima() const;                                   //devuelve la ultima posicion en la lista
        TListaCalendario SumarSubl(int, int, TListaCalendario&, int, int); //suma de dos sublistas en una nueva lista
        TListaCalendario ExtraerRango(int, int);                    //extraer un rango de nodos de la lista
};
#endif
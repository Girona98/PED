#ifndef __tvector__
#define __tvector__
#include <iostream>
#include <tcalendario.h>
using namespace std;

class TVectorCalendario{
    friend ostream& operator<<(ostream&, TVectorCalendario&);
    private:
        TCalendario *c;
        int tamano;
        TCalendario error;
    public:
        TVectorCalendario();                                //constructor por defecto
        TVectorCalendario(int);                             //consturctor a partir de un tamaño
        TVectorCalendario(TVectorCalendario&);              //constructor de copia
        ~TVectorCalendario();                               //destructor
        TVectorCalendario& operator=(TVectorCalendario&);   //sobrecarga del operador asignacion
        bool operator==(TVectorCalendario&);                //sobrecarga del operador igualdad
        bool operator!=(TVectorCalendario&);                //sobrecarga del operador desigualdad
        TCalendario& operator[](int);                       //sobrecarga del operador corchete(parte izquierda)
        TCalendario operator[](int) const;                  //sobrecarga del operador corchete (parte derecha)
        int Tamano();                                       //tamaño del vector (posiciones totales)
        int Ocupadas();                                     //cantidad de posiciones ocupadas (no vacias) del vector
        bool ExisteCal(TCalendario&);                       //devuelve true si existe el calendario en el vector
        void MostrarMensajes(int,int,int);                  //muestra por pantalla mensajes de tcalendario en el vector, fechecha igual o posterior a la pasada
        bool Redimensionar(int);                            //redimensiona el vector de tcalendario

};
#endif
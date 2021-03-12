#ifndef __TCALENDARIO__
#define __TCALENDARIO__
#include <iostream>
#include <string.h>
using namespace std;

class TCalendario{
    //funciones amigas
    friend ostream& operator<<(ostream&, const TCalendario&); //sobrecarga del operador de salida
    
    private:
        int dia;
        int mes;
        int anyo;
        char* mensaje;
        bool checkFecha(int, int, int);         //funcion auxiliar para comprobar fecha correcta
        bool isBisiesto(int);                   //devuelve true si el año es bisiesto
    public:
        //FORMA CANONICA
        TCalendario();                          //constructor por defecto
        TCalendario(int, int, int, char*);      //constructor por parametros
        TCalendario(const TCalendario&);              //constructor de copia
        ~TCalendario();                         //destructor
        TCalendario& operator=(const TCalendario&);   //sobrecarga del operador de asignacion
        //METODOS
        TCalendario operator+(int);             //sobrecarga del operador: suma de fecha + un numero de dias
        TCalendario operator-(int);             //sobrecarga del operador: resta de fecha - un numero de dias
        TCalendario operator++(int);            //modifica la fecha incrementandola en un dia (cons postincremento)
        TCalendario& operator++();              //modifica la fecha incrementandola en un dia (con preincremento)
        TCalendario operator--(int);            //modifica la fecha decrementandola en un dia ( con postdecremento)
        TCalendario& operator--();              //modifica la fecha decrementandola en un dia(con predecremento)
        bool ModFecha(int, int, int);           //modifica la fecha
        bool ModMensaje(char*);                 //modifica el mensaje
        bool operator==(const TCalendario&);          //sobrecarga del operador igualdad
        bool operator!=(const TCalendario&);          //sobrecarga del operador desigualdad
        bool operator>(const TCalendario&);           //sobrecarga del operador >
        bool operator<(const TCalendario&);           //sobrecarga del operador <
        bool EsVacio();                         //TCalendario vacio
        const int Dia();                              //devuelve el dia del calendario
        const int Mes();                              //devuelve el mes del calendario
        const int Anyo();                             //devuelve el año del calendario
        const char* Mensaje();                        //devuelve el mensaje del calendario
};
#endif
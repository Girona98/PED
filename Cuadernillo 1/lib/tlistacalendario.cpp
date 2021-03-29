#include "../include/tlistacalendario.h"

/*Metodos TNODOCALENDARIO
    ATRIBUTOS
    TCalendario c;  uso de leewayering sobre la clase 
    TNodoCalendario *siguiente
*/

//llama por defecto al constructor de tcalendario para c
TNodoCalendario::TNodoCalendario(){ 
    this->siguiente = NULL;
}

//en este caso llamamos al constructor de copia de tcalendario con :c(tnodo.c)
TNodoCalendario::TNodoCalendario(TNodoCalendario &tnodo):c(tnodo.c){
    this->siguiente = NULL;
}

TNodoCalendario::~TNodoCalendario(){
    this->c.~TCalendario();
    this->siguiente = NULL;
}

TNodoCalendario& TNodoCalendario::operator=(TNodoCalendario &tnodo){
    if(this != &tnodo){
        this->~TNodoCalendario();
        this->c = tnodo.c;
        if(tnodo.siguiente == NULL){
            this->siguiente = NULL;
        }
        else{
            this->siguiente = tnodo.siguiente;   
        }
    }
    return *this;
}

/*
Metodos TListaPos
    ATRIBUTOS
    TNodoCalendario *pos
*/
TListaPos::TListaPos(){
    this->pos = NULL;
}

TListaPos::TListaPos(TListaPos& tlista){
    if(tlista.pos == NULL){
        this->pos = NULL;
    }
    else{
        this->pos = tlista.pos;
    }
}

TListaPos::~TListaPos(){
    this->pos = NULL;
}

TListaPos& TListaPos::operator=(TListaPos &tlista){
    if(this != &tlista){
        if(tlista.pos != NULL){
            this->~TListaPos();
            this->pos = tlista.pos;
        }
        else{
            this->pos = NULL;
        }
    }
    return *this;
}

//son iguales si apuntan a la misma direccion de memoria 
bool TListaPos::operator==(TListaPos& tlista){
    bool iguales = false;
    if(this->pos == tlista.pos){
        iguales = true;
    }
    return iguales;
}

bool TListaPos::operator!=(TListaPos& tlista){
    return !(this == &tlista);
}

TListaPos TListaPos::Siguiente(){
    TListaPos tlista;
    tlista.pos = this->pos->siguiente;
    return tlista;
}
bool TListaPos::EsVacia(){
    bool vacia = false;
    if(this->pos == NULL){
        bool vacia = true;
    }
    return vacia;
}

/*Metodos TListaCalendario
    ATRIBUTOS
    TNodoCalendario *primero
*/

TListaCalendario::TListaCalendario(){
    this->primero = NULL;   
}

TListaCalendario::TListaCalendario(TListaCalendario& tlista){
    //para realizar una copia exacta primero checkeamos 
    //que no sea una lista vacia
    this->primero = tlista.primero;
    if(tlista.primero == NULL){
        this->primero = NULL;
    }
    else{
        TNodoCalendario *nuevoprimero;
        TNodoCalendario *nuevosiguiente;
        //recorremos la lista 
        nuevoprimero = primero; //asignamos el primero nodo
        while(nuevoprimero != NULL){    
            nuevosiguiente = nuevoprimero->siguiente; //guardamos el siguiente del primero
            this->primero->c = tlista.primero->
        }
    }
}

TListaCalendario::~TListaCalendario(){

}

TListaCalendario& TListaCalendario::operator=(TListaCalendario&){

}

bool TListaCalendario::operator==(TListaCalendario& tlista){

}

TListaCalendario TListaCalendario::operator+(TListaCalendario& tlista){

}

TListaCalendario TListaCalendario::operator-(TListaCalendario& tlista){

}

bool TListaCalendario::Insertar(TCalendario & tcalen){

}

bool TListaCalendario::Borrar(TCalendario & tcalen){

}

bool TListaCalendario::Borrar (TListaPos &tlista){

}

bool TListaCalendario::Borrar(int dia, int mes, int anyo){

}

bool TListaCalendario::EsVacia(){

}

TCalendario TListaCalendario::Obtener(TListaPos &tlista){

}

bool TListaCalendario::Buscar(TCalendario &tcalen){

}

int TListaCalendario::Longitud(){

}

TListaPos TListaCalendario::Primera(){

}

TListaPos TListaCalendario::Ultima(){

}

TListaCalendario TListaCalendario::SumarSubl(int I_L1, int F_L1, TListaCalendario &L2, int I_L2, int F_L2){

}

TListaCalendario TListaCalendario::ExtraerRango(int n1, int n2){

}

ostream& operator<<(ostream& salida, TListaCalendario &tlista){

}
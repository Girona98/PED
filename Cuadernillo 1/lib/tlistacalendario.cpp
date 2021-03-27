#include "../include/tlistacalendario.h"

/*Metodos TNODOCALENDARIO
    ATRIBUTOS
    TCalendario c;
    TNodoCalendario *siguiente
*/
TNodoCalendario::TNodoCalendario(){
    this->siguiente = NULL;
}

TNodoCalendario::TNodoCalendario(TNodoCalendario &tnodo){
    if(&tnodo.c == NULL){
        this->c = NULL;
    }
    else{
        this->c = tnodo.c;
    }

    if(tnodo.siguiente == NULL){
        this->siguiente = NULL;
    }
    else{
        this->siguiente = tnodo.siguiente;
    }
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
            this->pos = tlista.pos;
        }
        else{
            this->pos = NULL;
        }
    }
    return *this;
}

bool TListaPos::operator==(TListaPos& tlista){
    bool igual = false;
    if(this->pos == tlista.pos){
        igual = true;
    }
    return igual;
}

bool TListaPos::operator!=(TListaPos& tlista){
    return !(this == &tlista);
}

TListaPos TListaPos::Siguiente(){
    //En Siguiente(): si la posición actual es la última de la lista, se tiene que devolver un objetoTListaPosvacío
    //carencias
    return *this->pos->siguiente;
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
    TNodoCalendario *primero        //se interpreta como lista?¿?¿
*/

TListaCalendario::TListaCalendario(){
    this->primero = NULL;
}

TListaCalendario::TListaCalendario(TListaCalendario &tlista){
    
}

TListaCalendario::~TListaCalendario(){
    this->primero->~TNodoCalendario();  //veo carencias
}

TListaCalendario& TListaCalendario::operator=(TListaCalendario &tlista){
    if(this != &tlista){

    }
}

bool TListaCalendario::operator==(TListaCalendario& tlista){
    
}

TListaCalendario TListaCalendario::operator+(TListaCalendario& tlista){

}

TListaCalendario TListaCalendario::operator-(TListaCalendario& tlista){

}

bool TListaCalendario::Insertar(TCalendario &tcalen){

}

bool TListaCalendario::Borrar(TCalendario &tcalen){

}

bool TListaCalendario::Borrar (TListaPos &tlista){

}

bool TListaCalendario::Borrar(int dia, int mes, int anyo){

}

bool TListaCalendario::EsVacia(){
    bool vacio = false;
    if(this->primero == NULL){
        vacio = true;
    }
    return vacio;
}

TCalendario TListaCalendario::Obtener(TListaPos &tlista){
    TListaPos auxiliar(tlista);
    if(tlista.EsVacia()){
        TCalendario vacio;
        return vacio; 
    }
    else{
        //return auxiliar.pos->c; esto es chuclado 
    }
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
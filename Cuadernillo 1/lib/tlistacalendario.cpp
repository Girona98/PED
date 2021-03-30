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
    TNodoCalendario *primero        //se interpreta como lista?¿?¿
*/

TListaCalendario::TListaCalendario(){
    this->primero = NULL;   
}

TListaCalendario::TListaCalendario(TListaCalendario& tlista){
    //para realizar una copia exacta primero checkea 
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
            this->primero->c = tlista.primero->c;
            nuevoprimero = nuevosiguiente; //pasamos el siguiente nodo al primer lugar
        }
    }
}


TListaCalendario::~TListaCalendario(){
    this->primero->~TNodoCalendario();  //veo carencias
}

TListaCalendario& TListaCalendario::operator=(TListaCalendario &tlista){
    if(this != &tlista){
        this->~TCalendario();
        if(tlista.primero == NULL){
            this->primero = NULL;
        }
        else{
            this->primero = tlista.primero;
        }
    }
    return *this;
}

bool TListaCalendario::operator==(TListaCalendario& tlista){
    bool igual = true;
    if(this->Longitud() == tlista.Longitud()){
        TNodoCalendario nodo1;
        TNodoCalendario nodo2;
        nodo1 = this->primero;
        nodo2 = tlista.primero;
        for(int i = 0; i < tlista.Longitud && igual == true; i++){
            if(nodo1 != nodo2){
                igual = false;
            }
            nodo1 = nodo1.siguiente;
            nodo2 = nodo2.siguiente;
        }
    }
    return igual;
}

TListaCalendario TListaCalendario::operator+(TListaCalendario& tlista){

}

TListaCalendario TListaCalendario::operator-(TListaCalendario& tlista){

}

bool TListaCalendario::Insertar(TCalendario &tcalen){

}

bool TListaCalendario::Borrar(TCalendario &tcalen){

}

bool TListaCalendario::Borrar(TListaPos &tlista){
    //este llama al borrar que elimina tcalendario
}

bool TListaCalendario::Borrar(int dia, int mes, int anyo){
    bool borrable = false;
    if(this->Primera().EsVacia()){
        borrable = false;
    }
    else{
        
    }
    return borrable;
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
        return auxiliar.pos->c;
    }
}

bool TListaCalendario::Buscar(TCalendario &tcalen){
    bool encontrado = false;
    for(int i = 0; i < this->Longitud() && encontrado == false; i++){
        if(this->primero->c[i] == tcalen){
            encontrado = true;
        }
    }
    return encontrado;
}

int TListaCalendario::Longitud(){
    int contador = 0;
    for(int i = 0; i < this->primero->siguiente != NULL; i++){
        contador++;
    }
    return contador;
}

TListaPos TListaCalendario::Primera(){
    if(this->primero == NULL){
        TListaPos vacio;
        return vacio;
    }
    else{
        return this->primero;
    }
}

TListaPos TListaCalendario::Ultima(){
    if(this->primero == NULL){
        TListaPos vacio;
        return vacio;
    }
    else{
        TListaPos tlista;
        for(int i = 0; i < this->Longitud(); i++){
            tlista = tlista.Siguiente;
        }
        return tlista;
    }
}

TListaCalendario TListaCalendario::SumarSubl(int I_L1, int F_L1, TListaCalendario &L2, int I_L2, int F_L2){

}

TListaCalendario TListaCalendario::ExtraerRango(int n1, int n2){

}

ostream& operator<<(ostream& salida, TListaCalendario &tlista){
    if(tlista.EsVacia()){
        cout<<"<>";
    }
    else{
        TNodoCalendario nodo = tlista.primero;
        cout<<"<";
        for(int i = 0; i < tlista.Longitud(); i++){
            cout<<tlista.Obtener(nodo);
            if(i >= 0 && i < tlista.Longitud() - 1){
                cout<<", ";
            }    
            nodo = tlista.primero->siguiente;
        }
        cout<<">";
    }
    return salida;
}
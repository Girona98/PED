#include "tabbcalendario.h"


//el constructor llama mediante layering a los constructores de cada atributo
TNodoABB::TNodoABB():item(), iz(), de(){}

TNodoABB::TNodoABB(TNodoABB &tnodo):item(tnodo.item), iz(tnodo.iz), de(tnodo.de){}

TNodoABB::~TNodoABB(){
    this->item.~TCalendario();
    this->iz.~TABBCalendario();
    this->de.~TABBCalendario();
}

TNodoABB& TNodoABB::operator=(TNodoABB &tnodo){
    if(this != &tnodo){
        this->item = tnodo.item;
        this->iz = tnodo.iz;
        this->de = tnodo.de;
    }
    return *this;
}

TABBCalendario::TABBCalendario(){
    
}

TABBCalendario::TABBCalendario(TABBCalendario& tabb){

}

TABBCalendario::~TABBCalendario(){

}

TABBCalendario& TABBCalendario::operator=(TABBCalendario& tabb){

}

bool TABBCalendario::operator==(TABBCalendario &tabb){

}

bool TABBCalendario::EsVacio(){

}

bool TABBCalendario::Insertar(TCalendario &calen){

}

bool TABBCalendario::Borrar(TCalendario &calen){

}

bool TABBCalendario::Buscar(TCalendario &calen){

}

int TABBCalendario::Altura(){

}

int TABBCalendario::Nodos(){

}

int TABBCalendario::NodosHoja(){

}

TVectorCalendario TABBCalendario::Inorden(){

}

TVectorCalendario TABBCalendario::Preorden(){
    
}

TVectorCalendario TABBCalendario::PostOrden(){

}

TVectorCalendario TABBCalendario::Niveles(){

}

ostream &operator<<(ostream&, TABBCalendario&){

}

TABBCalendario TABBCalendario::operator+ (TABBCalendario &tabb){

}

TABBCalendario TABBCalendario::operator-(TABBCalendario &tabb){

}
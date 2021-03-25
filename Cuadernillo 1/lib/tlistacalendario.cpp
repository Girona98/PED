#include "../include/tlistacalendario.h"

/*Metodos TNODOCALENDARIO
    ATRIBUTOS
    TCalendario c;
    TNodoCalendario *siguiente
*/
TNodoCalendario::TNodoCalendario(){

}

TNodoCalendario::TNodoCalendario(TNodoCalendario &tnodo){

}

TNodoCalendario::~TNodoCalendario(){

}

TNodoCalendario& TNodoCalendario::operator=(TNodoCalendario &tnodo){

}

/*
Metodos TListaPos
    ATRIBUTOS
    TNodoCalendario *pos
*/
TListaPos::TListaPos(){

}

 TListaPos::TListaPos(TListaPos& tlista){

}

TListaPos::~TListaPos(){

}

TListaPos& TListaPos::operator=(TListaPos&){
    
}

bool TListaPos::operator==(TListaPos& tlista){
    
}

bool TListaPos::operator!=(TListaPos& tlista){

}

TListaPos TListaPos::Siguiente(){

}
bool TListaPos::EsVacia(){

}

/*Metodos TListaCalendario
    ATRIBUTOS
    TNodoCalendario *primero
*/

TListaCalendario::TListaCalendario(){
    
}

TListaCalendario::TListaCalendario(TListaCalendario& tlista){

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
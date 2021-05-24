#include "../include/tavlcalendario.h"
#include <queue>

//el constructor llama mediante layering a los constructores de cada atributo
TNodoAVL::TNodoAVL() : item(), iz(), de() {
    this->fe = 0;
}

TNodoAVL::TNodoAVL(const TNodoAVL &tnodo) : item(tnodo.item), iz(tnodo.iz), de(tnodo.de) {
    this->fe = 0;
}

TNodoAVL::~TNodoAVL(){}

TNodoAVL &TNodoAVL::operator=(TNodoAVL &tnodo){
    if (this != &tnodo){
        this->~TNodoAVL();
        this->item = tnodo.item;
        this->iz = tnodo.iz;
        this->de = tnodo.de;
        this->fe = tnodo.fe;
    }
    return *this;
}

TAVLCalendario::TAVLCalendario(){
    this->raiz = NULL;
}

TAVLCalendario::TAVLCalendario(const TAVLCalendario &tavl){
    this->raiz = NULL;
    this->Copiar(tavl);
}

TAVLCalendario::~TAVLCalendario(){
    delete this->raiz;
    this->raiz = NULL;
}
void TAVLCalendario::Copiar(const TAVLCalendario &tavl){
    if(tavl.raiz == NULL){
        this->raiz = NULL;
    }
    else{
        TNodoAVL *tnodo = new TNodoAVL();
        tnodo->item = tavl.raiz->item;
        this->raiz = tnodo;
        tnodo->fe = tavl.raiz->fe;
        this->raiz->iz.Copiar(tavl.raiz->iz);
        this->raiz->de.Copiar(tavl.raiz->de);
    }
}

TAVLCalendario& TAVLCalendario::operator=(const TAVLCalendario &tavl){
    if (this != &tavl){
        this->~TAVLCalendario();
        this->Copiar(tavl);
        return *this;
    }
    else{
        return *this;
    }
}

bool TAVLCalendario::operator==(TAVLCalendario &tavl) const{
    TVectorCalendario arbol1, arbol2;
    arbol1 = this->Inorden();
    arbol2 = tavl.Inorden();
    return arbol1 == arbol2;
}

bool TAVLCalendario::operator!=(TAVLCalendario &tavl) const{
        return !(this==&tavl);
}

bool TAVLCalendario::EsVacio() const{
    if (this->raiz == NULL){
        return true;
    }
    else{
        return false;
    }
}

bool TAVLCalendario::Insertar(TCalendario &calen){
    bool insertado = false;
    if (this->Buscar(calen) == true){
        insertado = false;
    }
    else if(this->raiz == NULL){    
        this->raiz = new TNodoAVL;
        this->raiz->item = calen;
        insertado = true;
    }
    else if(calen < this->raiz->item){
        insertado = this->raiz->iz.Insertar(calen);
    }
    else if(calen > this->raiz->item){
        insertado = this->raiz->de.Insertar(calen);
    }
    if(insertado == true){
        this->equilibrar();
    }
    return insertado;
}

void TAVLCalendario::equilibrar(){
    int fe = this->raiz->fe;

    if(fe > 1){  //rotación derecha
        TNodoAVL *tnodo;
        if(this->raiz->de.raiz->fe >= 0){
           tnodo = this->raiz->de.raiz;
           this->raiz->de.raiz = this->raiz->de.raiz->iz.raiz;
           this->raiz = tnodo; 
        }
        else{
            tnodo = this->raiz->de.raiz;
            this->raiz->de.raiz = this->raiz->iz.raiz->iz.raiz;
            tnodo->iz.raiz->iz.raiz = this->raiz;
            this->raiz = tnodo->iz.raiz;
            tnodo->iz.raiz = this->raiz->de.raiz;
            this->raiz->de.raiz = tnodo; 
        }
        this->raiz->fe = this->calcFE();
        this->updateFE();
    }
    else if(fe < -1){
        TNodoAVL *tnodo;
        if(this->raiz->de.raiz->fe <= 0){
           tnodo = this->raiz->iz.raiz;
           this->raiz->iz.raiz = this->raiz->iz.raiz->de.raiz;
           this->raiz = tnodo; 
        }
        else{
            tnodo = this->raiz->iz.raiz;
            this->raiz->iz.raiz = this->raiz->de.raiz->de.raiz;
            tnodo->de.raiz->de.raiz = this->raiz;
            this->raiz = tnodo->de.raiz;
            tnodo->de.raiz = this->raiz->iz.raiz;
            this->raiz->iz.raiz = tnodo; 
        }
        this->raiz->fe = this->calcFE();
        this->updateFE();
    }
}

int TAVLCalendario::calcFE(){
    return (this->raiz->de.Altura() - this->raiz->iz.Altura());
}

void TAVLCalendario::updateFE(){
    if (this->raiz->iz.raiz != NULL){
        this->raiz->iz.raiz->fe = this->calcFE();
    }
    if(this->raiz->de.raiz != NULL){
        this->raiz->de.raiz->fe = this->calcFE();
    }
}

bool TAVLCalendario::Borrar(TCalendario &calen){
    bool eliminado = false;
    if(this->Buscar(calen) == false || this->EsVacio() == true){
        eliminado = false;
        return eliminado;
    }
    else{
        if(calen == this->raiz->item){
            if(this->raiz->iz.EsVacio() == true || this->raiz->de.EsVacio() == true){  // 0 ó 1 hijo
            //no tiene hijo derecho, por lo cual analizamos el de la izquierda
                if(this->raiz->de.EsVacio() == true){
                    TNodoAVL *nextnodo(this->raiz->iz.raiz);
                    this->raiz = nextnodo; //hacemos que el nodo actual sea el nodo siguiente, eliminando el objetivo
                    eliminado = true;
                }
                else{
                    //no tiene hijo izquierdo ,por lo cual analizamos el de la derecha
                    if(this->raiz->iz.EsVacio() == true){
                        TNodoAVL *nextnodo(this->raiz->de.raiz);
                        this->raiz = nextnodo;
                        eliminado = true;
                    }
                    else{
                        this->raiz = NULL; //la raiz no tiene ningun hijo
                        eliminado = true;
                    }
                }
            }
            else{   // 2 hijos
                TNodoAVL *nodoavl = new TNodoAVL(this->raiz->iz.BuscarIzq());
                //guardamos el objeto this en nodoavl
                nodoavl->iz = this->raiz->iz;
                nodoavl->de = this->raiz->de;
                this->raiz = nodoavl;
                nodoavl = NULL;
                eliminado = true;
            }
        }
        else if(calen > this->raiz->item){
            eliminado = this->raiz->de.Borrar(calen);
        }
        else if(calen < this->raiz->item){
            eliminado = this->raiz->iz.Borrar(calen);
        }
        else{
            eliminado = false;
        }
    }

    if(this->raiz != NULL){
        this->equilibrar();
    }
    return eliminado;
}

TNodoAVL TAVLCalendario::BuscarIzq(){
    if(this->EsVacio() == true){
        TNodoAVL *tnodo = new TNodoAVL();
        return *tnodo;
    }
    else if(this->raiz->de.EsVacio() == true){
        TNodoAVL *tnodo = new TNodoAVL();
        tnodo = this->raiz;
        TCalendario delCalen = tnodo->item;
        this->Borrar(delCalen);
        return *tnodo;
    }
    else{
        TNodoAVL *tnodo = new TNodoAVL(this->raiz->de.BuscarIzq());
        return *tnodo;
    }
}

bool TAVLCalendario::Buscar(const TCalendario &calen)const{
    if (this->EsVacio() == true){
        return false;
    }
    else{
        if (this->raiz->item == calen){
            return true;
        }
        else{
            if (calen > this->raiz->item){
                return this->raiz->de.Buscar(calen);
            }
            else{
                return this->raiz->iz.Buscar(calen);
            }
        }
    }
}

TCalendario TAVLCalendario::Raiz(){
    if (this != NULL){
        return this->raiz->item;
    }
    else{
        TCalendario *vacio = new TCalendario();
        return *vacio;
    }
}

int TAVLCalendario::Altura(){
    if (this->EsVacio() == true){
        return 0;
    }
    else{
        return (1 + max(this->raiz->iz.Altura(), this->raiz->de.Altura()));
    }
}

int TAVLCalendario::Nodos()const{
    if (this->EsVacio() == false){
        return 1 + this->raiz->iz.Nodos() + this->raiz->de.Nodos();
    }
    else{
        return 0;
    }
}

int TAVLCalendario::NodosHoja(){
    if (this->EsVacio() == true){
        return 0;
    }
    else{
        if (this->raiz->iz.EsVacio() && this->raiz->de.EsVacio()){
            return 1;
        }
        else{
            return this->raiz->iz.NodosHoja() + this->raiz->de.NodosHoja();
        }
    }
}

TVectorCalendario TAVLCalendario::Inorden() const{
    TVectorCalendario tvector(this->Nodos());
    int n = 1;
    this->InordenAux(tvector, n); //porque el tvector cominenza en 1
    return tvector;
}

void TAVLCalendario::InordenAux(TVectorCalendario &tvector, int &n) const{
    if(this->raiz != NULL){
        this->raiz->iz.InordenAux(tvector, n);
        tvector[n] = this->raiz->item;
        n++;
        this->raiz->de.InordenAux(tvector, n);
    }
}

TVectorCalendario TAVLCalendario::Preorden()const {
    TVectorCalendario tvector(this->Nodos());
    int n = 1;
    this->PreordenAux(tvector, n);
    return tvector;
}

void TAVLCalendario::PreordenAux(TVectorCalendario &tvector, int &n)const{
    if(this->raiz != NULL){
        tvector[n] = this->raiz->item;
        n++;
        this->raiz->iz.PreordenAux(tvector, n);
        this->raiz->de.PreordenAux(tvector, n);
    }
}

TVectorCalendario TAVLCalendario::Postorden()const{
    TVectorCalendario tvector(this->Nodos());
    int n = 1;
    this->PostordenAux(tvector, n);
    return tvector;
}

void TAVLCalendario::PostordenAux(TVectorCalendario &tvector, int &n)const{
    if(this->raiz != NULL){
        this->raiz->iz.PostordenAux(tvector, n);
        this->raiz->de.PostordenAux(tvector, n);
        tvector[n] = this->raiz->item;
        n++;
    }
}

ostream &operator<<(ostream &salida, TAVLCalendario &tavlcalen){
    TAVLCalendario tavl(tavlcalen);
    TVectorCalendario recorrido = tavl.Inorden();
    salida<<recorrido;
    return salida;
}


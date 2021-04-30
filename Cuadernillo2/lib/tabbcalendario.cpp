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
    this->raiz = new TNodoABB();
}

TABBCalendario::TABBCalendario(TABBCalendario& tabb){
    if(tabb.raiz == NULL){
        this->raiz = NULL;
    }
    else{
        this->raiz = new TNodoABB(*tabb.raiz);
    }
}

TABBCalendario::~TABBCalendario(){
    delete this->raiz;
    this->raiz = NULL;
}

TABBCalendario& TABBCalendario::operator=(TABBCalendario& tabb){
    if(this != NULL){
        this->~TABBCalendario();
        TABBCalendario *nuevotabb = new TABBCalendario(tabb);
        return *nuevotabb;
    }
    else{
        TABBCalendario *nuevotabb = new TABBCalendario(tabb);
        return *nuevotabb;
    }
}

bool TABBCalendario::operator==(TABBCalendario &tabb){
    
}

bool TABBCalendario::EsVacio(){
    if(this->raiz == NULL){
        return true;
    }
    else{
        return false;
    }
}

bool TABBCalendario::Insertar(TCalendario &calen){
   if(this->raiz == NULL){
       this->raiz->item = calen;
       return true;
   }
   else{
       if(this->raiz->item == calen){
           return false;
       }
       else{
           if(calen < this->raiz.iz){
                return this->raiz->iz.Insertar(calen);
           }
           else{
               return this->raiz->de.Insertar(calen);
           }
       }
   }
}

bool TABBCalendario::Borrar(TCalendario &calen){

}

bool TABBCalendario::Buscar(TCalendario &calen){
    
    if(this->EsVacio() == true){
        return false;
    }
    else{
        if(this->raiz->item == calen){
            return true;
        }
        else{
            if(calen > this->raiz->item){
                return this->raiz->de.Buscar(calen);
            }
            else{
                return this->raiz->iz.Buscar(calen);
            }
        }
    }
}

TCalendario TABBCalendario::Raiz(){
    if(this != NULL){
        return this->raiz->item;
    }
    else{
        TCalendario vacio = TCalendario();
        return vacio;
    }
}

int TABBCalendario::Altura(){
    if(this->EsVacio() == true){
        return 0;
    }
    else{
        return (1 + max(this->raiz->iz.Altura(), this->raiz->de.Altura()));
    }
}

int TABBCalendario::Nodos(){
    int nodos = 1 + this->raiz->iz.Nodos() + this->raiz->de.Nodos();
    return nodos;
}

int TABBCalendario::NodosHoja(){
    int totalhoja = 0;
    if(this->EsVacio() == true){
        return totalhoja;
    }
    else{
        if(this->raiz->iz.EsVacio() && this->raiz->de.EsVacio()){
            totalhoja += 1;
        }
        else{
            totalhoja += this->raiz->iz.NodosHoja();
            totalhoja += this->raiz->de.NodosHoja();
        }
    }
}

TVectorCalendario TABBCalendario::Inorden(){
    TVectorCalendario tvector(this->Nodos());
    this->InordenAux(tvector, 1); //porque el tvector cominenza en 1
    return tvector;
}

void TABBCalendario::InordenAux(TVectorCalendario &tvector, int &n){
    this->raiz->iz.Inorden();
    tvector[n] = this->raiz;
    n++;
    this->raiz->de.Inorden();
}

TVectorCalendario TABBCalendario::Preorden(){
    TVectorCalendario tvector(this->Nodos());
    this->PreordenAux(tvector, 1);
    return tvector;
}

void TABBCalendario::PreordenAux(TVectorCalendario &tvector, int &n){
    tvector[n] = this->raiz;
    n++;
    this->raiz->iz.Preorden();
    this->raiz->de.Preorden();
}

TVectorCalendario TABBCalendario::PostOrden(){
    TVectorCalendario tvector(this->Nodos);
    this->PostordenAux(tvector, 1);
    return tvector;
}

void TABBCalendario::PostordenAux(TVectorCalendario &tvector, int &n){
    this->raiz->iz.PostOrden();
    this->raiz->de.PostOrden();
    tvector[n] = this->raiz;
    n++;
}

TVectorCalendario TABBCalendario::Niveles(){
    //var cola = cola de arbol binario
    TABBCalendario aux = this;

    while(!cola.isEmpty()){

    }
}

ostream &operator<<(ostream& salida, TABBCalendario& tabbcalen){
    
}

TABBCalendario TABBCalendario::operator+ (TABBCalendario &tabb){
    TABBCalendario copia(this);
    
}

TABBCalendario TABBCalendario::operator-(TABBCalendario &tabb){
    TVectorCalendario tvector;
    TABBCalendario copia;
    tvector = this->Inorden();
    
    for(int i = 1; i < tvector.Tamano(); i++){

    }
}
#include "tabbcalendario.h"

//el constructor llama mediante layering a los constructores de cada atributo
TNodoABB::TNodoABB() : item(), iz(), de() {}

TNodoABB::TNodoABB(TNodoABB &tnodo) : item(tnodo.item), iz(tnodo.iz), de(tnodo.de) {}

TNodoABB::~TNodoABB()
{
    this->item.~TCalendario();
    this->iz.~TABBCalendario();
    this->de.~TABBCalendario();
}

TNodoABB &TNodoABB::operator=(TNodoABB &tnodo){
    if (this != &tnodo){
        this->item = tnodo.item;
        this->iz = tnodo.iz;
        this->de = tnodo.de;
    }
    return *this;
}

TABBCalendario::TABBCalendario(){
    this->raiz = NULL;
}

TABBCalendario::TABBCalendario(TABBCalendario &tabb){
    if (tabb.raiz == NULL){
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

TABBCalendario &TABBCalendario::operator=(TABBCalendario &tabb){
    if (this != NULL){
        this->~TABBCalendario();
        
    }
    else{
        
    }
}

bool TABBCalendario::operator==(TABBCalendario &tabb) const{
    TVectorCalendario arbol1, arbol2;
    arbol1 = this->Inorden();
    arbol2 = tabb.Inorden();
    if(arbol1 == arbol2){
        return true;
    }
    else{
        return false;
    }
}

bool TABBCalendario::EsVacio(){
    if (this->raiz == NULL){
        return true;
    }
    else{
        return false;
    }
}

bool TABBCalendario::Insertar(TCalendario &calen){
    if (this->Buscar(calen) == true){
        return false;
    }
    else if(this->raiz == NULL){    
        this->raiz = new TNodoABB;
        this->raiz->item = calen;
        return true;
    }
    else if(calen < this->raiz->item){
        return this->raiz->iz.Insertar(calen);
    }
    else if(calen > this->raiz->item){
        return this->raiz->de.Insertar(calen);
    }
    else{}
        return false;
    }
}

bool TABBCalendario::Borrar(TCalendario &calen){
    if(this->Buscar(calen) == false || this->EsVacio() == true){
        return false;
    }
    else{
        if(calen == this->raiz->item){
            if(this->raiz->iz.EsVacio() || this->raiz->de.EsVacio()){  // 0 ó 1 hijo
                if(this->raiz->de.EsVacio()){    //no tiene hijo derecho, por lo cual analizamos el de la izquierda
                    TNodoABB *nextnodo(this->raiz->iz.raiz);
                    this->raiz = nextnodo; //hacemos que el nodo actual sea el nodo siguiente, eliminando el objetivo
                }
                else{
                    //no tiene hijo izquierdo ,por lo cual analizamos el de la derecha
                    if(this->raiz->iz.EsVacio()){
                        TNodoABB *nextnodo(this->raiz->de.raiz);
                        this->raiz = nextnodo;
                    }
                    else{
                        this->raiz = NULL; //la raiz no tiene ningun hijo
                    }
                }
            }
            else{   // 2 hijos
                //tenemos que sacar el maximo del arbol izquierdo
                /////////CUIDAOOOOOOOOOOOOOOOOOOOOOO CHUCLADDAAAAAAAAAAAAAAAAAA
                TNodoABB *nodo; 
                //en la variable nodo tenemos que guardar el mayor de la izquierda
                nodo->iz = this->raiz->iz;
                nodo->de = this->raiz->de;
                this->raiz = nodo;
            }
        }
        else if(calen > this->raiz->item){
            return this->raiz->de.Borrar(calen);
        }
        else if(calen < this->raiz->item){
            return this->raiz->iz.Borrar(calen);
        }
    }
}

bool TABBCalendario::Buscar(TCalendario &calen){
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

TCalendario TABBCalendario::Raiz(){
    if (this != NULL){
        return this->raiz->item;
    }
    else{
        TCalendario vacio = TCalendario();
        return vacio;
    }
}

int TABBCalendario::Altura(){
    if (this->EsVacio() == true){
        return 0;
    }
    else{
        return (1 + max(this->raiz->iz.Altura(), this->raiz->de.Altura()));
    }
}

int TABBCalendario::Nodos()const{
    int nodos = 1 + this->raiz->iz.Nodos() + this->raiz->de.Nodos();
    return nodos;
}

int TABBCalendario::NodosHoja(){
    int totalhoja = 0;
    if (this->EsVacio() == true){
        return totalhoja;
    }
    else{
        if (this->raiz->iz.EsVacio() && this->raiz->de.EsVacio()){
            totalhoja += 1;
        }
        else{
            totalhoja += this->raiz->iz.NodosHoja();
            totalhoja += this->raiz->de.NodosHoja();
        }
    }
}

TVectorCalendario TABBCalendario::Inorden() const{
    TVectorCalendario tvector(this->Nodos());
    int n = 1;
    this->InordenAux(tvector, n); //porque el tvector cominenza en 1
    return tvector;
}

void TABBCalendario::InordenAux(TVectorCalendario &tvector, int &n) const{
    this->raiz->iz.InordenAux(tvector, n);
    tvector[n] = this->raiz->item;
    n++;
    this->raiz->de.InordenAux(tvector, n);
}

TVectorCalendario TABBCalendario::Preorden()const {
    TVectorCalendario tvector(this->Nodos());
    int n = 1;
    this->PreordenAux(tvector, n);
    return tvector;
}

void TABBCalendario::PreordenAux(TVectorCalendario &tvector, int &n)const{
    tvector[n] = this->raiz->item;
    n++;
    this->raiz->iz.PreordenAux(tvector, n);
    this->raiz->de.PreordenAux(tvector, n);
}

TVectorCalendario TABBCalendario::Postorden()const{
    TVectorCalendario tvector(this->Nodos());
    int n = 1;
    this->PostordenAux(tvector, n);
    return tvector;
}

void TABBCalendario::PostordenAux(TVectorCalendario &tvector, int &n)const{
    this->raiz->iz.PostordenAux(tvector, n);
    this->raiz->de.PostordenAux(tvector, n);
    tvector[n] = this->raiz->item;
    n++;
}

TVectorCalendario TABBCalendario::Niveles()const{
    
}

ostream &operator<<(ostream &salida, TABBCalendario &tabbcalen){
    TVectorCalendario tvector = tabbcalen.Niveles();
    salida<<tvector;
}

//creamos la copia del arbol actual, y realizamos la inserción del arbol de la derecha
//en copia, segun su recorrido en inorden
TABBCalendario TABBCalendario::operator+(TABBCalendario &tabb){
    TABBCalendario copia(*this);
    TVectorCalendario tvector;
    tvector = tabb.Inorden();
    for (int i = 1; i <= tvector.Tamano(); i++){
        copia.Insertar(tvector[i]);
    }
    return copia;
}

//se recorre el operando árbol de la izquierda por INORDEN, y si el elemento
//NO está en el operando árbol de la derecha, se inserta en el árbol resultante
//(inicialmente vacío) y el proceso se repite para todos los elementos del
//operando de la izquierda.
TABBCalendario TABBCalendario::operator-(TABBCalendario &tabb){
    TVectorCalendario tvector;
    TABBCalendario copia(*this);
    tvector = this->Inorden();
    for (int i = 1; i <= tvector.Tamano(); i++){
        if (tabb.Buscar(tvector[i]) == false){
            copia.Insertar(tvector[i]);
        }
    }
    return copia;
}
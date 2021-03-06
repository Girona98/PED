#include "tabbcalendario.h"

//el constructor llama mediante layering a los constructores de cada atributo
TNodoABB::TNodoABB() : item(), iz(), de() {}

TNodoABB::TNodoABB(const TNodoABB &tnodo) : item(tnodo.item), iz(tnodo.iz), de(tnodo.de) {}

TNodoABB::~TNodoABB(){}

TNodoABB &TNodoABB::operator=(TNodoABB &tnodo){
    if (this != &tnodo){
        this->~TNodoABB();
        this->item = tnodo.item;
        this->iz = tnodo.iz;
        this->de = tnodo.de;
    }
    return *this;
}

TABBCalendario::TABBCalendario(){
    this->raiz = NULL;
}

TABBCalendario::TABBCalendario(const TABBCalendario &tabb){
    this->raiz = NULL;
    this->Copiar(tabb);
}

TABBCalendario::~TABBCalendario(){
    delete this->raiz;
    this->raiz = NULL;
}
void TABBCalendario::Copiar(const TABBCalendario &tabb){
    if(tabb.raiz == NULL){
        this->raiz = NULL;
    }
    else{
        TNodoABB *tnodo = new TNodoABB();
        tnodo->item = tabb.raiz->item;
        this->raiz = tnodo;
        this->raiz->iz.Copiar(tabb.raiz->iz);
        this->raiz->de.Copiar(tabb.raiz->de);
    }
}

TABBCalendario &TABBCalendario::operator=(const TABBCalendario &tabb){
    if (this != &tabb){
        this->~TABBCalendario();
        this->Copiar(tabb);
        return *this;
    }
    else{
        return *this;
    }
}

bool TABBCalendario::operator==(TABBCalendario &tabb) const{
    TVectorCalendario arbol1, arbol2;
    arbol1 = this->Inorden();
    arbol2 = tabb.Inorden();
    return arbol1 == arbol2;
}

bool TABBCalendario::EsVacio() const{
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
    else{
        return false;
    }
}

bool TABBCalendario::Borrar(TCalendario &calen){
    if(this->Buscar(calen) == false || this->EsVacio() == true){
        return false;
    }
    else{
        if(calen == this->raiz->item){
            if(this->raiz->iz.EsVacio() == true || this->raiz->de.EsVacio() == true){  // 0 ?? 1 hijo
            //no tiene hijo derecho, por lo cual analizamos el de la izquierda
                if(this->raiz->de.EsVacio() == true){
                    TNodoABB *nextnodo(this->raiz->iz.raiz);
                    this->raiz = nextnodo; //hacemos que el nodo actual sea el nodo siguiente, eliminando el objetivo
                    return true;
                }
                else{
                    //no tiene hijo izquierdo ,por lo cual analizamos el de la derecha
                    if(this->raiz->iz.EsVacio() == true){
                        TNodoABB *nextnodo(this->raiz->de.raiz);
                        this->raiz = nextnodo;
                        return true;
                    }
                    else{
                        this->raiz = NULL; //la raiz no tiene ningun hijo
                        return true;
                    }
                }
            }
            else{   // 2 hijos
                TNodoABB *nodoabb = new TNodoABB(this->raiz->iz.BuscarIzq());
                //guardamos el objeto this en nodoabb
                nodoabb->iz = this->raiz->iz;
                nodoabb->de = this->raiz->de;
                this->raiz = nodoabb;
                nodoabb = NULL;
                return true;
            }
        }
        else if(calen > this->raiz->item){
            return this->raiz->de.Borrar(calen);
        }
        else if(calen < this->raiz->item){
            return this->raiz->iz.Borrar(calen);
        }
        else{
            return false;
        }
    }
}

TNodoABB TABBCalendario::BuscarIzq(){
    if(this->EsVacio() == true){
        TNodoABB *tnodo = new TNodoABB();
        return *tnodo;
    }
    else if(this->raiz->de.EsVacio() == true){
        TNodoABB *tnodo = new TNodoABB();
        tnodo = this->raiz;
        TCalendario delCalen = tnodo->item;
        this->Borrar(delCalen);
        return *tnodo;
    }
    else{
        TNodoABB *tnodo = new TNodoABB(this->raiz->de.BuscarIzq());
        return *tnodo;
    }
}

bool TABBCalendario::Buscar(const TCalendario &calen)const{
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
        TCalendario *vacio = new TCalendario();
        return *vacio;
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
    if (this->EsVacio() == false){
        return 1 + this->raiz->iz.Nodos() + this->raiz->de.Nodos();
    }
    else{
        return 0;
    }
}

int TABBCalendario::NodosHoja(){
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

TVectorCalendario TABBCalendario::Inorden() const{
    TVectorCalendario tvector(this->Nodos());
    int n = 1;
    this->InordenAux(tvector, n); //porque el tvector cominenza en 1
    return tvector;
}

void TABBCalendario::InordenAux(TVectorCalendario &tvector, int &n) const{
    if(this->raiz != NULL){
        this->raiz->iz.InordenAux(tvector, n);
        tvector[n] = this->raiz->item;
        n++;
        this->raiz->de.InordenAux(tvector, n);
    }
}

TVectorCalendario TABBCalendario::Preorden()const {
    TVectorCalendario tvector(this->Nodos());
    int n = 1;
    this->PreordenAux(tvector, n);
    return tvector;
}

void TABBCalendario::PreordenAux(TVectorCalendario &tvector, int &n)const{
    if(this->raiz != NULL){
        tvector[n] = this->raiz->item;
        n++;
        this->raiz->iz.PreordenAux(tvector, n);
        this->raiz->de.PreordenAux(tvector, n);
    }
}

TVectorCalendario TABBCalendario::Postorden()const{
    TVectorCalendario tvector(this->Nodos());
    int n = 1;
    this->PostordenAux(tvector, n);
    return tvector;
}

void TABBCalendario::PostordenAux(TVectorCalendario &tvector, int &n)const{
    if(this->raiz != NULL){
        this->raiz->iz.PostordenAux(tvector, n);
        this->raiz->de.PostordenAux(tvector, n);
        tvector[n] = this->raiz->item;
        n++;
    }
}

TVectorCalendario TABBCalendario::Niveles()const{
    queue<TNodoABB*> cola;
    TNodoABB *nodo;
    TVectorCalendario tvector(this->Nodos());
    int i = 1;
    cola.push(this->raiz);

    while(cola.empty() == false && this->EsVacio() == false)    {
        nodo = cola.front();
        tvector[i] = nodo->item;
        cola.pop();
        if(this->raiz->de.EsVacio() == false){
            cola.push(nodo->iz.raiz);
        }
        if(this->raiz->iz.EsVacio() == false){
            cola.push(nodo->de.raiz);
        }
        i++;
    }
    return tvector;
}

ostream &operator<<(ostream &salida, TABBCalendario &tabbcalen){
    TVectorCalendario tvector = tabbcalen.Niveles();
    salida<<tvector;
    return salida;
}

//creamos la copia del arbol actual, y realizamos la inserci??n del arbol de la derecha
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

//se recorre el operando ??rbol de la izquierda por INORDEN, y si el elemento
//NO est?? en el operando ??rbol de la derecha, se inserta en el ??rbol resultante
//(inicialmente vac??o) y el proceso se repite para todos los elementos del
//operando de la izquierda.
TABBCalendario TABBCalendario::operator-(TABBCalendario &tabb){
    TVectorCalendario tvector;
    TABBCalendario copia;
    tvector = this->Inorden();
    for (int i = 1; i <= tvector.Tamano(); i++){
        if (tabb.Buscar(tvector[i]) == false){
            copia.Insertar(tvector[i]);
        }
    }
    return copia;
}

#include "../include/tlistacalendario.h"

/*Metodos TNODOCALENDARIO
    ATRIBUTOS
    TCalendario c;  uso de leewayering sobre la clase 
    TNodoCalendario *siguiente
*/

//con :c() llama al constructor de tcalendario
TNodoCalendario::TNodoCalendario():c(){ 
    this->siguiente = NULL;
}

//en este caso llamamos al constructor de copia de tcalendario con :c(tnodo.c)
TNodoCalendario::TNodoCalendario(const TNodoCalendario &tnodo):c(tnodo.c){
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

TListaPos::TListaPos(const TListaPos& tlista){
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

TListaPos& TListaPos::operator=(const TListaPos &tlista){
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
bool TListaPos::operator==(const TListaPos& tlista){
    bool iguales = false;
    if(this->pos == tlista.pos){
        iguales = true;
    }
    return iguales;
}

bool TListaPos::operator!=(const TListaPos& tlista){
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
        vacia= true;
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

TListaCalendario::TListaCalendario(const TListaCalendario& tlista){
    this->primero = tlista.primero;
}


TListaCalendario::~TListaCalendario(){
    this->primero = NULL;
}

TListaCalendario& TListaCalendario::operator=(const TListaCalendario &tlista){
    if(this != &tlista){
        this->~TListaCalendario();
        if(tlista.primero == NULL){
            this->primero = NULL;
        }
        else{
            this->primero = tlista.primero; //F carencias, sustituir por insertar porque sino se borra al borrar otro CAMBIAAAAAAA
        }
    }
    return *this;
}

bool TListaCalendario::operator==(const TListaCalendario& tlista){
    bool igual = true;
    if(this->Longitud() == tlista.Longitud()){
        TNodoCalendario *nodo1;
        TNodoCalendario *nodo2;
        nodo1 = this->primero;
        nodo2 = tlista.primero;
        for(int i = 0; i < tlista.Longitud() && igual == true; i++){
            if(nodo1 != nodo2){
                igual = false;
            }
            nodo1 = nodo1->siguiente;
            nodo2 = nodo2->siguiente;
        }
    }
    return igual;
}

TListaCalendario TListaCalendario::operator+(const TListaCalendario& tlista){
    TListaCalendario sumalista = *this; //referencialo tontito
    TNodoCalendario *aux = this->primero;
    TNodoCalendario *nodo = tlista.primero;

    for(int i = 0; i < tlista.Longitud(); i++){
        if( this->Buscar(nodo->c) == false ){
            sumalista.Insertar(nodo->c);
            nodo=nodo->siguiente;
            aux = aux->siguiente;
        }
        else{
            nodo = nodo->siguiente;
            aux = aux->siguiente;
        }
    }
    return sumalista;
}


TListaCalendario TListaCalendario::operator-(const  TListaCalendario& tlista){
    TListaCalendario restalista = *this;
    TNodoCalendario *auxiliar = tlista.primero;

    for(int i = 0; i < tlista.Longitud(); i++){
        restalista.Borrar(auxiliar->c); //borramos el elemento de la lista
        auxiliar = auxiliar->siguiente; //iteramos al siguiente nodo
    }    

    return restalista;
}


bool TListaCalendario::Insertar(const TCalendario &tcalen){
    bool insertado = false;
    TNodoCalendario *nodocalendario = new TNodoCalendario();
    TNodoCalendario *tnodo = this->primero; 

    //si existe en la lista no hacemos nada
    if(this->Buscar(tcalen)){
        return false;
    }
    else{
        if(this->primero == NULL){ //si no hay elementos en la lista
            nodocalendario->c = tcalen;
            this->primero = nodocalendario;
            insertado = true;
        }
        else{
            if(tcalen < this->primero->c){  //si el calendario es menor que el primero de la lista
                nodocalendario->c = tcalen;
                nodocalendario->siguiente = this->primero;
                this->primero = nodocalendario;
                insertado = true;
            }
            else{
                if(this->primero->siguiente == NULL){ //cuando solo queda un elemento en la lista
                    if(tcalen > tnodo->c){
                        nodocalendario->c = tcalen;
                        this->primero->siguiente = nodocalendario;
                        insertado = true;
                    }
                    else{
                        nodocalendario->c = tcalen;
                        nodocalendario->siguiente = this->primero;
                        this->primero = nodocalendario;
                        insertado = true;
                    }
                }
            }
        }
    }

    while(insertado == false && tnodo != NULL){
        if(tcalen > tnodo->c){
            if(tnodo->siguiente == NULL || tnodo->siguiente->c > tcalen){
                nodocalendario->c = tcalen;
                nodocalendario->siguiente = tnodo->siguiente;
                tnodo->siguiente = nodocalendario;
                insertado = true;
            }
        }
         else if(tnodo->c.Dia() == tcalen.Dia() && tnodo->c.Mes() == tcalen.Mes() && tnodo->c.Anyo() == tcalen.Anyo()){
                nodocalendario->c = tcalen;
                nodocalendario->siguiente = tnodo->siguiente;
                tnodo->siguiente = nodocalendario;
                insertado = true;
            }
        tnodo = tnodo->siguiente;
    }
    return insertado;
}


bool TListaCalendario::Borrar(const TCalendario &tcalen){
    bool borrar = false;
    TNodoCalendario *nodo = this->primero;
    //si lo encontramos en primer lugar
    if(this->Longitud() == 1){
        return new TListaCalendario();
    }
    else if(nodo->siguiente != NULL){
        for(int i = 0; i < this->Longitud() && borrar == false; i++){
            if(nodo->c == tcalen){
                nodo = nodo->siguiente;
                borrar = true;
            }
            else if(nodo->siguiente->c == tcalen){
                nodo->siguiente = nodo->siguiente->siguiente;
                borrar = true;
            }
            else{
                nodo = nodo->siguiente;
            }
        }
    }
    return borrar;
}

//obtenemos el calendario de la posicion dada y llamamos al borrar que recibe un tcalendario
bool TListaCalendario::Borrar(const TListaPos &tlista){
    TCalendario calen = tlista.pos->c;
    return this->Borrar(calen);
}

bool TListaCalendario::Borrar(int dia, int mes, int anyo){  
    /*TNodoCalendario *nodoeliminar;              //aeliminar
    TNodoCalendario *auxiliar = this->primero; //aux
    TCalendario calen = TCalendario(dia, mes, anyo, NULL);
    bool borrable = false;

    while(auxiliar->siguiente != NULL){
        if(auxiliar->c == calen){
            nodoeliminar = this->primero;
            this->primero = this->primero->siguiente;
            auxiliar = auxiliar->siguiente;
            this->Borrar(nodoeliminar->c);
            borrable = true;
        }
        else{
            if(auxiliar->siguiente != NULL && auxiliar->siguiente->c == calen){
                nodoeliminar = auxiliar->siguiente;
                auxiliar->siguiente = auxiliar->siguiente->siguiente; 
                this->Borrar(nodoeliminar->c);
                borrable = true;
            }
            else{
                auxiliar = auxiliar->siguiente;
            }
        }
    }
    return borrable;*/


}

bool TListaCalendario::EsVacia()const{
    bool vacio = false;
    if(this->primero == NULL){
        vacio = true;
    }
    return vacio;
}

TCalendario TListaCalendario::Obtener(const TListaPos &tlista) const{
    TListaPos auxiliar(tlista);

    if(auxiliar.EsVacia()){
        TCalendario vacio;
        return vacio; 
    }
    else{
        return auxiliar.pos->c;
    }
}

bool TListaCalendario::Buscar(const TCalendario &tcalen){
    bool encontrado = false;
    TNodoCalendario *nodo = this->primero;
    
    for(int i = 0; i < this->Longitud() && encontrado == false; i++){
        if(nodo->c == tcalen){
            encontrado = true;
        }
        nodo = nodo->siguiente;
    }
    return encontrado;
}



int TListaCalendario::Longitud()const {
    int contador = 0;
    TNodoCalendario *nodo;
    nodo = this->primero;
    while(nodo != NULL){
        contador++;
        nodo = nodo->siguiente;
    }
    return contador;
}

TListaPos TListaCalendario::Primera() const{
    TListaPos listapos = TListaPos();
    if(this->primero == NULL){        
        return listapos;
    }
    else{
        listapos.pos = this->primero;
        return listapos;
    }
}

TListaPos TListaCalendario::Ultima() const{
    if(this->primero == NULL){
        TListaPos vacio;
        return vacio;
    }
    else{
        TListaPos tlista;
        tlista.pos = this->primero;
        for(int i = 0; i < this->Longitud(); i++){
            tlista = tlista.Siguiente();
        }
        return tlista;
    }
}

TListaCalendario TListaCalendario::SumarSubl(int I_L1, int F_L1, TListaCalendario &L2, int I_L2, int F_L2){
    return *this;
}

TListaCalendario TListaCalendario::ExtraerRango(int n1, int n2){
    TListaCalendario *originalista = new TListaCalendario(*this);
    TListaCalendario *newlista = new TListaCalendario();
    //se numeran las posiciones a partir de 1
    if(n2 > this->Longitud()){
        //se selecciona el contenido desde n1 hasta longitud
        n2 = this->Longitud();
        for(int i = 1; i <= n2; i++){
            if( i >= n1){
                newlista->Insertar(originalista->primero->c);
                this->Borrar(originalista->primero->c); //lo eliminamos de la lista antigua
            }
            originalista->primero = originalista->primero->siguiente;
        }
        return *newlista;
    }
    else if(n1 <= 0){
        //entre 1 y n2
        n1 = 1;
        for(int i = n1; i <= n2; i++){
            newlista->Insertar(originalista->primero->c);
            this->Borrar(originalista->primero->c); //lo eliminamos de la lista antigua
            originalista->primero = originalista->primero->siguiente;
        }
        return *newlista;
    }
    else if(n1 == n2){
        //return lista de 1 elemento
         for(int i = 1; i <= n2; i++){
            if( i == n1 ){ //lo comparamos con uno porque nos da igual cual sea ya que valen lo mismo
                newlista->Insertar(originalista->primero->c);
                this->Borrar(originalista->primero->c); //lo eliminamos de la lista antigua
            }
            originalista->primero = originalista->primero->siguiente;
        }
        return *newlista;
    }
    else if(n1 > n2){
        //return lista vacia 
        return *newlista;
    }
    else{ //no se si esta bien
        return *newlista;
    }
}

ostream& operator<<(ostream& salida, const TListaCalendario &tlista){
    if(tlista.EsVacia()){
        salida<<"<>";
    }
    else{
        int tam = tlista.Longitud();
        TListaPos posinodo = tlista.Primera();
        
        salida<<"<";
        for(int i = 0; i < tam; i++){
            salida<<tlista.Obtener(posinodo);
            if(i>= 0 && i < tam - 1){
                salida<<" ";
            }
            posinodo = posinodo.Siguiente();
        }
        salida<<">";
    }
    return salida;
}
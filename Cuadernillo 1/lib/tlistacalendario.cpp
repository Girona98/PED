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
TNodoCalendario::TNodoCalendario(TNodoCalendario &tnodo):c(tnodo.c){
    this->siguiente = NULL;
}

TNodoCalendario::TNodoCalendario(const TCalendario &calen){
    this->c = calen;
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
    /*this->primero = tlista.primero;
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
    }*/
    //mas resumido xd
    this->primero = tlista.primero;
}


TListaCalendario::~TListaCalendario(){
    // this->primero->~TNodoCalendario();  //veo carencias
    this->primero = NULL;
}

TListaCalendario& TListaCalendario::operator=(TListaCalendario &tlista){
    if(this != &tlista){
        this->~TListaCalendario();
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
    TListaCalendario sumalista;
    TListaPos *auxIzq;
    auxIzq->pos = this->primero;

    for(int i = 0; i < this->Longitud(); i++){
        sumalista.Insertar(auxIzq->pos->c);   //insertamos el calendario en la lista
        auxIzq->pos = auxIzq->pos->siguiente;
    }

    TListaPos auxDer;
    auxDer.pos = tlista.primero;

    for(int j = 0; j < tlista.Longitud(); j++){
        sumalista.Insertar(auxDer.pos->c);
        auxDer.pos = auxDer.pos->siguiente;
    }
    return sumalista;


    /*TListaCalendario restalista = *this;
    TNodoCalendario *auxiliar = tlista.primero;

    while(auxiliar != NULL){
        restalista.Insertar(auxiliar->c); //borramos el elemento de la lista
        auxiliar = auxiliar->siguiente; //iteramos al siguiente nodo
    }    

    return sumalista;*/
}

TListaCalendario TListaCalendario::operator-(const  TListaCalendario& tlista){
    TListaCalendario restalista = *this;
    TNodoCalendario *auxiliar = tlista.primero;

    while(auxiliar != NULL){
        restalista.Borrar(auxiliar->c); //borramos el elemento de la lista
        auxiliar = auxiliar->siguiente; //iteramos al siguiente nodo
    }    

    return restalista;
}

bool TListaCalendario::Insertar(TCalendario &tcalen){
    bool insertado;
    if(this->EsVacia()){
        TNodoCalendario *tnodo;
        tnodo->c = tcalen;
        tnodo->siguiente = NULL;
        this->primero = tnodo;
        insertado = true;
    }
    else{
        if(tcalen.EsVacio()){   //como es vacio no hacemos nada
            insertado = true;
        }
        else if(this->Buscar(tcalen)){  //esto es que ya esta en la lista
            insertado = false;
        }
        else{
           TNodoCalendario *next;
           TNodoCalendario *actual;
           TNodoCalendario *aux;
           actual = this->primero;

           while(insertado == false){
                if(actual->c < tcalen || actual->c == tcalen){
                    next = actual;
                    actual = actual->siguiente;
                    insertado = true;
                }    
           }

            aux = new TNodoCalendario(tcalen);
            if(next != NULL){
                next->siguiente = aux;
            }
            else{
                this->primero = aux;
            }
        }
    }
    return insertado;
}

bool TListaCalendario::Borrar(TCalendario &tcalen){
    bool borrar = false;
    //si la lista no es vacio y tenemos ese calendario en la lista
    if(this->Primera().EsVacia() == false && Buscar(tcalen) == true){
        TNodoCalendario *auxiliar;
        for(int i = 0; i < this->Longitud() && borrar == false; i++){
            if(tcalen == this->primero->c){
                //si es igual nos saltamos el nodo que queremos borrar
                auxiliar = this->primero;
                this->primero = this->primero->siguiente;
                borrar = true;
            }
            else{
                //si no, pasamos al siguiente y continuamos
                auxiliar = this->primero->siguiente;
                this->primero = auxiliar;
                borrar = false;
            }
        }
    }
    return borrar;
}

//obtenemos el calendario de la posicion dada y llamamos al borrar que recibe un tcalendario
bool TListaCalendario::Borrar(TListaPos &tlista){
    TCalendario calen = tlista.pos->c;
    return this->Borrar(calen);
}

//FALTA POCO PARA TERMINAR ESTE BORRAR
bool TListaCalendario::Borrar(int dia, int mes, int anyo){  
    TNodoCalendario *nodoeliminar;              //aeliminar
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
    return borrable;
}

bool TListaCalendario::EsVacia()const{
    bool vacio = false;
    if(this->primero == NULL){
        vacio = true;
    }
    return vacio;
}

TCalendario TListaCalendario::Obtener(TListaPos &tlista) const{
    TListaPos auxiliar(tlista);
    if(tlista.EsVacia()){
        TCalendario vacio;
        return vacio; 
    }
    else{
        return auxiliar.pos->c;
    }
}

bool TListaCalendario::Buscar(TCalendario &tcalen) const{
    bool encontrado = false;
    TListaPos listapos;
    listapos.pos = this->primero;
    TNodoCalendario *nodo;
    nodo = this->primero;
    for(int i = 0; i < this->Longitud() && encontrado == false; i++){
        if(this->primero->c == tcalen){
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
    while(nodo->siguiente != NULL){
        contador++;
        nodo = nodo->siguiente;
    }
    return contador;
}

TListaPos TListaCalendario::Primera() const{
    if(this->primero == NULL){
        TListaPos vacio;
        return vacio;
    }
    else{
        TListaPos primer;
        primer.pos = this->primero;
        return primer;
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
            tlista.pos = tlista.pos->siguiente;
        }
        return tlista;
    }
}

TListaCalendario TListaCalendario::SumarSubl(int I_L1, int F_L1, TListaCalendario &L2, int I_L2, int F_L2){

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
                salida<<", ";
            }
            posinodo = posinodo.Siguiente();
        }
        salida<<">";
    }
    return salida;
}
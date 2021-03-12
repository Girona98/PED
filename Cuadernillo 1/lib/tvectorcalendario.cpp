#include "../include/tvectorcalendario.h"

/*
o El vector NO tiene por qué estar ordenado.
o El vector puede contener elementos repetidos. Incluso de los TCalendario considerados "vacíos"
(es decir, con el valor directamente generado por el Constructor por defecto de TCalendario).
o El Constructor por defecto crea un vector de dimensión 0 (puntero interno a NULL, no se reserva
memoria).
o En el Constructor a partir de un tamaño, si el tamaño es menor que 0, se creará un vector de
dimensión 0 (como el constructor por defecto).
o El Destructor tiene que liberar toda la memoria que ocupe el vector
*/

TVectorCalendario::TVectorCalendario(){
    this->c = NULL;
    this->tamano = 0;
}

TVectorCalendario::TVectorCalendario(int tam){
    if(tam < 0){
        TVectorCalendario();
    }
    else{
        this->tamano = tam;
        //this->c =             //no tengo ni idea reguntar como se hace
    }
}

TVectorCalendario::TVectorCalendario(const TVectorCalendario& tvector){
    this->tamano = tvector.tamano;
    this-> c = new TCalendario[tvector.tamano];
    //carencias
}

TVectorCalendario::~TVectorCalendario(){
    this->tamano = 0;
    delete[] c;                 //carencias aqui, no entiendo muy bien lo de asingar vector a un vector no vacio
    this->c = NULL;
}

TVectorCalendario& TVectorCalendario::operator=(TVectorCalendario& tvector){
    if(this != tvector){            //me falla la desiugaldad
        (*this).~TVectorCalendario();
        this->tamano = tvector.tamano;
        this->c = new TCalendario[tvector.tamano];
        for(int i = 0; i < tvector.tamano; i++){
            this->c[i] = tvector.c[i+1];        //porque empieza en 1 no desde 0
        }
        return *this;
    }
    else{
        return *this;
    }
}

bool TVectorCalendario::operator==(TVectorCalendario& tvector){
    bool equal = false;
    if(this->tamano == tvector.tamano){
        for(int i = 0; i < tvector.tamano; i++){
            if(tvector.c[i] != this->c[i]){
                break;
            }
        }
        equal = true;
    }
    return equal;
}

bool TVectorCalendario::operator!=(TVectorCalendario& tvector){
    return !(*this==tvector);
}

TCalendario& TVectorCalendario::operator[](int num){    //parte izquierda
    if(num >= 1 && num <= this->tamano){
        return this->c[num];
    }
    else{
        return this->error;
    }
}

TCalendario TVectorCalendario::operator[](int num)const{    //parte derecha
    if(num >= 1 && num <= this->tamano){
        return this->c[num];
    }
    else{
        return this->error;
    }
}

int TVectorCalendario::Tamano(){
    return tamano;
}

int TVectorCalendario::Ocupadas(){
    int cont = 0;
    for(int i = 0; i < this->tamano; i++){
        if(this->c[i] != error){
            cont++;
        }
    }
    return cont;
}

bool TVectorCalendario::ExisteCal(TCalendario& calen){
    //nos pasan un calendario y tenemos que comprobar si existe en la lista
    bool existe = false;
    for(int i = 0; i < this->tamano || existe = false; i++){
        if(this->c[i] == calen){
            existe = true;
        }
    }
    return existe;
}

void TVectorCalendario::MostrarMensajes(int dia, int fecha, int anyo){

}

bool TVectorCalendario::Redimensionar(int tam){
    bool red = false;
    if(tam <= 0){
        red = false;
    }
    else if(this->tamano == tam){
        red = false;
    }
    else if(tam > this->tamano){
        //hay que copiar los
        //componentes del vector en el vector nuevo, que pasará a tener el tamaño que indica el entero.
        //Las nuevas posiciones serán “vacías”, es decir, objetos TCalendario "vacío". 
        red = true;
    }
    else if(tam < this->tamano){
        //se deben eliminar los
        //TCalendario que sobren por la derecha, dejando el nuevo tamaño igual al valor del entero.
        red = true;
    }
    return red;
}

ostream& operator<<(ostream& salida, TVectorCalendario& tvector){
    salida<<"[ ";
    for (int i = 0; i < tvector.tamano; i++){
        salida<<"("<<i+1<<") ";
        salida<<tvector[i]; //esto llama al operator<< de tcalendario?
        salida<<", ";
    }
    salida<<"]";
}
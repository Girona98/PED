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
    this->tamano = 0;
    this->c = NULL;
}

TVectorCalendario::TVectorCalendario(int tam){
    if(tam <= 0){
        TVectorCalendario();
    }
    else{
        this->tamano = tam;
        c = new TCalendario[tam];
    }
}

TVectorCalendario::TVectorCalendario(const TVectorCalendario& tvector){
    if(tvector.tamano <= 0){
        this->tamano = 0;
        c = NULL;
    }
    else{
        this->tamano = tvector.tamano;
        this->c = new TCalendario[tamano];
        for(int i = 0; i < tvector.tamano; i++){
            this->c[i] = tvector.c[i + 1]; //i + 1 ya que se indica que empieza en 1
        }
    }
}

TVectorCalendario::~TVectorCalendario(){

}

TVectorCalendario& TVectorCalendario::operator=(TVectorCalendario& tvector){

}

bool TVectorCalendario::operator==(TVectorCalendario& tvector){

}

bool TVectorCalendario::operator!=(TVectorCalendario& tvector){
    return !(*this==tvector);
}

TCalendario& TVectorCalendario::operator[](int num){

}

TCalendario TVectorCalendario::operator[](int num)const{

}

int TVectorCalendario::Tamano(){
    return tamano;
}

int TVectorCalendario::Ocupadas(){

}

bool TVectorCalendario::ExisteCal(TCalendario& calen){

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
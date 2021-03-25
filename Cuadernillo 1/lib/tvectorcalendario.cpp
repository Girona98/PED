#include "../include/tvectorcalendario.h"

TVectorCalendario::TVectorCalendario(){
    this->tamano = 0;
    this->c = NULL;
}

TVectorCalendario::TVectorCalendario(int tam){
    if(tam <= 0){
        //TVectorCalendario();
        this->tamano = 0;
        this->c = NULL;
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
    this->tamano = 0;
    delete[] c;
    this->c = NULL;
}

TVectorCalendario& TVectorCalendario::operator=(const TVectorCalendario& tvector){
    if(this != &tvector){
        (*this).~TVectorCalendario();
        if(tvector.c == NULL){
            this->tamano = 0;
            this->c = NULL;
        }
        else{
            this->tamano = tvector.tamano;
            this->c = new TCalendario[tvector.tamano];
            for(int i = 0; i < tvector.tamano; i++){
                this->c[i] = tvector.c[i];
            }
        }
    }
    return *this;
}


bool TVectorCalendario::operator==(TVectorCalendario& tvector){
    bool equal = true;
    if(this->tamano == tvector.tamano){
        for(int i = 0; i < tvector.tamano && equal == true; i++){
            if(this->c[i] != tvector.c[i + 1]){
                equal = false;
            }
        }
    }   
    return equal;
}

bool TVectorCalendario::operator!=(TVectorCalendario& tvector){
    return !(*this==tvector);
}

TCalendario& TVectorCalendario::operator[](int num){
    if(num >= 1 && num <= this->tamano){
        return this->c[num - 1];
    }
    else{
        return error;
    }
}

TCalendario TVectorCalendario::operator[](int num)const{
    if(num >= 1 && num <= this->tamano){
        return this->c[num - 1];
    }
    else{
        return error;
    }
}

int TVectorCalendario::Tamano(){
    return tamano;
}

int TVectorCalendario::Ocupadas(){
    int ocupadas = 0;
    for (int i = 0; i < this->tamano; i++){
        if(this->c[i] != this->error){
            ocupadas++;
        }
    }
    return ocupadas;
}

bool TVectorCalendario::ExisteCal(TCalendario& calen){
    bool existe = false;
    for (int i = 0; i < this->tamano && existe == false; i++){
        if(this->c[i] == calen){
            existe = true;
        }
    }
    return existe;
}

//posible fallo de aqui es que no compruebo que una fecha es valida o no
void TVectorCalendario::MostrarMensajes(int dia, int mes, int anyo){
    TCalendario *fecha = new TCalendario(dia, mes, anyo, NULL);
    cout<<"[";  
    for(int i = 1; i < this->tamano; i++){
        if(this->c[i] > *fecha || this->c[i] == *fecha){
            cout<<this->c[i];
            if(i >= 1 && i < this->tamano - 1){
                cout<<", ";
            }
        }
    }
    cout<<"]";
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
        TCalendario *vector = new TCalendario[tam];
        for (int i = 0; i < this->tamano; i++){
            vector[i] = this->c[i];
        }
        this->tamano = tam;
        this->c = vector;
        red = true;
    }
    else if(tam < this->tamano){
        //se deben eliminar los
        //TCalendario que sobren por la derecha, dejando el nuevo tamaño igual al valor del entero.
        TCalendario *vector = new TCalendario[tam];
        for(int i = 0; i < tam; i++){
            vector[i] = this->c[i];
        }

        this->tamano = tam;
        this->c = vector;
        red = true;
    }
    return red;
}

ostream& operator<<(ostream& salida, TVectorCalendario& tvector){
    salida<<"[";
    if(tvector.tamano == 0){
        salida<<"]";
    }
    else{
        for (int i = 1; i <= tvector.tamano; i++){ //porque el vector empieza en 1
            salida<<"("<<i<<") ";
            salida<<tvector[i]; //esto llama al operator<< de tcalendario?
            if(i==tvector.tamano){
                salida<<"";
            }
            else{
                salida<<", ";
            }
            
        }
        salida<<"]";
    }

    return salida;
}
#include "../include/tcalendario.h"

TCalendario::TCalendario(){
    this->dia = 1;
    this->mes = 1;
    this->anyo = 1900;
    this->mensaje = NULL;
}

bool TCalendario::isBisiesto(int anyo){
    bool bisiesto = false;
    if(anyo % 4 == 0 && anyo % 100 != 0 || anyo % 400 == 0){
        bisiesto = true;
    }
    return bisiesto;
}

bool TCalendario::checkFecha(int dia, int mes, int anyo){
    bool correcto = false;
    if(anyo >= 1900){
        if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
            if(dia >= 1 && dia <= 31){
                correcto = true;
            }
        }
        else{
            if(mes == 2){       
                if( isBisiesto(anyo) == true){
                    if( dia >= 1 && dia <=29){
                        correcto = true;
                    }
                }
                else{
                    if(dia >= 1 && dia <= 28){
                        correcto = true;
                    }
                }
            }
            else{
                if(dia >= 1 && dia <= 30){
                    correcto = true;
                }
            }
        }
    }
    return correcto;
}




TCalendario::TCalendario(int dia, int mes, int anyo, char* cmensaje){
    if(checkFecha(dia, mes, anyo) == true){
        this->dia = dia;
        this->mes = mes;
        this->anyo = anyo;
        if( cmensaje != NULL){
            this->mensaje = new char[strlen(cmensaje) + 1];  //reservamos memoria
            strcpy(this->mensaje, cmensaje);                 //la asignamos
        }
        else{
            mensaje = NULL;
        }
    }
    else{
        this->dia = 1;
        this->mes = 1;
        this->anyo = 1900;
        this->mensaje = NULL;
    }
}

TCalendario::TCalendario(const TCalendario& calendario){
    if(checkFecha(calendario.dia, calendario.mes, calendario.anyo)){
        this->dia = calendario.dia;
        this->mes = calendario.mes;
        this->anyo = calendario.anyo;
        if( calendario.mensaje != NULL){
            this->mensaje = new char[strlen(calendario.mensaje) + 1];  
            strcpy(this->mensaje, calendario.mensaje);                 
        }
        else{
            mensaje = NULL;
        }
    }
    else{
        this->dia = 1;
        this->mes = 1;
        this->anyo = 1900;
        this->mensaje = NULL;
    }

}

TCalendario::~TCalendario(){
    dia = 1;
    mes = 1;
    anyo = 1900;
    if(mensaje != NULL){
        delete[] mensaje;
        mensaje = NULL;
    } 
    
}

TCalendario& TCalendario::operator=(const TCalendario& calen){
    if(this != &calen){         //para evitar que sea el mismo objeto
        this->~TCalendario();
        this->dia = calen.dia;
        this->mes = calen.mes;
        this->anyo = calen.anyo;
        if(this->mensaje != NULL){      //si el mensaje que tenemos ahora, eliminamos la memoria dinamica
            delete this->mensaje;
        }
        
        if(calen.mensaje == NULL){
            this->mensaje = NULL;
        }
        else{
            this->mensaje = new char[strlen(calen.mensaje) + 1];
            strcpy(this->mensaje, calen.mensaje);
        }
    }
    return (*this);
}

TCalendario TCalendario::operator+(int sumadia){
    TCalendario calen (*this);
    while(sumadia > 0){
        sumadia--;
        calen++;
    }
    return calen;
}

TCalendario TCalendario::operator++(int sumadia){  //con postincremento
    TCalendario calen(*this);
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        if(dia == 31){
            if(mes == 12){
                dia = 1;
                mes = 1;
                anyo++;
            }
            else{
                dia = 1;
                mes++;
            }
        }
        else{
            dia++;
        }
    }
    else{
        if(mes == 2){
            if(isBisiesto(anyo) == true){
                if(dia == 29){
                    dia = 1;
                    mes++;
                }
                else{
                    dia++;
                }
            }
            else{
                if(dia == 28){
                    dia = 1;
                    mes++;
                }
                else{
                    dia++;
                }
            }
        }
        else{
            if(dia == 30){
                dia = 1;
                mes++;
            }
            else{
                dia++;
            }
        }
    }
    return calen;
}

TCalendario& TCalendario::operator++(){ //con preincremento
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        if(dia == 31){
            if(mes == 12){
                dia = 1;
                mes = 1;
                anyo++;
            }
            else{
                dia = 1;
                mes++;
            }
        }
        else{
            dia++;
        }
    }
    else{
        if(mes == 2){
            if(isBisiesto(anyo) == true){
                if(dia == 29){
                    dia = 1;
                    mes++;
                }
                else{
                    dia++;
                }
            }
            else{
                if(dia == 28){
                    dia = 1;
                    mes++;
                }
                else{
                    dia++;
                }
            }
        }
        else{
            if(dia == 30){
                dia = 1;
                mes++;
            }
            else{
                dia++;
            }
        }
    }
    return *this;
}

bool TCalendario::ModFecha(int nuevodia, int nuevomes, int nuevoanyo){ 
    bool mod = false;
    if(checkFecha(nuevodia, nuevomes, nuevoanyo) == true){
        this->dia = nuevodia;
        this->mes = nuevomes;
        this->anyo = nuevoanyo;
        mod = true;
    }
    return mod;
}

bool TCalendario::ModMensaje(char* mensaje){  //como devuelvo true o false por fallo memoria
    if(mensaje == NULL){
        this->mensaje = NULL;
    }
    else{
        delete[] this->mensaje;
        this->mensaje = new char[strlen(mensaje)+1];
        strcpy(this->mensaje, mensaje);
    }
    return true;
}


TCalendario TCalendario::operator-(int restadia){
    TCalendario calen (*this);
    while(restadia > 0){
        restadia--;
        calen--;
    }
    if(!checkFecha(calen.dia, calen.mes, calen.anyo)){
        calen.~TCalendario();
    }
    return calen;
}

TCalendario TCalendario::operator--(int restadia){  //con postdecremtno
    TCalendario calen(*this);
    if(mes == 3){
            if(dia == 1){
                if(isBisiesto(anyo) == true){
                    dia = 29;
                    mes--;
                }
                else{
                    dia = 28;
                    mes--;
                }
            }
            else{
                dia--;
            }
        }
        else{
            if(mes == 1 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
                if(mes == 1){
                    if(dia == 1){
                        dia = 31;
                        mes = 12;
                        anyo--;
                    }
                    else{
                        dia--;
                    }
                }
                else{
                    if(dia == 1){
                        dia = 30;
                        mes--;
                    }
                    else{
                        dia--;
                    }
                }
            }
            else{
                if(dia == 1){
                    dia = 31;
                    mes--;
                }
                else{
                    dia--;
                }
            }
        }
        if(checkFecha(calen.dia, calen.mes, calen.anyo) == false){
            this->~TCalendario();
        }

        return calen;
    }

TCalendario& TCalendario::operator--(){  //con predecremento
    if(mes == 3){
        if(dia == 1){
            if(isBisiesto(anyo) == true){
                dia = 29;
                mes--;
            }
            else{
                dia = 28;
                mes--;
            }
        }
        else{
            dia--;
        }
    }
    else{
        if(mes == 1 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
            if(mes == 1){
                if(dia == 1){
                    dia = 31;
                    mes = 12;
                    anyo--;
                }
                else{
                    dia--;
                }
            }
            else{
                if(dia == 1){
                    dia = 30;
                    mes--;
                }
                else{
                    dia--;
                }
            }
        }
        else{
            if(dia == 1){
                dia = 31;
                mes--;
            }
            else{
                dia--;
            }
        }
    }
    if(checkFecha(dia, mes, anyo) == false){
        this->~TCalendario();
    }
    return *this;
}

bool TCalendario::operator==(const TCalendario& calen){
    bool igual = false;                                                  
    if(dia == calen.dia && mes == calen.mes && anyo == calen.anyo){
        if(mensaje == NULL || calen.mensaje == NULL){
            if(mensaje == NULL && calen.mensaje == NULL){
                igual = true;
            }
            else if(mensaje == NULL && calen.mensaje != NULL){
                    igual = false;
                }
                else if(mensaje != NULL && calen.mensaje == NULL){
                        igual = false;
                    }
        }
        else{
            if(strcmp(mensaje, calen.mensaje) == 0){
                igual = true;
            }
        }
    }
    return igual;
}

bool TCalendario::operator!=(const TCalendario& calen){
    return !(*this == calen);
}

bool TCalendario::operator>(const TCalendario& calen){
    bool mayor = false;
    if(this->anyo > calen.anyo){
        mayor = true;
    }
    else if(this->anyo == calen.anyo){
        if(this->mensaje == NULL && calen.mensaje == NULL){
            mayor = false;
        }
        else if(this->mensaje != NULL && calen.mensaje == NULL){
            mayor = true;
        }
        else if(this->mensaje == NULL && calen.mensaje != NULL){
            mayor = false;
        }
        else if(strlen(this->mensaje) > strlen(calen.mensaje)){
            mayor = true;
        }
        else if(strlen(this->mensaje) == strlen(calen.mensaje)){
            mayor = false;
        }
    }
    return mayor;
}

bool TCalendario::operator<(const TCalendario& calen){
    bool menor = false;
    if(this->anyo < calen.anyo){
        menor = true;
    }
    else if(this->anyo == calen.anyo){
        if(this->mensaje == NULL && calen.mensaje == NULL){
            menor = false;
        }
        else if(this->mensaje != NULL && calen.mensaje == NULL){
            menor = false;
        }
        else if(this->mensaje == NULL && calen.mensaje != NULL){
            menor = true;
        }
        else if(strlen(this->mensaje) < strlen(calen.mensaje)){
            menor = true;
        }
        else if(strlen(this->mensaje) == strlen(calen.mensaje)){
            menor = false;
        }
    }
    return menor;
}

bool TCalendario::EsVacio(){
    bool vacio = false;
    if(dia == 1 && mes == 1 && anyo == 1900 && mensaje == NULL){
        vacio = true;
    }
    return vacio;
}

const int TCalendario::Dia(){
    return dia;
}

const int TCalendario::Mes(){
    return mes;
}

const int TCalendario::Anyo(){
    return anyo;
}

const char* TCalendario::Mensaje(){
    return mensaje;
}

ostream& operator<<(ostream &salida, const TCalendario &calen){   
    if(calen.dia < 10){
        salida<<"0"<<calen.dia<<"/";
    }
    else{
        salida<<calen.dia<<"/";
    }

    if(calen.mes < 10){
        salida<<"0"<<calen.mes<<"/";
    }
    else{
        salida<<calen.mes<<"/";
    }

    salida<<calen.anyo<<" ";

    if(calen.mensaje == NULL){
        salida<<"\"\"";
    }
    else{
        salida<<"\""<<calen.mensaje<<"\"";
    }

    return salida;    
}

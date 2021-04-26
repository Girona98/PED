#include <iostream>

using namespace std;

#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"

int main()
{
    TCalendario a(10,10,2006, (char*) "mensaje 1");
    TCalendario b(11,10,2006, (char*) "mensaje 2");
    TCalendario c(12,10,2006, (char*) "mensaje 3");
    TCalendario d(13,10,2006, (char*) "mensaje 4");
    TCalendario e(14,10,2006, (char*) "mensaje 5");
    TCalendario f(15,10,2006, (char*) "mensaje 6");
    TListaCalendario lis;
    TListaPos p;

    lis.Insertar(a);
    lis.Insertar(b);
    lis.Insertar(c);
    lis.Insertar(d);
    lis.Insertar(e);
    lis.Insertar(f);

    cout << "Lista original: " << lis << endl << endl;

    p = lis.Primera();
    cout << lis.Borrar(p) << endl;
    cout << lis << endl;

    cout << lis.Insertar(a) << endl;
    cout << lis << endl;

    cout << lis.Insertar(a) << endl;
    cout << lis << endl;

    cout << lis.Borrar(p) << endl;
    cout << lis << endl;
    cout << lis.Insertar(b) << endl;
    cout << lis << endl;
}
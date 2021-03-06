#include <iostream>
#include <cstdlib>
#include <queue>
#include "arbin.h"
#include "abb.h"
#include "excep_abb.h"
#include "excep_arbin.h"
#include "excepcion.h"
#include "nodoB.h"
#include "excep_nosig.h"
// Recorridos

template <typename T>
void inorden(const Arbin<T>& a, const typename Arbin<T>::Iterador& r) {
    if (!r.arbolVacio()) {
        inorden(a, a.subIzq(r));
        cout << r.observar() << " ";
        inorden(a, a.subDer(r));
    }
}

template <typename T>
void preorden(const Arbin<T>& a, const typename Arbin<T>::Iterador& r) {
    if (!r.arbolVacio()) {
        cout << r.observar() << " ";
        preorden(a, a.subIzq(r));
        preorden(a, a.subDer(r));
    }
}

template <typename T>
void postorden(const Arbin<T>& a, const typename Arbin<T>::Iterador& r) {
    if (!r.arbolVacio()) {
        postorden(a, a.subIzq(r));
        postorden(a, a.subDer(r));
        cout << r.observar() << " ";
    }
}

template <typename T>
void anchura(const Arbin<T>& a) {
    if (!a.esVacio()) {
        queue<typename Arbin<T>::Iterador> c;
        typename Arbin<T>::Iterador ic = a.getRaiz();
        c.push(ic);
        while (!c.empty()) {
             ic = c.front();
             c.pop();
             cout << ic.observar() << " ";
             if (!a.subIzq(ic).arbolVacio())
                c.push(a.subIzq(ic));
             if (!a.subDer(ic).arbolVacio())
                c.push(a.subDer(ic));
        }
    }
}


/***************************************************************************/
/****************************** EJERCICIOS *********************************/
/***************************************************************************/
//Ejercicio 1
template <typename T>

int numHojas(const Arbin<T>& a){
    return numHojas(a, a.getRaiz());
}

template<typename T>
int numHojas(const Arbin<T>& a,const typename Arbin<T>::Iterador& it){
    int nhojas;
    if(it.arbolVacio()) nhojas=0;
    else if(a.subIzq(it).arbolVacio() && a.subDer(it).arbolVacio()) nhojas=1;
    else nhojas=numHojas(a, a.subIzq(it))+numHojas(a, a.subDer(it));
    return nhojas;
}

/****************************************************************************/
//Ejercicio 2

template<typename T>
Arbin<T> simetrico(const Arbin<T> &a){
    return simetrico(a, a.getRaiz());
}

template<typename T>
Arbin<T> simetrico(const Arbin<T> &a, const typename Arbin<T>::Iterador& it){
    if(!it.arbolVacio())
    {
       return Arbin<T>(it.observar(), simetrico(a, a.subDer(it)), simetrico(a, a.subIzq(it)));
    }
        else return Arbin<T>();

}

/****************************************************************************/
//Ejercicio 3

template<typename T>
Arbin<T> recorridoZigzag(const Arbin<T> &a){
    return recorridoZigzag(a.getRaiz());
}

template<typename T>
void recorridoZigzag(const Arbin<T> &a, const typename Arbin<T>::Iterador& it, char sentido)
{
   if(!it.arbolVacio()){
        if(sentido=='D'){
            cout<<it.observar()<<" ";

            recorridoZigzag(a, a.subDer(it), 'I');
        }
        else if(sentido=='I'){
            cout<<it.observar()<<" ";

            recorridoZigzag(a, a.subIzq(it), 'D');
        }
    }
}

template<typename T>
void recorridoZigzag(const Arbin<T> &a, char sentido){
    recorridoZigzag(a, a.getRaiz(), sentido);
}

/******************************************************************************/
//Ejercicio 4

template <typename T>

int numNodos(const Arbin<T>& a, const typename Arbin<T>::Iterador& r)
{
    if(r.arbolVacio())
        return 0;
    else
    {
        return (numNodos(a, a.subIzq(r)) +1 + numNodos(a, a.subDer(r)));
    }
}

template <typename T>
bool compensado(const Arbin<T>& a, const typename Arbin<T>::Iterador& r)
{
    if(r.arbolVacio())
    {
        return true;
    }
    else
    {
        return abs(numNodos(a, a.subIzq(r))- numNodos(a, a.subDer(r))) <= 1 && compensado(a, a.subIzq(r)) && compensado(a, a.subDer(r));
    }
}

template <typename T>
bool compensado(const Arbin<T>& a)
{
    return compensado(a, a.getRaiz());
}
/*****************************************************************************/
//Ejercicio 5 //No funciona
template <typename T>
void palabras(const Arbin<T> &a){
    palabras(a,"", a.getRaiz());
}

template <typename T>
void palabras(const Arbin<T> &a, string s, const typename Arbin<T>::Iterador& it){
    if(!it.arbolVacio()){
       if(a.subIzq(it).arbolVacio() && a.subDer(it).arbolVacio())
       {
           cout << s << it.observar() << endl;
       }
       else{
        string ns = s + it.observar();
        palabras(a, ns, a.subIzq(it));
        palabras(a, ns, a.subDer(it));
       }
    }
}

/******************************************************************************/
//Ejercicio 6

void siguienteMayor(const ABB<int>& a, const ABB<int>::Iterador & r, int x, int& sm)
{
    int eRaiz;
    if(!r.arbolVacio())
    {

    }
}

int siguienteMayor(const ABB<int>& a, int x) throw (NoHaySiguienteMayor)
{
    int sm=0;
    siguienteMayor(a, a.getRaiz(), x, sm);
    if(sm==0)
        throw (NoHaySiguienteMayor());
    else
        return sm;
}


/******************************************************************************/
//Ejercicio 7

template<typename T>
ABB<T> posicion(const ABB<T> &a){
    return posicion(a, a.getRaiz());
}

template<typename T>
int posicion(const ABB<T> &a, typename ABB<T>::Iterador& it, const T& n){
    int pos=0;
    if(a.buscar(n)){
        if(it.observar()<n){
            pos+=posicion(a.subDer(it))+1;
        }
        else{
            pos+=posicion(a.subIzq(it))-1;
        }
    }
    return pos;
}

/******************************************************************************/
//Ejercicio 8
bool haySumaCamino(const Arbin<int>& a, const Arbin<int>::Iterador& r, int suma)
{
    if (r.arbolVacio())
        return false;
    else
    {
        if(a.subIzq(r).arbolVacio()&&a.subDer(r).arbolVacio())
        return(suma==r.observar());
        else
            return(haySumaCamino(a,a.subIzq(r),suma-r.observar()) || haySumaCamino(a,a.subDer(r),suma-r.observar()));
    }
}

bool haySumaCamino(const Arbin<int>& a,int suma)
{
    if(a.esVacio())
        return (suma==0);
    else
        return haySumaCamino(a,a.getRaiz(),suma);
}

/****************************************************************************/
/****************************************************************************/
int main(int argc, char *argv[])
{
    Arbin<char> A('t', Arbin<char>('m', Arbin<char>(),
                                        Arbin<char>('f', Arbin<char>(), Arbin<char>())),
                       Arbin<char>('k', Arbin<char>('d', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>()));

    Arbin<char> B('t', Arbin<char>('n', Arbin<char>(),
                                        Arbin<char>('d', Arbin<char>('e', Arbin<char>(), Arbin<char>()),
                                                         Arbin<char>())),
                       Arbin<char>('m', Arbin<char>('f', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>('n', Arbin<char>(), Arbin<char>())));

    Arbin<char> D('t', Arbin<char>('k', Arbin<char>('d', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>()),
                       Arbin<char>('m', Arbin<char>(),
                                        Arbin<char>('f', Arbin<char>(), Arbin<char>())));

    Arbin<char> E('o', Arbin<char>('r', Arbin<char>(),
                                        Arbin<char>('o', Arbin<char>(), Arbin<char>())),
                       Arbin<char>('l', Arbin<char>('a', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>('e', Arbin<char>(), Arbin<char>())));

    Arbin<int> F(2, Arbin<int>(7, Arbin<int>(2, Arbin<int>(), Arbin<int>()),
                                  Arbin<int>(6, Arbin<int>(5, Arbin<int>(), Arbin<int>()),
                                                Arbin<int>(11, Arbin<int>(), Arbin<int>()))),
                    Arbin<int>(5, Arbin<int>(),
                                  Arbin<int>(9, Arbin<int>(),
                                                  Arbin<int>(4, Arbin<int>(), Arbin<int>()))));

    ABB<int> BB6, BB7;



    // NUMERO HOJAS //
    cout << "Num. hojas del arbol B: " << numHojas(B) << endl;
    cout << "Num. hojas del arbol E: " << numHojas(E) << endl << endl;

    // COPIA SIMETRICA //
    Arbin<char> C = simetrico(B);
    cout << "Recorrido en inorden del arbol B: " << endl;
    inorden(B, B.getRaiz());
    cout << endl << "Recorrido en inorden del arbol C: " << endl;
    inorden(C, C.getRaiz());
    cout << endl << endl;


    // RECORRIDO EN ZIG-ZAG //
    cout << "Recorrido en zigzag I de B:\n";
    recorridoZigzag(B, 'I');
    cout << endl;
    cout << "Recorrido en zigzag D de C:\n";
    recorridoZigzag(C, 'D');
    cout << endl << endl;


    // COMPENSADO //
    cout << "Esta A compensado?:";
    cout << (compensado(A) ? " SI" : " NO") << endl;
    cout << "Esta B compensado?:";
    cout << (compensado(B) ? " SI" : " NO") << endl << endl;

    // PALABRAS DE UN ARBOL //
    cout << "PALABRAS DE A:\n";
    palabras(E);
    cout <<"\n";
    cout << "PALABRAS DE B:\n";
    palabras(B);
    cout << endl;

    // SIGUIENTE MAYOR
    BB6.insertar(8); BB6.insertar(3); BB6.insertar(10); BB6.insertar(1); BB6.insertar(6);
    BB6.insertar(14); BB6.insertar(4); BB6.insertar(7); BB6.insertar(13);
    try
    {
        cout << "Siguiente mayor en BB6 de 5: " << siguienteMayor(BB6, 5) << endl;
        cout << "Siguiente mayor en BB6 de 8: " << siguienteMayor(BB6, 8) << endl;
        cout << "Siguiente mayor en BB6 de 13: " << siguienteMayor(BB6, 13) << endl;
        cout << "Siguiente mayor en BB6 de 14: " << siguienteMayor(BB6, 14) << endl;
    }
    catch(const NoHaySiguienteMayor& e)
    {
        cout << e.Mensaje() << endl << endl;
    }
/*
    // POSICION INORDEN //
    BB7.insertar(5); BB7.insertar(1); BB7.insertar(3); BB7.insertar(8); BB7.insertar(6);
    cout << "Posicion Inorden en BB7 de 3: ";
    cout << posicionInorden(BB7, 3);
    cout << endl << "Posicion Inorden en BB7 de 8: ";
    cout << posicionInorden(BB7, 8);
    cout << endl << "Posicion Inorden en BB7 de 7: ";
    cout << posicionInorden(BB7, 7);
    cout << endl << endl;

    // SUMA CAMINO
    cout << "Hay un camino de suma 26 en F?:";
    cout << (haySumaCamino(F, 26) ? " SI" : " NO") << endl;
    cout << "Hay un camino de suma 9 en F?:";
    cout << (haySumaCamino(F, 9) ? " SI" : " NO") << endl;
*/

    system("PAUSE");
    return 0;
}

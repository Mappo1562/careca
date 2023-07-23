#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

//  cartas
#define A 14
#define J 11
#define Q 12
#define K 13
#define JOKER 15

//  estado
#define MANO 0
#define VISIBLE 1
#define DESCONOCIDA 2

struct cartas{
    int estado;
    int value;
};

typedef cartas tElemPila;
typedef cartas tElemLista;
int MAXSIZE=108;

class tPila{
    private:
        unsigned int maxSize; //    tamaño maximo de la pila
        unsigned int top; //        tamaño actual de la pila
        tElemPila *stackArray; //   arreglo con los elementos de la pila
    
    public:
        tPila();
        ~tPila();

        void clear ();//                reinicializa una pila como vacía
        int push (tElemPila item);//    inserta un elemento en el tope de la pila
        void pop ();  //                elimina el elemento que está en el tope de la pila
        tElemPila topValue ();//        retorna una copia del elemento que está en el tope de la pila  
        int size ();//                  retorna el tamaño de una pila 
////        ojo que aqui comienzan mis funciones (no se deverian usar)        ////
        void print();
};

class tLista {
    private:
        unsigned int maxSize; //            tamaño máximo de la lista
        unsigned int listSize; //           tamaño actual de la lista
        unsigned int curr; //               posición actual de la lista
        tElemLista* listArray; //           arreglo con los elementos de la lista
    public:
        tLista();
        ~tLista();

        void clear();//                     borra todos los elementos de la lista, reinicializándola vacía
        int insert(tElemLista item);//      inserta un elemento en la posición actual de la lista
        int append(tElemLista item);//      agrega un elemento al final de la lista
        tElemLista erase();//               borra el elemento actual y retorna su valor
        void moveToStart();//               mueve la posición actual al comienzo de la lista
        void moveToEnd();//                 mueve la posición actual al final de la lista deja una posicion adelante del ultimo elemento
        void next();//                      mueve la posición actual al siguiente elemento de la lista, no produce cambios si está en la cola de la lista
        void prev();//                      mueve la posición actual al elemento anterior de la lista, no produce cambios si está en la cabeza de la lista
        int length();//                     retorna el número de elementos en la lista
        int currPos();//                    retorna la posición del elemento actual
        void moveToPos(int pos);//          mueve la posición actual a una especificada
        tElemLista getValue();//            obtiene el valor del elemento actual de la lista

        void print();
};

struct tNodo{
    tElemLista info;
    tNodo* sig;
};

class ListaE {
    private:
        tNodo* head;
        tNodo* tail;
        tNodo* curr;//                                      apuntara siempre al nodo anterior del actual, para acceder al valor seria curr->sig->info
        int listSize;
        int pos; // posicion actual en la lista
    public:
        ListaE();
        ~ListaE();

        void clear();//                     borra todos los elementos de la lista, reinicializándola vacía
        int insert(tElemLista item);//      inserta un elemento en la posición actual de la lista
        int append(tElemLista item);//      agrega un elemento al final de la lista
        tElemLista erase();//               borra el elemento actual y retorna su valor
        void moveToStart();//               mueve la posición actual al comienzo de la lista
        void moveToEnd();//                 mueve la posición actual al final de la lista deja una posicion adelante del ultimo elemento
        void next();//                      mueve la posición actual al siguiente elemento de la lista, no produce cambios si está en la cola de la lista
        void prev();//                      mueve la posición actual al elemento anterior de la lista, no produce cambios si está en la cabeza de la lista
        int length();//                     retorna el número de elementos en la lista
        //int currPos();//                    retorna la posición del elemento actual
        void moveToPos(int pos);//          mueve la posición actual a una especificada
        tElemLista getValue();//            obtiene el valor del elemento actual de la lista
};

class jugador{
    private:
        
};


//                      Pila





tPila::tPila(){
    maxSize=MAXSIZE;
    top=0;
    stackArray=new tElemPila[maxSize];
}

tPila::~tPila(){
    delete[] stackArray;
}

int tPila::push (tElemPila item){
    if (top == maxSize) 
        return 0;
    stackArray[top++] = item;
    return 1; // inserción exitosa
}

void tPila::clear (){
    top=0;
}

void tPila::pop(){
    if (top==0)
        return;
    top--;
}

tElemPila tPila::topValue(){
    return stackArray[top-1];
}

int tPila::size(){
    return top-1;
}

void tPila::print(){
    for (int i=top-1;i>0;i--)
        cout<<"["<<stackArray[i].value<<"] ";
    if (top==0)
        cout<<"la pila esta vacia";
    cout<<"\n";
}






//                          Lista basada en arreglos





// inicializa una lista como vacía
tLista::tLista() {
    maxSize = MAXSIZE; // tamaño máximo de la lista
    listSize = 0; // lista vacía
    curr = 0;
    listArray = new tElemLista[maxSize];
}


// borra todos los elementos de la lista, reinicializándola vacía
void tLista::clear() {
    listSize = curr = 0;
}


// inserta un elemento en la posición actual de la lista
int tLista::insert(tElemLista item) {
    unsigned int i;
    if (listSize >= maxSize)
        return -1; //lista llena, no se inserta
    for (i = listSize; i > curr; i--)
        listArray[i] = listArray[i-1];
    listArray[i] = item;
    listSize++;
    return i; // retorna posición de inserción
}


// agrega un elemento al final de la lista
int tLista::append(tElemLista item) {
    if (listSize >= maxSize)
        return 0; //lista llena, no se inserta
    listArray[listSize++] = item;
    return 1; // inserción exitosa
}


// borra el elemento actual y retorna su valor
tElemLista tLista::erase() {
    tElemLista item;
    unsigned int i;
    if (curr < 0 || curr >= listSize){
        cout<<"error 157 EDD.hpp\n";
        cartas carta;
        carta.estado=-1;
        carta.value=0;
        return carta;
    }
    item = listArray[curr];
    for (i = curr; i < listSize-1; i++)
        listArray[i] = listArray[i+1];
    listSize--;
    return item;
}


// mueve la posición actual al comienzo de la lista
void tLista::moveToStart() {
    curr = 0; 
}


// mueve la posición actual al final de la lista deja una posicion adelante del ultimo elemento
void tLista::moveToEnd() {
    curr = listSize; 
}


// mueve la posición actual al elemento anterior de la lista
void tLista::prev() { 
    if (curr != 0) 
        curr--; 
}


// mueve la posición actual al elemento siguiente de la lista
void tLista::next() { 
    if (curr < listSize) 
        curr++; 
}


// destructor, libera la memoria asociada
tLista::~tLista() { 
    delete[] listArray; 
}


// retorna el número de elementos en la lista
int tLista::length(){
    return listSize;
}


// retorna la posición del elemento actual
int tLista::currPos(){
    return curr;
}


// mueve la posición actual a una especificada
void tLista::moveToPos(int pos){
    if (pos<=(int)maxSize)
        curr=pos;
}


// obtiene el valor del elemento actual de la lista
tElemLista tLista::getValue(){
    return listArray[curr];
}


// **   *      Zona De Pruebas      *   ** //


void tLista::print(){
    for (unsigned int i=0 ; i<listSize ; i++)
        cout<<"["<<listArray[i].value<<"] ";   
    cout<<"\n";
}





//                          lista enlazada





ListaE::ListaE() {
 head = tail = curr = new tNodo;
 listSize = 0;
 pos = 0;
}

ListaE::~ListaE(){
    clear();
    delete head;
}

void ListaE::clear() {
    tNodo* aux = head->sig;    
    while (aux != NULL) {
        tNodo* temp = aux;
        aux = aux->sig;
        delete temp;
    }
    head->sig = NULL;
    tail = curr = head;
    listSize = 0;
    pos = 0;

}

int ListaE::insert(tElemLista item) {
    tNodo* aux = curr->sig;
    curr->sig = new tNodo;
    curr->sig->info = item;
    curr->sig->sig = aux;
    if (curr == tail)   
        tail = curr->sig;
    listSize++;
    return pos;
}

void ListaE::moveToStart() { 
    curr = head; 
    pos = 0; 
}

void ListaE::moveToEnd() { 
    curr = tail; 
    pos = listSize; 
}

void ListaE::prev() {
    tNodo* temp;
    if (curr == head)   
        return;
    temp = head;
    while (temp->sig != curr) 
        temp = temp->sig;
    curr = temp;
    pos--;
}

void ListaE::next() { 
    if (curr != tail) { 
        curr = curr->sig; 
        pos++; 
    } 
}

void ListaE::moveToPos(int posicion) {
    if (posicion < 0 || posicion > listSize) 
        return;
    curr = head;
    pos = 0;
    for (int i = 0; i < posicion; i++) {
        curr = curr->sig;
        pos++;
    }
}

tElemLista ListaE::getValue(){
    return curr->sig->info;
}

int ListaE::length(){
    return listSize;
}

tElemLista ListaE::erase() {
    tNodo* eliminar = curr->sig;
    tElemLista ret = eliminar->info;
    curr->sig = eliminar->sig;
    if (eliminar == tail)
        tail = curr;
    delete eliminar;
    listSize--;
    return ret;
}

int ListaE::append(tElemLista item){
    tNodo* aux = tail->sig;
    aux=new tNodo;
    aux->info=item;
    tail=aux;
    return 1;
}
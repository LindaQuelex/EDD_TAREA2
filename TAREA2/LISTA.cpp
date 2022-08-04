#include <iostream>
#include <conio.h>
using namespace std;

//CREACIÓN DE NODO
struct Nodo{
    int dato;
    string nombre;
    string apellido;
    int edad;
    string dirección;
    string carrera;
    string curso;
    string estado;

    Nodo *siguiente;
};

void insertarLista(Nodo *&, int);

int main(){
    cout <<"Implementacion de lista y funcionalidades en C++\n";
    Nodo *lista=NULL;

    int dato;
    cout<<"Ingrese un numero:";
    cin>>dato;
    insertarLista(lista, dato);
    cout<<"Ingrese un numero:";
    cin>>dato;
    insertarLista(lista, dato);
    cout<<"Ingrese un numero:";
    cin>>dato;
    insertarLista(lista, dato);

 
    getch();
    return 0;
}

//FUNCIÓN INSERTAR
void insertarLista(Nodo *&lista, int n){
    Nodo *nuevo_nodo=new Nodo();  //RESERVA ESPACIO EN MEMORIA PARA PODER ALMACENAR EL NODO
    nuevo_nodo -> dato =n;
    Nodo *aux1=lista;
    Nodo *aux2;
    while ((aux1 != NULL) && (aux1->dato<n)){
        aux2= aux1;
        aux2= aux2->siguiente;
    }
    if (lista ==aux1){
        lista= nuevo_nodo;
    }
    else{
        aux2->siguiente=nuevo_nodo;
    }
    nuevo_nodo->siguiente=aux1;
    cout <<"\tDato " <<n<< " insertado a la lista correctamente\n";
   
}
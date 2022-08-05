#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

//CREACIÓN DE NODO
struct Nodo{
    int dato;
    string nombre_nodo;
    string apellido_nodo;
    int edad_nodo;
    string direccion_nodo;
    string carrera_nodo;
    string curso_nodo;
    string estado_nodo;

    Nodo *siguiente;
};

void insertarLista(Nodo *&,  string nombre_nodo, string apellido_nodo, int edad_nodo, string direccion_nodo, string carrera_nodo, string curso_nodo, string estado_nodo );
void mostrarLista(Nodo *);
Nodo *lista=NULL;
void menu();

int main(){
    //cout <<"Implementacion de lista y funcionalidades en C++\n";
    menu();

    getch();
    return 0;
}

void menu(){
    int option;
    int edad_nodo;
    string nombre_nodo;
    string apellido_nodo;
    string direccion_nodo;
    string carrera_nodo;
    string curso_nodo;
    string estado_nodo;
    do{
        cout<<"\t.:MENU:.\n";
        cout<<"1. Insertar elementos a la lista \n";
        cout<<"2. Mostrar los elementos de la lista\n";
        cout<<"3. Salir\n";
        cin >> option;

        switch (option){
            case 1: cout<<"Ingrese nombre:";
                    cin>>nombre_nodo;
                    cout<<"Ingrese apellido:";
                    cin>>apellido_nodo;
                    cout<<"Ingrese edad:";
                    cin>>edad_nodo;
                    cout<<"Ingrese dirección:";
                    cin>>direccion_nodo;
                    cout<<"Ingrese carrera:";
                    cin>>carrera_nodo;
                    cout<<"Ingrese curso:";
                    cin>>curso_nodo;
                    cout<<"Ingrese estado:";
                    cin>>estado_nodo;
                    
                    insertarLista(lista, nombre_nodo, apellido_nodo,  edad_nodo, direccion_nodo, carrera_nodo, curso_nodo, estado_nodo);
                    cout<<"\n";
                    system("pause");
                    break;

            case 2: mostrarLista(lista);
                    cout<<"\n";
                    system("pause");
                    break;
        }
        // system("cls");
    }
    
    while(option !=3);
}

//FUNCIÓN INSERTAR
void insertarLista(Nodo *&lista,  string nombre, string apellido, int edad, string direccion, string carrera, string curso, string estado ){
    Nodo *nuevo_nodo=new Nodo();  //RESERVA ESPACIO EN MEMORIA PARA PODER ALMACENAR EL NODO
    nuevo_nodo -> nombre_nodo= nombre;
    nuevo_nodo -> apellido_nodo= apellido;
    nuevo_nodo -> edad_nodo =edad;
    nuevo_nodo -> direccion_nodo= direccion;
    nuevo_nodo -> carrera_nodo= carrera;
    nuevo_nodo -> curso_nodo= curso;
    nuevo_nodo -> estado_nodo= estado;

    Nodo *aux1=lista;
    Nodo *aux2;

    while ((aux1 != NULL) && (aux1->edad_nodo<edad)){
        aux2= aux1;
        aux1= aux1->siguiente;
    }
    if (lista ==aux1){
        lista= nuevo_nodo;
    }
    else{
        aux2->siguiente=nuevo_nodo;
    }
    nuevo_nodo->siguiente=aux1;
    cout <<"\tNombre: " << nombre <<"\t/Apellido: "<< apellido <<"\t/Edad: "<< edad <<"\t/Direccion: "<< direccion <<"\t/Carrera: "<< carrera <<"\t/Curso: "<< curso <<"\t/Estado: "<< estado << " /datos insertados a la lista correctamente\n";
}

void mostrarLista(Nodo *lista){
    Nodo *actual= new Nodo();
    actual=lista;
    while (actual != NULL){
        cout<< actual->nombre_nodo << actual->apellido_nodo << actual->edad_nodo << actual->direccion_nodo << actual->carrera_nodo  << actual->estado_nodo <<"->";
        actual = actual -> siguiente;
    }
}


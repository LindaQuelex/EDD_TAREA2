#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

//Tarea 2 EDD: Implementacion de lista y funcionalidades en C++

//CREACIÓN DE NODO
struct Nodo{
    int carnet_nodo;
    string nombre_nodo;
    string apellido_nodo;
    int edad_nodo;
    string direccion_nodo;
    string carrera_nodo;
    string curso_nodo;
    string estado_nodo;

    Nodo *siguiente;
    
};


void insertarLista(Nodo *&,  int carnet_nodo, string nombre_nodo, string apellido_nodo, int edad_nodo, string direccion_nodo, string carrera_nodo, string curso_nodo, string estado_nodo );
void mostrarLista(Nodo *);
void modificarDato(Nodo *);
Nodo *lista=NULL;
void menu();

int main(){
    menu();
    getch();
    return 0;
}

void menu(){
    int option;
    int edad_nodo;
    int carnet_nodo;
    string nombre_nodo;
    string apellido_nodo;
    string direccion_nodo;
    string carrera_nodo;
    string curso_nodo;
    string estado_nodo;
    do{
        cout<<"\t-----------------------------MENU-----------------------------\n";
        cout<<"1. Insertar elementos a la lista \n";
        cout<<"2. Mostrar los elementos de la lista\n";
        cout<<"3. Modificar elementos de la lista\n";
        cout<<"4. Salir\n";
        cin >> option;
        switch (option){
            case 1: cout<<"Ingrese carnet:";
                    cin>> carnet_nodo;
                    cout<<"Ingrese nombre:";
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
                    insertarLista(lista, carnet_nodo, nombre_nodo, apellido_nodo,  edad_nodo, direccion_nodo, carrera_nodo, curso_nodo, estado_nodo);
                    cout<<"\n";
                    system("pause");
                    break;
            case 2: mostrarLista(lista);
                    cout<<"\n";
                    system("pause");
                    break;
            case 3: modificarDato(lista);
                    cout<<"\n";
                    system("pause");
                    break;
        }
        system("cls");
    }
    while(option !=4);
}

//FUNCIÓN INSERTAR
void insertarLista(Nodo *&lista,  int carnet, string nombre, string apellido, int edad, string direccion, string carrera, string curso, string estado ){
    Nodo *nuevo_nodo=new Nodo();  //RESERVA ESPACIO EN MEMORIA PARA PODER ALMACENAR EL NODO
    nuevo_nodo -> carnet_nodo= carnet;
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
//FUNCIÓN MOSTRAR
void mostrarLista(Nodo *lista){
    Nodo *actual= new Nodo();
    actual=lista;
    while (actual != NULL){
        cout <<"\tCarnet : "<<actual->carnet_nodo <<"\tNombre: "<<actual->nombre_nodo <<"\t/Apellido: "<< actual->apellido_nodo <<"\t/Edad: "<< actual->edad_nodo <<"\t/Direccion: "<< actual->direccion_nodo <<"\t/Carrera: " << actual->carrera_nodo <<"\t/Curso: "<< actual->curso_nodo <<"\t/Estado: " << actual->estado_nodo <<"->\n";
        actual = actual -> siguiente;
    }
}
//FUNCIÓN MODIFICAR
void modificarDato(Nodo *lista){
    Nodo *actual =new Nodo();
    actual = lista;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el carnet para modificar datos: ";
	cin >> nodoBuscado;
	if(actual != NULL){
		
		while(actual != NULL && encontrado != true){
			
			if(actual->carnet_nodo == nodoBuscado){
				cout << "\n Estudiante con carnet: " << nodoBuscado << " Encontrado con exito";
				cout << "\n Ingrese edad para actualizar: ";
				cin >> actual->edad_nodo;
				cout << "\n Ingrese direccion para actualizar: ";
				cin >> actual->direccion_nodo;
				cout << "\n Ingrese estado para actualizar: ";
				cin >> actual->estado_nodo;
				encontrado = true;
			}
			
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Carnet no encontrado\n\n";
		}
	}else{
		cout  << "\n La lista está vacía\n\n";
	}
    }




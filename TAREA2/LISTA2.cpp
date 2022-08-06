#include <iostream>

using namespace::std;

struct nodo{
	int carnet;
    string nombre_nodo;
    string apellido_nodo;
    int edad_nodo;
    string direccion_nodo;
    string carrera_nodo;
    string curso_nodo;
    string estado_nodo;

	nodo* siguiente;
} *primero, *ultimo;

void insertarNodo();
void modificarNodo();
void MostrarDatos();

int main(){
	
	int opcion_menu = 0;
	
	do
	{
		cout << "\t-------------------MENU---------------\n";
        cout<<"1. Insertar elementos a la lista \n";
        cout<<"2. Modificar los elementos de la lista\n";
        cout<<"3. Mostrar elementos de la lista\n";
        cout<<"4. Salir\n";

		cin >> opcion_menu;
		switch(opcion_menu){
		case 1:
			cout << "\n\n INSERTA DATOS A LA LISTA \n\n";
			insertarNodo();
			break;

		case 2:
			cout << "\n\n MODIFICAR DATOS \n\n";
			modificarNodo();
			break;

		case 3: 
			cout << "\n\n MOSTRAR \n\n";
			MostrarDatos();
			break;
		case 4:
			cout << "\n\n Programa finalizado...";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (opcion_menu != 4);
	
	
	return 0;
}

void insertarNodo(){
	nodo* nuevo = new nodo();
    cout<<"Ingrese carnet:";
    cin>>nuevo->carnet;
    cout<<"Ingrese nombre:";
    cin>>nuevo->nombre_nodo;
    cout<<"Ingrese apellido:";
    cin>>nuevo->apellido_nodo;
    cout<<"Ingrese edad:";
    cin>>nuevo->edad_nodo;
    cout<<"Ingrese direccion:";
    cin>>nuevo->direccion_nodo;
    cout<<"Ingrese carrera:";
    cin>>nuevo->carrera_nodo;
    cout<<"Ingrese curso:";
    cin>>nuevo->curso_nodo;
    cout<<"Ingrese estado:";
    cin>>nuevo->estado_nodo;
	
	if(primero == NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
	cout << "\n Datos ingresados correctamente\n\n";
}    


void modificarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el carnet del alumno para actualizar datos: ";
	cin >> nodoBuscado;
	if(primero != NULL){
		
		while(actual != NULL && encontrado != true){
			
			if(actual->carnet == nodoBuscado){
				cout << "\n Alumno con carnet " << nodoBuscado << " ¡Encontrado con exito!";
				cout << "\n Ingrese la actualizacion de edad: ";
				cin >> actual->edad_nodo;
                cout << "\n Ingrese la actualizacion de dirección: ";
				cin >> actual->direccion_nodo;
                cout << "\n Ingrese la actualizacion de estado: ";
				cin >> actual->estado_nodo;

				encontrado = true;
			}
			
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Registro no encontrado\n\n";
		}
	}else{
		cout  << "\n La lista está vacía\n\n";
	}
}

void MostrarDatos(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero != NULL){
		
		while(actual != NULL){
            cout<<"\tNombre: "<<actual->nombre_nodo <<"\t/Apellido: "<< actual->apellido_nodo <<"\t/Edad: "<< actual->edad_nodo <<"\t/Direccion: "<< actual->direccion_nodo <<"\t/Carrera: " << actual->carrera_nodo <<"\t/Curso: "<< actual->curso_nodo <<"\t/Estado: " << actual->estado_nodo <<"->\n";
            actual = actual -> siguiente;
		}
		
	}else{
		cout  << "\n La lista está vacía\n\n";
	}
}


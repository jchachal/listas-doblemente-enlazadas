// lista simple.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// listas simples.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>//biblioteca estandar en c++ para entrada y salida de archivos
using namespace std;//permite usar todos los elementos del espacio de nombres estándar (std) sin necesidad de anteponer std:: a cada uno.

//la funcion insertarInicio cre un nuevo nodo y lo coloca al comienzo de la lista
//la funcion eliminar recorre la lista hasta encontrar al nodo con el dato especifico y lo elimina, actualizando los punteros 
//EL destructoe libera la memoria asignada a cada nodo para evitar fugas de memoria


struct Nodo {//declara una estructura llamada nodo
	int dato;//declara una variable llamada dato de tipo entero
	Nodo* siguiente;//puntero al siguiente nodo
};
class ListaSimple {//declara una clase llamada lista simple, 
private://define la seleccion privada de la clase 
	Nodo* cabeza;//declara un puntero llamada cabeza
public://define la seleccion publica de la clase
	ListaSimple() : cabeza(nullptr) {}//constructor que inicializa la lista vacia 

	//inserta un nuevo nodo al inicio de la lista 

	void insertarInicio(int valor) {//define un metodo llamado insertarinicio que rersive un entero llamada valor
		Nodo* nuevo = new Nodo;//crea un nuevo nodo en la memoria y asigna su direccion 
		nuevo->dato = valor;//asigna el valor recibido como argumento al campo dato
		nuevo->siguiente = cabeza,//enlaza el nuevo nodo con el reto de la lista estableciendo su puntero siguiente que apunte ak nodo actualmente  
			cabeza = nuevo;//actualiza el puntero cabeza para que apunte al nuevo nodo 
	}
	//imprime la lista 
	void imprimir() {//define un metodo llamado imprimir que no resive parametros ni devuelve valores
		Nodo* actual = cabeza;//declara un puntero llamada actual y lo inicializa en la memoria almacenada cabeza 
		while (actual != nullptr) {//inicia un bucle que se ejecute mientras actual no sea nulo 
			cout << actual->dato << "->";//imprime el dato del nodo actual siguido al "->" representa enlace 
			actual = actual->siguiente;//asigna la variable actual el siguiente nodo en la lista enlazadas
		}
		cout << "NULL" << endl;//se imprime en la consola la palabra null indica el final de la lista enlazadas
	}

	//Eliminar el primer nodo que contenga el valor dado
	void eliminar(int valor) {//funcion para eliminar un nodo de una lista enlazada que contiene un valor 
		Nodo* actual = cabeza;//inicializa un puntero llamada actual  para rrecorer la lista
		Nodo* anterior = nullptr;//se inicializa un puntero llamado enterior para mantener referencia el nodo previo mientras se recorre la lista
		while (actual != nullptr && actual->dato != valor) {//inicializa un bucle que recorre la lista hasta que encuntre el valor 
			anterior = actual;//se actualiza el puntero anterior para que apunte al nodo actual 
				actual = actual->siguiente;//avanza el siguiente nodo de la lista 
		}
		if (actual == nullptr) {//verifica si llego al final de la lista sin encontrar el valor 
			cout << "Valor no encontrado." << endl;//imprime en la consola un mensaje que el valor no ha sido encontrado
			return;//finaliza la ejecucion de la funcion
		}
		if (anterior == nullptr) {//verifica si el nodo a eliminar es la cabeza de la lista
			//Se elimina la cabeza
			cabeza = actual->siguiente;//se actualiza la cabeza para que apunte al nodo siguiente 
		}
		else {
			anterior->siguiente = actual->siguiente;//si el nodo a eliminar no es la cabeza se actualiza al puntero del nodo anterior
		}
		delete actual;//se libera la memoria ocupada por ek nodo actual
		cout << "Valor eliminado:" << valor << endl;//imprime en la consola un mensaje que el valor ha sido eliminado
	}
	//Destructor para liberar la memoria de la lista 
	~ListaSimple() {//destructu¿or de la clase lista simple para limpiar correctamente la men¿moria
		Nodo* actual = cabeza;//se inicializa un puntero actual para recorrer la lista despues de la cabeza
		while (actual != nullptr) {//bucle que recorre toda la lista hasta que no quede nodos
			Nodo* siguiente = actual->siguiente;//almacena el puntero al siguiente nod antes de borrar el nodo actual 
			delete actual;//libera la memoria ocupada por el nodo actual 
			actual = siguiente;//avanza al siguiente nodo de la lista

		}
	}

};
int main() {//funcion principal que ejecuta el programa 
	ListaSimple lista;//se crea una instancia de clase listasimple 
	lista.insertarInicio(5);//se inserta un nodo con el valor 5 al inicio de la lista 
	lista.insertarInicio(10);//se inseta un nodo con el valor 10 al inicion de la lista desplanzando el nodo5
	lista.insertarInicio(15);//se inserta un nodo con el valor 15 al inicio de la lista desplazando el nodo 10 y 5
	cout << "Liata despues de inserciones:" << endl;//imprime en la consola un mensaje indicando que se mostrara la lista 
	lista.imprimir();//se llama al metodo imprimir de la clase listasimple

	lista.eliminar (10);//se elimina la lista al nodo que contiene el valor 10 
	cout << "Lista despues de  inserciones :" << endl;//se imprime un mensaje indicandi que se mostrara la lista despues de la eliminacion 
	lista.imprimir();//se llama al metodo imprimir para mostrar los elementos actuales 

	return 0;//finaliza el programa 

}

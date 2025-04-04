// listas doblemete enlazadas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>//biblioteca estandar en c++ para salida y entrada de archivos 
//

using namespace std;//

//en InsetarInicio, se crea un nodo y se ajustan los punteros siguientes y anterior segun responda 
//Se ofrecen dos funciones de impresion: una que recorre la lista hacia adelante (imprimir Adelanre) y otra hacia atras (imprimirAtras), 

struct NodoDoble {// Declaración de una estructura para representar un nodo en una lista doblemente enlazada.
	int dato;// Variable para almacenar el valor del nodo.
	NodoDoble *siguiente;// Puntero al siguiente nodo en la lista.
	NodoDoble *anterior;// Puntero al nodo anterior en la lista.
};

class ListaDoble {// Declaración de una clase para manejar una lista doblemente enlazada.
private:
	NodoDoble *cabeza;// Puntero al primer nodo (cabeza) de la lista.
public:
	ListaDoble() : cabeza(nullptr){}// Constructor que inicializa la cabeza de la lista como un puntero nulo, indicando que la lista está vacía.

	//Insetar un nuevo nodo al inicio de la lista 
	void insertarInicio(int valor) {// Método para insertar un nodo con un valor dado al inicio de la lista.
		NodoDoble* nuevo = new NodoDoble;// Se crea un nuevo nodo dinámicamente en memoria.
		nuevo->dato = valor;// Se asigna el valor proporcionado al campo 'dato' del nuevo nodo.
		nuevo->siguiente = cabeza;// El nuevo nodo apunta al actual primer nodo de la lista como su siguiente.
		nuevo->anterior = nullptr;// Como este nodo será el primero, su puntero 'anterior' se establece como nulo.
		if (cabeza != nullptr) {// Verifica si la lista no está vacía.
			cabeza->anterior = nuevo;//si no esta vacia el actual primer nodo de la lista apunta la ni¿uevo nodo
			}
		cabeza = nuevo;//actualiza la cabeza de la lista para que apunte al nuevo nodo
}

//imprime la lista de principio a fila
	void imprimirAdelante() { // Método para imprimir la lista desde el inicio hasta el final.
		NodoDoble* actual = cabeza; // Se inicializa un puntero 'actual' para recorrer la lista, comenzando desde la cabeza.
		cout << "Lista(adelante):"; // Muestra un mensaje indicando que se imprimirá la lista hacia adelante.
		// Llegar al último nodo
		while (actual != nullptr) { // Bucle que recorre la lista mientras el nodo actual no sea nulo.
			cout << actual->dato << "<->"; // Imprime el valor del nodo actual seguido de "<->" para representar la conexión entre nodos.
			actual = actual->siguiente; // Avanza al siguiente nodo en la lista.
		}
		cout << "NULL" << endl; // Indica el final de la lista mostrando "NULL".
	}
	// Imprime la lista de fin a principio
	void imprimirAtras() { // Método para imprimir la lista desde el final hasta el inicio.
		NodoDoble* actual = cabeza; // Se inicializa un puntero 'actual' para recorrer la lista, comenzando desde la cabeza.
		if (actual == nullptr) return; // Si la lista está vacía (cabeza es nula), termina el método sin hacer nada.

		// Llegar al último nodo
		while (actual->siguiente != nullptr) { // Bucle que recorre la lista hasta encontrar el último nodo (donde siguiente es nulo).
			actual = actual->siguiente; // Avanza al siguiente nodo en la lista.
		}
		cout << "Lista (atras):"; // Muestra un mensaje indicando que se imprimirá la lista hacia atrás.
		while (actual != nullptr) { // Bucle que recorre la lista hacia atrás, mientras el nodo actual no sea nulo.
			cout << actual->dato << "<->:"; // Imprime el valor del nodo actual seguido de "<->:" para representar la conexión entre nodos.
			actual = actual->anterior; // Retrocede al nodo anterior en la lista.
		}
		cout << "NULL" << endl; // Indica el inicio de la lista mostrando "NULL".
	}
	//elimina el primer nodo que tenga el valor dado
	void eliminar(int valor) { // Define una función para eliminar un nodo con un valor específico en una lista doblemente enlazada.
		NodoDoble* actual = cabeza; // Inicializa un puntero 'actual' que comienza desde la cabeza de la lista para recorrerla.

		while (actual != nullptr && actual->dato != valor) { // Bucle que recorre la lista hasta encontrar el nodo con el valor especificado o llegar al final (nullptr).
			actual = actual->siguiente; // Avanza al siguiente nodo en la lista.
		}

		if (actual == nullptr) { // Verifica si se llegó al final de la lista sin encontrar el valor buscado.
			cout << "Valor no encontrado." << endl; // Imprime un mensaje indicando que el valor no está presente en la lista.
			return; // Finaliza la ejecución de la función porque no se encontró el valor.
		}

		if (actual->anterior != nullptr) { // Verifica si el nodo encontrado tiene un nodo anterior (es decir, no es la cabeza de la lista).
			actual->anterior->siguiente = actual->siguiente; // Actualiza el puntero 'siguiente' del nodo anterior para saltar el nodo actual y apuntar al siguiente nodo del nodo a eliminar.
		}
		else {
			//se elimina la cabeza
			cabeza = actual->siguiente; // Si el nodo a eliminar es la cabeza, se actualiza la cabeza para que apunte al siguiente nodo, eliminando así la referencia al nodo actual.
		}
		if (actual->siguiente != nullptr) { // Verifica si el nodo actual tiene un nodo siguiente para evitar errores al acceder a punteros nulos.
			actual->siguiente->anterior = actual->anterior; // Actualiza el puntero 'anterior' del siguiente nodo para que apunte al nodo anterior al nodo eliminado.
		}
		delete actual; // Libera la memoria asignada al nodo actual, eliminándolo de la lista.
		cout << "Valor eliminado:" << valor << endl; // Imprime un mensaje en la consola indicando que el nodo con el valor especificado ha sido eliminado.

	}
	//destructor para liberar la memoria de la lista 
	~ListaDoble() { // Destructor de la clase 'ListaDoble', encargado de liberar la memoria dinámica utilizada por la lista doblemente enlazada.
		NodoDoble* actual = cabeza; // Se inicializa un puntero 'actual' para recorrer la lista desde la cabeza.
		while (actual != nullptr) { // Bucle que recorre la lista mientras existan nodos (actual no sea nulo).
			NodoDoble* siguiente = actual->siguiente; // Guarda un puntero al siguiente nodo antes de eliminar el nodo actual.
			delete actual; // Libera la memoria ocupada por el nodo actual, evitando fugas de memoria.
			actual = siguiente; // Avanza al siguiente nodo en la lista.
		}
	}
};
int main() { // Función principal del programa que ejecuta todas las operaciones.
	ListaDoble lista; // Se crea una instancia de la clase 'ListaDoble', que representa una lista doblemente enlazada.

	lista.insertarInicio(20); // Se inserta un nodo con el valor 20 al inicio de la lista.
	lista.insertarInicio(30); // Se inserta un nodo con el valor 30 al inicio de la lista, desplazando los nodos existentes.
	lista.insertarInicio(40); // Se inserta un nodo con el valor 40 al inicio de la lista, desplazando los nodos existentes.

	cout << "Lista doblemente encadenadas:" << endl; // Se imprime un mensaje indicando que se mostrará la lista después de las inserciones.
	lista.imprimirAdelante(); // Se llama al método para imprimir la lista desde la cabeza hasta el último nodo.
	lista.imprimirAtras(); // Se llama al método para imprimir la lista desde el último nodo hasta la cabeza.

	lista.eliminar(30); // Se elimina de la lista el nodo que contiene el valor 30.
	cout << "Despues de eliminar 30." << endl; // Se imprime un mensaje indicando que se mostrará la lista después de eliminar el nodo con valor 30.
	lista.imprimirAdelante(); // Se llama al método para imprimir la lista hacia adelante después de la eliminación.
	lista.imprimirAtras(); // Se llama al método para imprimir la lista hacia atrás después de la eliminación.

	return 0; // Indica que la ejecución del programa terminó correctamente.
}
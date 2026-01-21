#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> 

using namespace std;

class ArregloUnidimensional {
private:
    static const int CAPACIDAD_MAXIMA = 10;
    string elementos[CAPACIDAD_MAXIMA]; 
    int tamano;

public:
    ArregloUnidimensional() {
        this->tamano = 0;
    }

    void insertar(int indice, string nombre) {
        if (tamano == CAPACIDAD_MAXIMA) {
            throw runtime_error("Arreglo Lleno");
        }
        if (indice < 0 || indice > tamano) {
            throw out_of_range("Indice fuera de rango: " + to_string(indice));
        }

        if (nombre.empty()) return;

        for (int i = tamano; i > indice; i--) {
            elementos[i] = elementos[i - 1];
        }

        elementos[indice] = nombre; 
        tamano++;
    }

    string eliminar(int indice) {
        if (indice < 0 || indice >= tamano) { 
            throw out_of_range("Indice fuera de rango: " + to_string(indice));
        }

        string nombreEliminado = elementos[indice];

        for (int i = indice; i < tamano - 1; i++) {
            elementos[i] = elementos[i + 1];
        }

        elementos[tamano - 1] = ""; 
        tamano--;

        return nombreEliminado;
    }

    string obtener(int indice) {
        if (indice < 0 || indice >= tamano) {
            throw out_of_range("Indice fuera de rango: " + to_string(indice));
        }
        return elementos[indice];
    }

    int getTamano() {
        return tamano;
    }

    bool estaLleno() {
        return tamano == CAPACIDAD_MAXIMA;
    }

    void imprimir() {
        if (tamano == 0) {
            cout << "[] (arreglo vacio)" << endl;
            return;
        }
        cout << "[";
        for (int i = 0; i < tamano; i++) {
            cout << elementos[i];
            if (i < tamano - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    ArregloUnidimensional arr; 

    arr.insertar(0, "Hugo"); 
    arr.insertar(1, "Paco");
    arr.insertar(1, "Luis");
    arr.insertar(2, "Ana"); 
    arr.insertar(3, "Javier");
    arr.insertar(4, "Maria");
    arr.insertar(5, "Ena"); 
    arr.insertar(6, "Martha");
    arr.insertar(7, "Bertha");
    arr.insertar(8, "Gaby"); 

    cout << "Arreglo Lleno" << endl;
    arr.imprimir();

    try {
        arr.insertar(9, "Donald Trompas");
    } catch (const runtime_error& e) {
        cout << "\n " << e.what() << endl;
    } catch (const exception& e) {
        cout << "\n Error inesperado: " << e.what() << endl;
    }

    try {
        string eliminado = arr.eliminar(0);
        cout << "\nEliminado: " << eliminado << endl;
        arr.imprimir();

        arr.eliminar(4);
        cout << "Despues de eliminar indice 4" << endl;
        arr.imprimir();
    } catch (const exception& e) {
        cout << "Error al eliminar: " << e.what() << endl;
    }

    return 0;
}
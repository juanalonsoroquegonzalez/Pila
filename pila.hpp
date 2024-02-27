#ifndef __PILA_H__
#define __PILA_H__

#include <iostream>

using namespace std;

template<typename T, int MAX>

class pila
{
private:
    T Datos[MAX];
    int Tam;
    int ultimo;
    void Inserta(T dato, int posicion);
    void Busca(T dato);
    void Muestra();
    int ultimo_() const;
    T recupera(int posicion);
public:
    pila();
    void Inicializa(T dato, int ultimo);
    void Agrega(T dato);
    void Elimina(int posicion);
    bool Vacia() const;
    bool Llena() const;
    void push(T element);
    int pop();
    T top(int opc);
};

template<typename T, int MAX>
pila<T, MAX>::pila() : Tam(MAX), ultimo(-1) {
}

template<typename T, int MAX>
void pila<T, MAX>::Inicializa(T dato, int ultimo)
{
    
}

template<typename T, int MAX>
void pila<T, MAX>::Inserta(T dato, int posicion)
{
    if(Llena() || posicion < 0 || posicion > ultimo + 1) {
        cout << "\nError de insercion" << endl;
    } else {
        int i = ultimo + 1;
        while(i > posicion) {
            Datos[i] = Datos[i - 1];
            i--;
        }
        Datos[posicion] = dato;
        ultimo++;
        cout << "\nElemento insertado" << endl;
    }
}

template<typename T, int MAX>
void pila<T, MAX>::Agrega(T dato)
{
     if (Llena()) {
        cout << "No se pudo agregar el empleado porque la pila esta llena." << endl;
    } else {
        Datos[++ultimo] = dato;
        cout << "Empleado agregado exitosamente." << endl;
    }
}

template<typename T, int MAX>
void pila<T, MAX>::Busca(T dato)
{
    bool encontrado = false;
    for (int i = 0; i <= ultimo; ++i) {
        if (Datos[i] == dato) {
            encontrado = true;
            cout << "El elemento " << dato << " se encontro en la posicion " << i << "." << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "El elemento " << dato << " no se encontro en la pila." << endl;
    }
}

template<typename T, int MAX>
void pila<T, MAX>::Elimina(int posicion)
{
    if(Vacia() || posicion < 0 || posicion > ultimo) {
        cout << "Error de eliminacion" << endl;
    } else {
        int i = posicion;
        while(i < ultimo) {
            Datos[i] = Datos[i + 1];
            i++;
        }
        ultimo--;
        cout << "Elemento eliminado" << endl;
    }
}

template<typename T, int MAX>
T pila<T, MAX>::recupera(int posicion)
{
    if(Vacia() || posicion < 0 || posicion > ultimo) {
        cout << "\nInsuficiencia datos";
        return T();
    } else {
        return Datos[posicion];
    }
}

template<typename T, int MAX>
bool pila<T, MAX>::Vacia() const
{
    if(ultimo==-1)
        return true;
    return false;
}

template<typename T, int MAX>
bool pila<T, MAX>::Llena() const
{
    return (ultimo == Tam - 1);
}

template<typename T, int MAX>
void pila<T, MAX>::Muestra()
{
    if (Vacia()) {
        std::cout << "La pila esta vacia." << std::endl;
        return;
    }
    cout << endl;
    std::cout << "Elementos de la pila:" << std::endl;
    for (int i = 0; i <= ultimo; ++i) {
        cout << "Elemento #" << i << ":  "<< endl;
        cout << Datos[i] << endl;
    }
}

template<typename T, int MAX>
int pila<T, MAX>::ultimo_() const
{
    return ultimo;
}

template<typename T, int MAX>
void pila<T, MAX>::push(T element)
{
    Agrega(element);
}

template<typename T, int MAX>
int pila<T, MAX>::pop()
{
     Elimina(ultimo);
}

template<typename T, int MAX>
T pila<T, MAX>::top(int opc)
{
    if (Vacia()) {
        cout << "La pila esta vacia. No hay elementos en la cima." << endl;
        return -1; 
    }
    if(opc == 0){
        cout << "El tope de la pila es el dato: " << endl << Datos[ultimo] << endl;
        return 0;
    }else{
        return Datos[ultimo];   
    }
    return Datos[ultimo]; 
}


#endif // __PILA_H__
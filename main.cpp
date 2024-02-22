#include <iostream>
#include "pila.hpp"
#include "empleado.hpp"

int main()
{
    pila<int, 5> miPila;

    miPila.push(1);
    miPila.push(2);
    miPila.push(3);
    miPila.push(4);
    miPila.pop();
    miPila.top();
    miPila.Muestra();
    

    system("PAUSE");
}

#include <iostream>
#include "pila.hpp"
#include "empleado.hpp"

int main()
{
    pila<empleado, 5> miPila;

     int opcion;
    do {
        system("cls");
        cout << "----- MENU -----" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                {
                    if (miPila.Llena()) {
                        cout << "La pila esta llena." << endl;
                        break;
                    }else{
                        empleado empleadoInserta;
                        cout << "Ingresa el empleado: " << endl;
                        cin>>empleadoInserta;
                        miPila.push(empleadoInserta);
                    }
                }
                break;
            case 2:
             {
                    if (miPila.Vacia()) {
                        cout << "La pila esta vacia." << endl;
                        break;
                    }else{
                        empleado empleadoEliminar;
                        char elim;
                        cout << "Desea eliminar al empleado? \n" << miPila.top(1) << "?(s/n): ";
                        cin >> elim;
                        elim = toupper(elim);
                        if (elim == 'S') {
                            miPila.pop();
                        } else {
                            cout << "\nNo se elimino el empleado." << endl;
                        }

                    }
                }
                break;
            case 3:
                {
                    miPila.top(0);
                }
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Por favor, ingrese una opcion valida." << endl;
                break;
        }
        system("PAUSE");
    } while (opcion != 4);
}

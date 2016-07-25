#include <iostream>
#include <string>
using namespace std;

struct posicion {
    bool encontra;
    int pos;
};
void inicializararreglo(); //prototipo de la función inicializararreglo
int num_inicial_elementos(string names[1000]);
void menu();
void buscarnombre(); //prototipo de la función buscarnombre
void agregardatos();
void modificardatos();
void eliminardatos();
void ordenar_mostrar(); //prototipo de la función mostrar
posicion encontrado(string name);

int numelem, i;

struct amigos {
    string nombre;
    string direccion;
    string numtel;
    bool st;
} datos[1000];

int main() { //inicio del programa, función main

    inicializararreglo(); //se inicializa el arreglo de estructuras
    menu();

    return 0;
}

void inicializararreglo() {
    string nombres[1000] = {"Michel", "Daniel", "Maria", "Juan", "Claudia", "*"};
    string direcciones[1000] = {"CalleA", "CalleB", "CalleC", "CalleD", "CalleE"};
    string numeros[1000] = {"33001", "33002", "33003", "33004", "33005"};
    bool estatus[1000] = {1, 1, 1, 1, 1};

    numelem = num_inicial_elementos(nombres);


    for (i = 0; i < numelem; i++) {
        datos[i].nombre = nombres[i];
        datos[i].direccion = direcciones[i];
        datos[i].numtel = numeros[i];
        datos[i].st = estatus[i];
    }
}

int num_inicial_elementos(string names[1000]) {
    i = 0;
    int total;
    while (names[i] != "*")
        i++;
    total = i;
    return total;
}

void menu() {
    char opcion; //declaración de variables locales del main

    do {
        cout << "Menu:" << endl;
        cout << "1. Buscar nombre" << endl;
        cout << "2. Agregar Datos" << endl;
        cout << "3. Modificar Datos" << endl;
        cout << "4. Eliminar Datos" << endl;
        cout << "5. Mostrar Datos " << endl;
        cout << "6. Salir" << endl;
        cout << "Opción: ";
        cin>>opcion;

        switch (opcion) {
            case '1': buscarnombre();
                break;
            case '2': agregardatos();
                break;
            case '3': modificardatos();
                break;
            case '4': eliminardatos();
                break;
            case '5': ordenar_mostrar();
                break;
            case '6': cout << "Cerrando sistema" << endl;
                break;
            default: cout << "Opción erronea";
        }
    } while (opcion != '6');
}

void buscarnombre() { // cuerpo de la función buscarnombre

    string buscar; //declaración de las variables locales de la función buscarnombre
    //    int i;
    cout << "Dame el nombre a buscar: " << endl;
    cin >> buscar;


    posicion found1;
    found1 = encontrado(buscar);
    if (found1.encontra) {
        cout << "Dirección: " << datos[found1.pos].direccion << "\t";
        cout << "Teléfono: " << datos[found1.pos].numtel << "\n";
    } else
        cout << "No encontrado\n";


}

void agregardatos() {
    string nom;
    char opc;

    posicion validar; //nueva estructura

    do {
        cout << "Quieres agregar datos(S/N)" << endl;
        cin >> opc;

        if (opc == 's') {
            cout << "Dame nombre: ";
            cin >> nom;
            validar = encontrado(nom); //asignar una estructura a otra.
            if (validar.encontra)
                cout << "Ya existe!" << endl;
            else {
                datos[numelem].nombre = nom;
                cout << " Dame dirección y telefono (seguido de un enter): " << endl;
                cin >> datos[numelem].direccion >> datos[numelem].numtel;
                datos[numelem].st = true;
                numelem++;
            }
        }
    } while (opc != 'n');

}

void modificardatos() {
    string buscar;

    cout << "Dame el nombre que deseas modificar:  " << endl;
    cin >> buscar;

    posicion modificar;
    modificar = encontrado(buscar);


    if (modificar.encontra and datos[modificar.pos].nombre == buscar) {
        cout << "Modificar Calle: " << endl;
        cin >> datos[modificar.pos].direccion;
        cout << "Modificar Teléfono: " << endl;
        cin >> datos[modificar.pos].numtel;

    } else {
        cout << "No existe" << endl;
    }




}

void eliminardatos() {

    string eliminarnombre;

    cout << "Dame el nombre para eliminar: " << endl;
    cin >> eliminarnombre;

    posicion eliminar;
    eliminar = encontrado(eliminarnombre);

    if (eliminar.encontra and eliminarnombre == datos[eliminar.pos].nombre) {

        cout << "Dato eliminado. " << endl;

        datos[eliminar.pos].st = false;
    }
    else {
        cout << "No encontrado" << endl;
    }

}

void ordenar_mostrar() {

    int j;
    string key1, key2, key3;

    for (i = 0; i < numelem; i++) {
        for (j = 0; j < numelem - 1 - i; j++) {
            if (datos[j].nombre > datos[j + 1].nombre) {
                key1 = datos[j].nombre;
                key2 = datos[j].direccion;
                key3 = datos[j].numtel;
                datos[j].nombre = datos[j + 1].nombre;
                datos[j].direccion = datos[j + 1].direccion;
                datos[j].numtel = datos[j + 1].numtel;
                datos[j + 1].nombre = key1;
                datos[j + 1].direccion = key2;
                datos[j + 1].numtel = key3;
            }
        }
    }

    for (i = 0; i < numelem; i++) {
        if (datos[i].st == 1) {
            cout << datos[i].nombre << "\t";
            cout << datos[i].direccion << "\t";
            cout << datos[i].numtel << "\t";
            cout << "\n";
        }
    }
}

posicion encontrado(string name) {
    posicion encontrado1;
    encontrado1.encontra = false;
    i = 0;
    while (i < numelem && encontrado1.encontra == false) {
        if (name == datos[i].nombre && datos[i].st) {
            encontrado1.encontra = true;
            encontrado1.pos = i;

        }
        i++;
    }
    return encontrado1;
}
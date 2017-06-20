#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>

using namespace std;
int menu();
void mostrarContactos();
void agregarContacto();
void borrarContacto();
void editarContacto();
string sustituir(char original, char sustituto,string texto);
int main()
{

    int eleccion = 0;
    while(eleccion != 5){
        eleccion = menu();
        switch(eleccion){
            case 1:{
                mostrarContactos();
                break;
            }
            case 2:{
                agregarContacto();
                break;
            }
            case 3:{
                borrarContacto();
                break;
            }
            case 4:{
                editarContacto();
                break;
            }
        }
    }
    return 0;
}

void mostrarContactos(){
    ifstream Archivo("Agenda.txt");
    int id = 0;
    string nombre;
    string apellido;
    string telefono;
    string correo;

    while(Archivo >> nombre >> apellido >> telefono >> correo){
        id++;
        nombre = sustituir('_',' ', nombre);
        apellido = sustituir('_',' ', apellido);
        telefono = sustituir('_',' ', telefono);
        cout << id <<"."<< "Nombre: " << nombre <<"\nApellido: " << apellido << "\nTelefono: " << telefono << "\nCorreo: " <<correo <<"\n\n";
    }
    Archivo.close();

}

void agregarContacto(){
    ofstream Archivo("Agenda.txt", std::ios_base::app);
    string nombre;
    string apellido;
    string telefono;
    string correo;

    cout << "Introduce el Nombre :" <<endl;
    getline(cin, nombre);
    nombre = sustituir(' ','_',nombre);
    cout << "Introduce el Apellido :" <<endl;
    getline(cin, apellido);
    apellido = sustituir(' ','_',apellido);
    cout << "Introduce el Telefono :" <<endl;
    getline(cin, telefono);
    telefono = sustituir(' ','_',telefono);
    cout << "Introduce el Correo :" <<endl;
    getline(cin, correo);
    correo = sustituir(' ','_',correo);


    Archivo << nombre << ' ' <<  apellido << ' ' << telefono << ' ' << correo << endl;
    Archivo.close();
}
int menu(){
    int eleccion;
    cout<<"1. Listar contactos" <<endl;
    cout<<"2. Agregar contacto" <<endl;
    cout<<"3. Borrar contacto" <<endl;
    cout<<"4. Modificar contacto" <<endl;
    cout<<"5. Salir" << endl;
    cin >> eleccion;
    cin.ignore();
    cout << endl;
    return eleccion;
}

void borrarContacto(){
    mostrarContactos();
    int id;
    string nombre;
    string apellido;
    string telefono;
    string correo;
    ifstream entrada("Agenda.txt");
    ofstream salida("Resultado.txt");
    int contador = 1;

    cout << "Introduzca el Numero a eliminar: ";
    cin >> id;
    cin.ignore();
    while(entrada >> nombre >> apellido >> telefono >> correo){
        contador++;
        if((contador - 1) != id){
            salida<< nombre << ' ' <<  apellido << ' ' << telefono << ' ' << correo << endl;
        }
    }
    entrada.close();
    salida.close();
    remove("Agenda.txt");
    rename("Resultado.txt","Agenda.txt");
}

void editarContacto(){
    mostrarContactos();
    int id;
    string nombre;
    string apellido;
    string telefono;
    string correo;
    ifstream entrada("Agenda.txt");
    ofstream salida("Resultado.txt");
    int contador = 1;

    cout << "Introduzca el Numero a Modificar: ";
    cin >> id;
    cin.ignore();
    while(entrada >> nombre >> apellido >> telefono >> correo){
        contador++;
        if((contador - 1) == id){
                cout << "Introduce el nuevo nombre (anterior :" << nombre <<"): " <<endl;
                getline(cin, nombre);
                nombre = sustituir(' ','_',nombre);
                cout << "Introduce el nuevo apellido (anterior :" << apellido <<"): " <<endl;
                getline(cin, apellido);
                apellido = sustituir(' ','_',apellido);
                cout << "Introduce el nuevo telefono (anterior :" << telefono <<"): " <<endl;
                getline(cin, telefono);
                telefono = sustituir(' ','_',telefono);
                cout << "Introduce el nuevo correo (anterior :" << correo <<"): " <<endl;
                getline(cin, correo);
                correo = sustituir(' ','_',correo);
        }
            salida<< nombre << ' ' <<  apellido << ' ' << telefono << ' ' << correo << endl;

    }
    entrada.close();
    salida.close();
    remove("Agenda.txt");
    rename("Resultado.txt","Agenda.txt");
}
string sustituir(char original, char sustituto, string texto){
    for(int i = 0; i < texto.length();i++){
        if(texto[i] == original){
            texto[i] = sustituto;
        }
    }
    return texto;
}

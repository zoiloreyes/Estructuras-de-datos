#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
int menu();
void mostrarCanciones();
void AgregarCancion();
void MostrarActual();
void ProximaCancion();
void AnteriorCancion();
void ActivarRepeticion();
void EliminarCancion();
void buscar();
bool bucle = true;
struct cancion{
    string titulo;
    string artista;
    int duracion;
    struct cancion* siguiente;
    struct cancion* anterior;

}*inicio, *ultimo;
int contador = 0;
struct cancion *actual;

cancion* crearCancion(string titCancion, string ArtCancion, int durCancion){
        contador++;
        struct cancion *temp;
        temp = new(struct cancion);
        temp->titulo = titCancion;
        temp->artista = ArtCancion;
        temp->duracion = durCancion;
        temp->anterior = 0;
        temp->siguiente = 0;
        return temp;
}
void MostrarActual(){
    if(inicio == ultimo && inicio == 0){
        cout << "La lista esta vacias" <<endl<<endl;
        return;
    }else if(actual == 0){
        cout << "Para ver la primera cancion seleccione la cancion proxima"<<endl;
    }else{
        cout << "Titulo: "<< actual->titulo<<endl;
        cout << "Artista: "<< actual->artista<<endl;
        cout << "Duracion: "<< actual->duracion<<" segundos"<<endl<<endl;
    }
}
void ProximaCancion(){
    if(inicio == ultimo && inicio == 0){
        cout << "La lista esta vacias" <<endl<<endl;
        return;
    }else if(actual == 0){
        actual = inicio;
        cout<< "Reproduciendo "<<actual->titulo<<"..."<<endl<<endl;
    }else{
        if(actual == ultimo && !bucle){
            cout << "Final de la lista, Active bucle para continuar"<<endl<<endl;
            return;
        }
        actual = actual->siguiente;
        cout<<"Reproduciendo "<< actual->titulo<<"..."<<endl<<endl;
    }
}

void AnteriorCancion(){
    if(inicio == ultimo && inicio == 0){
        cout << "La lista esta vacias" <<endl<<endl;
        return;
    }else if(actual == 0){
        actual = inicio;
        cout<< "Reproduciendo "<<actual->titulo<<"..."<<endl<<endl;
    }else{
        if(actual == inicio && !bucle){
            cout << "Inicio de la lista, Active bucle para continuar"<<endl<<endl;
            return;
        }
        actual = actual->anterior;
        cout<<"Reproduciendo "<< actual->titulo<<"..."<<endl<<endl;
    }
}
void AgregarCancion(){
    string tituloIn;
    string artistaIn;
    int duracionIn;
    cout <<"Introduzca el titulo de la cancion"<<endl;
    getline(cin,tituloIn);
    cout << "Introduzca el artista de la cancion"<<endl;
    getline(cin,artistaIn);
    cout << "Introduzca la duracion en segundos"<<endl;
    cin >> duracionIn;
    cin.ignore();
    struct cancion *temp = crearCancion(tituloIn,artistaIn,duracionIn);

    if(inicio == ultimo && inicio == 0){
        cout<<"Primer elemento insertado"<<endl;
        inicio = ultimo = temp;
        inicio->siguiente = ultimo->siguiente = 0;
        inicio->anterior = ultimo->anterior = 0;
    }
    else{
        ultimo->siguiente = temp;
        temp->anterior = ultimo;
        ultimo = temp;
        inicio->anterior = ultimo;
        ultimo->siguiente = inicio;
    }
}
void mostrarCanciones(){
    int i;
    struct cancion *ini;
    if(inicio == ultimo && inicio == 0){
        cout << "La lista esta vacia"<<endl;
        return;
    }
    ini = inicio;
    for(i = 0; i < contador-1; i++){
        cout << "Titulo: "<< ini->titulo<<endl;
        cout << "Artista: "<< ini->artista<<endl;
        cout << "Duracion: "<< ini->duracion<<" segundos"<<endl<<endl;
        ini = ini->siguiente;
    }
    cout << "Titulo: "<< ini->titulo<<endl;
    cout << "Artista: "<< ini->artista<<endl;
    cout << "Duracion: "<< ini->duracion<<" segundos"<<endl<<endl;
}
void ActivarRepeticion(){
    if(bucle){
        bucle = false;
        cout<<"Bucle ha sido desactivado"<<endl<<endl;
    }else{
        cout<<"Bucle ha sido activado"<<endl<<endl;
        bucle = true;
    }
}
void EliminarCancion(){
    if(inicio == ultimo && inicio == 0){
        cout << "La lista esta vacia"<<endl;
        return;
    }else if(actual != 0){
        if(actual == ultimo && ultimo == inicio){
            contador--;
            actual = 0;
            ultimo = 0;
            inicio = 0;
            cout << "La lista esta vacia"<<endl<<endl;
        }else if(actual == inicio){
            contador--;
            ultimo->siguiente = actual->siguiente;
            actual->siguiente->anterior = ultimo;
            inicio = actual->siguiente;
            cout<<"Borrando "<< actual->titulo<< "..."<<endl<<endl;
            delete(actual);
            cout<<"Borrado"<<endl<<endl;
            actual = inicio;
            return;
        }else if(actual == ultimo){
            contador--;
            inicio->anterior = actual->anterior;
            actual->anterior->siguiente = inicio;
            ultimo = actual->anterior;
            cout<<"Borrando "<<actual->titulo<<"..."<<endl<<endl;
            delete(actual);
            cout<<"Borrado"<<endl<<endl;
            actual = ultimo;
            return;
        }else{
            struct cancion *temp = actual->siguiente;
            contador--;
            actual->siguiente->anterior = actual->anterior;
            actual->anterior->siguiente = actual->siguiente;

            cout<<"Borrando " <<actual->titulo<<"..."<<endl<<endl;
            delete(actual);
            cout<<"Borrado"<<endl<<endl;
            actual = temp;
            return;
        }
    }
}
int main()
{
    inicio = 0;
    ultimo = 0;
    actual = 0;
    int eleccion = 0;
    cout << "Bienvenido al sistema de vellonera" << endl;
    while(eleccion != 8){
        eleccion = menu();
        switch(eleccion){
            case 1:{
                mostrarCanciones();
                break;
            }
            case 2:{
                AgregarCancion();
                break;
            }
            case 3: {
                MostrarActual();
                break;
            }
            case 4: {
                ProximaCancion();
                break;
            }
            case 5: {
                AnteriorCancion();
                break;
            }
            case 6: {
                ActivarRepeticion();
                break;
            }
            case 7: {
                EliminarCancion();
                break;
            }

        }
    }
    return 0;
}

int menu(){
    int eleccion;
    cout<<"1. Ver canciones" <<endl;
    cout<<"2. Agregar cancion" <<endl;
    cout<<"3. Mostrar cancion actual" <<endl;
    cout<<"4. Proxima cancion" <<endl;
    cout<<"5. Cancion anterior" << endl;
    cout<<"6. Activar/Desactivar Repeticion en lista" << endl;
    cout<<"7. Eliminar" << endl;
    cout<<"8. Salir" << endl;
    cin >> eleccion;
    cin.ignore();
    cout << endl;
    return eleccion;
}

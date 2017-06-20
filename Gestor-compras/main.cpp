#include <iostream>
using namespace std;

struct nodo{
    int id;
    string articulo;
    int cantidad;
    nodo *siguiente;
};

bool isEmpty(nodo *head){
    if(head == NULL){
        return true;
    }else{
        return false;
    }
}
void agregarInicio(nodo *&head, nodo *&last,int id, string articulo, int cantidad){
    nodo *temp = new nodo;
    temp->id = id;
    temp->articulo = articulo;
    temp->cantidad = cantidad;
    temp->siguiente = NULL;
    head = temp;
    last = temp;
}

void agregar(nodo *&head, nodo *&last,int id, string articulo, int cantidad){
    if(isEmpty(head)){
        agregarInicio(head,last,id,articulo,cantidad);
    }else{
        nodo *temp = new nodo;
        temp->id = id;
        temp->articulo = articulo;
        temp->cantidad = cantidad;
        temp->siguiente = NULL;
        last->siguiente = temp;
        last = temp;
    }
}
void eliminar(nodo *&head, nodo *&last,int id, string articulo){
    if(isEmpty(head)){
        cout << "La lista esta vacia" <<endl ;
    }else if(head == last){
        delete head;
        head == NULL;
        last == NULL;
    }else{
        nodo *temp = head;
        head = head->siguiente;
        delete temp;
    }
}
struct nodo *buscarNodo(struct nodo *head, int id){
    nodo *actual = head;
    while(actual){
        if(actual->id == id) return actual;
        actual = actual->siguiente;
    }
    cout << "No existe el articulo " << id << " en la lista. \n";
}

bool borrarArticulo(nodo *&head,nodo *&last, nodo *objetivo){
    nodo *actual = head;
    if(isEmpty(actual))
        cout << "La lista esta vacia \n";
    else{
        while(actual){
            if(actual->siguiente == objetivo){
                if(objetivo == last){
                    last = actual;
                }
                actual->siguiente = objetivo->siguiente;
                cout << "Se borro el articulo " << objetivo->articulo << endl;
                delete objetivo;
                return true;
            }
            actual = actual->siguiente;
        }
        cout << "\n\n";
        return false;
    }
}
void mostrarLista(nodo *actual){
    if(isEmpty(actual))
        cout << "La lista esta vacia \n";
    else{
        while(actual != NULL){
            cout << actual->id <<". "<< actual->articulo << " " << actual->cantidad << "\n";
            actual = actual->siguiente;
        }
        cout << "\n\n";
    }
}

int main(){
    nodo *inicio = NULL;
    nodo *ultimo = NULL;
    char eleccion = 'a';
    int contador = 1;
    int id;
    string articulo = "";
    int cantidad = 0;
    while(eleccion != '4'){
        cout<< "1. Listar Articulos "<< endl;
        cout<< "2. Introducir articulo "<< endl;
        cout<< "3. Eliminar articulo "<< endl;
        cout<< "4. salir "<< endl;
        cout<< "Elija una opcion -> ";
        cin >> eleccion;
        cout << "\n\n";
        switch(eleccion){
        case '1':
            mostrarLista(inicio);
            break;
        case '2':
            cout << "Intoduce el nombre del articulo -> ";
            cin >> articulo;
            cout << "Introduce la cantidad de " << articulo << " -> ";
            cin >> cantidad;
            agregar(inicio, ultimo,contador,articulo,cantidad);
            contador++;
            break;
        case '3':
            mostrarLista(inicio);
            cout << "Elija un articulo a eliminar -> ";
            cin >> id;
            borrarArticulo(inicio,ultimo, buscarNodo(inicio, id));
            break;
        default:
            cout << "Saliendo...";
            return 0;
        }
    }
}

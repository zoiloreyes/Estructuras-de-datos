#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct libro{
    struct libro* proximo;
    string titulo;
    string autor;
    string editora;
    string fecha;
    string categoria;
};

libro *ultimo = nullptr;

void agregar(libro* _libro){
    _libro ->proximo = nullptr;
    if(ultimo == nullptr){
        ultimo = _libro;
    }else{
        _libro ->proximo = ultimo;
        ultimo = _libro;
    }
    cout <<endl<< "Libro agregado"<<endl;
}

libro* extraer(){
    if(ultimo == nullptr){
        return nullptr;
    }
    libro* retorno = ultimo;
    ultimo = retorno->proximo;

    return retorno;
}

void mostrarLibros(libro *ultimo){
    if(ultimo == nullptr){
        cout << "No hay libros" << endl;
    }
    while(ultimo != nullptr){

        cout <<endl<< "Titulo :" <<ultimo ->titulo <<endl;
        cout << "Autor :" <<ultimo ->autor <<endl;
        cout << "Fecha de Publicacion :" <<ultimo ->fecha <<endl;
        cout << "Editora :" <<ultimo ->editora <<endl;
        cout << "Categoria :" <<ultimo ->categoria <<endl;
        ultimo = ultimo->proximo;
    }
}

void buscarCategoria(string categoriaIn){
    while(ultimo != nullptr){
        if(ultimo->categoria == categoriaIn){
            cout <<endl<< "Titulo :" <<ultimo ->titulo <<endl;
            cout << "Autor :" <<ultimo ->autor <<endl;
            cout << "Fecha de Publicacion :" <<ultimo ->fecha <<endl;
            cout << "Editora :" <<ultimo ->editora <<endl;
            cout << "Categoria :" <<ultimo ->categoria <<endl;
        }else{
            cout << "Se ha removido el libro "<<ultimo->titulo <<", no cumple con el criterio de búsqueda"<<endl;
        }
        ultimo = ultimo->proximo;
    }
}
int main()
{
    char eleccion = 'a';
    string tituloIn;
    string autorIn;
    string editoraIn;
    string fechaIn;
    string categoriaIn;
    string filler;
    libro* prestado;
    while(eleccion != '5'){
        cout<< "1. Listar Libros "<< endl;
        cout<< "2. Insertar Libro "<< endl;
        cout<< "3. Solicitar ultimo libro de la pila "<< endl;
        cout<< "4. Buscar libro por categoria"<<endl;
        cout<< "5. salir "<< endl;
        cout<< "Elija una opcion => ";
        cin >> eleccion;
        //getline utilizará el cin a menos que se cierre
        getline(cin,filler);
        switch(eleccion){
        case '1':
            mostrarLibros(ultimo);
            break;
        case '2':
            {


            cout<<"Introduzca el titulo del libro : ";
            getline(cin, tituloIn);
            cout<<"Introduzca el autor del libro : ";
            getline(cin, autorIn);
            cout << "Introduzca la editora del libro: ";
            getline(cin, editoraIn);
            cout << "Introduzca la fecha de publicacion: ";
            getline(cin, fechaIn);
            cout << "Introduzca la categoria: ";
            getline(cin, categoriaIn);

            libro* nuevo = new libro;
            nuevo ->autor = autorIn;
            nuevo ->titulo = tituloIn;
            nuevo ->editora = editoraIn;
            nuevo ->fecha = fechaIn;
            nuevo ->categoria = categoriaIn;
            agregar(nuevo);
            break;
            }
        case '3':{
            prestado = extraer();
            if(prestado != nullptr){
                cout << "El libro " << prestado->titulo << " Ha sido prestado" <<endl;
                delete prestado;
            }else{
                cout << "No hay mas libros" <<endl;
            }
            break;
        }
        case '4':{
            cout << "Introduzca la categoria a buscar" <<endl;
            getline(cin, categoriaIn);
            buscarCategoria(categoriaIn);
            break;
        }
        }
    }
    return 0;
}

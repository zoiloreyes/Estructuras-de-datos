#include <iostream>

using namespace std;
class Persona{
private:
    Persona* siguiente;
    string nombre;
    Persona* primerHijo;
    Persona* ultimoHijo;
    int hijos;

public:
    void agregarHijo(Persona *nuevo);
    Persona* getHijos();
    Persona(string nombre);
    int getNumeroHijos();

    void setHijos(int hijos){
        this->hijos = hijos;
    }

     string& getNombre() {
        return nombre;
    }

    void setNombre(string nombre){
        this->nombre = nombre;
    }

    Persona*& getSiguiente(){
        return siguiente;
    }

    void setSiguiente( Persona*& siguiente){
        this->siguiente = siguiente;
    }
};


class Arbol{
private:
    Persona* raiz;
public:
    void recorrer(Persona* persona);
    void preparar(Persona* persona);
    Arbol(Persona* raiz);
    Persona*& getRaiz(){
        return raiz;
    }
    void setRaiz( Persona*& raiz){
        this->raiz = raiz;
    }
};

void Arbol::recorrer(Persona* persona){

    if(persona -> getNumeroHijos() > 0){
        cout << persona->getNombre()<<" es padre de: ";
        Persona* cont = persona->getHijos();
        while(cont != 0){
            cout<< cont->getNombre()<<" ";
            cont = cont->getSiguiente();
        }
        cout<<endl;
    }else{
        cout << persona->getNombre()<<" no tiene hijos"<<endl;
    }
    if(persona -> getNumeroHijos() > 0){
        Persona* i = persona -> getHijos();
        while(i != 0){
            recorrer(i);
            i = i-> getSiguiente();
        }
    }
}
void Arbol::preparar(Persona* persona){
    int numero = 0;
    string nombre;
    cout << "Cuantos hijos tiene "<< persona->getNombre()<<endl;
    cin >> numero;
    cin.ignore();
    if(cin){
        while(numero != 0){
            for(int i = 1; i <= numero; i++){
                cout<<"Introduzca el nombre del hijo numero "<<i<<" de "<<persona->getNombre()<<endl;
                getline(cin,nombre);
                Persona *nuevoHijo = new Persona(nombre);
                preparar(nuevoHijo);
                persona->agregarHijo(nuevoHijo);
            }
            numero = 0;
        }
    }
    return;

}

Arbol::Arbol(Persona* raiz){
    this->raiz = raiz;
}



void Persona::agregarHijo(Persona *nuevo){
    hijos++;
    if(primerHijo == 0){
        primerHijo = nuevo;
        ultimoHijo = nuevo;
    }else{
        ultimoHijo ->setSiguiente(nuevo);
        ultimoHijo = nuevo;
    }
}

Persona* Persona::getHijos(){
    return primerHijo;
}
int Persona::getNumeroHijos(){
    return hijos;
}
Persona::Persona(string nombre){
    this->nombre = nombre;
    this->siguiente = 0;
    this->primerHijo = 0;
    this->ultimoHijo = 0;
    hijos = 0;
}

int menu(){
    int eleccion = 0;
    cout<<"1. Crear Arbol" <<endl;
    cout<<"2. Desplegar arbol genealogico" <<endl;
    cout<<"3. Salir" <<endl;
    cin >> eleccion;
    cin.ignore();
    return eleccion;
}

Arbol* crearArbol(){
    string nombre;
    cout<<"Ingrese el nombre de la persona: "<<endl;
    getline(cin,nombre);
    Persona *raiz = new Persona(nombre);
    Arbol *genealgico = new Arbol(raiz);
    genealgico->preparar(raiz);
    return genealgico;
}

void mostrarArbol(Arbol* genealogico){
    if(genealogico == 0){
        cout << "El arbol esta vacio, Crea el arbol primero "<<endl<<endl;
        return;
    }
    genealogico -> recorrer(genealogico->getRaiz());
}
int main()
{
    Arbol* genealogico = 0;
    int eleccion = 0;
    cout<<"Arbol genealogico"<<endl<<endl;
    while(eleccion != 3){
        eleccion = menu();
        switch(eleccion){
            case 1:{
                genealogico = crearArbol();
                break;
            }
            case 2:{
                mostrarArbol(genealogico);

                break;
            }
        }
    }
    return 0;
}



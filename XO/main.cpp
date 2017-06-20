#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
char jugadoractual;
char tablero[3][3];
void inicializar(){
    cout << "Bienvenido al juego de TIC TAC TOE \n";
    srand (time(NULL));
    short inicio = rand() % 2 + 1;
    if(inicio == 1){
        cout << "x inicia!" << endl;
        jugadoractual = 'x';
    }else{
        jugadoractual = 'o';
        cout << "o inicia!" << endl << endl;
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            tablero[i][j] = ' ';
        }
    }
}
void desplegarTablero()
{
    for(int i = 0; i < 3; i++)
    {
        cout << "   ";
        for(int j = 0; j < 3; j++)
        {
            if(j != 0){
                cout << "|";
            }
            cout << tablero[i][j];
        }

        cout << endl;
        if(i != 2){
            cout << "   ";
            cout << "-----";
        }

        cout << endl;
    }
}
bool hayEmpate(){
    bool resultado = true;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tablero[i][j] == ' '){
                resultado = false;
            }
        }
    }
    if(resultado){
        cout << "Han empatado, una lastima" << endl;
    }
    return resultado;
}
bool hayGanador(){
    char actual = tablero[0][0];
    for(int i = 0; i < 3; i++){
        actual = tablero[i][0];
        for(int j = 0; j < 3; j++){
            if(tablero[i][j] == ' '){
                  break;
            }
            if(actual != tablero[i][j]){
                  actual = tablero[i][j];
                  break;
            }
            actual = tablero[i][j];
            if(j == 2){
                cout << "Ha ganado " << actual << endl;
                return true;
            }
        }
    }
    for(int i = 0; i < 3; i++){
          actual = tablero[0][i];
        for(int j = 0; j < 3; j++){
            if(tablero[j][i] == ' '){
                  break;
            }
            if(actual != tablero[j][i]){
                  break;
            }
            actual = tablero [j][i];
            if(j == 2){
                cout << "Ha ganado " << actual << endl;
                return true;
            }
        }
    }
    actual = tablero[0][0];
    for(int i = 0; i < 3; i++){
        if(tablero[i][i] == ' '){
              break;
        }
        if(actual != tablero[i][i]){
              break;
        }
        actual = tablero[i][i];
        if(i == 2){
            cout << "Ha ganado " << actual << endl;
            return true;
        }
    }
    actual = tablero[0][2];
    for(int i = 2, j=0; i >= 0, j < 3; i-- ,j++){
            if(tablero[j][i] == ' '){
                break; break;
            }
            if(actual != tablero[j][i]){
                break; break;
            }
            actual = tablero[j][i];
            if(i == 0){
                cout << "Ha ganado " << actual << endl;
                return true;
            }



    }
    return false;
}


int main()
{
    inicializar();
    short fila;
    short columna;
    while(!hayGanador() && !hayEmpate()){
        desplegarTablero();
        cout << "Tu turno " << jugadoractual << endl;
        cout << "En que fila quieres jugar " << jugadoractual << " ?" <<endl;
        cin >> fila;
        fila--;
        cout << "En que columna quieres jugar " << jugadoractual << " ?" <<endl;
        cin >> columna;
        columna--;
        if(fila >= 3 || columna >=3 || fila < 0 || columna < 0){
            cout << "Numero se sale de los limites, intenta de nuevo" << endl;
            continue;
        }
        if(tablero[fila][columna] != ' '){
            cout << "Ese espacio ya esta lleno" << endl;
        }else
        {
            tablero[fila][columna] = jugadoractual;
            if(jugadoractual == 'x'){
                jugadoractual = 'o';
            }else{
                jugadoractual = 'x';
            }
        }

    }
    desplegarTablero();
    return 0;
}

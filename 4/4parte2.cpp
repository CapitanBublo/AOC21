#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

bool comprobar_tablero(vector<vector<pair<int, bool>>> tablero){
    bool resuelto = false;
    for(int i=0; (i<5) && (!resuelto); i++){
        resuelto = true;
        for(int j=0; (j<5) && (resuelto); j++){
            if(tablero[i][j].second == false){
                resuelto = false;
            }
        }
        if(!resuelto){
            resuelto = true;
            for(int j=0; (j<5) && (resuelto); j++){
                if(tablero[j][i].second == false)
                resuelto = false;
            }
        }
    }
    return resuelto;
};

int obtener_resultado(vector<vector<pair<int, bool>>> tablero, int ultimo){
    int resultado = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(tablero[i][j].second == false){
                resultado += tablero[i][j].first;
            }
        }
    }

    return resultado * ultimo;
}

int main(int argc, char **argv){
    ifstream entrada;
    string numeros, numero;
    vector<int> bingo, ganadores;
    vector<pair<int, bool>> fila;
    vector<vector<pair<int, bool>>> tablero, perdedor;
    vector<vector<vector<pair<int, bool>>>> tableros;
    int num, ultimo = -1;

    entrada.open(argv[1]);

    getline(entrada, numeros);
    for(int i=0; i<numeros.size(); i++){
        if(numeros[i] != ','){
            numero.push_back(numeros[i]);
        }
        else if(numeros[i] == ','){
            bingo.push_back(stoi(numero));
            numero.clear();
        }
    }

    while(!entrada.eof()){
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                entrada >> num;
                fila.push_back(pair<int, bool>(num, false));
            }
            tablero.push_back(fila);
            fila.clear();
        }
        tableros.push_back(tablero);
        tablero.clear();
    }

    for(int i=0; (i<bingo.size()) && (ultimo == -1); i++){
        num = bingo[i];
        for(int j=0; (j<tableros.size()) && (ultimo == -1); j++){
            for(int k=0; k<5; k++){
                for (int h=0; h<5; h++){
                    if(tableros[j][k][h].first == num){
                        tableros[j][k][h].second = true;
                    }
                }
            }
            if(comprobar_tablero(tableros[j])){
                bool repe = false;
                for(vector<int>::iterator it=ganadores.begin(); it!=ganadores.end(); it++){
                    if(*it == j){
                        repe = true;
                    }
                }
                if(!repe){
                    ganadores.push_back(j);
                }
            }
        }
        if(ganadores.size() == tableros.size()){
            perdedor = tableros[ganadores.back()];
            ultimo = num;
        }
    }

    cout << obtener_resultado(perdedor, ultimo);
}
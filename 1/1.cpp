#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv){
    std::ifstream entrada;
    int valores, anterior, total = 0;

    entrada.open(argv[1]);

    entrada >> anterior;

    while(!entrada.eof()){
        entrada >> valores;
        if(valores > anterior){
            total++;
        }
        anterior = valores;
    }

    std::cout << total;

    return 0;
}
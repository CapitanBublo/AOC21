#include <iostream>
#include <fstream>
#include <vector>

int main (int argc, char **argv){
    unsigned int lanternfish[9] ={0}, aux = 0;
    std::ifstream entrada;
    std::string numeros;

    entrada.open(argv[1]);
    entrada >> numeros;
    for(int i=0; i<numeros.size(); i++){
        switch(numeros[i])
        {
        case '0':
            lanternfish[0]++;
            i++;
            break;
        case '1':
            lanternfish[1]++;
            i++;
            break;
        case '2':
            lanternfish[2]++;
            i++;
            break;
        case '3':
            lanternfish[3]++;
            i++;
            break;
        case '4':
            lanternfish[4]++;
            i++;
            break;
        case '5':
            lanternfish[5]++;
            i++;
            break;
        case '6':
            lanternfish[6]++;
            i++;
            break;
        default:
            i++;
            break;
        }
    }

    for(int i=0; i<256; i++){
        aux = lanternfish[0];
        lanternfish[0] = lanternfish[1];
        lanternfish[1] = lanternfish[2];
        lanternfish[2] = lanternfish[3];
        lanternfish[3] = lanternfish[4];
        lanternfish[4] = lanternfish[5];
        lanternfish[5] = lanternfish[6];
        lanternfish[6] = lanternfish[0] + lanternfish[7];
        lanternfish[7] = lanternfish[8];
        lanternfish[8] = aux;
    }

    std::cout << lanternfish[0] + lanternfish[1] + lanternfish[2] + lanternfish[3] + lanternfish[4] + lanternfish[5] + lanternfish[6] + lanternfish[7] + lanternfish[8];
}
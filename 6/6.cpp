#include <iostream>
#include <fstream>
#include <vector>

int main (int argc, char **argv){
    std::vector<int> lanternfish;
    std::ifstream entrada;
    std::string numeros;

    entrada.open(argv[1]);
    entrada >> numeros;
    for(int i=0; i<numeros.size(); i++){
        lanternfish.push_back(numeros[i]-48);
        i++;
    }

    for(int i=0; i<80; i++){
        int poblacion = lanternfish.size();
        for(int j=0; j<poblacion; j++){
            if(lanternfish[j] == 0){
                lanternfish.push_back(8);
                lanternfish[j] = 6;
            }
            else{
                lanternfish[j]--;
            }
        }
    }

    std::cout << lanternfish.size();
}
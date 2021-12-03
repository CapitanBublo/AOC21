#include<iostream>
#include<fstream>
#include<string>

int main(int argc, char **argv){
    std::ifstream entrada;
    int cantidad, pos_final[2] = {0,0};
    std::string direccion;

    entrada.open(argv[1]);

    while(!entrada.eof()){
        entrada >> direccion;
        entrada >> cantidad;
        if(direccion == "forward"){
            pos_final[0] += cantidad;
        }
        else if(direccion == "down"){
            pos_final[1] += cantidad;
        }
        else if(direccion == "up"){
            pos_final[1] -= cantidad;
        }
    }

    std::cout << (pos_final[0]*pos_final[1]);
    return 0;
}
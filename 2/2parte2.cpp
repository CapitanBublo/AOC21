#include<iostream>
#include<fstream>
#include<string>

int main(int argc, char **argv){
    std::ifstream entrada;
    int cantidad, aim = 0, pos_final[2] = {0,0};
    std::string direccion;

    entrada.open(argv[1]);

    while(!entrada.eof()){
        entrada >> direccion;
        entrada >> cantidad;
        if(direccion == "forward"){
            pos_final[0] += cantidad;
            pos_final[1] += (aim * cantidad);
        }
        else if(direccion == "down"){
            aim += cantidad;
        }
        else if(direccion == "up"){
            aim -= cantidad;
        }
    }

    std::cout << (pos_final[0]*pos_final[1]);
    return 0;
}
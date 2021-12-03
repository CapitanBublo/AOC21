#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char **argv){
    std::ifstream entrada;
    int vent_act, vent_sig, aux_escritura, total = 0;
    std::vector<int> datos;

    entrada.open(argv[1]);
    while(!entrada.eof()){
        entrada >> aux_escritura;
        datos.push_back(aux_escritura);
    }

    vent_act = datos[0] + datos[1] + datos[2];
    for(int offset=1; offset<datos.size()-2; offset++){
        vent_sig = datos[offset] + datos[offset+1] + datos[offset+2];
        if(vent_sig > vent_act){
            total++;
        }
        vent_act = vent_sig;
    }

    std::cout << total;
    return 0;
}
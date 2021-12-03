#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char **argv){
    std::ifstream entrada;
    std::string valores, gamma, epsilon;
    std::vector<std::string> datos;
    int longitud_palabra, cero , uno, pow2 = 1, valor_g = 0, valor_e = 0;

    entrada.open(argv[1]);

    while(!entrada.eof()){
        entrada >> valores;
        datos.push_back(valores);
    }

    longitud_palabra = datos[0].size();
    for(int i=0; i<longitud_palabra; i++){
        cero = 0;
        uno = 0;
        for(int j=0; j<datos.size(); j++){
            if(datos[j][i] == '0'){
                cero++;
            }
            else if(datos[j][i] == '1'){
                uno++;
            }
        }
        if(cero > uno){
            gamma.append("0");
            epsilon.append("1");
        }
        else if(uno > cero){
            gamma.append("1");
            epsilon.append("0");
        }
    }

    std::cout << "Valor gamma: " << gamma << "\n";
    std::cout << "Valor epsilor: " << epsilon << "\n";

    std::cout << (std::stoi(gamma, NULL, 2) * std::stoi(epsilon, NULL, 2)) << std::endl;
}
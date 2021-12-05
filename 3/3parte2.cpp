#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string encontrar_O2(std::vector<std::string> datos){
    while (datos.size() != 1){
        int longitud_palabra, cero, uno;
        std::vector<std::string> p0, p1;

        longitud_palabra = datos[0].size();
        for (int i = 0; i < longitud_palabra; i++){
            cero = 0;
            uno = 0;
            p0.clear();
            p1.clear();
            for (int j = 0; j < datos.size(); j++){
                if (datos[j][i] == '0'){
                    cero++;
                    p0.push_back(datos[j]);
                }
                else if (datos[j][i] == '1'){
                    uno++;
                    p1.push_back(datos[j]);
                }
            }
            if (cero > uno){
                datos = p0;
            }
            else if (uno >= cero){
                datos = p1;
            }
        }
    }
    return datos[0];
}

std::string encontrar_CO2(std::vector<std::string> datos){
    while (datos.size() != 1){
        int longitud_palabra, cero, uno;
        std::vector<std::string> p0, p1;

        longitud_palabra = datos[0].size();
        for (int i = 0; ((i < longitud_palabra) && (datos.size() != 1)); i++){
            cero = 0;
            uno = 0;
            p0.clear();
            p1.clear();
            for (int j = 0; j < datos.size(); j++){
                if (datos[j][i] == '0'){
                    cero++;
                    p0.push_back(datos[j]);
                }
                else if (datos[j][i] == '1'){
                    uno++;
                    p1.push_back(datos[j]);
                }
            }
            if (cero > uno){
                datos = p1;
            }
            else if (uno >= cero){
                datos = p0;
            }
        }
    }
    return datos[0];
}

int main(int argc, char **argv)
{
    std::ifstream entrada;
    std::string valores, O2, CO2;
    std::vector<std::string> datos;
    int iteracion = 1;

    entrada.open(argv[1]);

    while (!entrada.eof())
    {
        entrada >> valores;
        datos.push_back(valores);
    }

    O2 = encontrar_O2(datos);
    iteracion = 1;
    CO2 = encontrar_CO2(datos);

    std::cout << "Valor O2: " << O2 << "\n";
    std::cout << "Valor CO2: " << CO2 << "\n";

    std::cout << (std::stoi(O2, NULL, 2) * std::stoi(CO2, NULL, 2)) << std::endl;
}
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    // 1. Validar argumentos según el subject (debe recibir exactamente 1 archivo)
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange btc;

        // 2. Cargar la base de datos oficial
        btc.LoadDatabase("data.csv");

        // 3. Procesar el archivo pasado por parámetro (ej: input.txt)
        btc.ProcessInput(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
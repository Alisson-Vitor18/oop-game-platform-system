#include <stdexcept>
#include <iostream>
#include <string>
#include "Plataforma.h"
#include "SalaDeJogo.h"
#include "Jogador.h"
#include "Perfil.h"
#include "Jogo.h"

void menuPlataforma();
int lerInt(const std::string msg);

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int opt;
    std::string nomePlataforma;
    std::vector <Plataforma> plataformas;

    do {   
        menuPlataforma();
        opt = lerInt("Informe um número do tipo inteiro: ");
        std::cout<<std::endl;

        switch (opt)
        {
        case 1: {
            std::cout << "Informe o nome da plataforma: ";
            std::getline(std::cin, nomePlataforma);

            Plataforma plataforma(nomePlataforma);
            plataformas.push_back(plataforma);

            std::cout << std::endl;
            std::cout << "\033[1;32mPlataforma criada com sucesso!\033[0m\n";
            break;
        }
        
        default:
            break;
        }

    }while(opt != 3);

    return 0;
}

void menuPlataforma() {
    std::cout << std::endl;
    std::cout << "1. Criar uma plataforma." << std::endl;
    std::cout << "2. Entrar em uma plataforma." << std::endl;
    std::cout << "3. Suporte." << std::endl;
    std::cout << "4. Sair." << std::endl;
    std::cout << std::endl;
}

int lerInt(const std::string msg) {
    while(true) {
        try {
            std::string entrada;

            std::cout << msg;
            std::getline(std::cin, entrada);

            size_t pos;
            int valor = std::stoi(entrada, &pos);

            if(pos != entrada.size()) {
                std::cerr << "\nErro: existem caracteres inválidos na entrada.\n\n";
                continue;
            }

            return valor;

        } catch(const std::invalid_argument&) {
            std::cerr << "\nErro capturado: você não digitou um número válido do tipo inteiro.\n" << std::endl;   
        } catch(const std::out_of_range&) {
            std::cerr << "\nErro: número fora do intervalo de int permitido para este compilador, " << 
                  "para saber com precisão os intervalos permitidos constulte a opção 3 (Suporte) do menu inicial.\n" << std::endl;
        }
    }
}
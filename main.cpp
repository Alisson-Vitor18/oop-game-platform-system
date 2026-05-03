#include <stdexcept>
#include <iostream>
#include <limits>
#include <string>
#include "Plataforma.h"
#include "SalaDeJogo.h"
#include "Jogador.h"
#include "Perfil.h"
#include "Jogo.h"

void menuPlataforma();
void menuSalaDeJogo();
void menuDeJogos(const std::string& nome);
void listarPlataformasDisponiveis(const std::vector <Plataforma>& p);
int lerInt(const std::string& msg);

int main(void) {
    setlocale(LC_ALL, ".UTF-8");

    int optPlataforma = 0;
    int optSalaDeJogos = 0;
    int optJogos = 0;
    std::string nomePlataforma;
    std::vector <Plataforma> plataformas;

    do {   
        menuPlataforma();
        optPlataforma = lerInt("Informe uma opção: ");
        std::cout<<std::endl;

        switch (optPlataforma)
        {
        case 1: {
            std::cout << "Informe o nome da plataforma: ";
            std::getline(std::cin, nomePlataforma);

            try{
                plataformas.emplace_back(nomePlataforma);
            } catch(const std::exception& e) {
                std::cout<<std::endl;
                std::cout << "\033[1;31mErro capturado: "<< e.what() <<"\033[0m"<< std::endl;
                break;
            }

            std::cout << std::endl;
            std::cout << "\033[1;32mPlataforma criada com sucesso!\033[0m\n";
            break;
        }

        case 2: {
            if(plataformas.empty()) {
                std::cout << "\033[1;31mNenhuma plataforma registrada! Use a opção 1 para criar uma nova plataforma.\033[0m" << std::endl;
                break;
            }
            std::cout << "\033[1;32mPlataformas disponíveis...\033[0m\n" << std::endl;
            listarPlataformasDisponiveis(plataformas);

            std::cout << std::endl;
            int indexPlataforma = lerInt("Informe o índice da plataforma que deseja entrar: ");

            if(indexPlataforma <= 0 || static_cast<size_t>(indexPlataforma) > plataformas.size()) {
                std::cout << "\033[1;31m\nO índice informado não está associado a nenhuma plataforma registrada!\033[0m" << std::endl;
                break;
            }

            do {
                menuSalaDeJogo();
                optSalaDeJogos = lerInt("Informe uma opção: ");
                std::cout << std::endl;

                switch (optSalaDeJogos)
                {
                case 1: {
                    std::string nomeSala;
                    std::string nomeJogo;
                    std::string categoria;

                    std::cout << "Informe o nome da sala que deseja criar: ";
                    std::getline(std::cin, nomeSala);

                    std::cout << "Informe o nome do jogo que será exibido nessa sala: ";
                    std::getline(std::cin, nomeJogo);

                    std::cout << "Informe a categoria do jogo: ";
                    std::getline(std::cin, categoria);
                    
                    try {
                        Jogo jogo(nomeJogo, categoria);
                        plataformas.at(indexPlataforma - 1).adicionarSala(nomeSala, jogo);
                    }catch(const std::exception& e) {
                        std::cout << "\033[1;31m\nErro capturado: "<< e.what() <<"\033[0m"<< std::endl;
                        break;
                    }

                    std::cout << "\033[1;32mSala criada com sucesso!\033[0m\n";
                    break;
                }
                
                case 2: {
                    if(plataformas.at(indexPlataforma - 1).qntdSalas() == 0) {
                        std::cout << "\033[1;31mNenhuma sala registrada nessa plataforma! Use a opção 1 para criar uma sala.\033[0m" << std::endl;
                        break;
                    }
                    std::cout << "\033[1;32mSalas disponíveis...\033[0m\n" << std::endl;
                    plataformas.at(indexPlataforma - 1).listarSalas();
                    std::cout << std::endl;

                    int indexSalaDeJogos = lerInt("Informe o índice da sala que deseja entrar: ");

                    if(indexSalaDeJogos <= 0 || static_cast<size_t>(indexSalaDeJogos) > plataformas.at(indexPlataforma - 1).qntdSalas()) {
                        std::cout << "\033[1;31m\nO índice informado não está associado a nenhuma sala registrada!\033[0m" << std::endl;
                        break;
                    }

                    do {
                        menuDeJogos(plataformas.at(indexPlataforma - 1).obtemNomeDoJogo(indexSalaDeJogos));
                        optJogos = lerInt("Informe uma opção: ");
                        std::cout << std::endl;

                        switch(optJogos) {
                            case 1:
                                std::cout << "Reproduzindo " << plataformas.at(indexPlataforma - 1).obtemNomeDoJogo(indexSalaDeJogos) << "...\n"<<std::endl;
                                std::cout << "\033[1;31mPressione 'enter' para encerrar!\033[0m" << std::endl;
                                std::cin.get();
                                std::cout << "\033[1;32mJogo Encerrado!\033[0m" << std::endl;
                                break;

                        }

                    }while(optJogos != 4);

                    break;
                }
                
                default:
                    break;
                }

            }while(optSalaDeJogos != 3);

            break;
        }
        
        default:
            break;
        }

    }while(optPlataforma != 4);

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

void menuSalaDeJogo() {
    std::cout << std::endl;
    std::cout << "1. Criar uma sala." << std::endl;
    std::cout << "2. Entrar em uma sala" << std::endl;
    std::cout << "3. Voltar ao menu de Plataformas." << std::endl;
    std::cout << std::endl;
}

void menuDeJogos(const std::string& nome) {
    std::cout << std::endl;
    std::cout << "1. Jogar " << nome << "."<<std::endl;
    std::cout << "2. Adicionar jogadores." << std::endl;
    std::cout << "3. Listar jogadores." << std::endl;
    std::cout << "4. Voltar ao menu de Salas." << std::endl;
    std::cout << std::endl;
}

void listarPlataformasDisponiveis(const std::vector <Plataforma>& p) {
    size_t i = 0;
    for(const Plataforma& plataforma : p) {
        std::cout << ++i << ". " << plataforma.getNome() << std::endl;
    }
}

int lerInt(const std::string& msg) {
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
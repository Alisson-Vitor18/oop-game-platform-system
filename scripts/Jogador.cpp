#include <iostream>
#include "Jogador.h"
#include "Perfil.h"

Jogador::Jogador(const Perfil& perfil) 
    : perfilJogador(perfil) {}

void Jogador::exibirDados() const {
    std::cout << "\nNome do perfil: " << this->perfilJogador.getNome() << std::endl;
    std::cout << "Ranking do jogador: "<< this->perfilJogador.getRanking() << std::endl;
    
    std::cout << "Conquistas: ";
    for(int i = 0; i < this->perfilJogador.getConquistas().size(); i++) {
        std::cout << this->perfilJogador.getConquistas().at(i) << std::endl;
    }
    std::cout << std::endl;
}
#include <iostream>
#include <stdexcept>
#include "Plataforma.h"

Plataforma::Plataforma(const std::string& nome) {
    setNome(nome);
}

void Plataforma::setNome(std::string nome) {
    if(nome.empty()) {
        throw std::invalid_argument("Nome da plataforma não pode ser vazio.");
    }

    this->nome = nome;
}

std::string Plataforma::getNome() const {
    return this->nome;
}

void Plataforma::adicionarSala(const std::string& nomeSala, int maxParticipantes,const Jogo& jogo) {
    this->salas.emplace_back(nomeSala, maxParticipantes,jogo);
}

void Plataforma::listarSalas() {
    size_t i = 0;
    for(SalaDeJogo sala : salas) {
        std::cout << ++i << ". " << sala.getNomeSala() << std::endl;
    }
}

std::string Plataforma::obtemNomeDoJogo(int index) {
    return this->salas.at(index - 1).getNomeJogoAtual();
}

size_t Plataforma::qntdSalas() {
    return this->salas.size();
}

SalaDeJogo& Plataforma::encontrarSala(int index) {
    return salas.at(index - 1);
}
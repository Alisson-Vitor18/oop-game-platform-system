#include <iostream>
#include <stdexcept>
#include "Plataforma.h"

Plataforma::Plataforma(std::string nome) {
    setNome(nome);
}

void Plataforma::setNome(std::string nome) {
    if(nome.empty()) {
        std::invalid_argument("Nome da plataforma não pode ser vazio.");
    }
    this->nome = nome;
}

std::string Plataforma::getNome() {
    return this->nome;
}

void Plataforma::adicionarSala(const SalaDeJogo& sala) {
    this->salas.push_back(sala);
}
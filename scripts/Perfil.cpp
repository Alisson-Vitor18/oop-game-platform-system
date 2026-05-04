#include <iostream>
#include <stdexcept>
#include "Perfil.h"

Perfil::Perfil(const std::string& nome, const int& ranking) {
    setNome(nome);
    setRanking(ranking);
}

void Perfil::setNome(std::string nome) {
    if(nome.empty()) {
        throw std::invalid_argument("Nome do perfil não pode ser vazio!");
    }
    this->nome = nome;
}

void Perfil::setConquista(std::string conquista) {
    if(conquista.empty()) {
        throw std::invalid_argument("A conquista não pode estar vazia!");
    }
    this->conquistas.push_back(conquista);
}

void Perfil::setRanking(int ranking) {
    if(ranking < 0) {
        throw std::invalid_argument("Ranking não pode ser menor que zero!");
    }

    this->ranking = ranking;
}

std::string Perfil::getNome() const {
    return this->nome;
}

std::vector<std::string> Perfil::getConquistas() const {
    return this->conquistas;
}

int Perfil::getRanking() const {
    return this->ranking;
}
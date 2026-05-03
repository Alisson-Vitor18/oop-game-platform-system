#include <iostream>
#include <stdexcept>
#include "Jogo.h"
#include "Jogador.h"
#include "SalaDeJogo.h"

SalaDeJogo::SalaDeJogo(const std::string& nome, const Jogo& jogo)
    : jogoAtual(jogo) 
    {
        setNomeSala(nome);
    }

void SalaDeJogo::setNomeSala(std::string nomeSala) {
    if(nomeSala.empty()) {
        throw std::invalid_argument("Nome da sala não pode ser vazio!");
    }
    this->nomeSala = nomeSala;
}

void SalaDeJogo::setMaxParticipantes(int maxParticipantes) {
    if(maxParticipantes <= 0) {
        std::invalid_argument("O máximo de participantes precisa ser maior que zero");
    }
    this->maxParticipantes = maxParticipantes;
}

std::string SalaDeJogo::getNomeSala() {
    return this->nomeSala;
}

std::string SalaDeJogo::getNomeJogoAtual() {
    return this->jogoAtual.getTitulo();
}

int SalaDeJogo::getMaxParticipantes() {
    return this->maxParticipantes;
}

void SalaDeJogo::adicionarJogador(const Jogador& jogador) {
    this->jogadores.push_back(jogador);
}
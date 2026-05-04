#include <iostream>
#include <stdexcept>
#include "Jogo.h"
#include "Jogador.h"
#include "SalaDeJogo.h"

SalaDeJogo::SalaDeJogo(const std::string& nome, int maxParticipantes,const Jogo& jogo)
    : jogoAtual(jogo) 
    {
        setNomeSala(nome);
        setMaxParticipantes(maxParticipantes);
        this->participantes = 0;
    }

void SalaDeJogo::setNomeSala(const std::string& nomeSala) {
    if(nomeSala.empty()) {
        throw std::invalid_argument("Nome da sala não pode ser vazio!");
    }
    this->nomeSala = nomeSala;
}

void SalaDeJogo::setMaxParticipantes(int maxParticipantes) {
    if(maxParticipantes <= 0) {
        throw std::invalid_argument("O máximo de participantes precisa ser maior que zero");
    }
    this->maxParticipantes = maxParticipantes;
}

void SalaDeJogo::incrementaParticipantes() {
    this->participantes++;
}

int SalaDeJogo::getParticipantes() {
    return this->participantes;
}

std::string SalaDeJogo::getNomeSala() const {
    return this->nomeSala;
}

std::string SalaDeJogo::getNomeJogoAtual() const {
    return this->jogoAtual.getTitulo();
}

int SalaDeJogo::getMaxParticipantes() const {
    return this->maxParticipantes;
}

void SalaDeJogo::adicionarJogador(const Jogador& jogador) {
    this->jogadores.push_back(jogador);
}

void SalaDeJogo::exibirJogadores() {
    for(const Jogador& jogador : this->jogadores) {
        jogador.exibirDados();
    }
}
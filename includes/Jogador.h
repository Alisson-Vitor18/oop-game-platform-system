#ifndef JOGADOR_H
#define JOGADOR_H

#include "Perfil.h"

class Jogador {
    private:
        Perfil perfilJogador;

    public:
        //Construtor para a classe Jogador
        Jogador(const Perfil& perfil);

        //Exibe o perfil do jogador
        void exibirDados() const;

        //Adiciona uma nova conquista ao perfil
        void adicionarConquista(const std::string& conquista);
};

#endif
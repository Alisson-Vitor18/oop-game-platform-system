#ifndef JOGADOR_H
#define JOGADOR_H

#include "Perfil.h"

class Jogador {
    private:
        Perfil perfilJogador;

    public:
        //Construtor para a classe Jogador
        Jogador(const Perfil& perfil);
};

#endif
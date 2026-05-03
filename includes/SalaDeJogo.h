#ifndef SALADEJOGO_H
#define SALADEJOGO_H

#include "Jogo.h"
#include "Jogador.h"
#include <vector>

class SalaDeJogo {
    private:    
        std::vector<Jogador> jogadores;
        Jogo jogoAtual;
        std::string nomeSala;
        int maxParticipantes;

    public:
        //Construtor da classe Sala de Jogo
        SalaDeJogo(const std::string& nome, const Jogo& jogo);

        //Informa o nome da sala 
        void setNomeSala(std::string nomeSala);

         //Informa o máximo de participantes
        void setMaxParticipantes(int maxParticipantes);
        
        //Obtém o nome da sala
        std::string getNomeSala();

        //Obtém o número máximo de participantes
        int getMaxParticipantes();

        //Adiciona jogador à sala de jogos
        void adicionarJogador(const Jogador& jogador);
};

#endif
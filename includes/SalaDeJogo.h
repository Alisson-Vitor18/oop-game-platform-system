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
        int participantes;

    public:
        //Construtor da classe Sala de Jogo
        SalaDeJogo(const std::string& nome, int maxParticipantes,const Jogo& jogo);

        //Informa o nome da sala 
        void setNomeSala(const std::string& nomeSala);

         //Informa o máximo de participantes
        void setMaxParticipantes(int maxParticipantes);

        //Informa um participante para a sala
        void incrementaParticipantes();

        //Obtém a quantidade de participantes na sala
        int getParticipantes();
        
        //Obtém o nome da sala
        std::string getNomeSala() const;

        //Obtém o nome do jogo
        std::string getNomeJogoAtual() const;

        //Obtém o número máximo de participantes
        int getMaxParticipantes() const ;

        //Adiciona jogador à sala de jogos
        void adicionarJogador(const Jogador& jogador);

        //Exibe os jogadores na sala escolhida
        void exibirJogadores();
};

#endif
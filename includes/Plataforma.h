#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include "SalaDeJogo.h"
#include <vector>
#include <string>

class Plataforma {
    private:
        std::vector<SalaDeJogo> salas;
        std::string nome;

    public:
        //Construtor para classe Plataforma
        Plataforma(const std::string& nome);

        //Informa o nome da plataforma
        void setNome(std::string nome);

        //Obtém o nome da plataforma
        std::string getNome() const;

        //Adiciona uma sala à plataforma
        void adicionarSala(const std::string& nomeSala, int maxParticipantes,const Jogo& jogo);

        //Lista as salas cadastradas à plataforma
        void listarSalas();

        //Obtém o nome do jogo
        std::string obtemNomeDoJogo(int index);

        //Retorna a quantidade de salas na plataforma
        size_t qntdSalas();

        //Encontra uma sala específica na plataforma
        SalaDeJogo& encontrarSala(int index);
};

#endif
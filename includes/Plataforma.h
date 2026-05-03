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
        Plataforma(std::string nome);

        //Informa o nome da plataforma
        void setNome(std::string nome);

        //Obtém o nome da plataforma
        std::string getNome();

        //Adiciona uma sala à plataforma
        void adicionarSala(const SalaDeJogo& sala);
};

#endif
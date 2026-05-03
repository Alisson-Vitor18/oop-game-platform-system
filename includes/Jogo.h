#ifndef JOGO_H
#define JOGO_H


#include <string>

class Jogo {
    private:
        std::string titulo;
        std::string categoria;

    public:
        //Construtor da classe Jogo
        Jogo(const std::string& titulo, const std::string& categoria);

        //Informa o título do jogo
        void setTitulo(std::string titulo);

        //Informa a categoria do jogo
        void setCategoria(std::string categoria);

        //Obtém o título do jogo atual
        std::string getTitulo();

        //Obtém a categoria do jogo atual
        std::string getCategoria();

};

#endif
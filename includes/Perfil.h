#ifndef PERFIL_H
#define PERFIL_H

#include <vector>
#include <string>

class Perfil{
    private:
        std::string nome;
        int ranking;
        std::vector <std::string> conquistas;
    
    public:
        //Construtor para a classe Perfil
        Perfil(const std::string& nome);

        //Informa o nome do perfil
        void setNome(std::string nome);

        //Informa uma nova conquista
        void setConquista(std::string conquista);

        //Informa o ranking do perfil
        void setRanking(int ranking);

        //Obtém o nome do perfil
        std::string getNome() const;

        //Obtém as conquistas atual do perfil
        std::vector<std::string> getConquistas() const; 

        //Obtém o ranking atual do perfil
        int getRanking() const;
};

#endif
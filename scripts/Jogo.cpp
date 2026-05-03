#include <iostream>
#include <stdexcept>
#include "Jogo.h"

Jogo::Jogo(const std::string& titulo, const std::string& categoria) {    
    setTitulo(titulo);
    setCategoria(categoria); 
}

void Jogo::setTitulo(std::string titulo) {
    if(titulo.empty()) {
        std::invalid_argument("Nome do jogo não pode ser vazio!");
    }
    this->titulo = titulo;
}

void Jogo::setCategoria(std::string categoria) {
    if(categoria.empty()) {
        std::invalid_argument("Categoria do jogo não pode ser vazio!");
    }
    this->categoria = categoria;
}

std::string Jogo::getTitulo() {
    return this->titulo;
}

std::string Jogo::getCategoria() {
    return this->categoria;
}
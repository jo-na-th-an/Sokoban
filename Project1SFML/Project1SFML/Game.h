#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Grid.h"

class Game {
private:
    sf::RenderWindow window;  // Ventana principal del juego
    Grid grid;                // Instancia de la clase Grid para manejar el tablero del juego
    int nivelSeleccionado;    // Variable para el nivel seleccionado

public:
    Game();  // Constructor
    void run();  // M�todo para ejecutar el juego
    void handleEvents();  // M�todo para manejar eventos
    void showMenu();  // Mostrar el men� y seleccionar nivel
};

#endif�//�GAME_H
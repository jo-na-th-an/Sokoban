#ifndef GRID_H
#define GRID_H
#include <SFML/Graphics.hpp>
#include "GridNode.h"
#include <string>

class Grid {
private:
    GridNode* head; // Pointer to the first node of the grid
    int rows, cols; // Dimensions of the grid
    // Textura para la caja
    sf::Texture boxTexture;
    sf::Sprite boxSprite;  // Sprite para la caja
    sf::Texture wallTexture;  // Textura para la pared
    sf::Sprite wallSprite;    // Sprite para la pared
    sf::Texture personajeText;
    sf::Sprite personaje;
    // Fuente para el texto
    sf::Font font;
public:
    Grid();
    ~Grid();
    void loadLevelFromFile(const std::string& filename);
    void printGrid();
    void draw(sf::RenderWindow& window, int cellSize);  // Dibujar el tablero en la ventana SFML


    void loadTextures();
    void drawMenu(sf::RenderWindow& window);
    int handleMenu(sf::RenderWindow& window);
};

#endif // GRID_H
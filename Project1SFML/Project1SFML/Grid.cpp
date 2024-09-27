#include "Grid.h"
#include <iostream>
#include <fstream>
#include <sstream> // Include for stringstream

Grid::Grid() : head(nullptr), rows(0), cols(0) {
    loadTextures();
}

Grid::~Grid() {
    GridNode* currentRow = head;
    while (currentRow != nullptr) {
        GridNode* currentNode = currentRow;
        while (currentNode != nullptr) {
            GridNode* nextNode = currentNode->getNext();
            delete currentNode;
            currentNode = nextNode;
        }
        GridNode* nextRow = currentRow->getDown();
        delete currentRow;
        currentRow = nextRow;
    }
}

void Grid::loadLevelFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::string line;
    GridNode* lastRow = nullptr;

    while (std::getline(file, line)) {
        if (line.empty()) {
            break; // End of grid when an empty line is found
        }

        GridNode* currentRow = nullptr;
        GridNode* lastNodeInRow = nullptr;

        for (char symbol : line) {
            GridNode* newNode = new GridNode(symbol);
            if (currentRow == nullptr) {
                currentRow = newNode;
            }
            else {
                lastNodeInRow->setNext(newNode);
            }
            lastNodeInRow = newNode;
        }

        if (lastRow == nullptr) {
            head = currentRow;
        }
        else {
            GridNode* temp = lastRow;
            while (temp->getDown() != nullptr) {
                temp = temp->getDown();
            }
            temp->setDown(currentRow);
        }
        lastRow = currentRow;
        ++rows;
        cols = line.length();
    }

    file.close();
}

void Grid::draw(sf::RenderWindow& window, int cellSize) {
    GridNode* currentRow = head;
    int y = 0;

    // Calcular el ancho y alto total del grid
    int gridWidth = cols * cellSize;
    int gridHeight = rows * cellSize;

    // Calcular las coordenadas para centrar el grid
    int offsetX = (window.getSize().x - gridWidth) / 2;
    int offsetY = (window.getSize().y - gridHeight) / 2;

    while (currentRow) {
        GridNode* currentNode = currentRow;
        int x = 0;

        while (currentNode) {
            if (currentNode->getSymbol() == '$') {
                // Configurar el sprite de la caja
                boxSprite.setPosition(offsetX + x * cellSize, offsetY + y * cellSize);
                boxSprite.setScale(cellSize / boxSprite.getLocalBounds().width, cellSize / boxSprite.getLocalBounds().height);
                window.draw(boxSprite);
            }
            else if (currentNode->getSymbol() == '#') {
                // Configurar el sprite de la pared
                wallSprite.setPosition(offsetX + x * cellSize, offsetY + y * cellSize);
                wallSprite.setScale(cellSize / wallSprite.getLocalBounds().width, cellSize / wallSprite.getLocalBounds().height);
                window.draw(wallSprite);
            }
            else if (currentNode->getSymbol() == '@') {
                personaje.setPosition(offsetX + x * cellSize, offsetY + y * cellSize);
                personaje.setScale(cellSize / personaje.getLocalBounds().width, cellSize / personaje.getLocalBounds().height);
                window.draw(personaje);

            }
            else {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                sf::Color color;

                switch (currentNode->getSymbol()) {
                case ' ': color = sf::Color::Red; break;
                case '.': color = sf::Color::Yellow; break;
                case '!': color = sf::Color::Blue; break;
                default: color = sf::Color::Transparent; break;
                }

                cell.setFillColor(color);
                cell.setPosition(offsetX + x * cellSize, offsetY + y * cellSize);
                window.draw(cell);
            }

            currentNode = currentNode->getNext();
            x++;
        }

        currentRow = currentRow->getDown();
        y++;
    }
}

void Grid::drawMenu(sf::RenderWindow& window) {
    // Definir el botón de Nivel 1
    sf::RectangleShape button1(sf::Vector2f(200, 50));
    button1.setFillColor(sf::Color::Black); // Cambié el color del botón a negro para mayor contraste
    button1.setPosition(300, 200);

    sf::Text text1(" Nivel 1 ", font, 30); // Ajusté el tamaño del texto
    text1.setFillColor(sf::Color::White); // Texto blanco para contraste
    text1.setPosition(310, 210); // Ajusta la posición del texto para que quede centrado en el botón

    // Definir el botón de Nivel 2
    sf::RectangleShape button2(sf::Vector2f(200, 50));
    button2.setFillColor(sf::Color::Black); // Cambié el color del botón a negro para mayor contraste
    button2.setPosition(300, 300);

    sf::Text text2(" Nivel 2", font, 30); // Ajusté el tamaño del texto
    text2.setFillColor(sf::Color::White); // Texto blanco para contraste
    text2.setPosition(310, 310); // Ajusta la posición del texto para que quede centrado en el botón

    // Dibujar botones y texto
    window.draw(button1);
    window.draw(text1);
    window.draw(button2);
    window.draw(text2);
}

int Grid::handleMenu(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return -1; // Cerrar la ventana

        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            // Verificar clic en el botón de Nivel 1
            if (mousePos.x >= 300 && mousePos.x <= 500 && mousePos.y >= 200 && mousePos.y <= 250) {
                return 1; // Nivel 1 seleccionado
            }

            // Verificar clic en el botón de Nivel 2
            if (mousePos.x >= 300 && mousePos.x <= 500 && mousePos.y >= 300 && mousePos.y <= 350) {
                return 2; // Nivel 2 seleccionado
            }
        }
    }
    return 0; // Ninguna selección
}
void Grid::loadTextures()
{
    if (!boxTexture.loadFromFile("Imagen/caja.png")) {
        std::cerr << "Error al cargar la textura de la caja." << std::endl;
    }
    boxSprite.setTexture(boxTexture);
    if (!wallTexture.loadFromFile("Imagen/pared.jpg")) {
        std::cerr << "Error al cargar la textura de la pared." << std::endl;
    }
    wallSprite.setTexture(wallTexture);
    if (!personajeText.loadFromFile("Imagen/personaje.png"))
    {
        std::cerr << "Error al cargar la textura de la pared." << std::endl;
    }
    personaje.setTexture(personajeText);
}

void Grid::printGrid() {
    std::cout << "Grid:" << std::endl;

    GridNode* currentRow = head;
    while (currentRow->getNext() != nullptr) {
        GridNode* currentNode = currentRow;
        while (currentNode != nullptr) {
            std::cout << currentNode->getSymbol();
            currentNode = currentNode->getNext();
        }
        std::cout << std::endl;
        currentRow = currentRow->getDown();
    }

}
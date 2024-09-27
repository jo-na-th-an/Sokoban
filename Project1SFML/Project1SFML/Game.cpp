#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Grid Display"), nivelSeleccionado(0) {
    // Constructor: inicializa la ventana y el nivel seleccionado a 0
}

void Game::run() {
    // Mostrar el menú al inicio
    showMenu();

    // Cargar el nivel seleccionado
    if (nivelSeleccionado == 1) {
        grid.loadLevelFromFile("nivel1.txt");
    }
    else if (nivelSeleccionado == 2) {
        grid.loadLevelFromFile("nivel2.txt");
    }

    // Bucle principal para el juego
    while (window.isOpen()) {
        handleEvents();  // Maneja eventos (teclado, ratón, etc.)

        window.clear(sf::Color::White);  // Limpia la ventana con color blanco

        grid.draw(window, 50);  // Dibuja el grid en la ventana con tamaño de celda 50

        window.display();  // Muestra el contenido en pantalla
    }
}

void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::showMenu() {
    // Mostrar el menú hasta que se seleccione un nivel
    while (nivelSeleccionado == 0 && window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Verificar clic en el botón de Nivel 1
                if (mousePos.x >= 300 && mousePos.x <= 500 && mousePos.y >= 200 && mousePos.y <= 250) {
                    nivelSeleccionado = 1;  // Nivel 1 seleccionado
                }

                // Verificar clic en el botón de Nivel 2
                if (mousePos.x >= 300 && mousePos.x <= 500 && mousePos.y >= 300 && mousePos.y <= 350) {
                    nivelSeleccionado = 2;  // Nivel 2 seleccionado
                }
            }
        }

        window.clear(sf::Color::White);

        // Dibuja el menú
        grid.drawMenu(window);

        window.display();
    }
}
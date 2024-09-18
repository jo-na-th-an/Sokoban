#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "/Users/jc401/source/repos/Project1SFML/Project1SFML/Menu.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Sokoban");
 
    Menu menu(window);

    // Carga de recursos gráficos (texturas, sprites, etc.)
    //sf::Texture fondoTexture;
    //if (!fondoTexture.loadFromFile("/Project1SMFL/Archivos de recursos/Imagen1.jpeg")) {
    //    // Maneja el error si no se puede cargar la imagen
    //    return 1;
    //}

    // Crea un sprite para el fondo
    //sf::Sprite fondoSprite;
    //fondoSprite.setTexture(fondoTexture);
    //fondoSprite.setPosition(0, 0); // Posición en la esquina superior izquierda


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        menu.handleInput(); // Maneja las teclas
        menu.draw(); // Dibuja el menú


        window.display();
    }

    return 0;
}

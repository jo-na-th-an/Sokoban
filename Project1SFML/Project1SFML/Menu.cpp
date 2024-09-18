#include "Menu.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

Menu::Menu(float width, float height) {
    if (!font.loadFromFile("Fonts/Roboto-Bold.ttf")) {
        cout << "No se encontró la fuente." << endl;
    }

    if (!texture.loadFromFile("Imagen/Imagen1.jpeg")) {
        cout << "No se encontró la imagen de fondo." << endl;
    }

    // Ajustar la imagen de fondo al tamaño de la ventana
    Vector2u windowSize(width, height);
    Vector2u textureSize = texture.getSize();
    sprite.setTexture(texture);
    sprite.setScale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );

    // Opciones del menú
    // Jugar
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(  Color::Black);
    mainMenu[0].setString("JUGAR");
    mainMenu[0].setCharacterSize(70);
    FloatRect textRect0 = mainMenu[0].getLocalBounds();
    mainMenu[0].setOrigin(textRect0.left + textRect0.width / 2.0f, textRect0.top + textRect0.height / 2.0f);
    mainMenu[0].setPosition(windowSize.x / 2.0f, 200);

    // Cargar partida
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(  Color::Black);
    mainMenu[1].setString("CARGAR PARTIDA");
    mainMenu[1].setCharacterSize(70);
    FloatRect textRect1 = mainMenu[1].getLocalBounds();
    mainMenu[1].setOrigin(textRect1.left + textRect1.width / 2.0f, textRect1.top + textRect1.height / 2.0f);
    mainMenu[1].setPosition(windowSize.x / 2.0f, 300);

    // Salir
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(Color::Black);
    mainMenu[2].setString("SALIR");
    mainMenu[2].setCharacterSize(70);
    FloatRect textRect2 = mainMenu[2].getLocalBounds();
    mainMenu[2].setOrigin(textRect2.left + textRect2.width / 2.0f, textRect2.top + textRect2.height / 2.0f);
    mainMenu[2].setPosition(windowSize.x / 2.0f, 400);

    MainMenuSelected = -1;
}

Menu::~Menu() {}

void Menu::draw(  RenderWindow& window) {
    window.draw(sprite);
    for (int i = 0; i < Max_main_menu; i++) {
        window.draw(mainMenu[i]);
    }
}

void Menu::MoveUp() {
    if (MainMenuSelected - 1 >= 0) {
        mainMenu[MainMenuSelected].setFillColor(Color::Black);
        MainMenuSelected--;
        if (MainMenuSelected == -1) {
            MainMenuSelected = 2;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);
    }
}

void Menu::MoveDown() {
    if (MainMenuSelected + 1 <= Max_main_menu) {
        mainMenu[MainMenuSelected].setFillColor(Color::Black);
        MainMenuSelected++;
        if (MainMenuSelected == 3) {
            MainMenuSelected = 0;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);
    }
}

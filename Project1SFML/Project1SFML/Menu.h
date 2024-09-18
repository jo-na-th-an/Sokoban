// Menu.h
#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


#define Max_main_menu 3
class Menu {

public:

    Menu(float width, float height);
    
    void draw(RenderWindow& window);
    void MoveUp();
    void MoveDown();

    int MainMenuPressed() {
        return MainMenuSelected;
    }
    ~Menu();
    
private:
    int MainMenuSelected;
    Font  font;
    Text mainMenu[Max_main_menu];
    Texture texture;
    Sprite sprite;

};

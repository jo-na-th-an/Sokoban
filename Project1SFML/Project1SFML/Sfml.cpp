#include "Menu.h"
#include <SFML/Graphics.hpp>


using namespace sf;

void main() {

	RenderWindow MENU(VideoMode(800, 600,64), "Pamela Keysha Cipriano Jonathan ", Style::Default);
	Menu menu(MENU.getSize().x, MENU.getSize().y);

	while (MENU.isOpen()) {

		Event event;
		while (MENU.pollEvent(event)) {

			if (event.type == Event::Closed) {
				MENU.close();
			}

			if (event.type == Event::KeyReleased) {

				if (event.key.code == Keyboard::Up) {

					menu.MoveUp();
					break;
				}
				if (event.key.code == Keyboard::Down) {

					menu.MoveDown();
					break;

				}
				if (event.key.code == Keyboard::Return) {

					RenderWindow JUGAR(VideoMode(960, 720), "SOKOBAN");
					RenderWindow CARGARPARTIDA(VideoMode(960, 720), "CARGAR PARTIDA");
					RenderWindow SALIR(VideoMode(960, 720), "SALIR");

					int x = menu.MainMenuPressed();
					if (x == 0) {

						while (JUGAR.isOpen()) {

							Event evento;
							while (JUGAR.pollEvent(evento)) {

								if (evento.type == Event::Closed) {

									JUGAR.close();
								}
								if (evento.type == Event::KeyPressed) {
									if (evento.key.code == Keyboard::Escape) {

										JUGAR.close();

									}
								}

							}
							CARGARPARTIDA.close();
							SALIR.close();
							JUGAR.clear();
							JUGAR.display();

						}
					}
					if (x == 1) {
						while (CARGARPARTIDA.isOpen()) {

							Event evento;
							while (CARGARPARTIDA.pollEvent(evento)) {

								if (evento.type == Event::Closed) {

									CARGARPARTIDA.close();
								}
								if (evento.type == Event::KeyPressed) {
									if (evento.key.code == Keyboard::Escape) {

										CARGARPARTIDA.close();

									}
								}

							}
							JUGAR.close();
							CARGARPARTIDA.close();
							SALIR.close();
							CARGARPARTIDA.display();

						}

					}

					if (x == 2) {
						MENU.close();
						break;
					}
				}
			}

		}

		MENU.clear();
		menu.draw(MENU);
		MENU.display();
	}
}

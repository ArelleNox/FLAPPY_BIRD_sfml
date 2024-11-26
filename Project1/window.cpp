#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "class.cpp"
using namespace sf;
using namespace std;

class mywindow {
public:

    int myWindow() {
        // Création d'une fenêtre
        sf::RenderWindow window(sf::VideoMode(1920, 1080), "Flappy Bird");

        // Charger une texture
        sf::Texture background;
        if (!background.loadFromFile("background2.png")) {
            return -1; // Erreur si le fichier est introuvable
        }

        // Associer la texture à un sprite
        RectangleShape back(Vector2f(1920, 1080));
        back.setTexture(&background);
        back.setPosition(0, 0);

        // Boucle principale
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }
       

        return 0;
    }
};
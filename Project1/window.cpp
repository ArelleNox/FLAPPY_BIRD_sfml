#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "class.cpp"
using namespace sf;
using namespace std;

class Mywindow {
public:

    int myWindow() {
        // Cr�ation d'une fen�tre
        sf::RenderWindow window(sf::VideoMode(1920, 1080), "Flappy Bird");

        // Charger une texture
        sf::Texture background;
        if (!background.loadFromFile("background2.png")) {
            return -1; // Erreur si le fichier est introuvable
        }

        // Associer la texture � un sprite
        RectangleShape back(Vector2f(1920, 1080));
        back.setTexture(&background);
        back.setPosition(0, 0);

        return 0;
    }
};
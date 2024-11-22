#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main() {
    // Cr�ation d'une fen�tre
    sf::RenderWindow window(sf::VideoMode(600, 850), "Flappy Bird");

    // Charger une texture
    sf::Texture background;
    if (!background.loadFromFile("background.jpg")) {
        return -1; // Erreur si le fichier est introuvable
    }

    // Associer la texture � un sprite
    RectangleShape back(Vector2f(600, 850));
    back.setTexture(&background);
    back.setPosition(0, 0);

    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // Fermer la fen�tre
            }
            if (event.key.code == sf::Keyboard::Escape) {
                window.close(); // Fermer avec �chap
            }
        }

        window.clear(); // Effacer le contenu de la fen�tre
        window.draw(back); // Dessiner le sprite
        window.display(); // Afficher le contenu de la fen�tre
    }

    return 0;
}

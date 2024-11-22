#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main() {
    // Création d'une fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ma Première Fenêtre");

    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Fermer la fenêtre
        }

        window.clear(); // Effacer le contenu de la fenêtre
        window.display(); // Afficher le contenu de la fenêtre
    }

    return 0;
}

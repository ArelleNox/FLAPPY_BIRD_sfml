#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main() {
    // Cr�ation d'une fen�tre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ma Premi�re Fen�tre");

    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Fermer la fen�tre
        }

        window.clear(); // Effacer le contenu de la fen�tre
        window.display(); // Afficher le contenu de la fen�tre
    }

    return 0;
}

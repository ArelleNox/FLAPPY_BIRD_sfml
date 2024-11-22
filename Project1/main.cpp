#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main() {
    // Cr�ation d'une fen�tre
    sf::RenderWindow window(sf::VideoMode(600, 850), "Flappy Bird");

    sf::View view(sf::FloatRect(0.f, 0.f, 600.f, 850.f));
    // d�placement de la vue en (300, 425)
    view.setCenter(300.f, 425.f);

    // d�calage de la vue de (100, 100) (sa position finale est donc (300, 300))
    //view.move(100.f, 0.f);


    // Charger une texture
    sf::Texture background;
    if (!background.loadFromFile("background.jpg")) {
        return -1; // Erreur si le fichier est introuvable
    }

    sf::Texture pipe;
    if (!pipe.loadFromFile("pipe.png")) {
        return -1; // Erreur si le fichier est introuvable
    }


    // Associer la texture � un sprite
    sf::Sprite sprite;
    sprite.setTexture(pipe);


    // Associer la texture � un sprite
    RectangleShape back(Vector2f(600, 850));
    back.setTexture(&background);
    back.setPosition(0, 0);

    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close(); // Fermer avec �chap
            }


        window.clear(); // Effacer le contenu de la fen�tre
        window.setView(view); // on l'active
        window.draw(back); // Dessiner le sprite
        //window.draw(sprite);
        window.display(); // Afficher le contenu de la fen�tre
    }

    return 0;
}

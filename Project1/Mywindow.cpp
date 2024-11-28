#include "Mywindow.hpp"       
#include <stdexcept>           // Pour la gestion des exceptions

Mywindow::Mywindow() {}

Mywindow::~Mywindow() {}

int Mywindow::myWindow() {
    // Cr�ation d'une fen�tre
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Flappy Bird");

    // Charger une texture
    sf::Texture background;
    if (!background.loadFromFile("background2.png")) {
        throw std::runtime_error("Erreur : texture de l'arri�re-plan introuvable.");
    }

    // Associer la texture � un rectangle
    sf::RectangleShape back(sf::Vector2f(1920, 1080));
    back.setTexture(&background);
    back.setPosition(0, 0);

    /*while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        window.clear();       // Effacer le contenu de la fen�tre
        window.draw(back);    // Dessiner l'arri�re-plan
        window.display();     // Afficher le contenu de la fen�tre
    }*/
    return 0;
}

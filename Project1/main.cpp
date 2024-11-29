#include <iostream>
#include "Bird.hpp"       // Pour la classe Bird
#include "Mywindow.hpp"   // Pour la classe Mywindow
#include "Pipe.hpp"
#include <vector>
using namespace sf;
using namespace std;

int main() {
    // Utilisation de la classe Mywindow
    Mywindow myWin;
    myWin.myWindow();

    // Création et gestion de l'oiseau
    Bird bird;

    // Génération des tuyaux
    Pipe pipe (100.f, 600.f);


    Clock deltaClock;

    // Exemple d'intégration avec une boucle principale
    sf::RenderWindow window(sf::VideoMode(600, 800), "Flappy Bird");

    sf::Texture background;
    if (!background.loadFromFile("background2.png")) {
        return -1; // Erreur si le fichier est introuvable
    }

    sf::RectangleShape back(sf::Vector2f(600, 800));
    back.setTexture(&background);
    back.setPosition(0, 0);

    // Génération des tuyaux
    std::vector<Pipe> pipes;
    for (int i = 0; i < 3; ++i) {
        pipes.emplace_back(600 + i * 400, 180.f); // Espacement et gap ajustables
    }

    while (window.isOpen()) {
        Time timeSinceLastFrame = deltaClock.restart();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }

            // Gérer l'appui sur la touche "Espace"
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                bird.jump(); // Faire sauter l'oiseau
                cout << "Space" << endl;
            }
        }

        // Mettre à jour les tuyaux
        for (auto& pipe : pipes) {
            pipe.update(timeSinceLastFrame.asSeconds());

            // Réinitialiser les tuyaux qui sont sortis de l'écran
            if (pipe.isOffScreen()) {
                pipe.resetPosition(1200.f);
            }
        }

        // Mettre à jour l'oiseau
        bird.update(timeSinceLastFrame.asSeconds());


        window.clear();

        window.draw(back);
        bird.draw(window); // Dessiner l'oiseau    
        for (const auto& pipe : pipes) {
            pipe.draw(window);// Dessiner chaque tuyau
        }

        window.display();
    }

    return 0;
}

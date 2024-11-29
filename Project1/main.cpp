#include "Bird.hpp"       // Pour la classe Bird
#include "Mywindow.hpp"   // Pour la classe Mywindow
#include "Pipe.hpp"
#include "overlay.hpp"
#include <iostream>
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

    Overlay overlay;

    // Curseur (un rectangle simple)
    sf::RectangleShape cursor(sf::Vector2f(20.f, 10.f));
    cursor.setFillColor(sf::Color::Cyan);
    cursor.setPosition(150.f, 750.f); // Placer le curseur en bas de l'écran

    // Variables pour l'opacité
    float opacity = 0.f;
    float cursorX = 150.f; 

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
        
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                bird.jump(); // Faire sauter l'oiseau
            }

            // Gestion du curseur par déplacement avec la souris
            if (event.type == sf::Event::MouseMoved) {
                // Déplacer le curseur horizontalement avec la souris
                if (event.mouseMove.x >= 150 && event.mouseMove.x <= 450) {
                    cursorX = event.mouseMove.x;  // Limiter entre 150 et 450
                    opacity = (cursorX - 150) * 255.f / 300.f;  // Calculer l'opacité
                }
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

        // Mettre à jour l'opacité de l'overlay
        overlay.setOpacity(opacity);
        
        // Mettre à jour l'oiseau
        bird.update(timeSinceLastFrame.asSeconds());

        window.clear();

        window.draw(back);
        bird.draw(window); // Dessiner l'oiseau    
        for (const auto& pipe : pipes) {
            pipe.draw(window);// Dessiner chaque tuyau
        }

        overlay.draw(window);    // Dessiner l'overlay
        
        // Dessiner le curseur
        cursor.setPosition(cursorX - cursor.getSize().x / 2, 750.f); // Centrer le curseur
        window.draw(cursor);

        window.display();
    }

    return 0;
}

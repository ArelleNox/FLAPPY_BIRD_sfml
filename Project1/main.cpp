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

    // Cr�ation et gestion de l'oiseau
    Bird bird;

    // G�n�ration des tuyaux
    Pipe pipe (100.f, 600.f);

    Overlay overlay;

    // Curseur (un rectangle simple)
    sf::RectangleShape cursor(sf::Vector2f(20.f, 10.f));
    cursor.setFillColor(sf::Color::Cyan);
    cursor.setPosition(150.f, 750.f); // Placer le curseur en bas de l'�cran

    // Variables pour l'opacit�
    float opacity = 0.f;
    float cursorX = 150.f; 

    Clock deltaClock;

    // Exemple d'int�gration avec une boucle principale
    sf::RenderWindow window(sf::VideoMode(600, 800), "Flappy Bird");

    sf::Texture background;
    if (!background.loadFromFile("background2.png")) {
        return -1; // Erreur si le fichier est introuvable
    }

    sf::RectangleShape back(sf::Vector2f(600, 800));
    back.setTexture(&background);
    back.setPosition(0, 0);

    // G�n�ration des tuyaux
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

            // Gestion du curseur par d�placement avec la souris
            if (event.type == sf::Event::MouseMoved) {
                // D�placer le curseur horizontalement avec la souris
                if (event.mouseMove.x >= 150 && event.mouseMove.x <= 450) {
                    cursorX = event.mouseMove.x;  // Limiter entre 150 et 450
                    opacity = (cursorX - 150) * 255.f / 300.f;  // Calculer l'opacit�
                }
            }
        }

        // Mettre � jour les tuyaux
        for (auto& pipe : pipes) {
            pipe.update(timeSinceLastFrame.asSeconds());

            // R�initialiser les tuyaux qui sont sortis de l'�cran
            if (pipe.isOffScreen()) {
                pipe.resetPosition(1200.f);
            }
        }

        // Mettre � jour l'opacit� de l'overlay
        overlay.setOpacity(opacity);
        
        // Mettre � jour l'oiseau
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

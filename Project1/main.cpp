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
    Pipe pipe;
    vector<Pipe> pipes;


    for (int i = 0; i < 3; ++i) {
        pipes.emplace_back(800 + i * 400); // Espacement initial entre les tuyaux
    }

    // Exemple d'intégration avec une boucle principale
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Flappy Bird");

    sf::Texture background;
    if (!background.loadFromFile("background2.png")) {
        return -1; // Erreur si le fichier est introuvable
    }

    sf::RectangleShape back(sf::Vector2f(1920, 1080));
    back.setTexture(&background);
    back.setPosition(0, 0);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }

        for (auto& pipe : pipes) {
            pipe.update();

            // Réinitialise la position si le tuyau sort de l'écran
            if (pipe.isOffScreen()) {
                pipe.resetPosition(1920);
            }
        }

        bird.jump(); // Gérer le saut de l'oiseau

        for (const auto& pipe : pipes) {
            pipe.draw(window);
        }

        window.clear();
        window.draw(back);
        bird.draw(window); // Dessiner l'oiseau
        window.display();
    }

    return 0;
}

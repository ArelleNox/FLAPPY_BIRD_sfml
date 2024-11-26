#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>  // Pour rand()
#include <ctime>    // Pour srand()
using namespace sf;
using namespace std;






int main() {
    // Création d'une fenêtre
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Flappy Bird");

    // Charger une texture
    sf::Texture background;
    if (!background.loadFromFile("background2.png")) {
        return -1; // Erreur si le fichier est introuvable
    }

    // Associer la texture à un sprite
    RectangleShape back(Vector2f(1920, 1080));
    back.setTexture(&background);
    back.setPosition(0, 0);


    sf::Texture birdTexture;
    if (!birdTexture.loadFromFile("flbird2.png")) {
        return -1; // Erreur si le fichier est introuvable
    }

    sf::Sprite bird;
    bird.setTexture(birdTexture);
    bird.setPosition(200.f, 540.f); // Position initiale

    sf::Texture uppipe;
    if (!uppipe.loadFromFile("pi.png")) {
        return -1; // Erreur si le fichier est introuvable
    }

    RectangleShape pipe1(Vector2f(324, 624));
    pipe1.setTexture(&uppipe);
    pipe1.setPosition(400, -110);
  
    sf::Texture downpipe;
    if (!uppipe.loadFromFile("pip.png")) {
        return -1; // Erreur si le fichier est introuvable
    }

    RectangleShape pipe2(Vector2f(324, 624));
    pipe2.setTexture(&downpipe);
    pipe2.setPosition(500, 900);
  

    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }



        }
        window.clear(); // Effacer le contenu de la fenêtre
        window.draw(back); // Dessiner le sprite
        window.draw(bird);
        window.draw(pipe1);
        window.draw(pipe2);
        window.display(); // Afficher le contenu de la fenêtre
    }

    return 0;
}

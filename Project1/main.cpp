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
    if (!birdTexture.loadFromFile("bird.jpg")) {
        return -1; // Erreur si le fichier est introuvable
    }

    sf::Sprite bird;
    bird.setTexture(birdTexture);
    bird.setPosition(200.f, 540.f); // Position initiale


   /* float gravity = 0.5f;    // Gravité qui affecte l'oiseau
    float jumpHeight = -10.f; // Hauteur du saut
    float velocity = 0.f;     // Vitesse de l'oiseau*/

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

          /*  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                velocity = jumpHeight; // Appliquer une impulsion pour sauter
            }*/


            /*if (bird.getPosition().y + bird.getGlobalBounds().height >= 1080 || bird.getPosition().y <= 0) {
                // L'oiseau touche le sol ou le haut de l'écran
                std::cout << "Game Over!" << std::endl;
                window.close();
            }*/

        }

       /* velocity += gravity;                  // Appliquer la gravité
        bird.move(0.f, velocity);   */          // Mettre à jour la position de l'oiseau

        window.clear(); // Effacer le contenu de la fenêtre
        window.draw(back); // Dessiner le sprite
        window.draw(bird);
        window.display(); // Afficher le contenu de la fenêtre
    }

    return 0;
}

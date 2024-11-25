#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;


class Game {
public:
    Game();
    ~Game();

};



int main() {
    // Création d'une fenêtre
    sf::RenderWindow window(sf::VideoMode(600, 850), "Flappy Bird");

    sf::View view(sf::FloatRect(0.f, 0.f, 600.f, 850.f));
    // déplacement de la vue en (300, 425)
    view.setCenter(300.f, 425.f);

    // décalage de la vue de (100, 100) (sa position finale est donc (300, 300))
    //view.move(100.f, 0.f);


    // Charger une texture
    sf::Texture background;
    if (!background.loadFromFile("background2.png")) {
        return -1; // Erreur si le fichier est introuvable
    }

    sf::Texture birdTexture;
    if (!birdTexture.loadFromFile("bird.jpg")) {
        return -1; // Erreur si le fichier est introuvable
    }

    sf::Sprite bird;
    bird.setTexture(birdTexture);
    bird.setPosition(100.f, 425.f); // Position initiale


    // Associer la texture à un sprite
    RectangleShape back(Vector2f(600, 850));
    back.setTexture(&background);
    back.setPosition(0, 0);

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


            if (bird.getPosition().y + bird.getGlobalBounds().height >= 850 || bird.getPosition().y <= 0) {
                // L'oiseau touche le sol ou le haut de l'écran
                std::cout << "Game Over!" << std::endl;
                window.close();
            }

        }

        window.clear(); // Effacer le contenu de la fenêtre
        window.setView(view); // on l'active
        window.draw(back); // Dessiner le sprite
        window.draw(bird);
        window.display(); // Afficher le contenu de la fenêtre
    }

    return 0;
}

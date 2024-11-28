#include "Bird.hpp"       // Pour la classe Bird
#include "Mywindow.hpp"   // Pour la classe Mywindow

using namespace sf;
using namespace std;

int main() {
    // Utilisation de la classe Mywindow
    Mywindow myWin;
    myWin.myWindow();

    // Création et gestion de l'oiseau
    Bird bird;

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

        bird.jump(); // Gérer le saut de l'oiseau

        window.clear();
        window.draw(back);
        bird.draw(window); // Dessiner l'oiseau
        window.display();
    }

    return 0;
}

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;


int main() {
    // Création de la fenêtre
    //sf::RenderWindow window(sf::VideoMode(800, 600), "Fenêtre SFML");
    //sf::RenderWindow window(sf::VideoMode(800, 600), "Gestion des Entrées");
    sf::RenderWindow window(sf::VideoMode(800, 600), "Affichage de Texture");

    // Charger une texture

    sf::Texture texture;
    if (!texture.loadFromFile("basket.jpg")) {
        return -1; // Erreur si le fichier est introuvable
    }
    
    sf::Texture texture2;
    if (!texture2.loadFromFile("téléchargement.jpg")) {
        return -1; // Erreur si le fichier est introuvable
    }
   
    //// Associer la texture à un sprite
    RectangleShape shape(Vector2f(800, 600));
    shape.setTexture(&texture);
    shape.setPosition(0, 0);
    //
    //// création d'un rectangle
    RectangleShape shape2(Vector2f(20, 80));
    shape2.setFillColor(Color::Red);
    shape2.setPosition(0, 300);
    //
    //// création d'un rectangle
    RectangleShape shape3(Vector2f(20, 80));
    shape3.setFillColor(Color::Cyan);
    shape3.setPosition(780, 300);
    //
    //// Création d'un cercle
    CircleShape circle(20);
    circle.setTexture(&texture2);
    circle.setPosition(400, 300);
    // change la position absolue de l'entité
    //circle.setPosition(10.f, 50.f);
   
    //
    float directionX = 1.f;
    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Fermer la fenêtre
            // déplace l'entité relativement à sa position actuelle

            circle.move(directionX, 2.f);

                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                } // Fermer avec Échap
            }
        }
    // movement des shape par l'utilisateur
    if (Keyboard::isKeyPressed()) {
        if (event.key.code == sf::Keyboard::Up) {
            shape3.move(0.f, -5.f);
        }
        if (event.key.code == sf::Keyboard::Down) {
            shape3.move(0.f, 5.f);
        }
        if (event.key.code == sf::Keyboard::A) {
            shape2.move(0.f, -5.f);
        }
        if (event.key.code == sf::Keyboard::Z) {
            shape2.move(0.f, 5.f);
        }


        // Effacer la fenêtre
        window.clear();
        // Dessiner la forme
        window.draw(shape); // Dessiner le sprite
        window.draw(shape2);
        window.draw(shape3);

        window.draw(circle);
        // Afficher le contenu
        window.display();
    }

    return 0;
}
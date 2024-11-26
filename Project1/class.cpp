#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>
using namespace sf;
using namespace std;

class Bird {
private:
    
        sf::Texture birdTexture;
        if (!birdTexture.loadFromFile("flbird2.png")) {
            return -1; // Erreur si le fichier est introuvable
        }

        sf::Sprite bird;
        bird.setTexture(birdTexture);
        bird.setPosition(200.f, 540.f); // Position initiale

public:
    float birdVelocity = 0.f; // Vitesse verticale de l'oiseau
    float gravity = 0.5f;     // Force gravitationnelle
    float jumpStrength = -10.f; // Force d'un saut

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        birdVelocity = jumpStrength; // Saut
    }

    birdVelocity += gravity; // Appliquer la gravité
    bird.move(0.f, birdVelocity); // Déplacer l'oiseau

};









/*sf::Texture uppipe;
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
pipe2.setPosition(500, 900);*/



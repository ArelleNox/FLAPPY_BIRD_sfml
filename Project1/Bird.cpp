#include "Bird.hpp"
#include <stdexcept>
#include <iostream>
using namespace sf;
using namespace std;

// Constructor
Bird::Bird() : birdVelocity(0.f), gravity(0.5f), jumpStrength(-1.0f) {
    // Load the texture and set the sprite
    if (!birdTexture.loadFromFile("flbird2.png")) {
        throw runtime_error("Erreur : texture de l'oiseau introuvable.");
    }
    else {
        cout << "Texture de l'oiseau chargée avec succès." << endl;
    }
    cout << "Position initiale de l'oiseau : " << bird.getPosition().x << ", " << bird.getPosition().y << endl;

    bird.setTexture(birdTexture);
    bird.setPosition(200.f, 540.f); // Initial position of the bird
}

// Destructor
Bird::~Bird() {}

// Jump 
void Bird::jump() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        birdVelocity = jumpStrength; // Appliquer la force du saut
    }

    // Appliquer la gravité en continu
    birdVelocity += gravity;

    // Empêcher l'oiseau de sortir de l'écran
    if (bird.getPosition().y + birdVelocity < 0) {
        bird.setPosition(bird.getPosition().x, 0); // Bloquer en haut
        birdVelocity = 0;
    }
    else if (bird.getPosition().y + birdVelocity > 1080 - bird.getGlobalBounds().height) {
        bird.setPosition(bird.getPosition().x, 1080 - bird.getGlobalBounds().height); // Bloquer en bas
        birdVelocity = 0;
    }
    else {
        bird.move(0.f, birdVelocity); // Déplacer l'oiseau
    }
}

// Draw the bird
void Bird::draw(sf::RenderWindow& window) {
    window.draw(bird);
}
 





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



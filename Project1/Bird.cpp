#include "Bird.hpp"
#include <stdexcept>

using namespace sf;
using namespace std;

// Constructor
Bird::Bird() : birdVelocity(0.f), gravity(0.1f), jumpStrength(-0.5f) {
    // Load the texture and set the sprite
    if (!birdTexture.loadFromFile("flbird2.png")) {
        throw runtime_error("Erreur : texture de l'oiseau introuvable.");
    }
    
    bird.setTexture(birdTexture);
    bird.setPosition(200.f, 400.f); // Initial position of the bird
}

// Destructor
Bird::~Bird() {}

Event event;
// Jump 
void Bird::jump() {
    // Si la touche Espace est pressée, appliquer la force du saut
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        birdVelocity = jumpStrength; // Force initiale du saut
    }
   
    if (event.type == Event::KeyReleased && event.key.code == Keyboard::Space) {
        birdVelocity += jumpStrength;
    }
    // Appliquer la gravité en continu
    birdVelocity += gravity;

    // Empêcher l'oiseau de sortir de l'écran
    if (bird.getPosition().y + birdVelocity < 0) {
        bird.setPosition(bird.getPosition().x, 0); // Limite supérieure
        birdVelocity = 0;
    }

     if (bird.getPosition().y + birdVelocity > 800 - bird.getGlobalBounds().height) {
        bird.setPosition(bird.getPosition().x, 800 - bird.getGlobalBounds().height); // Limite inférieure
        birdVelocity = 0;
    }

    else {
        bird.move(0.f, birdVelocity); // Déplacer l'oiseau selon sa vitesse verticale
    }
}


// Draw the bird
void Bird::draw(sf::RenderWindow& window) {
    window.draw(bird);
}

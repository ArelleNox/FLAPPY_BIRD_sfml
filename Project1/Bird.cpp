#include "Bird.hpp"
#include <stdexcept>

using namespace sf;
using namespace std;

// Constructor
Bird::Bird() : birdVelocity(0.f), gravity(0.2f), jumpStrength(-1.0f) {
    // Load the texture and set the sprite
    if (!birdTexture.loadFromFile("flbird2.png")) {
        throw runtime_error("Erreur : texture de l'oiseau introuvable.");
    }
    
    bird.setTexture(birdTexture);
    bird.setPosition(200.f, 540.f); // Initial position of the bird
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

    // Appliquer la gravité en continu
    birdVelocity += gravity;

    /*// Empêcher l'oiseau de sortir de l'écran
    if (bird.getPosition().y + birdVelocity < 0) {
        bird.setPosition(bird.getPosition().x, 0); // Limite supérieure
        birdVelocity = 0;
    }*/

     if (bird.getPosition().y + birdVelocity > 1080 - bird.getGlobalBounds().height) {
        bird.setPosition(bird.getPosition().x, 1080 - bird.getGlobalBounds().height); // Limite inférieure
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



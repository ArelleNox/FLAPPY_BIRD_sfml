#include "Bird.hpp"
#include <stdexcept>

using namespace sf;
using namespace std;

#include "Bird.hpp"
#include <stdexcept>

using namespace sf;
using namespace std;

// Constructeur
Bird::Bird() : birdVelocity(0.f), gravity(0.5f), jumpStrength(-10.0f) {
    
    if (!birdTexture.loadFromFile("flbird2.png")) {
        throw runtime_error("Erreur : texture de l'oiseau introuvable.");
    }

    bird.setTexture(birdTexture);
    bird.setPosition(200.f, 540.f); //position of the bird
}

// Destructor
Bird::~Bird() {
    
}


void Bird::jump() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        birdVelocity = jumpStrength; //jump
    }

    birdVelocity += gravity; //  gravity
    bird.move(0.f, birdVelocity);
}

// Draw 
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



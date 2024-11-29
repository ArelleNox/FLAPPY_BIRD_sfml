#include <iostream>
#include "Bird.hpp"
#include <stdexcept>
#include <assert.h>

using namespace sf;
using namespace std;

// Constructor
Bird::Bird() {
    birdVelocity = .0f;
    gravity = 450.0f;
    jumpStrength = 300.0f;

    // Load the texture and set the sprite
    if (!birdTexture.loadFromFile("flbird2.png")) {
        throw runtime_error("Erreur : texture de l'oiseau introuvable.");
    }

    bird.setTexture(birdTexture);
    bird.setPosition(200.f, 400.f); // Initial position of the bird
}

// Destructor
Bird::~Bird() {}

// Handle jump event
void Bird::jump() {
    // Appliquer une impulsion verticale vers le haut
    birdVelocity = -jumpStrength; // Saut dirigé vers le haut
    cout << "BirdVelocity at jump: " << birdVelocity << endl;
}

void Bird::update(float deltaTime) {
    cout << "DeltaTime: " << deltaTime << endl;
    birdVelocity += gravity * deltaTime; // Appliquer la gravité

    float newY = bird.getPosition().y + birdVelocity * deltaTime;

    // Empêcher l'oiseau de dépasser les limites de l'écran
    if (newY < 0) {
        cout << "There" << endl;
        newY = 0;
        birdVelocity = 0;
    }
    else if (newY > 800 - bird.getGlobalBounds().height) {
        //cout << "Here" << endl;
        newY = 800 - bird.getGlobalBounds().height;
        birdVelocity = 0;
    }

    // Mettre à jour la position de l'oiseau
    bird.setPosition(bird.getPosition().x, newY);
}


// Draw the bird
void Bird::draw(sf::RenderWindow& window) {
    window.draw(bird);
}

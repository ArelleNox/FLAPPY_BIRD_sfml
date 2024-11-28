#include "Pipe.hpp"

Pipe::Pipe(float startX, float gapSize) : pipeSpeed(0.2f), gapSize(gapSize) {
    // Charger la texture des tuyaux
    if (!pipeTexture.loadFromFile("pip.png")) {
        throw std::runtime_error("Erreur : texture des tuyaux introuvable.");
    }

    // Configurer le tuyau supérieur
    topPipe.setTexture(pipeTexture);
    topPipe.setScale(1.f, -1.f); // Inverser le tuyau pour qu'il pointe vers le bas
    topPipe.setPosition(startX, -rand() % 300); // Position aléatoire en haut

    // Configurer le tuyau inférieur
    bottomPipe.setTexture(pipeTexture);
    bottomPipe.setPosition(startX, topPipe.getGlobalBounds().height + gapSize);
}

Pipe::~Pipe() {}

void Pipe::update() {
    // Déplacer les tuyaux vers la gauche
    topPipe.move(-pipeSpeed, 0);
    bottomPipe.move(-pipeSpeed, 0);
}

void Pipe::draw(sf::RenderWindow& window) const {
    window.draw(topPipe);
    window.draw(bottomPipe);
}


float Pipe::getXPosition() const {
    return topPipe.getPosition().x;
}

bool Pipe::isOffScreen() const {
    return topPipe.getPosition().x + topPipe.getGlobalBounds().width < 0;
}

void Pipe::resetPosition(float newX) {
    // Réinitialiser les positions des tuyaux
    topPipe.setPosition(newX, -rand() % 100);
    bottomPipe.setPosition(newX, topPipe.getGlobalBounds().height + gapSize);
}


bool Pipe::checkCollision(const sf::Sprite& bird) const {
    return bird.getGlobalBounds().intersects(topPipe.getGlobalBounds()) ||
        bird.getGlobalBounds().intersects(bottomPipe.getGlobalBounds());
}

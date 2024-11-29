#include "Pipe.hpp"
#include <iostream>



Pipe::Pipe(float startX, float gapSize) : pipeSpeed(200.0f), gapSize(gapSize) {
    // Charger la texture des tuyaux
    if (!pipeTexture.loadFromFile("pip.png")) {
        throw std::runtime_error("Erreur : texture des tuyaux introuvable.");
    }

    // Générer une hauteur aléatoire pour les tuyaux
    float randomHeight = rand() % 300 + 10;

    // Configurer le tuyau supérieur
    topPipe.setTexture(pipeTexture);
    topPipe.setScale(1.f, -1.f); // Inverser le tuyau pour qu'il pointe vers le bas
    topPipe.setPosition(startX, randomHeight);

    // Configurer le tuyau inférieur
    bottomPipe.setTexture(pipeTexture);
    bottomPipe.setPosition(startX, randomHeight + gapSize);
}

Pipe::~Pipe() {}

void Pipe::update(float deltaTime) {
    // Déplacer les tuyaux vers la gauche
    topPipe.move(-pipeSpeed * deltaTime, 0.f);
    bottomPipe.move(-pipeSpeed * deltaTime, 0.f);
}

void Pipe::draw(sf::RenderWindow& window) const {
    // Dessiner les tuyaux sur la fenêtre
    window.draw(topPipe);  
    window.draw(bottomPipe);
}

float Pipe::getXPosition() const {
    return topPipe.getPosition().x;
}

bool Pipe::isOffScreen() const {
    // Vérifier si le tuyau est complètement sorti de l'écran
    return topPipe.getPosition().x + topPipe.getGlobalBounds().width < 0;
}

void Pipe::resetPosition(float newX) {
    // Générer une nouvelle hauteur aléatoire pour les tuyaux
    float randomHeight = rand() % 300 + 100;

    // Réinitialiser les positions des tuyaux
    topPipe.setPosition(newX, randomHeight * -1);
    bottomPipe.setPosition(newX, randomHeight + gapSize);
}

bool Pipe::checkCollision(const sf::Sprite& bird) const {
    // Vérifier si l'oiseau entre en collision avec l'un des deux tuyaux
    if (bird.getGlobalBounds().intersects(topPipe.getGlobalBounds()) ||
        bird.getGlobalBounds().intersects(bottomPipe.getGlobalBounds())) {
        std::cout << "game over" << std::endl;
      
    }

}

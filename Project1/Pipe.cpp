#include "Pipe.hpp"
#include <iostream>



Pipe::Pipe(float startX, float gapSize) : pipeSpeed(200.0f), gapSize(gapSize) {
    // Charger la texture des tuyaux
    if (!pipeTexture.loadFromFile("pip.png")) {
        throw std::runtime_error("Erreur : texture des tuyaux introuvable.");
    }

    // G�n�rer une hauteur al�atoire pour les tuyaux
    float randomHeight = rand() % 300 + 10;

    // Configurer le tuyau sup�rieur
    topPipe.setTexture(pipeTexture);
    topPipe.setScale(1.f, -1.f); // Inverser le tuyau pour qu'il pointe vers le bas
    topPipe.setPosition(startX, randomHeight);

    // Configurer le tuyau inf�rieur
    bottomPipe.setTexture(pipeTexture);
    bottomPipe.setPosition(startX, randomHeight + gapSize);
}

Pipe::~Pipe() {}

void Pipe::update(float deltaTime) {
    // D�placer les tuyaux vers la gauche
    topPipe.move(-pipeSpeed * deltaTime, 0.f);
    bottomPipe.move(-pipeSpeed * deltaTime, 0.f);
}

void Pipe::draw(sf::RenderWindow& window) const {
    // Dessiner les tuyaux sur la fen�tre
    window.draw(topPipe);  
    window.draw(bottomPipe);
}

float Pipe::getXPosition() const {
    return topPipe.getPosition().x;
}

bool Pipe::isOffScreen() const {
    // V�rifier si le tuyau est compl�tement sorti de l'�cran
    return topPipe.getPosition().x + topPipe.getGlobalBounds().width < 0;
}

void Pipe::resetPosition(float newX) {
    // G�n�rer une nouvelle hauteur al�atoire pour les tuyaux
    float randomHeight = rand() % 300 + 100;

    // R�initialiser les positions des tuyaux
    topPipe.setPosition(newX, randomHeight * -1);
    bottomPipe.setPosition(newX, randomHeight + gapSize);
}

bool Pipe::checkCollision(const sf::Sprite& bird) const {
    // V�rifier si l'oiseau entre en collision avec l'un des deux tuyaux
    if (bird.getGlobalBounds().intersects(topPipe.getGlobalBounds()) ||
        bird.getGlobalBounds().intersects(bottomPipe.getGlobalBounds())) {
        std::cout << "game over" << std::endl;
      
    }

}

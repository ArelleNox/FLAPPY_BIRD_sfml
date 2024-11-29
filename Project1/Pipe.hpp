#ifndef PIPE_HPP
#define PIPE_HPP

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class Pipe {
private:
    sf::Texture pipeTexture;   // Texture partag�e pour les tuyaux
    sf::Sprite topPipe;        // Sprite pour le tuyau sup�rieur
    sf::Sprite bottomPipe;     // Sprite pour le tuyau inf�rieur
    float pipeSpeed;           // Vitesse horizontale des tuyaux
    float gapSize;             // Taille de l'�cart entre les tuyaux

public:
    Pipe(float startX, float gapSize = 200.f);
    ~Pipe();

    void update();                                 // D�placer les tuyaux
    void draw(sf::RenderWindow& window) const;     // Dessiner les tuyaux
    float getXPosition() const;                   // R�cup�rer la position X
    bool isOffScreen() const;                     // V�rifier si les tuyaux sont hors de l'�cran
    void resetPosition(float newX);               // R�initialiser la position des tuyaux
    bool checkCollision(const sf::Sprite& bird) const; // D�tecter une collision avec l'oiseau
};

#endif // PIPE_HPP

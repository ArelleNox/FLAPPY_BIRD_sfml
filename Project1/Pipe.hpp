#ifndef PIPE_HPP
#define PIPE_HPP

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class Pipe {
private:
    sf::Texture pipeTexture;   // Texture partagée pour les tuyaux
    sf::Sprite topPipe;        // Sprite pour le tuyau supérieur
    sf::Sprite bottomPipe;     // Sprite pour le tuyau inférieur
    float pipeSpeed;           // Vitesse horizontale des tuyaux
    float gapSize;             // Taille de l'écart entre les tuyaux

public:
    Pipe(float startX, float gapSize = 200.f);
    ~Pipe();

    void update();                                 // Déplacer les tuyaux
    void draw(sf::RenderWindow& window) const;     // Dessiner les tuyaux
    float getXPosition() const;                   // Récupérer la position X
    bool isOffScreen() const;                     // Vérifier si les tuyaux sont hors de l'écran
    void resetPosition(float newX);               // Réinitialiser la position des tuyaux
    bool checkCollision(const sf::Sprite& bird) const; // Détecter une collision avec l'oiseau
};

#endif // PIPE_HPP

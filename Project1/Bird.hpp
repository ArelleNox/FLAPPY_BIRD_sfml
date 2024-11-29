#ifndef BIRD_HPP
#define BIRD_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

class Bird {
private:
    sf::Texture birdTexture;   // Texture de l'oiseau
    sf::Sprite bird;           // Sprite de l'oiseau
    float birdVelocity;        // Vitesse verticale de l'oiseau
    float gravity;             // Gravit� appliqu�e � l'oiseau
    float jumpStrength;        // Force du saut

public:
    Bird();                    // Constructeur
    ~Bird();                   // Destructeur

    void jump();               // G�re le saut
    void update(float deltaTime);             // Met � jour la position et applique la gravit�
    void draw(sf::RenderWindow& window); // Dessine l'oiseau sur la fen�tre
};

#endif // BIRD_HPP


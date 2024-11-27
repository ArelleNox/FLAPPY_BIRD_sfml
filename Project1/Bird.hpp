#ifndef BIRD_HPP
#define BIRD_HPP
#include <SFML/Graphics.hpp>

class Bird {
private:
    sf::Texture birdTexture;
    sf::Sprite bird;
    float birdVelocity;
    float gravity;
    float jumpStrength;

public:
    Bird();
    ~Bird();

    void jump();
    void draw(sf::RenderWindow& window);
};

#endif // BIRD_HPP

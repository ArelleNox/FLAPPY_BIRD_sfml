#ifndef PIPE_HPP
#define PIPE_HPP

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

class Pipe {
private:
    sf::Texture pipeTexture;
    sf::Sprite topPipe;
    sf::Sprite bottomPipe;
    float pipeSpeed;
    float gapSize;

public:
    Pipe(float startX, float gapSize = 200.f);
    ~Pipe();

    void update();
    void draw(sf::RenderWindow& window) const; // Marquer comme const
    float getXPosition() const;
    bool isOffScreen() const;
    void resetPosition(float newX);
    bool checkCollision(const sf::Sprite& bird) const;
};

#endif // PIPE_HPP

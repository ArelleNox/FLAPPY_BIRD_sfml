#ifndef OVERLAY_HPP
#define OVERLAY_HPP

#include <SFML/Graphics.hpp>

class Overlay {
private:
    sf::RectangleShape overlay;  // Rectangle noir semi-transparent

public:
    Overlay();
    ~Overlay();

    void setOpacity(float opacity);  // Ajuster la transparence
    void draw(sf::RenderWindow& window) const;  // Dessiner l'overlay
};

#endif // OVERLAY_HPP

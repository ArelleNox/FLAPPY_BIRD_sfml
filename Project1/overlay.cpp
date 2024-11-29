#include "Overlay.hpp"

// Constructeur
Overlay::Overlay() {
    overlay.setSize(sf::Vector2f(600.f, 800.f));  // Taille de la fen�tre du jeu
    overlay.setFillColor(sf::Color(0, 0, 0, 255)); // Noir opaque
}

// Destructeur
Overlay::~Overlay() {}

// Fonction pour ajuster l'opacit� de l'overlay
void Overlay::setOpacity(float opacity) {
    // Limiter l'opacit� entre 0 et 255
    opacity = std::max(0.f, std::min(opacity, 255.f));
    overlay.setFillColor(sf::Color(0, 0, 0, static_cast<sf::Uint8>(opacity)));
}

// Fonction pour dessiner l'overlay
void Overlay::draw(sf::RenderWindow& window) const {
    window.draw(overlay);
}

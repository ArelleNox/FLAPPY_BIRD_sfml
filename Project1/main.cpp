#include <cstdlib> 
#include <ctime>
#include "window.cpp"
//#include "class.cpp"
using namespace sf;
using namespace std;



int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Flappy Bird");

    // Charger une texture
    sf::Texture background;
    if (!background.loadFromFile("background2.png")) {
        return -1; // Erreur si le fichier est introuvable
    }

    // Associer la texture à un sprite
    RectangleShape back(Vector2f(1920, 1080));
    back.setTexture(&background);
    back.setPosition(0, 0);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
    }

    //return 1;
    window.clear(); // Effacer le contenu de la fenêtre
    window.draw(back); // Dessiner le sprite
    window.display(); // Afficher le contenu de la fenêtre


    /*mywindow window;
    return window.myWindow();*/

}

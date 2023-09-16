#include <SFML/Graphics.hpp>
using namespace sf;

class Shooting{
    private:
        sf::RectangleShape* body;
        bool shot;
    public:
        Shooting(); // default constuctor
        void draw(sf::RenderWindow* win); // draws the bullets
        void set_position(sf::Vector2f position); // sets the position of the bullets same as the tanks
        void move(); // speed of the bullet
        bool isShot(); // check if the bullet is fired
        void useShot(sf::Vector2f position); // shoting the bullet
        ~Shooting();

};
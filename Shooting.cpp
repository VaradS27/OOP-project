#include <SFML/Graphics.hpp>
#include "Shooting.h"
using namespace sf;

Shooting::Shooting(){
    body = new sf::RectangleShape(sf::Vector2f(5,5));
    body->setFillColor(sf::Color(255,0,0)); // color 'RED' for the bullet
    //body->setPosition(-1,-1);
    shot = false;
}
void Shooting::draw(sf::RenderWindow* win){
    win->draw(*body); // draws the bullet
}
void Shooting::set_position(sf::Vector2f position){
    body->setPosition(position);
}
void Shooting::move(){
    body->move(0,-1); // change this 
}
bool Shooting::isShot(){
    return shot;
}
void Shooting::useShot(sf::Vector2f position){
    body->setPosition(position);
    shot = true;
}
Shooting::~Shooting(){ 
}
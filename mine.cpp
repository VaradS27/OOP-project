#include "mine.h"
#include "playerOne.h"
#include "movement.h"

Mine::Mine(){
mineCordX = 600; // make random
mineCordY = 500; // make random
mine.setRadius(20);
mine.setFillColor(sf::Color::Red);
mine.setPosition(mineCordX, mineCordY);
}
void Mine::draw(RenderWindow& window){
window.draw(mine);
}
// float Mine::clamp(float value, float minn, float maxx){
//     if(value < minn){
//         return minn;
//     } else if(value > maxx){
//         return maxx;
//     } else {
//         return value;
//     }
// }
// int Mine::collision(PlayerOne &R1, CircleShape &C1){
//     // find the closest point of the circle to rectangle
//     float closestX = clamp(600, movement.getX(), movement.getX()+50);
//     float closestY = clamp(500, .getPosition().y, R1.getPosition().y)+50;

//     // get the distance between the two points
//     float distanceX = C1.getPosition().x - closestX;
//     float distanceY = C1.getPosition().y - closestY;

//     // checking the conditions are met and collision occurs, return 1
//     float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
//     if(distanceSquared < C1.getRadius()*C1.getRadius() && closestX != C1.getPosition().x && closestY != C1.getPosition().y){
//         return 1;
//     }else if(distanceSquared < C1.getRadius()*C1.getRadius() && closestX == C1.getPosition().x){
//         return 1;
//     }else if(distanceSquared < C1.getRadius()*C1.getRadius() && closestY == C1.getPosition().y){
//         return 1;
//     }
//     return 0; // no collision hence return 0
// }
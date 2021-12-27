#ifndef TRIANGLE_H //NOLINT
#define TRIANGLE_H
#include <iostream>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
// Copyright
class Triangle : public sf::Drawable {
 public:
          explicit Triangle(double sideLength);
          Triangle(double sideLength, int windowSize);
          Triangle(const Triangle &t);
          double getLength() {
               return length;
          }
          sf::Vector2f getPosition(void);
          void setPosition(sf::Vector2f initialPos);
          void reposition(int childNum, double length);
 private:
          double length;
          sf::ConvexShape tri;
          virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{ //NOLINT function won't work if target is const
               target.draw(tri, states);
          }
};
#endif  // _HOME_OSBOXES_PS3_TRIANGLE_H_

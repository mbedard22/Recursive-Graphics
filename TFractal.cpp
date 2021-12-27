#include "Triangle.h"
// Copyright
void fTree (sf::RenderTarget& target, int N, Triangle& parent); //NOLINT
void fTree (sf::RenderTarget& target, double L, int N, int windowSize); //NOLINT

int main(int argc, char* argv[]) {
     double L = atof(argv[1]);
     int N = atoi(argv[2]);
     int windowSize = L * 3;
     Triangle myTriangle(L, windowSize);
     sf::RenderWindow window1(sf::VideoMode(L * 3, L * 3), "Triangle Fractal");
     while (window1.isOpen()) {
          sf::Event event;
          while (window1.pollEvent(event)) {
               if (event.type == sf::Event::Closed)
                    window1.close();
          }
          window1.clear();
          fTree(window1, L, N, windowSize);
          window1.display();
     }
     return 0;
}


void fTree (sf::RenderTarget& target, int N, Triangle& parent) { //NOLINT
     if (N < 1) {
          return;
     }
     target.draw(parent);
     double newLength = (parent.getLength() / 2);
     Triangle child1(newLength);
     Triangle child2(newLength);
     Triangle child3(newLength);
     child1.setPosition(parent.getPosition());
     child2.setPosition(parent.getPosition());
     child3.setPosition(parent.getPosition());
     child1.reposition(1, newLength);
     child2.reposition(2, newLength);
     child3.reposition(3, newLength);
     fTree(target, N - 1, child1);
     fTree(target, N - 1, child2);
     fTree(target, N - 1, child3);
}

void fTree (sf::RenderTarget& target, double L, int N, int windowSize) { //NOLINT
     Triangle myTriangle(L, windowSize);
     fTree(target, N, myTriangle);
}

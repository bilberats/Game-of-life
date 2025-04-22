//
// Created by leroy on 06/08/2022.
//

#ifndef JEUDELAVIE_DISPLAY_H
#define JEUDELAVIE_DISPLAY_H
#include <SFML/Graphics.hpp>


class Display {
public:
    Display(int newsize,int taillegrille):size(newsize),grillewidth(taillegrille){};
    void init();
    void update(int** tab);
    void inputs(int** tab);
    sf::RenderWindow window;
private:
    int size;
    int grillewidth;
};


#endif //JEUDELAVIE_DISPLAY_H

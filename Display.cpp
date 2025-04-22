//
// Created by leroy on 06/08/2022.
//

#include "Display.h"



void Display::init() {
    this->window.create(sf::VideoMode(this->size, this->size), "SFML works!");
}

void Display::update(int **tab) {
    this->window.clear();
    int squaresize = this->size/this->grillewidth;

    //squares
    sf::RectangleShape square(sf::Vector2f(squaresize, squaresize));
    square.setFillColor(sf::Color::White);
    for(int i=0;i<this->grillewidth;i++){
        for(int j=0;j<this->grillewidth;j++){
            if(tab[i][j]){
                square.setPosition(i*squaresize,j*squaresize);
                this->window.draw(square);
            }
        }
    }

    //grille
    sf::RectangleShape lineHori(sf::Vector2f(this->size,1));
    sf::RectangleShape lineVert(sf::Vector2f(1,this->size));
    lineHori.setFillColor(sf::Color::White);
    lineVert.setFillColor(sf::Color::White);

    for(int i=1;i<this->grillewidth;i++){
        lineHori.setPosition(0,i*squaresize);
        this->window.draw(lineHori);
        lineVert.setPosition(i*squaresize,0);
        this->window.draw(lineVert);
    }

    this->window.display();
}

void Display::inputs(int** tab) {
    int squaresize = this->size / this->grillewidth;
    sf::Vector2<int> mousepos = sf::Mouse::getPosition(window);
    if (mousepos.x >= 0 && mousepos.x <= this->size && mousepos.y >= 0 && mousepos.y <= this->size) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            tab[mousepos.x / squaresize][mousepos.y / squaresize] = 1;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
            tab[mousepos.x / squaresize][mousepos.y / squaresize] = 0;
        }
    }
}

#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include "Core.h"
#include "Display.h"


using namespace std;

void printtab2D(int** tab,int lentab){
    for(int i=0;i<lentab;i++){
        for(int j=0;j<lentab;j++){
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int** table;
    int n = 50;
    float updatetime = 1;


    table = (int**) malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        table[i] = (int*) malloc(sizeof(int)*n);
        for(int j=0;j<n;j++){
            table[i][j]=0;
        }
    }
    //grenouille
    /*
    table[2][5]=1;
    table[3][3]=1;
    table[4][3]=1;
    table[3][6]=1;
    table[4][6]=1;
    table[5][4]=1;
    */

    //planeur
    table[2][4]=1;
    table[3][5]=1;
    table[4][3]=1;
    table[4][4]=1;
    table[4][5]=1;


    Core core = Core(table,n);

    Display screen(1000,n);
    screen.init();
    int unpaused = 0;
    time_t timer=clock();
    while (screen.window.isOpen())
    {
        sf::Event event;
        while (screen.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                screen.window.close();
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::X){
                    unpaused = !unpaused;       //  PAUSE/UNPAUSE
                }else if(event.key.code == sf::Keyboard::Space && !unpaused){
                    core.update();              //  ONE UPDATE
                    table = core.getTab();
                }else if(event.key.code == sf::Keyboard::R){
                    core.resetTab();
                    table = core.getTab();
                }
            }
        }
        screen.inputs(table);
        screen.update(table);

        if(unpaused && clock()-timer>=1500/updatetime) {
            core.update();
            table = core.getTab();
            timer = clock();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C)){
            updatetime+=0.05;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
            updatetime-=0.05;
        }
        if(updatetime<0){
            updatetime=0;
        }


    }

    for(int i=0;i<n;i++){
        free(table[i]);
    }
    free(table);
    return 0;
}

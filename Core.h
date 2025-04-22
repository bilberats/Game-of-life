//
// Created by leroy on 06/08/2022.
//

#ifndef JEUDELAVIE_CORE_H
#define JEUDELAVIE_CORE_H

#include <iostream>

using namespace std;

class Core {
public:
    Core(int** initab,int tabsize):tab(initab),size(tabsize){}
    void update();
    int** getTab();
    int getSize();
    void resetTab();
private:
    int **tab;
    int size;
    int alivecellsaround(int x,int y);
};


#endif //JEUDELAVIE_CORE_H

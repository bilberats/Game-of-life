//
// Created by leroy on 06/08/2022.
//

#include "Core.h"


void Core::update() {
    int count=0;
    int newtab[this->size][this->size];

    for(int i=0;i<this->size;i++){

        for(int j=0;j<this->size;j++){
            count = alivecellsaround(i,j);
            newtab[i][j] = (count==3 || (this->tab[i][j] && count==2));
        }
    }
    for(int i=0;i<this->size;i++){
        for(int j=0;j<this->size;j++){
            this->tab[i][j]=newtab[i][j];
        }
    }
}

int Core::alivecellsaround(int x,int y) {
    int count=0;
    if(x>0){

        if(this->tab[x-1][y]){
            count++;
        }
        if(y+1<this->size && this->tab[x-1][y+1]){
            count++;
        }
        if(y>0 && this->tab[x-1][y-1]){
            count++;
        }
    }
    if(x+1<this->size){
        if(this->tab[x+1][y]){
            count++;
        }
        if(y>0 && this->tab[x+1][y-1]){
            count++;
        }
        if(y+1<this->size && this->tab[x+1][y+1]){
            count++;
        }
    }
    if(y>0 && this->tab[x][y-1]){
        count++;
    }
    if(y+1<this->size && this->tab[x][y+1]){
        count++;
    }
    return count;
}

int **Core::getTab() {
    return this->tab;
}

int Core::getSize() {
    return this->size;
}

void Core::resetTab() {
    for(int i=0;i<this->size;i++){
        for(int j=0;j<this->size;j++){
            this->tab[i][j]=0;
        }
    }
}

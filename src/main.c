#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"

int shots = 40;
int size = 10;

int main() {

    printf("\nEntrez une taille de plateau : ");
    fscanf(stdin,"%d",&size);

    InitBoard(size);
    PlaceShips(5);


    for (int i = 0; i < shots; i++)
    {
        int x;
        int y;

        DisplayBoard();
        printf("\nEntrez X : ");
        fscanf(stdin,"%d",&x);
        if(x > size){
            return 0;
        }
        printf("\nEntrez Y : ");
        fscanf(stdin,"%d",&y);
        if(y > size){
            return 0;
        }

        Shoot(x-1,y-1);
    }
    

    FreeBoard();
    return 0;
}


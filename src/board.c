#include <stdbool.h>
#include "board.h"
#include <stdlib.h>
#include <stdio.h>

Board board;
int boardSize;
int shipNumber;

void InitBoard(int boardSizeTemp){
    boardSize=boardSizeTemp;
    char** pgrid = (char**) malloc(sizeof(char*)*boardSize);
    if(pgrid == 0){
        return;
    }
    for (int i = 0; i < boardSize; i++)
    {
        pgrid[i] = (char*) malloc(sizeof(char)*boardSize);
        if(pgrid[i] == 0){
            return;
        }
        for (int j = 0; j < boardSize; j++)
        {
            pgrid[i][j] = NEUTRAL;
        }
    }
    board.grid = pgrid;
}

bool CheckForShip(int x, int y){
    bool touch = false;
    for (int i = 0; i < shipNumber; i++)
    {
        Ship ship = board.ships[i];
        if (ship.isVertical && (ship.y <= y && ship.y+ship.size >= y && ship.x == x))
        {
            touch = true;
        } else if(ship.x <= x && ship.x+ship.size >= x && ship.y == y){
            touch = true;
        }
    }
    return touch;
}

void PlaceShips(int shipNumberTemp){
    shipNumber = shipNumberTemp;
    Ship* ships = (Ship*) malloc(sizeof(Ship)*shipNumber);
    if(ships == 0){
        return;
    }
    board.ships = ships;
    for (int i = 0; i < shipNumber; i++){
        int shipSize = i+2;
        bool isPlaced = false;
        while (!isPlaced)
        {
            int direction = rand() % 2; //1 = Vertical, 0 = Horizontal
            int x = rand() % boardSize;
            int y = rand() % boardSize;
            bool canPlace = false;
            if(direction == 1 && y+shipSize < boardSize){
                canPlace = true;
                for (int i = 0; i < shipSize; i++)
                {
                    if(CheckForShip(x, y+i)){
                        canPlace = false;
                    }
                }
            } else if (direction == 0 && x+shipSize < boardSize){
                canPlace = true;
                for (int i = 0; i < shipSize; i++)
                {
                    if(CheckForShip(x+i,y)){
                        canPlace = false;
                    }
                }
            }

            if(canPlace){
                Ship ship = {.x = x,.y = y,.isVertical = direction,.size=shipSize};
                board.ships[i] = ship;
                isPlaced = true;
            }
        }
    }
    
}

void Shoot(int x, int y){
    if(CheckForShip(x,y)){
        board.grid[y][x] = STRUCK;
    } else {
        board.grid[y][x] = EMPTY;
    }
}

void CheckForSink(){
    for (int i = 0; i < board.ships; i++)
    {
        bool isSunk = true;
        Ship ship = board.ships[i];
        for (int j = 0; j < ship.size; j++)
        {
            if (ship.isVertical)
            {
                /* TODO */
            }
            
        }
        
    }
    
}

void FreeBoard(){
    for (int i = 0; i < boardSize; i++)
    {
        free(board.grid[i]);
    }
    free(board.grid);
    free(board.ships);
}

void DisplayBoard(){
    printf("\e[1;1H\e[2J");
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            printf("%c ", board.grid[i][j]);
        }
        printf("\n");
    }
}
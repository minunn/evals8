#ifndef BOARD_H
#define BOARD_H

#define NEUTRAL '0'
#define EMPTY '.'
#define STRUCK '#'
#define SUNK '@'

#define BOARD_SIZE 10
#define MAX_SHIPS 5

typedef struct {
    int x;
    int y;
    int size;
    bool isVertical;
} Ship;

typedef struct {
    char** grid;
    Ship* ships;
} Board;

void InitBoard(int boardSizeTemp);
void PlaceShips(int shipNumberTemp);
void DisplayBoard();
void Shoot(int x, int y);
void FreeBoard();
void CheckForSink();

#endif
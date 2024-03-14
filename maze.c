#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//define the maze dimensions
#define MAX_WIDTH 100
#define MIN_WIDTH 5
#define MAX_HEIGHT 100
#define MIN_HEIGHT 5

typdef struct Maze{
    int height;
    int width;
    char mazeSize[MAX_HEIGHT][MAX_WIDTH];
} maze;

//struct to hold player position
typdef struct Player{
    int x;
    int y;
} player;

//function to load the maze from data file
void loadMaze(char maze[][MAZE_WIDTH], const char* mazeFile){
    //reads maze data from the specified file

}

//function to show map
void showMap(){
    //shows map with player position marked with an X
}


//function for main game loop
void gameLoop(){
    //asks for users WASD inputs
    //handles player moving around maze
}


//function to check if player has won
int checkWin(){
    //checks if player reached E
    //if on E return 1
}

int main() {

    //set up wasd keys for movement

    //initialize a 2d array to store the size of the maze
    char mazeSize[MAX_HEIGHT][MAX_WIDTH];

    //call function to load the maze from a data file

    //find start position in maze and place player there

    //run the game loop

    //check conditions satisfied for player to win the game

    return 0;
}
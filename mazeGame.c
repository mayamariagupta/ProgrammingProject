#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int x, y; // Player's position
} Player;

typedef struct {
    char map[MAX_SIZE][MAX_SIZE]; // The maze
    int width, height; // Size of the maze
    Player player; // The player
} Maze;

// Function prototypes
int load_maze(const char *filename, Maze *maze);
void print_maze(Maze *maze);
void move_player(Maze *maze, char direction);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./maze <mazefile path>\n");
        return 1;
    }

    Maze maze;
    int load_status = load_maze(argv[1], &maze);
    if (load_status != 0) {
        return load_status; // Return the error code from load_maze
    }

    char command;
    do {
        printf("Enter command (WASD to move, M to show map): ");
        scanf(" %c", &command); // The space before %c eats the newline

        if (command == 'M' || command == 'm') {
            print_maze(&maze);
        } else {
            move_player(&maze, command);
        }
    } while (maze.map[maze.player.y][maze.player.x] != 'E');

    printf("Congratulations, you've exited the maze!\n");

    return 0; // Successful running
}

int load_maze(const char *filename, Maze *maze) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 2; // File error
    }

    // Read the maze from the file
    // This is a simplified version and does not check for invalid mazes
    maze->width = 0;
    maze->height = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            maze->height++;
        } else {
            maze->map[maze->height][maze->width] = ch;
            if (ch == 'S') {
                maze->player.x = maze->width;
                maze->player.y = maze->height;
            }
            maze->width++;
        }
    }

    fclose(file);
    return 0; // Successful loading
}

void print_maze(Maze *maze) {
    for (int y = 0; y < maze->height; y++) {
        for (int x = 0; x < maze->width; x++) {
            if (x == maze->player.x && y == maze->player.y) {
                printf("X");
            } else {
                printf("%c", maze->map[y][x]);
            }
        }
        printf("\n");
    }
}

void move_player(Maze *maze, char direction) {
    int dx = 0, dy = 0;
    switch (direction) {
        case 'W': case 'w': dy = -1; break;
        case 'A': case 'a': dx = -1; break;
        case 'S': case 's': dy = 1; break;
        case 'D': case 'd': dx = 1; break;
    }

    int new_x = maze->player.x + dx;
    int new_y = maze->player.y + dy;
    if (new_x >= 0 && new_x < maze->width && new_y >= 0 && new_y < maze->height && maze->map[new_y][new_x] != '#') {
        maze->player.x = new_x;
        maze->player.y = new_y;
    } else {
        printf("You cannot move in that direction.\n");
    }
}

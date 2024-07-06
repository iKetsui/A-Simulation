#include <stdio.h>
#include "raylib.h"
#include <stdlib.h> 
#include <time.h> 

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define CELL_SIZE 50

// Define a structure to represent a cell
typedef struct {
    Vector2 position; // Location in the grid
    Color color;      // Color of the cell
    bool isActive;    // State of the cell
} Cell;

// Function prototypes
void drawGrid(Cell grid[][SCREEN_WIDTH / CELL_SIZE]);
void handleInput(Cell grid[][SCREEN_WIDTH / CELL_SIZE]);

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Grid Cells");
    SetTargetFPS(60);

    srand(time(0));
    int random = rand() % ( 12 - 1 + 1)  ;  
    int random2 = rand() % ( 12 - 1 + 1)  ;  


    // Create a grid of cells
    Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE];

    // Initialize the grid
    for (int y = 0; y < SCREEN_HEIGHT / CELL_SIZE; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH / CELL_SIZE; x++)
        {
            grid[y][x].position = (Vector2){x * CELL_SIZE, y * CELL_SIZE};
            grid[y][x].color = WHITE; // Initial color
            grid[y][x].isActive = false; // Initially inactive
            
        }
    }
            grid[random2][random2].color = RED;
            grid[random2][random2].isActive = true;
            grid[random][random].color = GREEN;
            grid[random][random].isActive = true;

    while (!WindowShouldClose()) 
    {

        BeginDrawing();
        ClearBackground(GRAY);
        drawGrid(grid);
        EndDrawing();

    }

    CloseWindow();

    return 0;
}

// Draw the grid
void drawGrid(Cell grid[][SCREEN_WIDTH / CELL_SIZE])
{
    for (int y = 0; y < SCREEN_HEIGHT / CELL_SIZE; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH / CELL_SIZE; x++)
        {
            DrawRectangleV(grid[y][x].position, (Vector2){CELL_SIZE, CELL_SIZE}, grid[y][x].color);
        }
    }
}


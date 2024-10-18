#include "life.hpp"
#include <ncurses.h>
#include <array>
#include <set>
#include <unistd.h> // for usleep

using namespace std;

// Function to check if a cell is alive
bool isAlive(const BOARD &m, int r, int c) {
    return m.find(CELL{r, c}) != m.end();
}

// Function to count the number of live neighbors for a given cell
int countNeighbour(const BOARD &board, int row, int col) {
    int liveNeighbors = 0;
    array<int, 8> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    array<int, 8> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    for (int i = 0; i < 8; ++i) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];
        
        // Check if the neighbor is within bounds
        if (newRow >= 0 && newRow < NROW && newCol >= 0 && newCol < NCOL) {
            if (isAlive(board, newRow, newCol)) {
                liveNeighbors++;
            }
        }
    }
    return liveNeighbors;
}

// Function to display the board using ncurses
void displayBoard(const BOARD &board) {
    clear(); // Clear the previous content
    for (const CELL &cell : board) {
        mvprintw(cell[0], cell[1], "X"); // Display live cells as 'X'
    }
    refresh(); // Refresh the screen to show changes
}

// Function to handle mouse input and toggle cells
void handleMouseInput(BOARD &board) {
    MEVENT event;
    if (getmouse(&event) == OK) {
        int row = event.y;
        int col = event.x;
        if (row >= 0 && row < NROW && col >= 0 && col < NCOL) { // Ensure within bounds
            CELL clickedCell = {row, col};
            if (board.find(clickedCell) == board.end()) {
                board.insert(clickedCell); // Add live cell
            } else {
                board.erase(clickedCell); // Remove live cell
            }
            displayBoard(board);
        }
    }
}

// Function to run the Game of Life with continuous generations
void runGameOfLife(BOARD &board) {
    while (true) {
        // Check if 'q' is pressed to quit the game
        timeout(1000); // Set a timeout of 100ms for input
        int ch = getch();
        if (ch == 'q') break; // Quit if 'q' is pressed

        // Calculate the next generation
        BOARD nextBoard; // Create a new board for the next generation

        // Loop through each cell in the grid
        for (int r = 0; r < NROW; r++) {
            for (int c = 0; c < NCOL; c++) {
                int liveNeighbours = countNeighbour(board, r, c); // Count live neighbors

                if (isAlive(board, r, c)) {
                    // Cell survives if it has 2 or 3 live neighbors
                    if (liveNeighbours == 2 || liveNeighbours == 3) {
                        nextBoard.insert(CELL{r, c}); // Cell survives
                    }
                } else {
                    // Dead cell becomes alive if it has exactly 3 live neighbors
                    if (liveNeighbours == 3) {
                        nextBoard.insert(CELL{r, c}); // Cell is born
                    }
                }
            }
        }

        // Update the board to the next generation
        board = nextBoard;

        // Display the current board
        displayBoard(board);
        usleep(2500); // Sleep between generations
    }
}


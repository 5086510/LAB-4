#include <ncurses.h>
#include <unistd.h> // for usleep
#include "life.hpp"

int main() {
    // Initialize ncurses
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE); // Enable special keys (arrow, mouse)
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL); // Enable mouse events
    BOARD board; // Set to store live cells

    // Instructions
    mvprintw(0, 0, "Click to toggle cells, press 's' to start, 'q' to quit during simulation.");
    refresh();

    // Allow user to click and configure initial setup
    while (true) {
        int ch = getch();
        if (ch == KEY_MOUSE) {
            handleMouseInput(board); // Handle mouse clicks to toggle cells
        } else if (ch == 's') {
            if (board.empty()) {
                mvprintw(2, 0, "No live cells selected! Please toggle some cells before starting.");
                refresh();
                usleep(2000000); // Wait for 2 seconds to read the message
                mvprintw(2, 0, "                                   "); // Clear the message
            } else {
                break; // Start the game after pressing 's'
            }
        }
    }

    // Start running the Game of Life continuously
    runGameOfLife(board);

    // End ncurses mode
    endwin();

    return 0;
}


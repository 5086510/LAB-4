#ifndef LIFE_HPP
#define LIFE_HPP

#include <array>
#include <set>

using CELL = std::array<int, 2>;
using BOARD = std::set<CELL>;

const int NROW = 24; // Number of rows
const int NCOL = 80; // Number of columns

bool isAlive(const BOARD &m, int r, int c);
int countNeighbour(const BOARD &board, int row, int col);
void displayBoard(const BOARD &board);
void handleMouseInput(BOARD &board);
void runGameOfLife(BOARD &board);

#endif // LIFE_HPP


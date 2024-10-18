# Nemanja Blagojevic
# Lab assignment 4
**what is the assignment doing**

This lab assignment consists of two distinct programs that simulate popular games: a dice game called "Craps" and Conway's Game of Life.

*Program 1*

The first program simulates the dice game "Craps." In this game, a player rolls two dice and bets a certain amount of credits. The player can win or lose based on the sum of the rolled dice, and the program tracks the player's credits.

*Program 2*

The second program implements Conway's Game of Life. It reads the initial configuration of live cells, displays the first generation, and continues to show subsequent generations until the user decides to quit. The program utilizes the ncurses library for user interaction.

**how to build your program**

*Program 1*

Compile the files and run ./program1

*Program 2*

Compile the files and run ./game_of_life

**how to use your program**

*Program 1*

The game starts with a balance of 100 credits.

You will be prompted to wager an amount before each game.

The game rules are as follows:

Win: You win if you roll a sum of 7 or 11 on the first throw.

Lose: You lose if you roll a sum of 2, 3, or 12 on the first throw.

Point Established: If you roll a sum of 4, 5, 6, 8, 9, or 10, that becomes your "point." You must roll your point again before rolling a 7 to win.

After each game, you can choose to play again or exit.

*Program 2*

Choose the initial configuration of live cells and press "s" for program to start

The program displays the next generations of live cells until you press the letter q to exit the program.

Any live cell with fewer than two live neighbours dies, as if by underpopulation.

Any live cell with two or three live neighbours lives on to the next generation.

Any live cell with more than three live neighbours dies, as if by overpopulation.

Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

**Any limitation, issues**

*Program 1* - The player must enter valid integer values when wagering. Invalid inputs may lead to undefined behavior.

*Program 2* - The initial configuration must be manually set up by clicking.

Performance may degrade with larger boards or many live cells due to set operations and continuous rendering.

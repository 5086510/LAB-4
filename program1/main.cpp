#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
using namespace std;

void playGame();
int die();
int rollDice();

int main() {
    char ans;
    bool done = false;
    srand(static_cast<unsigned int>(time(0))); // Random number
    while (!done) {
        playGame(); 
        cout << "Play again (y/n)? ";
        cin >> ans;
        if (ans == 'n' || ans == 'N') done = true;
        else done = false;
    }
    return 0;
}

// will return the result of rolling a die
int die() {
    return (rand() % 6) + 1;  // Random number between 1 and 6
}

int rollDice() {
    int die1 = die();
    int die2 = die();
    cout << "player rolled " << die1 << " + " << die2 << " = " << (die1 + die2) << endl;
    return die1 + die2;
}

void playGame() {
    static int balance = 100;  
    int wager, point, sum;
    
    if (balance == 0) {
        cout << "You are out of credits - game over!" << endl;
        exit(0);
    }

    cout << "You have " << balance << " credits. How much do you wager? ";
    cin >> wager;

    // Validate wager
    while (wager > balance || wager <= 0) {
        cout << "Your wager exceeds your balance or is invalid. Try again." << endl;
        cout << "How much do you wager? ";
        cin >> wager;
    }

    sum = rollDice();

    // Determine the outcome of the first roll
    if (sum == 7 || sum == 11) {
        cout << "player wins" << endl;
        balance += wager;
        cout << "You won " << wager << " credits. Your new balance is " << balance << " credits" << endl;
    } else if (sum == 2 || sum == 3 || sum == 12) {
        cout << "player loses" << endl;
        balance -= wager;
        cout << "You lost " << wager << " credits. Your new balance is " << balance << " credits" << endl;
    } else {
        // Player's point is set
        point = sum;
        cout << "point is " << point << endl;

        // Continue rolling until player makes the point or loses by rolling a 7
        do {
            sum = rollDice();
        } while (sum != point && sum != 7);

        if (sum == point) {
            cout << "player wins" << endl;
            balance += wager;
            cout << "You won " << wager << " credits. Your new balance is " << balance << " credits" << endl;
        } else if (sum == 7) {
            cout << "player loses" << endl;
            balance -= wager;
            cout << "You lost " << wager << " credits. Your new balance is " << balance << " credits" << endl;
        }
    }

    if (balance == 0) {
        cout << "You are out of credits - game over!" << endl;
        exit(0);
    }
}


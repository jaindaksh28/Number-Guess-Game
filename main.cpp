#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string name;
    int number, guess, tries = 0, maxRange;
    char wantHint;

    // Get player's name
    cout << "Enter your name: ";
    cin >> name;
    cout << "\n Welcome, " << name << "! Let's play the Number Guessing Game!\n";

    // Choose difficulty
    int choice;
    cout << "\nChoose difficulty level:\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard \n";
    cout << "Enter your choice : ";
    cin >> choice;

    if (choice == 1)
        maxRange = 50;
    else if (choice == 2)
        maxRange = 100;
    else
        maxRange = 500;

    // Seed random number generator
    srand(time(0));
    number = rand() % maxRange + 1;

    cout << "\nI'm thinking of a number between 1 and " << maxRange << ".\n";

    // Ask if player wants hints
    cout << "Do you want a hint during the game? (y/n): ";
    cin >> wantHint;

    // Main game loop
    do {
        cout << "\nEnter your guess: ";
        cin >> guess;
        tries++;

        if (guess > number) {
            cout << "Too high!\n";
        } else if (guess < number) {
            cout << "Too low!\n";
        } else {
            cout << " Correct, " << name << "! You guessed it in " << tries << " tries.\n";
            break;
        }

        
        if (wantHint == 'y' || wantHint == 'Y') {
            if (tries == 3) {
                cout << "💡 Hint: The number is " 
                     << (number % 2 == 0 ? "even.\n" : "odd.\n");
            } else if (tries == 5) {
                if (number > maxRange / 2)
                    cout << " Hint: The number is greater than " << maxRange / 2 << ".\n";
                else
                    cout << " Hint: The number is less than or equal to " << maxRange / 2 << ".\n";
            }
        }

    } while (guess != number);

    return 0;
}
//Program which generates the random number and asks the user to guess it .

#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int userGuess = 0;
    int numberOfGuesses = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a random number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    // Loop until the user guesses the correct number
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        numberOfGuesses++;

        if (userGuess > randomNumber) {
            cout << "Your guess is too high. Try again." << endl;
        } else if (userGuess < randomNumber) {
            cout << "Your guess is too low. Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number: " << randomNumber << endl;
            cout << "It took you " << numberOfGuesses << " guesses." << endl;
        }
    } while (userGuess != randomNumber);

    return 0;
}

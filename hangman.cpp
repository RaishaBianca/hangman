#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

// Function to generate a random word for the game
std::string generateRandomWord() {
    std::vector<std::string> words = { "apple", "banana", "chocolate", "dinosaur", "elephant", "football" };

    // Generate a random index to select a word from the vector
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

// Function to check if the guessed letter is present in the word
bool isGuessCorrect(const std::string& word, char guess) {
    for (char c : word) {
        if (c == guess) {
            return true;
        }
    }
    return false;
}

// Function to update the word display with correct guesses
void updateWordDisplay(const std::string& word, const std::string& guessedLetters, std::string& wordDisplay) {
    wordDisplay = "";
    for (char c : word) {
        if (guessedLetters.find(c) != std::string::npos) {
            wordDisplay += c;
        } else {
            wordDisplay += "-";
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    std::string word = generateRandomWord();
    std::string guessedLetters;
    std::string wordDisplay(word.length(), '-');
    int remainingAttempts = 6;

    std::cout << "Welcome to Hangman!" << std::endl;
    std::cout << "Guess the word: " << wordDisplay << std::endl;

    while (remainingAttempts > 0 && wordDisplay != word) {
        std::cout << "Enter your guess (a-z): ";
        char guess;
        std::cin >> guess;
        guess = tolower(guess);

        if (guessedLetters.find(guess) != std::string::npos) {
            std::cout << "You already guessed that letter. Try again." << std::endl;
            continue;
        }

        guessedLetters += guess;

        if (isGuessCorrect(word, guess)) {
            updateWordDisplay(word, guessedLetters, wordDisplay);
            std::cout << "Correct guess! Word: " << wordDisplay << std::endl;
        } else {
            remainingAttempts--;
            std::cout << "Wrong guess! You have " << remainingAttempts << " attempts left." << std::endl;
        }
    }

    if (wordDisplay == word) {
        std::cout << "Congratulations! You guessed the word correctly: " << word << std::endl;
    } else {
        std::cout << "Game over! The word was: " << word << std::endl;
    }

    return 0;
}

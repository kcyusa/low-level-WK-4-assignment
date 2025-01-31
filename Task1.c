#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_GUESSES 6
#define WORD_COUNT 6
#define MAX_WORD_LENGTH 20


const char *wordList[WORD_COUNT] = {"lemans", "banana", "cherry", "date","programming","football"};


void chooseWord(char *selectedWord) {
    srand(time(NULL)); 
    int randomIndex = rand() % WORD_COUNT;
    strcpy(selectedWord, wordList[randomIndex]);
}


void displayWord(const char *word, const int *guessed) {
    for (int i = 0; i < strlen(word); i++) {
        if (guessed[i])
            printf("%c ", word[i]);
        else
            printf("_ ");
    }
    printf("\n");
}


int checkGuess(char guess, const char *word, int *guessed) {
    int found = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (tolower(word[i]) == tolower(guess)) {
            guessed[i] = 1;
            found = 1;
        }
    }
    return found;
}


int isWordGuessed(const int *guessed, int length) {
    for (int i = 0; i < length; i++) {
        if (!guessed[i])
            return 0;
    }
    return 1;
}


void playGame() {
    char selectedWord[MAX_WORD_LENGTH];
    chooseWord(selectedWord);
    int wordLength = strlen(selectedWord);

    int guessed[wordLength]; 
    memset(guessed, 0, sizeof(guessed)); 

    int incorrectGuesses = 0;
    char guessedLetters[MAX_WORD_LENGTH + MAX_GUESSES];
    int guessedCount = 0;

    printf("\n=== Welcome to Guessing Game ===\n");

    while (incorrectGuesses < MAX_GUESSES) {
        printf("\nWord: ");
        displayWord(selectedWord, guessed);
        printf("Incorrect guesses: %d/%d\n", incorrectGuesses, MAX_GUESSES);

        printf("Guessed letters: ");
        for (int i = 0; i < guessedCount; i++)
            printf("%c ", guessedLetters[i]);
        printf("\n");

        printf("Enter a letter: ");
        char guess;
        scanf(" %c", &guess);
        guess = tolower(guess);

        
        int alreadyGuessed = 0;
        for (int i = 0; i < guessedCount; i++) {
            if (guessedLetters[i] == guess) {
                alreadyGuessed = 1;
                break;
            }
        }

        if (alreadyGuessed) {
            printf("You already guessed '%c'. Try again.\n", guess);
            continue;
        }

        guessedLetters[guessedCount++] = guess; 

        if (checkGuess(guess, selectedWord, guessed)) {
            printf("Correct!\n");
        } else {
            printf("Wrong guess!\n");
            incorrectGuesses++;
        }

        if (isWordGuessed(guessed, wordLength)) {
            printf("\n🎉 Congratulations! You guessed the word: %s\n", selectedWord);
            printf("Your score: %d\n", (MAX_GUESSES - incorrectGuesses) * 10);
            return;
        }
    }

    printf("\n😢 You lost! The correct word was: %s\n", selectedWord);
}

int main() {
    char playAgain;
    do {
        playGame();
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (tolower(playAgain) == 'y');

    printf("Thanks for playing!\n");
    return 0;
}

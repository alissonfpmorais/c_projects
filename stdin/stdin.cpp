#include <stdio.h>
#include <stdlib.h>

// Main function
int main() {
    // Used in loop
    int i;

    // How many characters the sentence will have
    int sentenceLength = 100;

    // Size needed to alocate the whole sentence in memory
    int buffer = sizeof(char) * sentenceLength;

    // The sentence itself
    char *sentence = (char *) malloc(buffer);
    // The letter captured in stdin
    char letter;

    // Capture first letter
    letter = getchar();

    // Loop through stdin until reaches one of the three conditions
    // 1) End the array size
    // 2) Reach a break line
    // 3) Reach end of string
    for(i = 0; i < sentenceLength && letter != '\n' && letter != '\0'; i++) {
        // Add letter to sentence
        *(sentence + sizeof(char) * i) = letter;
        // Get new letter from stdin
        letter = getchar();
    }

    // Print the whole sentence
    printf("Sentence: %s", sentence);
    // Wait until user type something
    scanf("%d", &i);

    // Free allocated memory
    free(sentence);

    return 0;
}
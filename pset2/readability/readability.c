#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int numberOfLetters(string text);
int numberOfWords(string text);
int numberOfSentences(string text);

float indexL(int letters, int words);
float indexS(int sentences, int words);
float colemanLiau(float L, float S);

void showGrade(float index);

int main(void)
{
    string text = get_string("Text: ");
    int number_of_letters = numberOfLetters(text);
    int number_of_words = numberOfWords(text);
    int number_of_sentences = numberOfSentences(text);

    float L = indexL(number_of_letters, number_of_words);
    float S = indexS(number_of_sentences, number_of_words);

    float indexGrade = colemanLiau(L, S);

    showGrade(indexGrade);
}

int numberOfLetters(string text) {
    int counter = 0;
    for(int i = 0; i < strlen(text); i++) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            counter++;
        } else if(text[i] >= 'A' && text[i] <= 'Z') {
            counter++;
        }
    }

    return counter;
}

int numberOfWords(string text) {
    int counter = 1;
    for(int i = 0; i < strlen(text); i++) {
        if( (int) text[i] == 32) {
            counter++;
        }
    }

    return counter;
}

int numberOfSentences(string text) {
    int counter = 0;

    for(int i = 0; i < strlen(text); i++) {
        if((int) text[i] == 33 || (int) text[i] == 46 || (int) text[i] == 63) {
            counter++;
        }
    }

    return counter;
}

float indexL(int letters, int words) {
    return letters * 100.0 / words;
}

float indexS(int sentences, int words) {
    return sentences * 100.0 / words;
}

float colemanLiau(float L, float S) {
    return (0.0588 * L) - (0.296 * S) - 15.8;
}

void showGrade(float index) {
    if(index < 1) {
        printf("Before Grade 1\n");
    } else if (index > 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %i\n", (int) round(index));
    }
}
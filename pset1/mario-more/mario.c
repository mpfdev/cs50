#include <cs50.h>
#include <stdio.h>

//prototype
void printSpaces(int n);
void printHashes(int n);

int main(void)
{
    int height;
    do{
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for(int i = 1; i <= height; i++) {
        printSpaces(height - i);
        printHashes(i);
        printSpaces(2);
        printHashes(i);
        printf("\n");
    }
}

void printSpaces(int n) {
    for(int i = 0; i < n; i++) {
        printf(" ");
    }
}

void printHashes(int n) {
    for(int i = 0; i < n; i++) {
        printf("#");
    }
}
#include <cs50.h>
#include <stdio.h>

//C Prototype (to show the compiler that there is a Function created like this, but its not here, yet!!!!)
void printSpaces(int n);
void printHashes(int n);

int main(void)
{
    int height;
    do {
        height = get_int("Height: ");
    }
    while (height < 1);

    //Number of rows
    for(int i = 1; i <= height; i++) {
        printSpaces(height - i);
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
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Prototype
void magicText(string text, int code);

int main(int argc, string argv[])
{
    int cypher = atoi(argv[1]);

    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    magicText(plaintext, cypher);

}

void magicText(string text, int code) {
    string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string abc = "abcdefghijklmnopqrstuvwxyz";

    char cypher[strlen(text)];

    for(int i = 0; i < strlen(text); i++) {
        if(isalpha(text[i])) {

            if(isupper(text[i])) {
                int pos = text[i] - 65;
                int newPos = (pos + code) % 26;
                cypher[i] = ABC[newPos];
            } else {
                int pos = text[i] - 97;
                int newPos = (pos + code) % 26;
                cypher[i] = abc[newPos];
            }

        } else {
            cypher[i] = text[i];
        }
    }

    printf("cyphertext: %s\n", cypher);
}
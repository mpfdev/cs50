#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Prototype C
bool validateKey(string key, int numOfArguments);
void encrypt(string text, string key);

int main(int argc, string argv[])
{
    string key = argv[1];
    int nArguments = argc;

    bool isKeyValid = validateKey(key, nArguments);

    if(isKeyValid == false) {
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    encrypt(plaintext, key);

}

void encrypt(string text, string key) {
    char cyphertext[strlen(text)];

    for(int i = 0; i < strlen(text); i++) {
        if(isalpha(text[i])) {
            if(isupper(text[i])) {
                int pos = text[i] - 65;
                cyphertext[i] = toupper(key[pos]);
            } else {
                int pos = text[i] - 97;
                cyphertext[i] = tolower(key[pos]);
            }
        } else {
            cyphertext[i] = text[i];
        }
    }

    printf("%s\n", cyphertext);
}

bool validateKey(string key, int numOfArguments) {
    if(numOfArguments != 2) {
        printf("Usage: ./substitution key\n");
        return false;
    }

    if(strlen(key) != 26) {
        for(int i = 0; i < strlen(key); i++) {
            if(isalpha(key[i])) {
                printf("Key must contain 26 characters.\n");
                return false;
            } else {
                printf("Usage: ./substitution key\n");
                return false;
            }
        }
    }
    return true;

}
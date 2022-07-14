#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Prototype
bool luhnAlgo(long cardNumber);
void cardProvider(int cardLength, long cardNumber);
int cardLength(long cardNumber);

int main(void)
{
    long cardNumber = get_long("Card Number: ");

    if(luhnAlgo(cardNumber) == true) {

        int lengthNumber = cardLength(cardNumber);

        cardProvider(lengthNumber, cardNumber);

    } else {
        printf("INVALID\n");
    }
}

bool luhnAlgo(long cardNumber) {
    //
    long temp = cardNumber;
    int sum = 0;
    int oddSum = 0;
    int evenSum = 0;

    for(int i = 0; temp > 0; i++) {

        if(i % 2 != 0) {

            if((temp % 10) * 2 >= 10) {
                int newTemp = (temp % 10) * 2;
                oddSum += newTemp % 10;
                newTemp /= 10;
                oddSum += newTemp;
            } else {
                oddSum += ((temp % 10) * 2);
            }

        } else {
            evenSum += temp % 10;
        }

        temp /= 10;

    }

    sum = evenSum + oddSum;

    if(sum % 10 == 0) {
        return true;
    } else {
        return false;
    }
}

void cardProvider(int cardLength, long cardNumber) {

    long firstDigits = cardNumber;

    if(cardLength == 16) {
        firstDigits = firstDigits / (long) (1e15);


        if(firstDigits == 4) {
            printf("VISA\n");
        } else {
            printf("MASTERCARD\n");
        }

    }else if(cardLength == 15) {
        printf("AMERICAN EXPRESS\n");
    }else if(cardLength == 13) {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }
}

int cardLength(long cardNumber) {
    return log10(cardNumber) + 1;
}
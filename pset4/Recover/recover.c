#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if(argc != 2) {
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if(!file) {
        return 1;
    }

    BYTE buffer[512];
    int amountJPEG = 0;
    FILE *img = NULL;
    char filename[10] = {};

    while(fread(buffer, sizeof(BYTE) * 512, 1, file) == 1) {
        if(buffer[0] == 0xFF && buffer[1] == 0XD8 && buffer[2] == 0xFF && (buffer[3] & 0XF0) == 0XE0) {

            if(img != NULL || !(amountJPEG == 0)) {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", amountJPEG++);

            img = fopen(filename, "w");
        }

        if(img != NULL) {
            fwrite(buffer, sizeof(BYTE) * 512, 1, img);
        }
    }

    if(img != NULL) {
        fclose(img);
    }

    fclose(file);

    return 0;
}
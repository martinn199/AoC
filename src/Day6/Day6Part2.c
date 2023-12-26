#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*Define constant*/
#define MAX_LEN 5000

int main() {
    /*Define variables*/
    char data[MAX_LEN];
    char character;
    int i;
    int j;
    int a;
    int b;
    int unique;

    /*Open the file*/
    FILE *fPointer;
    fPointer = fopen("src/Day6/input.txt", "r");

    /*If there exist no file, return an error*/
    if (fPointer == NULL) {
        perror("opening input.txt failed");
        return 1;
    }

    /*Store each character in an array*/
    while ((character = getc(fPointer)) != EOF) {
        data[j] = character;
        j++;
    }
    /*Close the file*/
    fclose(fPointer);

    /*Loop through the file*/
    for(i = 0; i < strlen(data) - 13; i++){
        /*Assume that the we have found the start-of-packet*/
        unique = 1;

        /*Loop through the 14 upcoming characters in the file and check if there are characters that are equal*/
        for(a = 0; a < 14; a++){
            for(b = a + 1; b < 14; b++){
                if(data[i + a] == data[i + b]){
                    unique = 0;
                    break;
                }
            }
            /*If there exist characters that are equal*/
            if(!unique){
                break;
            }
        }
        /*If there is no characters that are equal, break the loop*/
        if(unique){
            break;
        }
    }

    /*When determining the start-of-packet market zero indexing is used. Also the question says that the marker needs to report the
    number of characters from the beginning of the buffer to the end of the sequence where the 14 characters are not equal. Therefore the
    start-of-packet market is at position: i + 1 + 13*/
    printf("The start-of-packet marker is at position: %d\n", i + 1 + 13);
    return 0;
}

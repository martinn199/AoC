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

    /*Open the file*/
    FILE *fPointer;
    fPointer = fopen("Day6/input.txt", "r");

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

    /*Loop through the file and find the sequence where the start-of-packet market is at*/
    for(i = 0; i < strlen(data) - 3; i++){
        if(data[i] != data[i + 1] && data[i] != data[i + 2] && data[i] != data[i + 3] && 
        data[i + 1] != data[i + 2] && data[i + 1] != data[i + 3] &&
        data[i + 2] != data[i + 3]){
            break;
        }
    }
    /*When determining the start-of-packet market zero indexing is used. Also the question says that the marker needs to report the
    number of characters from the beginning of the buffer to the end of the sequence where the four characters are not equal. Therefore the
    start-of-packet market is at position: i + 1 + 3*/
    printf("The start-of-packet marker is at position: %d\n", i + 1 + 3);
    return 0;
}

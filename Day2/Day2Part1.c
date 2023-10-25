#include <stdio.h>
#include <string.h>

int main(){
    /*Define variables and constant*/
    int DATA_SIZE = 5000;
    char character;
    char data[DATA_SIZE];
    char opponent;
    char me;
    int score = 0;
    int me_X = 1;
    int me_Y = 2;
    int me_Z = 3;
    int loss = 0;
    int draw = 3;
    int win = 6;
    int i = 0;
    int j = 0;

    /*Open the file*/
    FILE * fPointer;
    fPointer = fopen("Day2/input.txt", "r");

    /*If there exist no file, return an error*/
    if (fPointer == NULL){
        perror("opening input.txt failed");
        return 1;
    }

    /*Loop through the file and save the characters in a string of characters. Print the
    string too*/
     while ((character = getc(fPointer)) != EOF) {
        if (character != '\n' && character != ' ') {
            data[i] = character;
            printf("%c", data[i]);
            i++;
        }
    }
    /*Print the last value in the string*/
    printf("\nLast value is: %c \n", data[4999]);
    /*Print the length of the string*/
    printf("Length is: %zu \n", sizeof(data));
    fclose(fPointer);

    /*Compare my moves and my opponent moves and calculate the score*/
    for(j = 0; j < DATA_SIZE; j++){
        opponent = data[j];
        me = data[j+1];
        if(opponent == 'A' && me == 'X'){
            score += me_X + draw;
        }
        else if(opponent == 'A' && me == 'Y'){
            score += me_Y + win;
        }
        else if(opponent == 'A' && me == 'Z'){
            score += me_Z + loss;
        }
        else if(opponent == 'B' && me == 'X'){
            score += me_X + loss;
        }
        else if(opponent == 'B' && me == 'Y'){
            score += me_Y + draw;
        }
        else if(opponent == 'B' && me == 'Z'){
            score += me_Z + win;
        }
        else if(opponent == 'C' && me == 'X'){
            score += me_X + win;
        }
        else if(opponent == 'C' && me == 'Y'){
            score += me_Y + loss;
        }
        else if(opponent == 'C' && me == 'Z'){
            score += me_Z + draw;
        }
    }
    printf("My total score is: %d\n", score);

    return 0;
}
#include <stdio.h>
#include <string.h>

int main(){
    /*Define variables and constant*/
    int DATA_SIZE = 5000;
    char character;
    char data[DATA_SIZE];
    char opponent;
    char outcome;
    int score = 0;
    int rock = 1;
    int paper = 2;
    int scissors = 3;
    int loss = 0;
    int draw = 3;
    int win = 6;
    int i = 0;
    int j = 0;

    /*Open the file*/
    FILE * fPointer;
    fPointer = fopen("//home//martin//AoC//Day2//input.txt", "r");

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

    /*Compare my opponent moves and choose the right shape. Then calculate the score*/
    for(j = 0; j < DATA_SIZE; j++){
        opponent = data[j];
        outcome = data[j+1];
        if(opponent == 'A' && outcome == 'X'){
            score += scissors + loss;
        }
        else if(opponent == 'A' && outcome == 'Y'){
            score += rock + draw;
        }
        else if(opponent == 'A' && outcome == 'Z'){
            score += paper + win;
        }
        else if(opponent == 'B' && outcome == 'X'){
            score += rock + loss;
        }
        else if(opponent == 'B' && outcome == 'Y'){
            score += paper + draw;
        }
        else if(opponent == 'B' && outcome == 'Z'){
            score += scissors + win;
        }
        else if(opponent == 'C' && outcome == 'X'){
            score += paper + loss;
        }
        else if(opponent == 'C' && outcome == 'Y'){
            score += scissors + draw;
        }
        else if(opponent == 'C' && outcome == 'Z'){
            score += rock + win;
        }
    }
    printf("My total score is: %d\n", score);

    return 0;
}
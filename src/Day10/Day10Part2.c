#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

/*Define constants*/
#define DATA_SIZE 300

int main() {
    /* Define variables */
    char line[DATA_SIZE];
    /*Register starts with value 1*/
    int X = 1;
    int V;
    int i;
    int j;
    int cycle[DATA_SIZE] = {0};
    int index = 0;

    /*Open the file*/
    FILE *fPointer;
    fPointer = fopen("src/Day10/input.txt", "r");

    /*If there exists no file, return an error*/
    if (fPointer == NULL) {
        perror("opening input.txt failed");
        return 1;
    }

    /*Read each line of the file*/
    while(fgets(line, sizeof(line), fPointer) != NULL){

        /*If the line is "noop" it takes one cycle to complete. Do not increase X*/
        if(strcmp(line, "noop\n") == 0){
            cycle[index++] = X;
        }
        
        /*If the line is "addx V" it takes two cycles to complete. Increase X with V after the second cycle*/
        else{
            sscanf(line, "%*s %d", &V);
            cycle[index++] = X;
            cycle[index++] = X;
            X += V;
        }
    }
    
    /*Create the image by looping over the rows and columns*/
    for(i = 0; i < index - 1; i += 40){
        for(j = 0; j < 40; j++){

            /*Print a "#" if the euclidean distance between the sprite and the CRT is less than or equal to 1*/
            if(abs(cycle[i + j] - j) <= 1){
                printf("#");
            }
            /*Otherwise, print a "."*/
            else{
                printf(".");
            }
        }
        /*At the end of a row, create a new row*/
        printf("\n");

    }
    /*Close the file*/
    fclose(fPointer);

    return 0;
}
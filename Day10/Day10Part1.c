#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

/*Define constants*/
#define DATA_SIZE 300
#define SIGNAL_STRENGTH_CYCLES 220

int main() {
    /* Define variables */
    char line[DATA_SIZE];
    /*Register starts with value 1*/
    int X = 1;
    int V;
    int tot_signal_strengths = 0;
    int i;
    int cycle[DATA_SIZE] = {0};
    /*To make the cycle value consistent with the interesting signal strengths*/
    int index = 1;

    /*Open the file*/
    FILE *fPointer;
    fPointer = fopen("Day10/input.txt", "r");

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

    /*Calculate the sum of the signal strenghts from cycle 20, 60, 100, 140, 180 and 220*/
    for(i = 20; i <= SIGNAL_STRENGTH_CYCLES; i += 40){
        tot_signal_strengths += i*cycle[i];
    }

    /*Close the file*/
    fclose(fPointer);

    /*Print the result*/
    printf("The sum of the signal strengths is: %d\n", tot_signal_strengths);
    return 0;
}
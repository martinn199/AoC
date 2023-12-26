#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include "Day10Part1.h"

/* *********************** THIS FILE IS USED FOR THE UNIT TEST *********************** */

/*Define constants*/
#define DATA_SIZE 300
#define SIGNAL_STRENGTH_CYCLES 220

int calculate_signal_strenghts(int* cycle){
    int tot_signal_strengths = 0;
    int i;

    /*Calculate the sum of the signal strenghts from cycle 20, 60, 100, 140, 180 and 220*/
    for(i = 20; i <= SIGNAL_STRENGTH_CYCLES; i += 40){
        tot_signal_strengths += i*cycle[i];
    }
    return tot_signal_strengths;
}

int read_data_and_calculate_signal(void) {
    /* Define variables */
    char line[DATA_SIZE];
    /*Register starts with value 1*/
    int X = 1;
    int V;
    int signal_strengths_tot = 0;
    int cycle[DATA_SIZE] = {0};
    /*To make the cycle value consistent with the interesting signal strengths*/
    int index = 1;

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

    /*Calculate the sum of signal strenghts*/
    signal_strengths_tot = calculate_signal_strenghts(cycle);

    /*Close the file*/
    fclose(fPointer);

    /*Print the result*/
    printf("The sum of the signal strengths is: %d\n", signal_strengths_tot);
    return 0;
}
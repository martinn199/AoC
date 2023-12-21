#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

/*Define constants*/
#define XY 2
#define GRID_SIZE 300
#define DATA_SIZE 2514
/*The rope consists of 10 knots*/
/*The head is number 0*/
/*The tail is number 9*/
#define KNOTS 10

int main() {
    /* Define variables */
    char line[KNOTS];
    char motion;
    int step;
    int i;
    int found;
    int j;

    /*Define the position, the x-component and the y-component, of the rope*/
    int rope_x[KNOTS] = {0};
    int rope_y[KNOTS] = {0};

    /*Define the motions*/
    int dx[GRID_SIZE] = {0};
    int dy[GRID_SIZE] = {0};
    dx['R'] = 1;
    dx['L'] = -1;
    dy['U'] = 1;
    dy['D'] = -1;

    /*Store the position of each knot and keep track of the positions the new tail visits*/
    int rope_position[DATA_SIZE][XY];
    int visited_positions = 0;

    /*Open the file*/
    FILE *fPointer;
    fPointer = fopen("Day9/input.txt", "r");

    /*If there exists no file, return an error*/
    if (fPointer == NULL) {
        perror("opening input.txt failed");
        return 1;
    }

    /*Read each line of the file*/
    while(fgets(line, sizeof(line), fPointer) != NULL){

        /*Store the motion and the step*/
        sscanf(line, "%c %d\n", &motion, &step);

        /*Loop through each step*/
        while(step--){

            /*The head moves independent of the other knots*/
            rope_x[0] += dx[(int)motion];
            rope_y[0] += dy[(int)motion];

            /*Loop through the knots*/
            /*Move a knot if the euclidean distance between it and its neighbors is greater than 1*/
            for(i = 0; i < 9; i++) {
                if(abs(rope_x[i] - rope_x[i + 1]) > 1 || abs(rope_y[i] - rope_y[i + 1]) > 1) {

                    /*First move the x-component of the knot*/
                    if(rope_x[i + 1] < rope_x[i]){
                        rope_x[i + 1]++;
                    }
                    else if(rope_x[i + 1] > rope_x[i]){
                        rope_x[i + 1]--;
                    }

                    /*Then move the y-component of the knot*/
                    if(rope_y[i + 1] < rope_y[i]){
                        rope_y[i + 1]++;
                    }
                    else if(rope_y[i + 1] > rope_y[i]){
                        rope_y[i + 1]--;
                    }
                }
            }

            /*Check if the tail has already visited the current position*/
            found = 0;
            for(j = 0; j < visited_positions; j++){
                if(rope_position[j][0] == rope_x[9] && rope_position[j][1] == rope_y[9]){
                    found = 1;
                    break;
                }
            }

            /*If the tail has not visited the current position, store the current position and add 1 to the visited positions*/
            if(!found){
                rope_position[visited_positions][0] = rope_x[9];
                rope_position[visited_positions][1] = rope_y[9];
                visited_positions++;
            }
        }
    }
    /*Close the file*/
    fclose(fPointer);

    /*Print the result*/
    printf("The tail has visited: %d at least once\n", visited_positions);
    return 0;
}

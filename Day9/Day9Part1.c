#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

/*Define constants*/
#define XY 2
#define GRID_SIZE 300
#define DATA_SIZE 6057
#define MAX_LEN 10

int main() {
    /*Define variables*/
    char line[MAX_LEN];
    char motion;
    int step;
    int found;
    int i;

    /*Define the position of the head and the tail*/
    int head[XY] = {0, 0};
    int tail[XY] = {0, 0};

    /*Define the motions*/
    int dx[GRID_SIZE] = {0};
    int dy[GRID_SIZE] = {0};
    dx['R'] = 1;
    dx['L'] = -1;
    dy['U'] = 1;
    dy['D'] = -1;

    /*Store the position of the tail and the positions the tail has visited at least once*/
    int tail_position[DATA_SIZE][XY];
    int visited_positions = 0;

    /*Open the file*/
    FILE *fPointer;
    fPointer = fopen("Day9/input.txt", "r");

    /*If there exist no file, return an error*/
    if (fPointer == NULL) {
        perror("opening input.txt failed");
        return 1;
    }

    /*Read each line of the file*/
    while (fgets(line, sizeof(line), fPointer) != NULL){

        /*Store the motion and the step*/
        sscanf(line, "%c %d\n", &motion, &step);

        /*Loop through each step*/
        while(step--){

            /*Store the head position*/
            head[0] += dx[(int)motion];
            head[1] += dy[(int)motion];

            /*Move the tail if the euclidean distance between the head and the tail is more than 1*/
            if (abs(head[0] - tail[0]) > 1 || abs(head[1] - tail[1]) > 1){

                /*First move the x-component of the tail*/
                if(head[0] < tail[0]){
                    tail[0]--;
                } 
                else if(head[0] > tail[0]){
                    tail[0]++;
                }

                /*Then move the y-component of the tail*/
                if(head[1] < tail[1]){
                    tail[1]--;
                }
                else if(head[1] > tail[1]){
                    tail[1]++;
                }
            }

            /*Check if the tail has already visited the current position*/
            found = 0;
            for(i = 0; i < visited_positions; i++){
                if(tail_position[i][0] == tail[0] && tail_position[i][1] == tail[1]){
                    found = 1;
                    break;
                }
            }

            /*If the tail has not visited the current position, store the current position and add 1 to the visited positions*/
            if(!found){
                tail_position[visited_positions][0] = tail[0];
                tail_position[visited_positions][1] = tail[1];
                visited_positions++;
            }
        }
    }
    /*Print the results*/
    printf("The tail has visited: %d positions at least once\n", visited_positions);
    return 0;
}

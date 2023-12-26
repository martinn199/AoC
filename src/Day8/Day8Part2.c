#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*Define constants*/
#define MAX_LEN 1000
#define MAX_SIZE 1000

int main() {
    /*Define variables*/
    char grid[MAX_SIZE][MAX_LEN];
    char line[MAX_LEN];
    int m = 0;
    int index;
    int col;
    int i;
    int j;
    int row;
    int top;
    int bottom;
    int left;
    int right;
    int number_row = 0;
    int currentTreeHeight;
    int score[MAX_SIZE][MAX_LEN];
    int edge;
    int highest_score;

    /*Open the file*/
    FILE *fPointer;
    fPointer = fopen("src/Day8/input.txt", "r");

    /*If there exist no file, return an error*/
    if (fPointer == NULL) {
        perror("opening input.txt failed");
        return 1;
    }

    /*Store each tree into an array*/
    while(fgets(line, sizeof(line), fPointer) != NULL){
        index = 0;
        for(m = 0; m < MAX_LEN; m++){
            grid[number_row][index] = line[m];
            index++;
        }
        number_row++;
    }

    /*Loop through the quadratic grid*/
    for (row = 0; row < number_row; row++){
        for(col = 0; col < number_row; col++){
            /*Initialize the viewing distance*/
            top = 0;
            bottom = 0;
            left = 0;
            right = 0;
            edge = 1;
            
            /*Transform the height of the current tree to a integer*/
            currentTreeHeight = grid[row][col] - '0';

            /*The viewing distance is zero for a tree that is right on the edge*/
            if(row == 0 || row == number_row - 1 || col == 0 || col == number_row - 1){
                edge = 0;
            }
            /*If the current tree is not a placed around the edge, loop through top, bottom, left and right*/
            /*Calculate the viewing distance*/
            /*Stop if there is a tree that is taller or equal to the height of the current tree*/
            else{
                for(i = row - 1; i >= 0; i--){
                    if(grid[i][col] - '0' < currentTreeHeight){
                        top += 1;
                    }
                    else if(grid[i][col] - '0' >= currentTreeHeight){
                        top += 1;
                        break;
                    }
                }
                for(i = row + 1; i < number_row; i++){
                    if(grid[i][col] - '0' < currentTreeHeight){
                        bottom += 1;
                    }
                    else if(grid[i][col] - '0' >= currentTreeHeight){
                        bottom += 1;
                        break;
                    }
                }
                for(j = col - 1; j >= 0; j--){
                    if(grid[row][j] - '0' < currentTreeHeight){
                        left += 1;
                    }
                    else if(grid[row][j] - '0' >= currentTreeHeight){
                        left += 1;
                        break;
                    }
                }
                for(j = col + 1; j < number_row; j++){
                    if(grid[row][j] - '0' < currentTreeHeight){
                        right += 1;
                    }
                    else if(grid[row][j] - '0' >= currentTreeHeight){
                        right += 1;
                        break;
                    }
                }
            }
            /*Store the scenic score for each tree*/
            score[row][col] = edge*top*bottom*left*right;

        }
    }

    /*Find the highest scenic score*/
    highest_score = score[0][0];

    for(row = 0; row < number_row; row++){
        for(col = 0; col < number_row; col++){
            if(score[row][col] > highest_score){
                highest_score = score[row][col];
            }
        }
    }

    printf("The highest scenic score is: %d\n", highest_score);

    return 0;
}

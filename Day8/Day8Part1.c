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
    int visible_nr_tree = 0;
    int currentTreeHeight;

    /*Open the file*/
    FILE *fPointer;
    fPointer = fopen("Day8/input.txt", "r");

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
            /*Initialize top, bottom, left and right*/
            top = 1;
            bottom = 1;
            left = 1;
            right = 1;
            
            /*Transform the height of the current tree to a integer*/
            currentTreeHeight = grid[row][col] - '0';

            /*All of the trees around the edge is visible*/
            if(row == 0 || row == number_row - 1 || col == 0 || col == number_row - 1){
                visible_nr_tree += 1;
            }
            /*If the current tree is not a placed around the edge, loop through top, bottom, left and right*/
            /*Check if there is a tree that is taller than the current tree*/
            /*If there is not a tree that is taller, add 1 to the number of visible trees*/
            else{
                for(i = 0; i < row; i++){
                    if(grid[i][col] - '0' >= currentTreeHeight){
                        top = 0;
                    }
                }
                if(top == 1){
                    visible_nr_tree += 1;
                    continue;
                }
                for(i = row + 1; i < number_row; i++){
                    if(grid[i][col] - '0' >= currentTreeHeight){
                        bottom = 0;
                    }
                }
                if(bottom == 1){
                    visible_nr_tree += 1;
                    continue;
                }
                for(j = 0; j < col; j++){
                    if(grid[row][j] - '0' >= currentTreeHeight){
                        left = 0;
                    }
                }
                if(left == 1){
                    visible_nr_tree += 1;
                    continue;
                }
                
                for(j = col + 1; j < number_row; j++){
                    if(grid[row][j] - '0' >= currentTreeHeight){
                        right = 0;
                    }
                }
                if(right == 1){
                    visible_nr_tree += 1;
                    continue;
                }
            }
        }
    }

    /*Print the result*/
    printf("The number of trees that are visible from outside the grid are: %d\n", visible_nr_tree);

    return 0;
}

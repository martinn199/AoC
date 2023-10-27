#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*Define constants*/
/*Maximum number columns*/
#define MAX_LEN 50
/*Maximum number of rows*/
#define MAX_SIZE 90
#define START_READING 70

int main() {
    /*Define variables*/
    char line[MAX_LEN];
    int row = 0;
    int move_from;
    int number_crates;
    int move_to;
    int i;
    int j;
    int a;
    int e;
    int m;
    int n;
    int index;
    int move_done;
    char crates[MAX_SIZE][MAX_LEN];
    char char_move_from;
    char top_crate[MAX_LEN];

    /*Open the file*/
    FILE *fPointer;
    fPointer = fopen("Day5/input.txt", "r");

    /*If there exist no file, return an error*/
    if (fPointer == NULL) {
        perror("opening input.txt failed");
        return 1;
    }

    /*Create an empty array of strings for the crates*/
    for (a = 0; a < MAX_SIZE; a++) {
        for (e = 0; e < MAX_SIZE; e++) {
            crates[a][e] = ' ';
        }
    }

    /*Loop though the lines with crates*/
    /*Insert the crates in the end of crates so the crates are able to move in the array*/
    while (row < MAX_SIZE) {
        if (row > START_READING) {
            fgets(line, sizeof(line), fPointer);
            if (line[0] != '\n' && line[0] != 'm') {
                index = 0;
                for (i = 1; i < MAX_LEN; i += 4) {
                    crates[row][index] = line[i];
                    index++;
                }
            }
            
        }
        row++;
    }

    /*Reset the filepointer to the beginning of the the file*/
    rewind(fPointer);

    /*Read each line of the instructions*/
    while (fgets(line, sizeof(line), fPointer) != NULL) {
        if (line[0] == ' ' || line[0] == '\n' || line[0] == '[') {
            continue;
        }
        /*Store the number of crates that should be moved, the column to move from and the column to move to*/
        sscanf(line, "move %d from %d to %d", &number_crates, &move_from, &move_to);
        move_from--;
        move_to--;

        /*Loop until all crates have been moved*/
        move_done = 0;        
        while(move_done < number_crates){

            /*First delete the crate to be moved*/
            /*Loop through each row in crates and find the row that has the crate that should be moved*/
            j = 0;
            while(j < MAX_SIZE && move_done < number_crates){
                if(crates[j][move_from] == ' '){
                    j++;
                    continue;
                }
                /*Remove the crate from the array*/
                char_move_from = crates[j][move_from];
                crates[j][move_from] = ' ';

                /*Insert the crate at the disered position by looping from the end of crates.*/
                /*The crate is inserted at the first empty place in the disered column*/
                int f = MAX_SIZE - 1;
                do{
                    if (crates[f][move_to] != ' ' && crates[f - 1][move_to] == ' '){
                        crates[f - 1][move_to] = char_move_from;
                        move_done++;
                        break;
                    }
                    f--;
                } while(f >= 0);
            }
            j++;
            
        }
    }
    
    /*Close the file*/
    fclose(fPointer);
    
    /*Find the crates that end up on the top of each stack*/
    /*Loop through each column*/
    while(m < MAX_LEN){
        n = 0;

        /*Loop through each row*/
        while(n < MAX_SIZE){
            if(crates[n][m] >= 'A' && crates[n][m] <= 'Z'){
                top_crate[m] = crates[n][m];
                break;
            }
            n++;
        }
        m++;
    }
    /*The crates that end up on the top of each stack are printed*/
    printf("\nThe crates that end up on the top of each stack are: %s \n", top_crate);

    return 0;
}

#include <stdio.h>          // fprintf, stderr
#include <stdlib.h>         // atoi, srand
#include <ctype.h>          // isdigit
#include <stdbool.h>        // bool, true, false
#include <string.h>         // strcmp, strlen
#include <time.h>           // time

#include "instructions.h"
#include "dice.h"
#include "charactergen.h"

int main(int argc, char *argv[]) {

    // Print instructions if no argument is passed        
    if(argc == 1) {
        printInstructions();
		return 0;
	}	

    int tmp = 1;             
    int num_d6 = -1;            
    int num_d10 = -1;
    bool rollD10 = false;
    bool rollD6 = false;
    bool dice_sum = false;

    srand(time(NULL));

    for(int i = 1; i < argc; i++) { 
        
        // If argument is "d10" roll tmp d10s
        if(strcmp(argv[i], "d10") == 0) {
            rollD10 = true;
            num_d10 = tmp;
            tmp = 1;
        }
        // If argument is "d6" roll tmp d6s
        else if(strcmp(argv[i], "d6") == 0) { 
            rollD6 = true;
            num_d6 = tmp;
            tmp = 1;
        }
		// If argument is a percentage roll
		else if(strcmp(argv[i], "-p") == 0) {
			percentageRoll();	
		} 
		// If rolls a sum is needed
		else if(strcmp(argv[i], "-s") == 0) {
			dice_sum = true;
		}
		// Generate character stats at random
		else if(strcmp(argv[i], "-c") == 0) {
			generateStats();
		} 
		// If user included multiple options after '-'
		else if(argv[i][0] == '-') {
			int k = 0;

			while(argv[i][++k] != '\0') {
				if(argv[i][k] == 'p') 
					percentageRoll();
				else if(argv[i][k] == 's')
					dice_sum = true;
				else if(argv[i][k] == 'c')
					generateStats();
				else {
					fprintf(stderr, "ERROR, invalid option.\n");
					return 1;
				}
			}
				
		}
        // Argument is either a number or invalid input
        else {
            for(int j = 0; j < strlen(argv[i]); j++) {

                // If argument is not a number, but is not "d6" or "d10"
                if(isdigit((unsigned char)argv[i][j]) == 0) {
                    fprintf(stderr, "ERROR: Invalid argument passed.\n");
                    printExamples();
                    return 1;
                }
                // If argument is a number, but a number of both dice has already been input
                else if(rollD10 == true && rollD6 == true) {
                    fprintf(stderr, "ERROR: Trailing argument(s) not used.\n");
                    printExamples();
                    return 1;
                }
                // Read the string input as an int and store it in tmp
                else {
                    tmp = atoi(argv[i]);
                }
            }   
        }
    }

	if(dice_sum == true && (rollD10 == false && rollD6 == false)){
		fprintf(stderr, "ERROR: Cannot print sum. No dice provided\n");
		return 1;
	} 
	else if(rollD10 == false && rollD6 == false) {
		printf("\n");
	}
	else {
   		printResults(dice_sum, rollD10, num_d10, rollD6, num_d6);
	}

    return 0;
}




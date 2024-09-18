#include <stdlib.h>     // rand
#include <stdio.h>      // printf
#include <stdbool.h>    // true, false
#include "config.h"
#include "dice.h"

// Roll a percentage
void percentageRoll() {

	int percentage = (rand() % PERCENTAGE) + 1;
	
	printf("\nPercentage: %d\n", percentage);
}

// Print the results of the input to the terminal
void printResults(bool dice_sum, bool rollD10, int num_d10, bool rollD6, int num_d6) {

    int tmp = 0;
    int sum;
	
	printf("\n");
	
    if(rollD10 == true) {
        sum = 0;
        printf("d10: ");
        for(int i = 0; i < num_d10; i++) {
            tmp = (rand() % D_10) + 1;
            printf("%d  ", tmp);
            sum += tmp;
        }    
		if(dice_sum == true)
        	printf("|  Sum: %d", sum);
		
		printf("\n");
    }
	
    if(rollD6 == true) {
        sum = 0;
        printf("d6: ");
        for(int i = 0; i < num_d6; i++) {
            tmp = (rand() % D_6) + 1;
            printf("%d  ", tmp);
            sum += tmp;
        }
		if (dice_sum == true)
        	printf("|  Sum: %d", sum);

		printf("\n");
    }

	printf("\n");
}

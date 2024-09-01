#include <stdio.h>          	// printf, fprintf, stderr
#include <stdlib.h>         	// atoi, srand, rand
#include <ctype.h>          	// isdigit
#include <stdbool.h>        	// bool, true, false
#include <string.h>         	// strcmp, strlen
#include <time.h>           	// time

#define     D_10    	10      // number of sides on a D10
#define     D_6     	6       // number of ides on a D6
#define		PERCENTAGE 	100		// basis for percentages
#define		MAX_ARGS	8		// maximum number of arguments possible
#define		NUM_ROLES	9		// number of character roles in the game
#define		NUM_STATS	9		// numner of base stats
#define		RUN			3		// MA multiple to determine run distance
#define		LEAP		4		// MA multiple to determine leap distance
#define		LIFT		40		// BODY multiple to determine Lift max in kg
#define		CARRY		10		// BODY multiple to determine Carry max in kg
#define		HUMANITY 	10		// EMP multiple to determine Humanity

void printInstructions();
void printExamples();
void percentageRoll();
void generateStats();
void printResults(bool, bool, int, bool, int);
int greaterThanTwo();

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

// Print the instructions for rollDice if no arguments are entered
void printInstructions() {
    
    printf("\nroll2020 is a program that will roll dice and build a character for you. You may roll one or "
        "multiple d6 or d10.\nInput should be entered as follows: [option] [num_dice] [dice_type] ... "
        "where num_dice is an integer\ngreater than 0 and dice_type is the type of dice you "
        "would like to roll. dice_type should\nbe entered as a lower case d with the number of "
        "sides of the dice imediately after, no spaces.\n\n");
    printf("If nothing is entered after roll2020 the program will print the instructions and exit.\n"
        "You do not need to enter 0 for a dice you do not wish to roll. Simply omit the [num_dice]\n"
        "and [dice_type] for that particular die. If a [dice_type] is entered with no [num_dice]\n" 
        "before it the program will simply roll one die of that type. Extra leading numbers will be\n"
		"ignored. Trailing numbers will result in error.Specifying the -s option without dice will \n"
		"result in error.\n\n");
	printf("OPTIONS:\n");
	printf("  -p\tPrints a percentage.\n");
	printf("  -s\tSums the rolls of each respective die type.\n");
	printf("  -c\tCreates a random character based on the \"fast\" method for\n"
		"\tgenerating character points. This means that no stat will be lower than 3.\n\n");
        
    printExamples();
}   

// Print examples for use in instructions or incorrect usage
void printExamples() {

    printf("EXAMPLES:\n");
	printf("  Print instructions.\n");
	printf("    roll2020\t\t\tThis will print instructions, examples, and sample errors.\n\n");
	printf("  Roll a percentage.\n");
	printf("    roll2020 -p\t\t\tThis will roll a percentage.\n");
	printf("    roll2020 -p -p -p\t\tThis will roll 3 percentage rolls.\n");
	printf("    roll2020 -ppp\t\tThis will also roll 3 percentage rolls.\n\n");
	printf("  Roll d10s and/or d6s.\n");
	printf("    roll2020 2 d6 4 d10\t\tThis will roll 2 d6 and 4 d10.\n");
    printf("    roll2020 2 d6 d10\t\tThis will roll 2 d6 and 1 d10.\n");
    printf("    roll2020 2 d6\t\tThis will roll 2 d6.\n"); 
	printf("    roll2020 -s 2 d6 4 d10\tThis will roll 2 d6 and 4 d10 and return the sum of each.\n\n");
	printf("  Generate characters.\n");
	printf("    roll2020 -c\t\t\tThis will generate a character (role, stats, and derived stats).\n");
	printf("    roll2020 -c -c -c\t\tThis will generate 3 characters.\n");
	printf("    roll2020 -ccc\t\tThis will also generate 3 characters.\n\n");
	printf("  Errors.\n");
    printf("    roll2020 4 2 d6\t\tThis will roll 2 d6. The 4 will be ignored.\n");
    printf("    roll2020 -s\t\t\tThis will reseult in error (cannot sum without dice).\n");
    printf("    roll2020 2 d6 d10 4\t\tThis will result in error (trailing numerical argument).\n");
	printf("    roll2020 2 d6 4 d10 2 d10\tThis will result in error (trailing arguments).\n\n");
} 

// Roll a percentage
void percentageRoll() {

	int percentage = (rand() % PERCENTAGE) + 1;
	
	printf("\nPercentage: %d\n", percentage);
}

// Generate character stats 
void generateStats() {

	char *roles[] = {"Rockerboy", "Solo", "Netrunner", "Techie", "Media", 
					 "Cop", "Corpo", "Fixer", "Nomad"};
	int MA, BODY, EMP, BTM;

	MA = greaterThanTwo();
	BODY = greaterThanTwo();
	EMP = greaterThanTwo();

	if(BODY == 3 || BODY == 4)
		BTM = -1;
	else if(BODY == 5 || BODY == 6 || BODY == 7)
		BTM = -2;
	else if(BODY == 8 || BODY == 9)
		BTM = -3;
	else if(BODY == 10)
		BTM = -4;
	else
		fprintf(stderr, "ERROR: There was a problem calculating BTM\n\n");

	printf("\nROLE: %s\n\n", roles[rand() % NUM_ROLES]);
	printf("INT: %d\n", greaterThanTwo());
	printf("REF: %d\n", greaterThanTwo());
	printf("TECH: %d\n", greaterThanTwo());
	printf("COOL: %d\n", greaterThanTwo());
	printf("ATTR: %d\n", greaterThanTwo());
	printf("LUCK: %d\n", greaterThanTwo());
	printf("MA: %d\n", MA);
	printf("BODY: %d\n", BODY);
	printf("EMP: %d\n\n", EMP);
	printf("Run: %d\n", MA * RUN);
	printf("Leap: %d\n", MA * LEAP);
	printf("Lift: %d\n", BODY * LIFT);
	printf("Carry: %d\n", BODY * CARRY);
	printf("Save: %d\n", BODY);
	printf("BTM: %d\n", BTM);
	printf("Humanity: %d\n", EMP * HUMANITY);
	
}

// Ensures a stat roll is greater than two
int greaterThanTwo() {

	int stat = 0;

	do {
		stat = (rand() % D_10) + 1;
	} while(stat <= 2);
	
	return stat;

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



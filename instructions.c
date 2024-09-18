#include <stdio.h>			// printf
#include "instructions.h"


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

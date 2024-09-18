#include <stdio.h>          // printf, fprintf
#include <stdlib.h> 		// rand
#include <stdbool.h>        // bool, true, false
#include <string.h>			// strcmp 
#include "config.h"
#include "charactergen.h"

// Ensures a stat roll is greater than two
int greaterThanTwo() {

	int stat = 0;

	do {
		stat = (rand() % D_10) + 1;
	} while(stat <= 2);
	
	return stat;

}

// Generate character equipment
void generateEquipment(bool isSolo) {

	char *cyberoptics[] = {"Infrared", "Lowlight", "Camera", "Dartgun", "Antidazzle", 
						   "Targeting Scope"};

	char *cyberarmGun[] = {"Lt. Pistol", "Med. Pistol", "Lt. SMG", "Med. SMG", 
						   "Hvy. Pistol", "VHvy. Pistol"};

	char *cyberaudio[] = {"Wearman", "Radio Splice", "Phone Link", "Amplified Hearing", 
						  "Sound Editing", "Digital Recording Link"};

	char *weapon[] = {"Knife", "Lt. Pisol", "Med. Pistol", "Hvy. Pistol", "Lt. SMG", 
					  "Med. SMG", "Hvy. SMG", "Lt. Assault Rifle", "Med. Assault Rifle", 
					  "Hvy. Assault Rifle"};

	char *armor[] = {"Hvy. Leather", "Armor Vest", "Lt. Armor Jacket", "Lt. Armor Jacket", 
					 "Med. Armor Jacket", "Med. Armor Jacket", "Med. Armor Jacket", 
					 "Hvy. Armor Jacket", "Hvy. Armor Jacket", "MetalGear"};
	
	int numRolls = -1;
	int i;
	int d6Tmp;
	int weaponArmor;
	int opticsCheck[] = {0, 0, 0, 0, 0, 0};
	int cyberarmCheck[] = {0, 0, 0, 0, 0, 0};
	int audioCheck[] = {0, 0, 0, 0, 0, 0};
	int cyberwareCheck[] = {0, 0, 0, 0, 0, 0, 0};

	if(isSolo)
		numRolls = SOLO_ROLLS;
	else
		numRolls = OTHER_ROLLS;

	printf("CYBERWARE\n");

	for(i = 0; i < numRolls; i++) {

		int tmp = rand() % D_10;

		switch(tmp) {
			case 0:

				d6Tmp = rand() %D_6;

				while(opticsCheck[d6Tmp] == 1) {
					d6Tmp = rand() % D_6;
				}

				printf("  Cyberoptics: %s\n", cyberoptics[d6Tmp]);
				opticsCheck[d6Tmp] = 1;
				break;
			case 1:

				d6Tmp = rand() %D_6;

				while(cyberarmCheck[d6Tmp] == 1) {
					d6Tmp = rand() % D_6;
				}

				printf("  Cyberarm with: %s\n", cyberarmGun[d6Tmp]);
				cyberarmCheck[d6Tmp] = 1;
				break;
			case 2:

				d6Tmp = rand() %D_6;

				while(audioCheck[d6Tmp] == 1) {
					d6Tmp = rand() % D_6;
				}

				printf("  Cyberaudio: %s\n", cyberaudio[d6Tmp]);
				audioCheck[d6Tmp] = 1;
				break;
			case 3:
				if(cyberwareCheck[tmp-CYBER_OFFSET] == 0){
					printf("  Big Knuckles\n");
					cyberwareCheck[tmp-CYBER_OFFSET] = 1;
				}
				else{
					--i;
				}
				
				break;
			case 4:
				if(cyberwareCheck[tmp-CYBER_OFFSET] == 0){
					printf("  Rippers\n");
					cyberwareCheck[tmp-CYBER_OFFSET] = 1;
				}
				else{
					--i;
				}
				
				break;
			case 5:
				if(cyberwareCheck[tmp-CYBER_OFFSET] == 0){
					printf("  Vampires\n");
					cyberwareCheck[tmp-CYBER_OFFSET] = 1;
				}
				else{
					--i;
				}
				
				break;
			case 6:
				if(cyberwareCheck[tmp-CYBER_OFFSET] == 0){
					printf("  Slice n' Dice\n");
					cyberwareCheck[tmp-CYBER_OFFSET] = 1;
				}
				else{
					--i;
				}
				
				break;
			case 7: 
				if(cyberwareCheck[tmp-CYBER_OFFSET] == 0){
					printf("  Kerenzikov\n");
					cyberwareCheck[tmp-CYBER_OFFSET] = 1;
				}
				else{
					--i;
				}
				
				break;
			case 8:
				if(cyberwareCheck[tmp-CYBER_OFFSET] == 0){
					printf("  Sandevistan\n");
					cyberwareCheck[tmp-CYBER_OFFSET] = 1;
				}
				else{
					--i;
				}
				
				break;
			case 9:
				if(cyberwareCheck[tmp-CYBER_OFFSET] == 0){
					printf("  NOTHING\n");
					cyberwareCheck[tmp-CYBER_OFFSET] = 1;
				}
				else{
					--i;
				}
				
				break;
			default:
				fprintf(stderr, "ERROR: Unable to generate cyberware.\n");
				break;
		}
	}

	weaponArmor = rand() % D_10;

	printf("\nWEAPONS & ARMOR\n");
	printf("  Weapon: %s\n", weapon[weaponArmor]);
	printf("  Armor: %s\n", armor[weaponArmor]);
}




// Generate character stats 
void generateStats() {

	char *roles[] = {"Rockerboy", "Solo", "Netrunner", "Techie", "Media", 
					 "Cop", "Corpo", "Fixer", "Nomad"};
	int MA, BODY, EMP, BTM;

	MA = greaterThanTwo();
	BODY = greaterThanTwo();
	EMP = greaterThanTwo();

	bool isSolo = false;

	char *role = roles[rand() % NUM_ROLES];

	if((strcmp(role, "Solo") == 0))
		isSolo = true;

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



	printf("\nROLE: %s\n\n", role);
	printf("STATS\n");
	printf("  INT: %d\n", greaterThanTwo());
	printf("  REF: %d\n", greaterThanTwo());
	printf("  TECH: %d\n", greaterThanTwo());
	printf("  COOL: %d\n", greaterThanTwo());
	printf("  ATTR: %d\n", greaterThanTwo());
	printf("  LUCK: %d\n", greaterThanTwo());
	printf("  MA: %d\n", MA);
	printf("  BODY: %d\n", BODY);
	printf("  EMP: %d\n\n", EMP);
	printf("DERIVED STATS\n");
	printf("  Run: %d\n", MA * RUN);
	printf("  Leap: %d\n", MA * LEAP);
	printf("  Lift: %d\n", BODY * LIFT);
	printf("  Carry: %d\n", BODY * CARRY);
	printf("  Save: %d\n", BODY);
	printf("  BTM: %d\n", BTM);
	printf("  Humanity: %d\n\n", EMP * HUMANITY);

	generateEquipment(isSolo);
	
}


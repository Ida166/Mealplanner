#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "KostPreference.h"

//This array stores each diet preference the user selects fx [1, 2, ...]
int userDietChoices[MAX_DIET_CHOICES];
//This integer stores how many preferences the user has chosen
int userDietCount = 0;

//Laver et seperat array til at give indexene navne. Vi kan muligvis lave options om til et struct


const char *optionNames[] = {
	"All",
	"Vegetarian",
	"Vegan"
};

//insted of havwing i equal to 3 wich is hard codede do ths insted
int dietPreferenceAmount =sizeof(optionNames)/sizeof(optionNames[0]);

void listOptions() {

	char s[100];
	char input[100];

	//Print intro text
	printf("Choose the diet preferences you would like one at a time (type 'go' when done)\n");
	printf("Your optiens are:\n");
	printf("- Type 0 for All diet types\n");
	printf("- Type 1 for Vegetarian\n");
	printf("- Type 2 for Vegan\n");

	while(1){
		// Check if max choices reached
		if (userDietCount >= MAX_DIET_CHOICES) {
			printf("Maximum number of diet choices reached.\n");
			break;  // exit the loop immediately
		}

		printf("\nEnter your choosen diet prference or type go: ");

		//Få fat på brugerens input via fgets 
		if(!fgets(s,sizeof(s),stdin)){
			continue;
		}

		// Make copy without newline
		strcpy(input, s); //copies input into s
		input[strcspn(input, "\n")] = '\0';

		// Check for exit
		if (strcmp(input, "go") == 0) { // if the user have typed exit it will break out of the loop
			break;
		}

		// Convert to integer
		char *p; 
		int value = strtol(s, &p, 10);

		// Validate input
		if (p == s || *p != '\n' || value < 0 || value >= dietPreferenceAmount) {
			printf("Invalid input\n");
			continue;
		}

		// If "All" is selected, stop immediately
		if (value == ALL) {
			userDietChoices[0] = ALL;
			userDietCount = 1;
			printf("All diets selected. ");
			break;
		}

		// Store value in array
		userDietChoices[userDietCount++] = value;
		printf("Added %s\n", optionNames[value]);
			
		}

	printf("Diet selection complete.\n\n");
}
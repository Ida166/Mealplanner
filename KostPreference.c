#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "KostPreference.h"

//This array stores each diet preference the user selects fx [1, 2, ...]
int userDietChoices[MAX_DIET_CHOICES];
//This integer stores how many preferences the user has chosen
int userDietCount = 0;

//Laver et seperat array til at give indexene navne. Vi kan muligvis lave options om til et struct

int dietPreferenceAmount = 3;

char optionNames[3][10] = {
	"All",
	"Vegetarian",
	"Vegan"
};


void listOptions() {

	char s[100];
	char input[100];

	//Print intro text
	printf("Choose diet preferences (type 'exit' when done)\n");
	printf("Options: 0 = All, 1 = Vegetarian, 2 = Vegan\n");

	while(1){
		// Check if max choices reached
		if (userDietCount >= MAX_DIET_CHOICES) {
			printf("Maximum number of diet choices reached.\n");
			break;  // exit the loop immediately
		}

		printf("Enter choice: ");

		//Få fat på brugerens input via fgets
		if(!fgets(s,sizeof(s),stdin)){
			continue;
		}

		// Make copy without newline
		strcpy(input, s); //copies input into s
		input[strcspn(input, "\n")] = '\0';

		// Check for exit
		if (strcmp(input, "exit") == 0) { // if the user have typed exit it will break out of the loop
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
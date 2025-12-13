#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "KostPreference.h"

//This integer stores how many preferences the user has chosen
int userDietCount = 0;

const char *optionNames[] = {
	"All",
	"Vegetarian",
	"Vegan"
};

//insted of having it equal to 3 wich is hard codede do ths insted
int dietPreferenceAmount = sizeof(optionNames)/sizeof(optionNames[0]);
// maximum selections = number of diet options.
int MAX_DIET_CHOICES = dietPreferenceAmount;  
//This array stores each diet preference the user selects fx [1, 2, ...] 
int userDietChoices[dietPreferenceAmount]; // array sized dynamically, it adaps if we add more diet options

void listOptions() {

	char s[100];
	char input[100];

	//Print intro text
	printf("Choose the diet preferences you would like one at a time (type 'go' when done)\n");
	printf("Your options are:\n");
	printf("- Type 0 for All diet types\n");
	printf("- Type 1 for Vegetarian\n");
	printf("- Type 2 for Vegan\n");

	while(1){
		// Check if max choices reached
		if (userDietCount >= MAX_DIET_CHOICES) {
			printf("Maximum number of diet choices reached.\n");
			break;  // exit the loop immediately
		}

		printf("\nEnter your chosen diet preference or type go: ");

		//Få fat på brugerens input via fgets 
		if(!fgets(s,sizeof(s),stdin)){
			continue;
		}

		// Make copy without newline
		strcpy(input, s); //copies input into s
		input[strcspn(input, "\n")] = '\0';

		// Check for go 
		if (strcasecmp(input, "go") == 0) { // if the user have typed go it will break out of the loop
			break;
		}

		// Convert to integer
		char *p; 
		int value = strtol(s, &p, 10);

		//skips whitespace so if the user type 0 and tab before enter it is not invalid.
		//After skipping, p points to the first non-whitespace character or '\0' if there is nothing else
		while(isspace((unsigned char)*p)) {
			p++;
		}

		// Validate input
		if (p == s || *p != '\0' || value < 0 || value >= dietPreferenceAmount) {
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
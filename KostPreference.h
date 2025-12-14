#ifndef KOSTPREFERENCE_H
#define KOSTPREFERENCE_H

// Diet type identifiers
typedef enum Diet_Prefs {
	ALL,
	VEGETARIAN,
	VEGAN,
	DIET_COUNT //number of diets
} Diet_Preference;

// Number of possible diet options
#define MAX_DIET_CHOICES DIET_COUNT

// Global variables (shared across .c files)
extern int userDietChoices[MAX_DIET_CHOICES];
extern int userDietCount;

// Function for user selection
void listOptions();

#endif
#ifndef KOSTPREFERENCE_H
#define KOSTPREFERENCE_H

// Diet type identifiers
typedef enum Diet_Prefs {
	ALL,
	VEGETARIAN,
	VEGAN
} Diet_Preference;

// Max allowed user selections
#define MAX_DIET_CHOICES 5

// Global variables (shared across .c files)
extern int userDietChoices[MAX_DIET_CHOICES];
extern int userDietCount;

// Function for user selection
void listOptions();

#endif
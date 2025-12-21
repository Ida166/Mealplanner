// printmealplanner.h
#ifndef PRINTMEALPLANNER_H
#define PRINTMEALPLANNER_H

#include "Recipes.h"  // Recipe struct and recipes arrays

typedef struct {
    const char *name;      // Meal name
    Recipe *recipes;       // Pointer to the array of recipes
    int *resultArray;      // Indices of selected recipes (NULL if not chosen)
} Meal;

// Deklaration af funktionen
int print_mealplan(Meal meals[], int mealCount);

#endif

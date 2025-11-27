//
#include "IngrediensIndtast.h"

#ifndef RECIPES_H
#define RECIPES_H

#define Max_Name_Length 50
#define Max_Ingredients 10
#define Max_Ingredient_name 30
#define Max_Procedure_Length 200

typedef struct{
    char name[Max_Name_Length];
    int time; // cooking time in minutes
    int portion; // portion description
    int calories;  // total calories
    char ingredient[Max_Ingredients][Max_Ingredient_name];
    char procedure[Max_Procedure_Length];
    int ingredient_count;  // number of ingredients used
}Recipe;


// Declare the array for other files
extern Recipe recipes_breakfast[];
extern int breakfastcount;
extern Recipe recipes_lunch[];
extern int lunchcount;
extern Recipe recipes_dinner[];
extern int dinnercount;

void print_recipes(Recipe arr[],int size,Node *IngredienList, int (*result)[7]);
int hasIngredient(Recipe targetRecipe,char target[]);

#endif
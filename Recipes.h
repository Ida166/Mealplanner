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

void print_breakfast_recipes(void);

#endif
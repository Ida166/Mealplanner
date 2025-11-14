#include "Recipes.h"
#include <stdio.h>


Recipe recipes_breakfast[] = {
    {"Pancakes", 30, 2, 300, {"flour", "eggs", "milk", "sugar"}, "First mix the dry igredients and ad the weat ones. Then heat the pan and cook the pancakes til they are done.", 4},
    {"Omelette", 30, 1, 350, {"eggs", "milk", "salt", "pepper"}, "First mix the ingredients and then cook them on the pan until the eggmass is bakaed", 4},
    
};
int breakfastcount = 2;

Recipe recipes_lunch[] = {
    
};

Recipe recipes_dinner[] = {
    
};


//function to print all recepies
void print_breakfast_recipes(void){
    for(int i = 0; i < breakfastcount; i++){
        Recipe current = recipes_breakfast[i]; //variable of type Recipe named current storing the current breakfast recipe
        printf("Recipe: %s\n", current.name);
        printf("Time: %d\n", current.time);
        printf("Portions: %d\n", current.portion);
        printf("Calories: %d\n", current.calories);
        printf("Ingredients:\n");
        for(int j = 0; j < current.ingredient_count; j++){
            printf("- %s\n", current.ingredient[j]);
        }
        printf("Procedure: %s\n", current.procedure);
    }
}
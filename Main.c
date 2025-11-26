#include <stdio.h>
#include "IngrediensIndtast.h"
#include "KostPreference.h"
#include "Recipes.h"

int main(){

    printf("\nVelkommen til meal plan programmet!\n\n");
    listOptions();

    //Instantiate the index variable for the result
    int BreakfastResult = 0;
    //Create a new ingredient list
    Node *IngredientsBreakfast = NULL;
    //Run the ingredient input function to fill out the list
    IngredientsBreakfast = IngrediensIndtast_mainFunction();
    //Print the recipes based on the ingredients
    //Also get the user input and set breakfast result to that
    print_recipes(recipes_breakfast,10,IngredientsBreakfast,&BreakfastResult);

    printf("\n");
    //Now repeat for lunch and dinner (This could be a for loop frankly)

    int LunchResult = 0;
    Node *IngredientsLunch = NULL;
    IngredientsLunch = IngrediensIndtast_mainFunction();
    print_recipes(recipes_lunch,10,IngredientsLunch,&LunchResult);

    printf("\n");

    int DinnerResult = 0;
    Node *IngredientsDinner = NULL;
    IngredientsDinner = IngrediensIndtast_mainFunction();
    print_recipes(recipes_dinner,10,IngredientsDinner,&DinnerResult);

    printf("\n");

    //Print the selected recipes
    printf("%s\n",recipes_breakfast[BreakfastResult].name);
    printf("%s\n",recipes_lunch[LunchResult].name);
    printf("%s\n",recipes_dinner[DinnerResult].name);

    return 0;
}
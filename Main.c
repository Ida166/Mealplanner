#include <stdio.h>
#include "IngrediensIndtast.h"
#include "KostPreference.h"
#include "Recipes.h"

int main(){

    printf("\nVelkommen til meal plan programmet!\n\n");
    listOptions();

    int BreakfastResult = 0;
    Node *IngredientsBreakfast = NULL;
    IngredientsBreakfast = IngrediensIndtast_mainFunction();
    print_recipes(recipes_breakfast,10,IngredientsBreakfast,&BreakfastResult);

    printf("\n");
    
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

    printf("%s\n",recipes_breakfast[BreakfastResult].name);
    printf("%s\n",recipes_lunch[LunchResult].name);
    printf("%s\n",recipes_dinner[DinnerResult].name);

    return 0;
}
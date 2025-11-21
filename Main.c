#include <stdio.h>
#include "IngrediensIndtast.h"
#include "KostPreference.h"
#include "Recipes.h"

int main(){

    printf("\nVelkommen til meal plan programmet!\n\n");
    listOptions();


    Node *IngredientsBreakfast = NULL;

    IngredientsBreakfast = IngrediensIndtast_mainFunction();

    //print_list(IngredientsBreakfast);

    print_recipes(recipes_breakfast,10,IngredientsBreakfast);
    //print_recipes(recipes_lunch,10);
    //print_recipes(recipes_dinner,10);

    return 0;
}
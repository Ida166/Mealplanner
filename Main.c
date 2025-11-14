#include <stdio.h>
#include "IngrediensIndtast.h"
#include "KostPreference.h"
#include "Recipes.h"

int main(){

    printf("\nVelkommen til meal plan programmet!\n\n");
    listOptions();
    IngrediensIndtast_mainFunction();
    
     print_breakfast_recipes();

    return 0;
}
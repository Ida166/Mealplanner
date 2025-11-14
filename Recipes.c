#include "Recipes.h"
#include <stdio.h>


Recipe recipes_breakfast[] = {
{"Pancakes", 30, 2, 300,
 {"flour: 200g", "eggs: 1", "milk: 100ml", "sugar"},
 "Mix dry ingredients, add wet ingredients, then cook on a hot pan.", 4},
{"Omelette", 30, 1, 350,
 {"eggs: 2", "milk: 100ml", "salt", "pepper"},
 "Whisk ingredients together and cook on a pan until firm.", 4},
{"Skyr", 5, 1, 350,
 {"Skyr: 200g", "Fruit", "Oats"},
 "Place skyr in a bowl and add fruit and oats.", 3},
{"Oats", 3, 1, 400,
 {"Oats: 70g", "Cinnamon", "Apple", "Milk: 200ml"},
 "Add oats and milk to a bowl, mix, and top with apple and cinnamon.", 4},
{"Toast", 5, 1, 400,
 {"Toast", "Cheese", "Ham"},
 "Assemble the toast and grill if desired.", 3},
{"Yoghurt", 5, 1, 400,
 {"Yoghurt: 200g", "Fruit", "Oats"},
 "Add yoghurt to a bowl and top with fruit and oats.", 3},
{"Scrambled Eggs", 10, 1, 250,
 {"Eggs: 2", "Butter: 10g", "Salt", "Pepper"},
 "Whisk eggs, melt butter in pan, and cook while stirring gently.", 4},
{"Banana Smoothie", 5, 1, 280,
 {"Banana: 1", "Milk: 200ml", "Oats: 30g"},
 "Blend banana, milk, and oats until smooth.", 3},
{"Avocado Toast", 7, 1, 320,
 {"Toast", "Avocado: 1", "Salt", "Lemon juice"},
 "Mash avocado, spread on toast, and season with salt and lemon.", 4},
{"Fruit Bowl", 5, 1, 220,
 {"Apple", "Banana", "Grapes", "Strawberries"},
 "Chop fruit and mix in a bowl.", 4}
};
int breakfastcount = 10;

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
        printf("\n");
    }
}
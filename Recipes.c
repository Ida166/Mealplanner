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
{"Chicken Stir Fry", 20, 1, 450,
    {"Chicken breast: 150g", "Mixed veggies: 200g", "Soy sauce: 1 tbsp", "Rice: 100g"},
    "Cook the chicken, add vegetables, pour soy sauce and serve with rice.",
    4
},
{"Tuna Pasta", 15, 1, 500,
    {"Pasta: 100g", "Canned tuna: 1 can", "Corn: 50g", "Cream cheese: 1 tbsp"},
    "Boil pasta, mix with tuna, corn, and cream cheese.",
    4
},
{"Veggie Wrap", 10, 1, 350,
    {"Tortilla", "Lettuce", "Tomato", "Chicken: 100g"},
    "Fill tortilla with vegetables and cooked chicken, then roll tightly.",
    4
},
{"Chili Beans", 15, 1, 400,
    {"Kidney beans: 1 can", "Tomato sauce: 200ml", "Onion", "Spices"},
    "Heat onion, add beans and tomato sauce, season and simmer.",
    4
},
{"Salmon Bowl", 20, 1, 500,
    {"Salmon: 150g", "Rice: 100g", "Spinach: 50g", "Lemon"},
    "Bake salmon, cook rice, add spinach and lemon juice on top.",
    4
},
{"Chicken Caesar Salad", 12, 1, 350,
    {"Chicken: 120g", "Lettuce", "Croutons", "Caesar dressing: 1 tbsp"},
    "Cook chicken, add lettuce, croutons and dressing, then toss.",
    4
},
{"Easy Veggie Pasta", 15, 1, 420,
    {"Pasta: 100g", "Zucchini", "Tomatoes", "Olive oil: 1 tbsp"},
    "Boil pasta, sauté veggies, mix together with olive oil.",
    4
},
{"Egg Fried Rice", 10, 1, 450,
    {"Rice: 150g", "Eggs: 2", "Peas: 50g", "Soy sauce: 1 tbsp"},
    "Scramble eggs, add rice and peas, stir soy sauce through.",
    4
},
{"Chicken Pita", 8, 1, 380,
    {"Pita bread", "Chicken: 100g", "Lettuce", "Yoghurt dressing"},
    "Fill pita with chicken, lettuce, and a spoon of yoghurt dressing.",
    4
},
{"Tomato Soup & Toast", 12, 1, 300,
    {"Tomato soup: 1 can", "Toast", "Cheese"},
    "Heat soup, toast bread with cheese, serve together.",
    3
},
    
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
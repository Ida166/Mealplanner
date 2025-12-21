//Prototyper
#ifndef INGREDIENSINDTAST_H
#define INGREDIENSINDTAST_H

typedef struct Node{
    char ingredient[50]; 
    struct Node *next; //pointer til næste node i den linkede liste
}Node;

Node* IngrediensIndtast_mainFunction(const char hint[]);
void get_ingredient(char *ingrediens_input);
Node* tilfoj_ingrediens_til_liste(char *ingrediens_input, Node *head);
void free_list(Node *head);
void print_list(Node *head);
void capitalize(char *ingrediens_input);

#endif
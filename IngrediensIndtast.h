//Prototyper

typedef struct Node{
    char ingredient[50]; 
    struct Node *next; //pointer til næste node i den linkede liste
}Node;

int IngrediensIndtast_mainFunction();
void get_ingredient(char *ingrediens_input);
Node* tilfoj_ingrediens_til_liste(char *ingrediens_input, Node *head);
void free_list(Node *head);
void print_list(Node *head);
void capitalize(char *ingrediens_input);
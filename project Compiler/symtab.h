#ifndef SYMTAB_H
#define SYMTAB_H
#include <stdint.h>
#include "definitions.h"
#include "ast.h"
#define MAX_LENGTH 128
#define HASHTABLE_SIZE 200



// the element struct that hashtable contains
typedef struct element{
	char* key; // the key of the element
	symbol_node* head; // the head of the list
}element;


//Hashtabe structure
typedef struct {
	int size; // the size of the hashtable
	int num_of_elements; // the number of elements inside the table
	element** table;	// our table which contains the elements
} hashtable;



//creates a new element
element* make_element(char*key, symbol_node* entery);

//initializes the hashtable
hashtable* make_symtable(int size);

//transforms a string into a unique index
int stringToHash(char *id);

//if the symbol is inside the table, we will return it
symbol_node* lookup(char* id);


//inserts a symbol into the table
void insert(symbol_ref* symbol_ref);

//printing the symboltable
void print_table(hashtable* h);

//deleteing every element from the current scope
void deleteFromScope();

#endif

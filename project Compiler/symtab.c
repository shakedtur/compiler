
#include "symtab.h"

hashtable* symtable;



hashtable* make_symtable(int size){

	hashtable* table = NULL;
	int i;

	if( size < 1 ) return NULL;

	/* Allocate the table itself. */
	if( ( table = malloc( sizeof( hashtable ) ) ) == NULL ) {
		return NULL;
	}

	/* Allocate pointers to the head nodes. */
	if( ( table->table = malloc( sizeof( element * ) * size ) ) == NULL ) {
		return NULL;
	}
	for( i = 0; i < size; i++ ) {
		table->table[i] = NULL;
	}

	table->size = size;
	table->num_of_elements = 0;
return table; 
}




element* make_element(char* key,symbol_node* entry){
	element* ele = (element*)emalloc(sizeof(element));
	ele->key = strdup(key);
	ele->head = entry;//head of the list

}

//TODO free element



int stringToHash(char* id){
    unsigned long hash = 5381;
    int c;

    while (c = *id++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % HASHTABLE_SIZE;
}

symbol_node* lookup(char* id) {
	int hashIndex=stringToHash(id); 
   	element** ele = symtable->table;

   	//move in array until an empty
   	while(ele[hashIndex] != NULL){
   		if(strcmp(ele[hashIndex]->key,id) == 0)//found the key
   			return ele[hashIndex]->head; // return head of the list
	   	++hashIndex;
	   	hashIndex %= HASHTABLE_SIZE; //looping through the table if hashIndex > table size
   	}
   	//didnt find the entry
   	return NULL;

}

void print_table(hashtable* h){
	int i = 0;
	 element** ele = symtable->table;
	 symbol_node* head;
	printf("SYMBOL TABLE:\n");
	for(i;i<HASHTABLE_SIZE;i++){
		if(ele[i] != NULL){
			head = ele[i]->head;
			printf("%s->",ele[i]->key);
			while(head!= NULL){
				printf(",(%d,%d,t:%d)",head->symbol_type,head->scope_lvl,head->type);
				head = head->next;
			}
			printf("\n");
		}
	}

}

void deleteFromScope(){
	symbol_node* head;
	element** ele = symtable->table;
	int i=0;
	//deleting all the current scope symbols
	for(i;i<HASHTABLE_SIZE;i++){
		if(ele[i] != NULL){
			head = ele[i]->head;
			if(head != NULL && head->scope_lvl == currentScope){
				ele[i]->head = head->next;
				if(ele[i]->head == NULL){//TODO FREE ELEMENT[I] BEFORE NULLING IT
					ele[i] = NULL;
					symtable->num_of_elements--;
				}
			}
		}
	}

}


void insert(symbol_ref* symbol_ref){
	symbol_node* symbol = symbol_ref->symbol;
	int hashIndex=stringToHash(symbol_ref->id);
	//printf("ID :%s\n",symbol_ref->id);
   	element** ele = symtable->table;
   	//move in array until  empty or until we find our element
	while(ele[hashIndex] != NULL && strcmp(ele[hashIndex]->key ,symbol_ref->id)!=0){
	   	++hashIndex;
	   	hashIndex %= HASHTABLE_SIZE;
	}
   	//if there is no such element at all
   	if(ele[hashIndex] == NULL){ 			   	
   		symtable->num_of_elements++;
   		ele[hashIndex] = make_element(symbol_ref->id,symbol);
   	}
	else{
		//printf("index: %d\n",hashIndex);
		if(symbol == NULL) printf("NULL\n");
		symbol->next = ele[hashIndex]->head;
		ele[hashIndex]->head = symbol;
	}

}

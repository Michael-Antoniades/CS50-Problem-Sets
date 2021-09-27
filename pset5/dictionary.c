// Implements a dictionary's functionality

#include <strings.h> // strcasecmp functionality,
//compares 2 strings case-insensitively
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "dictionary.h" //brings in LENGTH and other useful functions

// Represents a node in a hash table

int wordcount = 0; //global variable for size function

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26; //went with 26 buckets for each letter in the alphabet

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int key = hash(word);

    node *tmpnode = table[key];

    while(tmpnode != NULL) {
        if(strcasecmp(tmpnode->word,word) == 0){
            return true;
        }
       tmpnode = tmpnode ->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int lv = 0; //initialize lowercase value calculated in our for loop

    for(int i = 0; word[i] != '\0'; i++)
    {
        lv += tolower(word[i]);
    }

    return lv % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *od = fopen(dictionary, "r"); //od = opendictionary

    if (od == NULL)
    {
    return false;
    }

    for(int i = 0; i<N; i++)
    {
        table[i] = NULL;
    }

    char new_word[LENGTH+1]; //initialize word to be largest possible word size

    while(fscanf(od, "%s\n", new_word) != EOF)
    {
        node *new_node = malloc(sizeof(node)); //allocates memory for our node

        if (new_node == NULL) //unsuccessful memory allocation
        {
        unload();
        return false;
        }

    //successful memory allocation move on to hash key, 2 scenarios
    //one scenario we have a NULL table (empty) or value already exists
        strcpy(new_node->word, new_word);
        int key = hash(new_word);

        if(table[key] == NULL) //hash index, check if value exists or not in table
        {
        new_node->next = NULL;
        table[key] = new_node;
        }
     // case in which a value exists and what we have to do to table and our node
        else
        {
        new_node->next = table[key];
        table[key] = new_node;
        }
    wordcount++;


    }
    fclose(od);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for( int i = 0; i < N; i++) {
        node* tmpNode = table[i];

        while(tmpNode != NULL){
            node* deleteNode = tmpNode;
            tmpNode = tmpNode ->next;
            free(deleteNode);
        }
        table[i] = NULL;
    }
    return true; //if this works properly shouldn't need to return false
}

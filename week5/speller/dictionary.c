// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];


//Count Word thaht you use in the dictionary;
unsigned int word_count = 0;
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
  unsigned int index = hash(word);
    node *cursor = table[index];

  while(cursor != NULL)
  {
    if (strcasecmp(cursor->word,word) == 0)
    {
        return true;
    }

    cursor = cursor->next;
  }
  return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash_value = 5381;
    int c;
    while((c = toupper(*word++)))
    {
        hash_value = ((hash_value << 5) + hash_value) + c;
    }
    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *source = fopen(dictionary, "r");
    if(source == NULL)
    {
        return 1;
    }
    char word[LENGTH + 1];

    while( fscanf(source, "%s", word) != EOF)
    {
         node *n = malloc(sizeof(node));
         if(n == NULL)
         {
            return 1;
         }
         strcpy(n->word,word);
         unsigned int index = hash(n->word);
         n->next = table[index];
         table[index] = n;
         word_count++;
    }
    // TODO
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i = 0; i < N; i ++)
    {
        node *cursor = table[i];
        while(cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    // TODO
    word_count = 0;
    return true;
}

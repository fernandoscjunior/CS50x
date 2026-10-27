// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
unsigned int words_counted = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash the word to obtain its hash value
    int hashed_word = hash(word);

    // Search the hash table at the location specified by the word’s hash value
    node *cursor = table[hashed_word];

    // Iterate through the Nodes to find the word.
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
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
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        printf("Could not read the dictionary.\n");
        return 1;
    }

    // Allocates memory for words that will be read.
    char line[LENGTH + 1];

    bool run = true;

    // Read each line and add to node loop
    while (run == true)
    {
        if (fscanf(source, "%s", line) == EOF)
        {
            run = false;
            break;
        }

        // Creates node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(source);
            free(new_node);
            printf("Could not create the node");
            return 3;
        }

        strcpy(new_node->word, line);

        int index = hash(line);

        new_node->next = table[index];
        table[index] = new_node;

        words_counted++;
    }

    fclose(source);

    if (words_counted > 0)
    {
        return true;
    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return words_counted;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload()
{
    // Running through every "bucket" in table
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        // Freeing every node from the "i" "bucket"
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
            words_counted--;
        }
    }

    if (words_counted == 0)
    {
        return true;
    }
    return false;
}

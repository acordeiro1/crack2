#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

const int PASS_LEN = 20;        // Maximum any password will be
const int HASH_LEN = 33;        // Length of MD5 hash strings


// Given a target plaintext word, use it to try to find
// a matching hash in the hashFile.
// Get this function working first!
char * tryWord(char * plaintext, char * hashFilename)
{
    // Hash the plaintext
    char *hashed = md5(plaintext, strlen(plaintext));
    if (hashed == NULL) 
    {
        return NULL; 
    }

    // Open the hash file
    FILE *hashFile = fopen(hashFilename, "r");
    if (!hashFile)
    {
        printf("Can't open %s for writing\n", hashFilename);
        free(hashed);
        exit(1);
    }
    
    // Loop through the hash file, one line at a time.
    char line[HASH_LEN];
    while (fgets(line, sizeof(line), hashFile) != NULL) 
    {
        size_t length = strlen(line);
        if (length > 0 && line[length - 1] == '\n') 
        {
            line[length - 1] = '\0';
        }

    // Attempt to match the hash from the file to the hash of the plaintext.
    // If there is a match, you'll return the hash.
        if (strcmp(hashed, line) == 0) {
            fclose(hashFile);
            free(hashed);
            return strdup(line); //dynamic allocated copy
        }
    }
    // Before returning, cleanup
    fclose(hashFile);
    free(hashed);
    return NULL; // No match found, return NULL
}

    /*// Modify this line so it returns the hash
    // that was found, or NULL if not found.
    return "0123456789abcdef0123456789abcdef";
}*/


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        fprintf(stderr, "Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }

    // These two lines exist for testing. When you have
    // tryWord working, it should display the hash for "hello",
    // which is 5d41402abc4b2a76b9719d911017c592.
    // Then you can remove these two lines and complete the rest
    // of the main function below.
    char *found = tryWord("hello", "hashes00.txt");
    printf("%s %s\n", found, "hello");


    // Open the dictionary file for reading.
    

    // For each dictionary word, pass it to tryWord, which
    // will attempt to match it against the hashes in the hash_file.
    
    // If we got a match, display the hash and the word. For example:
    //   5d41402abc4b2a76b9719d911017c592 hello
    
    // Close the dictionary file.

    // Display the number of hashes that were cracked.
    
    // Free up any malloc'd memory?
}


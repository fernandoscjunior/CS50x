#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open Memory card.\n");
        return 2;
    }

    // Create a buffer for a block of data
    uint8_t buffer[512];
    int counter = 0;
    FILE *recovered = NULL;

    // Allocating memory for dynamic jpg's name
    char *filename = malloc(9);
    if (filename == NULL)
    {
        printf("Not enough memory to store string.\n");
        fclose(card);
        return 3;
    }

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Identify jpeg header to know when to start a new image
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (recovered != NULL)
            {
                fclose(recovered);
            }

            sprintf(filename, "%03i.jpg", counter);

            // Open output file again
            recovered = fopen(filename, "w");
            if (recovered == NULL)
            {
                fclose(card);
                printf("Could not create %s.\n", filename);
                free(filename);
                return 4;
            }

            counter++;
        }

        if (recovered != NULL)
        {
            // Create JPEGs from the data
            fwrite(buffer, 1, 512, recovered);
        }
    }

    if (recovered != NULL)
    {
        fclose(recovered);
    }

    free(filename);
    fclose(card);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");

    if (input_file == NULL)
    {
        printf("Could not open file");
        return 2;
    }

    // store 512 byte blocks in array
    unsigned char buffer[512];

    // track no of images generated
    int count_image = 0;

    // pointer for recovered images
    FILE *output_file = NULL;

    // char filename[8]
    char *filename = malloc(8 * sizeof(char));

    // read 512 byte blocks
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(count_image > 0)
            {
                fclose(output_file);
            }

            sprintf(filename, "%03i.jpg", count_image);

            output_file = fopen(filename, "w");

            count_image++;
        }

        if(output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }

    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;
}
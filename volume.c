// Modifies the volume of an audio file
// contains:
// one 44-byte header
// many 2-byte samples
// to change the volume of a sample, multiply the sample by a number

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // atof(): convert a character string (C-style string) into a double-precision floating-point number from <stdlib.h>
    float factor = atof(argv[3]);

    // TODO: Copy header(=44 bytes) from input file to output file
    uint8_t header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file
    // Create a buffer for a single sample
    int16_t buffer;

    // Read single sample into buffer
    // or while(fread(&buffer, sizeof(int16_t), 1, input) != 0)
    // or while(fread(&buffer, sizeof(int16_t), 1, input))
    while (fread(&buffer, sizeof(int16_t), 1, input) == 1)
    {
        // Update volume of sample
        buffer *= factor;

        // Write updated sample to new file
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}

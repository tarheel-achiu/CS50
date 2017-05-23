#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

/* pseudocode:
        
    open card file
    repeat until end of card
        read 512 bytes into a buffer
        start of a new JPEG?
            yes > ...
            no > ...
        already found a JPEG
            no > ...
            yes ...
        close any remaining files
*/


int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }
    
    // remember filenames
    char *infile = argv[1];
    

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    // declaring buffer array
    uint8_t buffer[512] = {0};
    
    // tracking number of JPEG's
    int count_jpeg = 0;
    
    // JPEG found indicator
    bool JPEG_ind = false;
    
    // declare image pointer
    FILE *img = NULL;
    
    // repeat until end of card
    while (fread(buffer, 512, 1, inptr) == 1)
    {
        // check first four bytes to evaluate if block is a JPEG header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // executes if new jpeg header is found indicating we can close previous file
            if (JPEG_ind == true && img != NULL)
            {
                fclose(img);    
            }
            
            //
            else 
            {
                JPEG_ind = true;
            }
            
            // making a new JPEG name
            char filename[8] = {0}; // this is where the segemtation fault was origenating, char filename[8];
            sprintf(filename, "%03i.jpg", count_jpeg);
            img = fopen(filename, "w");
            count_jpeg++;
        }
        
        // if JPEG is found write contents of buffer to a file
        if (JPEG_ind == true)
        {
            fwrite(&buffer, 512, 1, img); 
        }
    }
    
    // close files
    fclose(inptr);
    fclose(img);
    
    return 0;
}
    
    
    
    
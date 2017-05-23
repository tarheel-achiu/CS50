/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// storing tile location and blank location
int tile_i;
int tile_j;
int blank_i;
int blank_j;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void swaptile(int tile);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();
    

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // TODO
    int total = d * d;
    
    //iterated over the rows
    for (int i = 0; i < d; i++)
    {
        //iterate over the columns
        for (int j = 0; j < d; j++)
        {
            //set tile's value
            board[i][j] = --total;
        }
    }
    // if d is even, swap 2 and 1. use modulo
    if (d % 2 == 0)
    {
        board[d - 1][d - 3] = 1;
        board[d - 1][d - 2] = 2;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    for (int i = 0; i < d; i++)
    {
        //iterate over the columns
        for (int j = 0; j < d; j++)
        {
            //set tile's value
            if (board[i][j] == 0 && d < 4)
            {
                printf(" _");    
            }
            else if (board[i][j] == 0 && d >= 4)
            {
                printf("  _");    
            }
            else if (d < 4)
            {
                printf("%2i", board[i][j]);    
            }
            else
            {
                printf("%3i", board[i][j]);    
            }
            
        }
         printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO
    // check user input validity
    if (tile > (d * d) - 1 || tile < 1)
    {
        return false;    
    }

    // determine location of user input
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == tile)
            {
                tile_i = i;
                tile_j = j;
            } 
        }
    }
    
    // check if blank space is adjacent to user input
    // check row above
    if (tile_i > 0 && board[tile_i - 1][tile_j] == 0)
    {
        blank_i = tile_i - 1;
        blank_j = tile_j;
        swaptile(tile);
        return true;
    }
    // check row below     
    if (tile_i < d - 1 && board[tile_i + 1][tile_j] == 0)
    {
        blank_i = tile_i + 1;
        blank_j = tile_j;
        swaptile(tile);
        return true;
    }
    // check left column
    if (tile_j > 0 && board[tile_i][tile_j - 1] == 0)
    {
        blank_i = tile_i;
        blank_j = tile_j - 1;
        swaptile(tile);
        return true;
    }
    // check right column
    if (tile_j < d - 1 && board[tile_i][tile_j + 1] == 0)
    {
        blank_i = tile_i;
        blank_j = tile_j + 1;
        swaptile(tile);
        return true;
    }
   
    else
    {    
        return false;    
    }
}    


/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int counter = 1;
    
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == counter)
                counter++;
        } 
    }
    
    if (counter == d * d && board[d - 1][d - 1] == 0)
        return true;
    else
        return false;
}

/**
 * Function that swaps the user input and 
 */
void swaptile(tile)
{
    int temp = board[tile_i][tile_j];
    board[tile_i][tile_j] = board[blank_i][blank_j];
    board[blank_i][blank_j] = temp;
    
    // update location of blank tile
    blank_i = tile_i;
    blank_j = tile_j;
}

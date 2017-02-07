#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    
    // ask for a height
    do
    {
        printf("Please, enter a height between 1 and 23: ");
        height = GetInt();
    }
    while(!(height >= 0 && height <= 23));
    
    
    /**
     * Print half-pyramid using hashes and spaces 
     * with the height which user entered.
     * 
     * Has main loop which sets a heigh of our pyramid and
     * two nested loops which specify number of spaces and
     * hashes in every row.
     */
    for (int i = 0; i < height; i++)
    {
        for(int j = height-1-i; j > 0  ; j--)
        {
            // print spaces in a row
            printf(" ");  
        }
        
        for(int k = 0; k < i+2 ; k++)
        {
            // print hashes in a row
            printf("#");  
        }
        
        // print new line after a row
        printf("\n"); 
    }
    
}


/**
 * Pseudocode 
 *
 * get amount in dollars 
 * round
 * while (quarters can be used) 
 *	increase count 
 *	amount decrease by a quarter 
 *	
 * while (dimes can be used) 
 *	increase count 
 *	amount decrease by a dime 
 *	
 * (etc...) 
 * print number of coins used 
 */

#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    float input;
    
    do
    {
        printf("Please, enter you charge: \n");
        input = GetFloat();
    }
    while(input < 0);
    
    int charge = round(input * 100);
    int coins = 0;
    
    while(charge >= 25)
    {
        coins++;
        charge = charge - 25;
    }
    
    while(charge >= 10)
    {
        coins++;
        charge = charge - 10;
    }
    
    while(charge >= 5)
    {
        coins++;
        charge = charge - 5;
    }
    
    while(charge >= 1)
    {
        coins++;
        charge = charge - 1;
    }
    
    printf("%d\n", coins);
}

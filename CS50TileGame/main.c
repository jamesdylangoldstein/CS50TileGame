//
//  main.c
//  CS50TileGame
//
//  Created by James Dylan Goldstein on 6/14/16.
//  Copyright © 2016 James Dylan Goldstein. All rights reserved.
//

//next step, build function to find the coordinate of zero

#include <stdio.h>

int tileGameBoard[4][4];
int currentRow;
int currentColumn;

void populateBoard(void);
void findCurrentRowCol(void);
void printOutBoard(void);
int moveLeft(int moveLeftVal);

int main(int argc, const char * argv[]) {
    int moveLeftVal;
    
    // Build the board and populate the board
    populateBoard();
    
    // Print Out Board
    printOutBoard();
    
    // Move left 1
    moveLeft(1);

    
    // Move left 2
    moveLeft(2);
    
    // Move left 3     
    return 0;
}

void populateBoard(void)
{
    int boardPopNum = 15;
    
    for (int boardPopRowCounter = 0; boardPopRowCounter < 4; boardPopRowCounter++)
    {
        for (int boardPopColCounter = 0; boardPopColCounter < 4; boardPopColCounter++)
        {
            tileGameBoard[boardPopRowCounter][boardPopColCounter] = boardPopNum;
            boardPopNum--;
        }
    }
}

void findCurrentRowCol(void)
{
    for (int boardRowCounter = 0; boardRowCounter < 4; boardRowCounter++)
    {
        for (int boardColCounter = 0; boardColCounter < 4; boardColCounter++)
        {
            if (tileGameBoard[boardRowCounter][boardColCounter] == 0)
            {
                currentRow = boardRowCounter;
                currentColumn = boardColCounter;
            }
        }
    }
}

void printOutBoard(void)
{
    int printCounter = 0;
    for (int boardRowCounter = 0; boardRowCounter < 4; boardRowCounter++)
    {
        for (int boardColCounter = 0; boardColCounter < 4; boardColCounter++)
        {
            printf("%-8i", tileGameBoard[boardRowCounter][boardColCounter]);
            printCounter++;
            if (printCounter % 4 == 0)
            {
                printf("\n");
                printCounter = 0;
            }
        }
    }
    printf("\n\n\n");
}

int moveLeft(int moveLeftVal)
{
    findCurrentRowCol();
    
    if ((currentRow - moveLeftVal) < 0)
    {
        printf("Incorrect input!  Takes you off the board!");
        return 0;
    }
    
    if (moveLeftVal == 1)
    {
        int moveTileBufferOne = tileGameBoard[currentRow][currentColumn - moveLeftVal];
        tileGameBoard[currentRow][currentColumn - moveLeftVal] = tileGameBoard[currentRow][currentColumn];
        tileGameBoard[currentRow][currentColumn] = moveTileBufferOne;
    }
    else if (moveLeftVal == 2)
    {
        int moveTileBufferOne = tileGameBoard[currentRow][currentColumn - moveLeftVal];
        tileGameBoard[currentRow][currentColumn - moveLeftVal] = tileGameBoard[currentRow][currentColumn];
        tileGameBoard[currentRow][currentColumn] = tileGameBoard[currentRow][currentColumn - 1];
        tileGameBoard[currentRow][currentColumn - 1] = moveTileBufferOne;
    }
    else if (moveLeftVal == 3)
    {
        //copy 3
        int moveTileBufferOne = tileGameBoard[currentRow][currentColumn - moveLeftVal];
        // Move 0 where 3 was
        tileGameBoard[currentRow][currentColumn - moveLeftVal] = tileGameBoard[currentRow][currentColumn];
        // Move 1 to where 0 was
        tileGameBoard[currentRow][currentColumn] = tileGameBoard[currentRow][currentColumn - 1];
        // Move 2 to where 1 was
        tileGameBoard[currentRow][currentColumn - 1] = tileGameBoard[currentRow][currentColumn - 2];
        // Move 3 to where 2 was
        tileGameBoard[currentRow][currentColumn - 2] = moveTileBufferOne;
    }
    
    printOutBoard();
    
    return 0;
}

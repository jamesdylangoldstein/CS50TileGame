//
//  main.c
//  CS50TileGame
//
//  Created by James Dylan Goldstein on 6/14/16.
//  Copyright © 2016 James Dylan Goldstein. All rights reserved.
//

//next step, build function to find the coordinate of zero

#include <stdio.h>
#include <stdlib.h>

int tileGameBoard[4][4];
int currentRow;
int currentColumn;
int winningBoard[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};

void populateBoard(void);
void findCurrentRowCol(void);
void printOutBoard(void);
int moveLeft(int moveLeftVal);
int moveRight(int moveRightVal);
int moveUp(int moveUpVal);
int moveDown(int moveDownVal);
int checkForWinner(void);

int main(int argc, const char * argv[]) {
    int moveLeftVal;
    int moveRightVal;
    int moveUpVal;
    int moveDownVal;
    char directionToMove;
    int tilesToMove;
    
    // Build the board and populate the board
    populateBoard();
    
    // Print Out Board
    printOutBoard();
    
    do
    {
        printf("Type 'L' to move left, 'R' to move right, 'U' to move up, 'D' to move down:");
        scanf(" %c", &directionToMove);
        
        if (directionToMove != 'q' || directionToMove != 'Q')
        {
            printf("Enter the number of tiles to move:");
            scanf(" %i", &tilesToMove);
            
            if (directionToMove == 'l' || directionToMove == 'L')
            {
                moveLeft(tilesToMove);
                checkForWinner();
            }
            else if (directionToMove == 'r' || directionToMove == 'R')
            {
                moveRight(tilesToMove);
                checkForWinner();
            }
            else if (directionToMove == 'u' || directionToMove == 'U')
            {
                moveUp(tilesToMove);
                checkForWinner();
            }
            else if (directionToMove == 'd' || directionToMove == 'D')
            {
                moveDown(tilesToMove);
                checkForWinner();
            }
        }
        
    }while(directionToMove != 'q' || directionToMove != 'Q');
    
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
    printf("\n\n");
}

int moveLeft(int moveLeftVal)
{
    findCurrentRowCol();
    
    if ((currentColumn - moveLeftVal) < 0)
    {
        printf("Incorrect input!  Takes you off the board!\n");
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

int moveRight(int moveRightVal)
{
    findCurrentRowCol();
    
    if ((currentColumn + moveRightVal) > 3)
    {
        printf("Incorrect input!  Takes you off the board!\n");
        return 0;
    }
    
    if (moveRightVal == 1)
    {
        int moveTileBufferOne = tileGameBoard[currentRow][currentColumn + moveRightVal];
        tileGameBoard[currentRow][currentColumn + moveRightVal] = tileGameBoard[currentRow][currentColumn];
        tileGameBoard[currentRow][currentColumn] = moveTileBufferOne;
    }
    else if (moveRightVal == 2)
    {
        int moveTileBufferOne = tileGameBoard[currentRow][currentColumn + moveRightVal];
        tileGameBoard[currentRow][currentColumn + moveRightVal] = tileGameBoard[currentRow][currentColumn];
        tileGameBoard[currentRow][currentColumn] = tileGameBoard[currentRow][currentColumn + 1];
        tileGameBoard[currentRow][currentColumn + 1] = moveTileBufferOne;
    }
    else if (moveRightVal == 3)
    {
        int moveTileBufferOne = tileGameBoard[currentRow][currentColumn + moveRightVal];
        tileGameBoard[currentRow][currentColumn + moveRightVal] = tileGameBoard[currentRow][currentColumn];
        tileGameBoard[currentRow][currentColumn] = tileGameBoard[currentRow][currentColumn + 1];
        tileGameBoard[currentRow][currentColumn + 1] = tileGameBoard[currentRow][currentColumn + 2];
        tileGameBoard[currentRow][currentColumn + 2] = moveTileBufferOne;
    }
    
    printOutBoard();
    
    return 0;
}

int moveUp(int moveUpVal)
{
    findCurrentRowCol();
    
    if ((currentRow - moveUpVal) < 0)
    {
        printf("Incorrect input!  Takes you off the board!\n");
        return 0;
    }
    
    if (moveUpVal == 1)
    {
        int moveTileBufferOne = tileGameBoard[currentRow - moveUpVal][currentColumn];
        tileGameBoard[currentRow - moveUpVal][currentColumn] = tileGameBoard[currentRow][currentColumn];
        tileGameBoard[currentRow][currentColumn] = moveTileBufferOne;
    }
    else if (moveUpVal == 2)
    {
        int moveTileBufferOne = tileGameBoard[currentRow - moveUpVal][currentColumn];
        tileGameBoard[currentRow - moveUpVal][currentColumn] = tileGameBoard[currentRow][currentColumn];
        tileGameBoard[currentRow][currentColumn] = tileGameBoard[currentRow - 1][currentColumn];
        tileGameBoard[currentRow - 1][currentColumn] = moveTileBufferOne;
    }
    else if (moveUpVal == 3)
    {
        int moveTileBufferOne = tileGameBoard[currentRow - moveUpVal][currentColumn];
        tileGameBoard[currentRow - moveUpVal][currentColumn] = tileGameBoard[currentRow][currentColumn];
        tileGameBoard[currentRow][currentColumn] = tileGameBoard[currentRow - 1][currentColumn];
        tileGameBoard[currentRow - 1][currentColumn] = tileGameBoard[currentRow - 2][currentColumn];
        tileGameBoard[currentRow - 2][currentColumn] = moveTileBufferOne;
    }
    
    printOutBoard();
    
    return 0;
}

int moveDown(int moveDownVal)
{
    findCurrentRowCol();
    
    if ((currentRow + moveDownVal) > 3)
    {
        printf("Incorrect input!  Takes you off the board!\n");
        return 0;
    }
    
    if (moveDownVal == 1)
    {
        int moveTileBufferOne = tileGameBoard[currentRow + moveDownVal][currentColumn];
        tileGameBoard[currentRow + moveDownVal][currentColumn] = tileGameBoard[currentRow][currentColumn];
        tileGameBoard[currentRow][currentColumn] = moveTileBufferOne;
    }
    else if (moveDownVal == 2)
    {
        int moveTileBufferOne = tileGameBoard[currentRow + moveDownVal][currentColumn];
        tileGameBoard[currentRow + moveDownVal][currentColumn] = tileGameBoard[currentRow][currentColumn];
        tileGameBoard[currentRow][currentColumn] = tileGameBoard[currentRow + 1][currentColumn];
        tileGameBoard[currentRow + 1][currentColumn] = moveTileBufferOne;
    }
    else if (moveDownVal == 3)
    {
        int moveTileBufferOne = tileGameBoard[currentRow + moveDownVal][currentColumn];
        tileGameBoard[currentRow + moveDownVal][currentColumn] = tileGameBoard[currentRow][currentColumn];
        tileGameBoard[currentRow][currentColumn] = tileGameBoard[currentRow + 1][currentColumn];
        tileGameBoard[currentRow + 1][currentColumn] = tileGameBoard[currentRow + 2][currentColumn];
        tileGameBoard[currentRow + 2][currentColumn] = moveTileBufferOne;
    }
    
    printOutBoard();
    
    return 0;
}

int checkForWinner(void)
{
    int winnerCounter = 0;
    for (int boardRowCounter = 0; boardRowCounter < 4; boardRowCounter++)
    {
        for (int boardColCounter = 0; boardColCounter < 4; boardColCounter++)
        {
             if (tileGameBoard[boardRowCounter][boardColCounter] == winningBoard[boardRowCounter][boardColCounter])
             {
                 winnerCounter++;
             }
             else
             {
                 return 0;
             }
        }
    }
    
    if (winnerCounter == 16)
    {
        printf("We've got a winner!\n");
        exit(0);
    }
    
    
    return 0;
}
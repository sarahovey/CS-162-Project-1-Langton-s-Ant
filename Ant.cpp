/***************************************
Author: Sara Hovey  
Date: 4/16/17
Description: 
This creates an Ant object, which simulates an ant
that moves around a game board of Langton's Ant.
The Ant moves around for n steps, where n is given
by the user at the start of the game 
***************************************/
#include "Ant.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*******************************
Constructor
*******************************/
Ant::Ant(char** b, char o, char sc, int s, int r, int c, int lR, int lC)
{
    gameBoard = b;
    orientation = o;
    steps = s;
    rows = r;
    cols = c;
    lRow = lR;
    lCol = lC;
    spaceColor = sc;
    
}


/*******************************
This function simulates the Ant taking a step
It "steps" to the element indicated in the
lRow and lCol variables
The second portion of the function prepares for
the next step by determining the correct direction, element,
and detecting/handling collisions
*******************************/
void Ant::move(char** gameBoard, char orientation, int steps, int rows, int cols, int lRow, int lCol)
{
    int stepsTaken = 0;
    
    // Perform the following until all steps are taken
    while(stepsTaken <= steps)
    {
        // Evaluate the color of the current spaceColor
        // white space
        if(gameBoard[lRow][lCol] == ' ')
        {
            spaceColor = 'W';
        }
        
        else if(gameBoard[lRow][lCol] == '#')
        {
            spaceColor = 'B';
        }
        
        else
        {
            cout << "Unknown color";
        }
        
        
        // Update orientation given current space color
        orientation = orient(orientation, spaceColor);
        
        // Update the board with the Ant's current spot
        gameBoard[lRow][lCol] = '@';
        
        // Print the board
        print();
        
        // Prepare for the next step
        
        // Swap color 
        if(spaceColor == 'B')
        {
            gameBoard[lRow][lCol] = ' ';
        }
        
        else if(spaceColor == 'W')
        {
            gameBoard[lRow][lCol] = '#';
        }
        
        else
        {
            cout << "Unknown color" << endl;
        }
        
        
        // Based on orientation, call the 
        // approproate location update function
        
        // N and S orientation correspond with a row change
        if(orientation == 'N' || orientation == 'S')
        {
            lRow = updateRow(rows, lRow, orientation);
            
        }
        
        // E and W orientation correspond with a column change
        if(orientation == 'W' || orientation == 'E')
        {
            lCol = updateCol(cols, lCol, orientation);
        }
       
        
        // Increment stepsTaken
        stepsTaken++;
        
        
    }
}
/*******************************
This function, given the num of rows in the array, 
an int that represents the Ant's current row, 
and the direction it is facing, 
it updates the lRow variable to 
reflect the row where the Ant 
will step to
*******************************/
int Ant::updateRow(int rows, int lRow, char orientation)
{
    // Simulates taking a step in the correct direction
    // Saves the step in a temp variable to detect collisions
    
    int tempLRow;
    
    if (orientation == 'N')
    {
        tempLRow = lRow - 1;
    }
    
    else if (orientation == 'S')
    {
        tempLRow = lRow + 1;
    }
    
    else
    {
        cout << "Unknown orientation" << endl;
    }
    
    // Collision detection
    
    // off the top of the board
    if(tempLRow < 0)
    {
        
        tempLRow = rows - 1;
    }
    
    // off the bottom of the board
    if(tempLRow >= rows)
    {
        tempLRow = 0;
    }
    
    lRow = tempLRow;
    return lRow;
}

int Ant::updateCol(int cols, int lCol, char orientation)
{
    int tempLCol;
    // Simulates taking a step in the correct direction
    // Saves the step in a temp variable to detect collisions
    
    if(orientation == 'E')
    {
        tempLCol = lCol + 1;
    }
    else if(orientation == 'W')
    {
        tempLCol = lCol - 1;
    }
    else
    {
        cout << "Unknown orientation" << endl;
    }
    
    // Collision detection
    
    // Collision detectected, wrap around
    if(tempLCol < 0)
    {
        tempLCol = cols - 1;
    }
    
    // Collision detectected, wrap around
    if(tempLCol >= cols)
    {
        tempLCol = 0;
    }
    
    // Collisions have been dealt with
    // Next step is valid
    lCol = tempLCol;
    return lCol;
}

/*******************************
Given the Ant's current orientation,
and the color of the space it is on,
the Ant is reoriented
*******************************/
char Ant::orient(char orientation, char spaceColor)
{
    // Represents a turn to the right,
    // functionally clockwise
    if(spaceColor == 'W')
    {
        switch (orientation)
        {
            case 'N':
                orientation = 'E';
                break;
            case 'S':
                orientation = 'W';
                break;
            case 'E':
                orientation = 'S';
                break;
            case 'W':
                orientation = 'N';
                break;
            default:
                cout << "bad orientation" << endl;
                break;
        }
    }
    // Represents a turn to the left
    // Functionally is counter clockwise
    else if(spaceColor == 'B')
    {
        switch (orientation)
        {
            case 'N':
                orientation = 'W';
                break;
            case 'S':
                orientation = 'E';
                break;
            case 'E':
                orientation = 'N';
                break;
            case 'W':
                orientation = 'S';
                break;
            default:
                cout << "bad orientation" << endl;
                break;
        }
    }
    
    else 
    {
        cout << "bad color" << endl;
    }
    
    return orientation;
}

/*******************************
This function prints the array
with the Ant being represented by
the "@" symbol
*******************************/
void Ant::print()
{
    // Column header
    //cout << "  0 1 2" << endl;
    for (int i = 0; i < rows ; ++i)
    {
        // Prints row headers
        //cout << i << " ";

        for (int j = 0; j < cols; ++j)
        {
            if (gameBoard[i][j] == ' ')
            {
                cout << " ";
            }
            
            else if (gameBoard[i][j] == '#')
            {
                cout << "#";
            }
            
            else if (gameBoard[i][j] == '@')
            {
                cout << "@";
            }
            else
            {
                cout << gameBoard[i][j] << " ";
            }
            
        }
        cout << endl;
    }
}


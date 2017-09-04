/*****************************************
Author: Sara Hovey 
Date: 4/16/17
Description: This is the main file for Langton's Ant
It creates a new Ant object, and begins a new game of
Langton's Ant.

This was done for CS 162 at Oregon State
*****************************************/
#include "Ant.hpp"
#include <iostream>
#include <climits>

using std::cin;
using std::cout;
using std::endl;

char** newBoard(int rows, int cols);
bool validateInt (int data, int min, int max);
bool validateChar(char data, int type);
void play();


/***************************************
Menu/main
**************************************/
int main ()
{
    bool valid = false;
    int input;
    
    while (valid == false)
    {
        // This style of data type input validation came from
        // http://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer
        // and http://stackoverflow.com/questions/2075898/good-input-validation-loop-using-cin-c
        for(;;)
        {
            cout<< "Welcome, friend. Please select what you would like to do" << endl;
            cout<< "1: Langton's Ant" << endl;
            cout<< "2: Exit" << endl;
            
            if(cin >> input)
            {
                break;
            }
            else
            {
                cout << "Please enter an integer" << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        }

        // validate for range
        
        valid = validateInt(input, 1, 2);
    }
    
    // Now that we have valid input, we can evaluate the response
    switch (input)
    {
        case 1:
            play();
            break;
        case 2:
            cout << "goodbye! " << endl;
        default:
            break;
    }
    
    return 0;
}


char** newBoard(int rows, int cols)
{
    // Allocates memory
	char** gameBoard = new char*[rows];
	for (int i = 0; i<rows; i++)
	{
		gameBoard[i] = new char[cols];
	}
    
    // Fills all elements with ' '
    // This indicates a "white" space
     for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            gameBoard[i][j] = ' ';
        }
        
    }
    return gameBoard;
     
}

/***************************************
This function bounds-checks an int, 
given a min and max
**************************************/
bool validateInt (int data, int min, int max)
{
    bool valid;
    
    if (data < min || data > max)
    {
        valid = false;
    }
    
    else
    {
        valid = true; 
    }
    
    return valid;
}

/*
bool validateChar(char data, int type)
{
    bool valid;
    // Type 1: Color
    if (type == 1)
    {
        // Evaluate possible colors
        if(data == 'B' || data == 'W')
        {
            valid = true;
        }
        
        else
        {
            valid = false;
        }
        
    }
    
    // Type 2: Orientation  
    if (type == 2)
    {
        if(data == 'N' || data == 'W' || data == 'S' || data == 'E')
        {
            valid = true;
        }
        
        else
        {
            valid = false;
        }
    }
    
}
*/

/***************************************
This function starts a new run of Langton's Ant
**************************************/
void play()
{
    bool validRow = false;
    bool validCol = false;
    bool validStep = false;
    bool validLoc = false;
    
    int rows, cols, steps, lRow, lCol, locationChoice;
    lRow = 0;
    lCol = 0;
    
    // Begins with a default White space colors
    // and a default E orientation
    char spaceColor = 'W';
    
    char orientation = 'E';
    
    while (validRow == false)
    {
        // Ask user for Board size
        // VALIDATE
        cout << "Welcome to Langton's Ant, let's make a game board" << endl;
        for(;;)
        {
            cout << "How many rows should it have? Please enter 80 or fewer" << endl;
            if(cin >> rows)
            {
                break;
            }
            else
            {
                cout << "Please enter an integer" << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        }  
        
       // cout << "How many rows should it have? Please enter 80 or fewer" << endl;
        //cin >> rows;
        
        
        // Now that we know it's an int, we can validate content
        validRow = validateInt(rows, 1, 80);   
        
    }
        
    while(validCol == false)
    {
        
        for(;;)
        {
            cout << "How many columbs should it have? Please enter 80 or fewer" << endl;
            if(cin >> cols)
            {
                break;
            }
            else
            {
                cout << "Please enter an integer" << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        }  
        

        // Now that we know it's an int, we can validate content
        validCol = validateInt(cols, 1, 80); 
        
    }
    
    while(validStep == false)
    {
        for(;;)
        {
            cout << "How many steps should the ant walk?" << endl;
            if(cin >> steps)
            {
                break;
            }
            
            else
            {
                cout << "Please enter an integer" << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
          
        }
       
        validStep = validateInt(steps, 1, 100);
    }
    
    while(validLoc == false)
    {
        for(;;)
        {
            cout<< "Where should the ant begin" << endl;
            cout<< "1: Custom location" << endl;
            cout<< "2: Random location" << endl; 
            
            if(cin >> locationChoice)
            {
                break;
            }
            else
            {
                cout << "Please enter an integer" << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        }
   
        validLoc = validateInt(locationChoice, 1, 2);
    
    }
    
    // Now that we have valid input, we can evaluate the response
    
    if (locationChoice == 1)
    {
        // prompt for location
        
        bool validLC = false;
        bool validLR = false;
        
        while(validLR == false)
        {
            cout << "Enter starting row. Remember that indexing begins at 0. " << endl;
            for(;;)
            {
                if(cin >> lRow)
                {
                    break;
                    
                }
                
                else
                {
                    cout << "Please enter an integer" << endl;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }
            }
            
           // Validate for range
           validLR = validateInt(lRow, 0 , rows-1);
        }
        
        while(validLC == false)
        {
            for(;;)
            {
                cout << "Enter starting column. Remember that indexing begins at 0. " << endl;
                if(cin >> lCol)
                {
                    break;
                }
                
                else
                {
                    cout << "Please enter an integer" << endl;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }
                
            }
           
           // Validate for range
           validLC = validateInt(lCol, 0 , cols-1);
        }
        
    }
    
    // Generate a random start by getting a random row and column
    // between 0 and the number of rows - 1
    // to account for off-by-one errors
    if(locationChoice == 2)
    {
        lRow = rand() % (rows-1) + 0;        
        
        lCol = rand() % (cols-1) + 0;
    }
    
    cout << "It's time to do ant stuff";
    // Create new Board
    char** gameBoard = newBoard(rows, cols);
    
    // Create new Ant
    Ant ant1(gameBoard, orientation, spaceColor, steps, rows, cols, lRow, lCol);
  
    ant1.move(gameBoard, orientation, steps, rows, cols, lRow, lCol);
    
    cout << "The game has concluded, behold" << endl;
    
    // Deallocate mem for array
	for (int i = 0; i<rows; i++)
	{
		delete[] gameBoard[i];
	}
	
	delete[] gameBoard;
	
}





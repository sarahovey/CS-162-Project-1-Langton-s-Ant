/***************************************
Author: Sara Hovey  
Date: 4/16/17
Description: This is the header file for the Ant class
This creates an Ant object, which simulates an ant
that moves around a game board of Langton's Ant 
***************************************/

#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
    private:
    char** gameBoard;
    char orientation;
    int steps;
    int rows;
    int cols;
    int lRow;
    int lCol;
    char spaceColor;
    
    public:
    
    // Constructor 
    Ant(char** b, char o, char sc, int s, int r, int c, int lR, int lC);
    
    // Other member functions
    void move(char** gameBoard, char orientation, int steps, int rows, int cols, int lRow, int lCol); 
    int updateRow(int rows, int lRow, char orientation);
    int updateCol(int cols, int lCol, char orientation);
    char orient(char orientation, char spaceColor);
    void print();
    
    
};


#endif
/*The program simulates a snake moving on a grid from a gate, avoiding walls and obstacles, 
and ends if the snake runs into itself based on user-provided movement directions. It also grows when it eats*/
#include <iostream>
using namespace std;
char ** createField(int length, int width);
void playGame(char ** arr, int width, int length);
int main ()
{
    cout<<"length width";
    int l,w;
    cin>>l>>w;
    char ** x = createField(l,w);
    playGame(x,l,w);
    return 0;

}
char ** createField(int width, int length)
{

    char **arr= new char*[width];

    // Use a loop to create each individual row
    for(int i=0; i<width; i++)
        arr[i] = new char[length];
 // use it like a regular 2D array


    for (int i = 0; i < width; i++)
    {
        for (int j=0; j< length; j++)
        {
            if (i ==0 || i ==width-1 || j==0 || j == length-1)
            arr[i][j]= 'W';
            else
            arr[i][j]='.';


        }
    }
    /*Read a number ‘N’ from the user. Then, read in ‘N’ points marking the location of obstacles.
Obstacles will only occupy one “spot” in the field, specified by a row and column number (0
indexed. Mark the obstacles with an ‘O’. (10 points)*/

    cout<<"Coor num: ";
    int n,row,col;
    char comma;
    cin>>n;
    //cin.ignore();

    cout<<"enter "<<n<<" coordinates: ";
    for (int i= 0; i< n; i++)
    {
        cin>>row;
        cin>>comma;
        cin>>col;
        //cin.ignore();
            arr[row][col] = 'O';

    }

    for(int i=0; i<width; i++)
    {
        for(int j=0; j<length; j++)
        cout<<arr[i][j]; 
        cout<<endl;
    }


    return arr;
}
/* 
– Each turn will consist of a direction and a number of spots. The snake will turn in the given
direction and travel the given number of spots.
– The snake will begin from the location of the gate.
– Directions are as follows: U - Up, D - Down, L - Left, R- Right. You may assume that the
snake will never do a 180 degree turn in one go, that is, if the snake were travelling down, the
next turn will only ever be left or right, never up. The directions are also according to your
perspective on the map, not the snake’s.
– You may assume that the first turn will work with the location of the gate. That is, if the gate
is on the Eastern wall, the first turn’s direction will be ‘L’. You may also assume the gate will
never be at the corner, and the obstacles will not block entry into the field.
– For every turn, read in the direction and number of spots, and move the snake in the direction,
for the given number of spots, and mark the passage of the snake with ‘S’. (15 points)
– If the snake ever runs into itself, stop the game. (5 points)
– You may assume that the snake will be able to move the given number of spots in the given
direction without running into a wall. However, if it runs into an obstacle, move on to the next
turn. (5 points)
– If we finish out all the turns, and the snake is yet to run into itself, stop the game*/


void playGame(char ** arr, int width, int length)
{
    cout<<"Enter the location of the gate: ";
    int gRow,gCol;
    char comma;
    cin>>gRow;
    cin>>comma;
    cin>>gCol;
    //cin.ignore();
    
            arr[gRow][gCol] = 'G';
    int T;
    cout<<"Enter num of turns: ";
    cin>>T;
    //cout<<"this is t: "<<T;

    char letter;
    int n;
    //maybe idk
    //add if statements for where the gate is located (top or bottom row or left or rigth)
    int CURRENTROW = gRow;
    int CURRENTCOL = gCol;
    /* 
    if (gRow == 0 )
        CURRENTROW = gRow + 1;
    if (gRow == width-1)  
        CURRENTROW = gRow - 1;  
    if (gCol == 0)  
        CURRENTCOL = gCol + 1;
    if (gCol == length -1)
        CURRENTCOL = gCol - 1;
    */

    for (int i = 0; i < T; i++)
    {
        cout<<"letter: ";
        cin>>letter;
        cout<<"number: ";
        cin>>n;
        //cout<<letter<<'\t'<<n;
        cout<<"current row is now: "<<CURRENTROW<<endl;
        int tempCurRow;
        int tempCurCol;
        bool gameOver = false;

        if (gameOver == false)
        {

        switch (letter)
        {
            case 'U' : //code

            case 'u' :  
                        for (int i = CURRENTROW - 1, j = 0; j < n && arr[i][CURRENTCOL] != 'O' && gameOver == false; j++, i--)
                            {
                                arr[i][CURRENTCOL] = 'S';
                                tempCurRow = i;
                                if (arr[i-1][CURRENTCOL] == 'S')
                                gameOver = true;
                            }
                            CURRENTROW = tempCurRow;
                            cout<<"current row is now: "<<CURRENTROW<<endl;
                            for(int i=0; i<width; i++)
                                {
                                    for(int j=0; j<length; j++)
                                    cout<<arr[i][j]; 
                                    cout<<endl;
                                }

            break;

            case 'D' : //code

            case 'd' : 
                    for (int i = CURRENTROW + 1, j = 0; j < n && arr[i][CURRENTCOL] != 'O' && gameOver == false; j++, i++)
                        {         
                            arr[i][CURRENTCOL] = 'S';
                            tempCurRow = i;
                            if (arr[i+1][CURRENTCOL] == 'S')
                                gameOver = true; 
                        }

                        CURRENTROW = tempCurRow;
                        cout<<"current row is now: "<<CURRENTROW<<endl;
                    for(int i=0; i<width; i++)
                        {
                            for(int j=0; j<length; j++)
                            cout<<arr[i][j]; 
                            cout<<endl;
                        }

            break;

            case 'L' : //code

            case 'l' : 
                        for (int i = CURRENTCOL - 1 , j = 0; j < n && arr[CURRENTROW][i] != 'O' && gameOver == false; j++, i--)
                            {         
                                arr[CURRENTROW][i] = 'S';
                                tempCurCol = i;
                                if (arr[CURRENTROW][i-1] == 'S')
                                gameOver = true;  
                            }
                            CURRENTCOL = tempCurCol;
                            cout<<"current col is now: "<<CURRENTCOL<<endl;
                            for(int i=0; i<width; i++)
                                {
                                    for(int j=0; j<length; j++)
                                    cout<<arr[i][j]; 
                                    cout<<endl;
                                }

            break;

            case 'R' : //code

            case 'r' : 
                        for (int i = CURRENTCOL + 1, j = 0; j < n && arr[CURRENTROW][i] != 'O' && gameOver == false; j++, i++)
                                        {           
                                            arr[CURRENTROW][i] = 'S';
                                            tempCurCol = i;
                                            if (arr[CURRENTROW][i+1] == 'S')
                                            gameOver = true; 
                                        }
                                        CURRENTCOL = tempCurCol;
                                        cout<<"current col is now: "<<CURRENTCOL<<endl;
                                        for(int i=0; i<width; i++)
                                            {
                                                for(int j=0; j<length; j++)
                                                cout<<arr[i][j]; 
                                                cout<<endl;
                                            }

            break;

        }

    }
    if (gameOver == true)
    cout<<"GAME OVER"<<endl;
   

        
}
}





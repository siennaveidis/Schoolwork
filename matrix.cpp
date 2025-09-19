/* Name: (Sienna Veidis)
Date: (3/24)
Section: (2)
Assignment: (HW 5)
Due Date: (3/24)
About this project: reads in array and prints its transpose
Assumptions: rows and collumn numbers will not be negative, will not exceed 99

All work below was performed by (Sienna Veidis) */
#include <iostream>
int const ROWCAP = 100;
int const COLCAP = 100;
void initialize(int arr[ROWCAP][COLCAP], int row, int col);
void printRotation(int arr[ROWCAP][COLCAP], int row, int col);
using namespace std;
int main () 
{
    int matrix[ROWCAP][COLCAP];
    int row, col;
    cout<<"Enter the number of rows: ";
    cin>>row;
    cout<<"Enter the number of columns: ";
    cin>>col;
    cout<<"Enter the matrix: ";
    initialize(matrix,row,col);

    cout<<"The rotated matrix is:"<<endl;
    printRotation(matrix, row, col);

    
}
void initialize(int arr[ROWCAP][COLCAP], int row, int col)
{
        for(int i=0; i<row; i++)
        for(int j =0; j<col; j++)
            cin>>arr[i][j];
}

void printRotation(int arr[ROWCAP][COLCAP], int row, int col)
{
    for(int i=col-1; i>=0; i--)
    {
        for(int j=row-1; j>=0; j--)
            cout<<arr[j][i]<<"\t";
            cout<<endl;

    }
}
/*initialize LOGIC: it reads values row by row, once the inner loop completes its run that means all the collumns 
of that row has been entered, then it continues to the next row and reads in the collumns and continues as many times as there are rows*/

/*printRotation LOGIC: prints out the matrix but flips the values of the inner and out loop and also the order of the increment variables. if the number
of rows and collumns are different, the function will print as many collumns as the number of rows the user enters, and as many rows as the number of collumns the user enters*/


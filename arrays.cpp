/* Name: (Sienna Veidis)
Date: (3/24)
Section: (2)
Assignment: (HW 5)
Due Date: (3/24)
About this project: (this project displays a menu and based on the users choice, calls a function that either prints the array, 
sorts the array in descending order, inserts a number after every instance of a value in the array and every time the number
is inserted it increments, removes all values between two values in the array inclusive, and circularly moves all odd indecies to the next odd
index to the left as many times as the user enters while simultaneously circularly moving all even indecies to the next even
index to the right as many times as the user enters)
Assumptions: The insertion values and the fourth parameter of the insert function will never be the same number. the array size will never drop
below 1 and will never rise above 99. the moveElements function will only be called when the array has at least 3 elements. move elements entered value will not be negative


All work below was performed by (Sienna Veidis) */
#include <iostream> 
using namespace std;
void readArray(double arr[] , int size);
void printArray( double arr[] , int sz);
int linearSearch( const double arr[], int size, double key, int start);
void insertValues( double arr[], int &size, double key, double num);
int removeValues ( double arr[], int &size, double lo, double hi);
void moveElements (double arr[], int size, int odd, int even);
void sort(double arr[], int size);
int main()
{
    //declaring max size of array as a constant
    int const CAPACITY = 100;
    int size,odd,even;
    double val, occurance,remove1,remove2;
    //getting paramater needed for read funct
    cout<<"Enter the number of values: ";
    cin>>size;
    int USERSIZE;
    //declare array to be used
    double array[CAPACITY];
    //call read funct
    readArray(array,size);
    //give user menu and reads in their choice
    cout<<"1. Print the Array\n2. Insert Values\n3. Remove Values\n4. Move Elements\n5. Sort the Array\n6. Exit"<<endl;
    int choice = 0;
    cout<<"Enter your choice: ";
    cin>>choice;
    //while loop runs as long as the user has not exited by pressing 6
    //each case calls the function respective to the menu choice
    //6 prints goodbye message default prints an error message
    while (choice != 6)
    {
    switch (choice) {
        case 1 : cout<<"The array is: "<<endl; 
                 printArray(array,size);
            break;
        case 2 : cout<<"Enter the value after which to insert: ";
                cin>>occurance;
                cout<<"Enter the starting value: ";
                cin>>val;
                USERSIZE = size;
                insertValues(array, size, occurance ,val);
                if (size == USERSIZE)
                cout<<"Value not found in the array"<<endl;
                else
                cout<<"Element inserted"<<endl;
            break;
        case 3 : cout<<"Enter the first value in the list: "<<endl;
                cin>>remove1;
                cout<<"Enter the second value in the list: "<<endl;
                cin>>remove2;
                USERSIZE = size;
                removeValues (array, size, remove1, remove2);
                if (USERSIZE == size)
                cout<<"Entered numbers were not the end points of a list"<<endl;
                else
                cout<<"Elements deleted"<<endl;

            break;
        case 4 : cout<<"Enter the number of spots to move odd positions: ";
                cin>>odd;
                cout<<"Enter the number of spots to move even positions:";
                cin>>even;
                moveElements (array, size, odd, even);
                cout<<"Elements moved"<<endl;
            break;
        case 5 : sort(array, size);
            cout<<"Elements sorted"<<endl;
            break;
        case 6 : cout<<"Goodbye"<<endl;
            break;
        default : cout<<"Wrong option entered"<<endl;
                break;

    }
    //reprompt user for new menu choice
    cout<<"Enter your choice: ";
    cin>>choice;
    }
    if (choice == 6)
    cout<<"Goodbye"<<endl;

return 0;
}
//reads in array
void readArray(double arr[] , int size)
{
    cout<<"Enter " <<size<<" values: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>> arr[i];
    }
}

//prints array

void printArray(double array[] , int sz)
{
    for (int i = 0; i < sz; i++)
    {
        cout<<array[i]<<'\t';
    }
}
//Searches through array for first instance of key if key is there
int linearSearch( double arr[], int size, double key, int start)
{
    int pos=-1;
    for(int i=start; i<size && pos == -1; i++)
        if(arr[i] == key)
            pos = i;
    return pos;
}

//function inserts value num after every instance of the parameter key, num increments each time it is inserted
void insertValues(double arr[], int &size, double key, double num)
{

    int currentIndex = linearSearch(arr, size, key, 0);
    while (currentIndex != -1)
    {
        size++;
    for(int i= size-1; i>currentIndex; i--)
    {

            arr[i]=arr[i-1];
           arr[currentIndex] = key;

    }
    
    arr[currentIndex + 1] =num;
    currentIndex = linearSearch(arr, size, key, currentIndex +1);

    num++;
    }
    
}

//removes all values in the array starting at the first entered num to the second entered num
int removeValues (double arr[], int &size, double lo, double hi)
{
    //check 3 is to see if lo comes before hi - false means function will not continue
    //check 1 is to see if lo exists
    //check 2 is to see if hi exists

    bool check1 = false;
    bool check2 = false;
    bool check3 = true;


    int start = linearSearch(arr, size, lo, 0);
    int end = linearSearch(arr, size, hi, 0);

    if (start != -1)
    check1 = true;

    
    if (end != -1)
    check2 = true;

       
   if (start>end)
   {
   check3 = false;
   }

    if (check1 == true && check2 == true && check3 == true)
    {
        for (int j = 0; j <= end - start; j++ )
         { 
        for (int i = 0; i < size; i++)
        {
            arr[start + i]= arr[start + i+1];

        }
        --size;
    }
    
        
    }

    return size;

}

/*circular left shift the elements in the odd indices by the third parameter 
number of odd positions and also circular right shift the elements in even 
odd indices by the fourth parameter number of even positions*/

void moveElements (double arr[], int size, int odd, int even)
{
    double rollOver = arr[1];
    double rollOverEven;
    int counter = 0;
    if (size % 2 == 1)
    rollOverEven = arr[size-1];
    else 
    rollOverEven = arr[size-2];

    if (odd > 0)
    {
    if (size % 2 == 1)
    {
    for (int j = 0; j < odd; j++)
    {
        for (int i = 1; i < size; i+=2)
        {
            arr[i]= arr[i+2];
            counter++;
        }      
            arr[size - 2] = rollOver;
            rollOver = arr[1];
    }
    }
    else 
    {
    for (int j = 0; j < odd; j++)
    {
        for (int i = 1; i < size; i+=2)
        {
            arr[i]= arr[i+2];
            counter++;
        }      
            arr[size - 1] = rollOver;
            rollOver = arr[1];
    }
    }
    }

    if (even > 0)
    { 
    if(size % 2 == 0)
    {
    for (int j = 0; j < even; j++)
    {
        for(int i=size-2; i>0; i-=2)
        {
    
            arr[i] = arr[i-2];
            counter++;
        }
          
        arr[0] = rollOverEven;
        rollOverEven = arr[size-2];
    }    
    }
    else
    {
        for (int j = 0; j < even; j++)
        {
            for(int i=size-1; i>0; i-=2)
            {
        
                arr[i] = arr[i-2];
                counter++;
            }
            arr[0] = rollOverEven;
            rollOverEven = arr[size-1];
        }    
        }

    }
    

    

}

//Uses Selection Sort algorithm to sort the array in descending order.
void sort(double arr[], int size)
{
    for(int i=0;i<size-1; i++)
    {
        for(int j=0; j<size-i-1; j++)
        {
            if(arr[j]< arr[j+1])
            {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}
/*readArray LOGIC: you cannot just cin an entire array. you have to do it one index at a time. 
this function uses a loop to iterate through every index of the array and reads it in*/

/*printArray LOGIC: similarly to how you cannot cin an entire array in one go, you also cannot cout an entire array. 
if you do cout<< arrayName it will give you the starting address. this function uses a loop to iterate through every index of the array and prints it*/

/*linearSearch LOGIC: the position of key is what we want to find and is also the return value. it is initialized to -1 because there can never be an array index of -1.
if the position stays at -1 that means no value has been found. the loop begins at the starting index the user enters, 
and goes through the entire array while the position has not been found, this is because of the && pos == -1, if it weren't for that
this function would return the last occurance of the key value, when it really needs to return the first value then exit the loop. 
the function checks if the value is in the array by the == operater and iterates through every index individually*/

/*insertValues LOGIC: First is error checking, using linear search to see if the third parameter is in the array. if the value is there it will proceed with the function. 
since size increments every time a value is added, if size the other size variable value in main are not equal, the value must have been inserted. the loop works by
first increasing the current size of the array making room for the new value then shifts all neccessary indecies right 
so that the value can be inserted into current index. after the for loop runs, current index is reassigned 
using the function linearSearch amd num is incremented*/

/*removeValues LOGIC: I decided to use boolean values to determine whether the fucntion should continue as intended or not.
The first two checks are initialized to false and they use the linearSearch function to see ONLY if both values are simply in the array,
the next check is initialized to true (but can also work by initializing to false then proving it to be true) and it compare the returned
indecies of the two values from the linearSearch function, if the expected "starting" value is larger than the expected "end" value the check is
set to be false, if all checks are true the function proceeds. The outer loop runs the amount of indecies there are from the start to end value,
the inner loop goes through all of those values and shifts them left, reassigning the starting value to the next value and repeating this as many
times as it needs to "remove" all the neccessary values, if all checks are false it prints out a message, it returns new size which is initialized to the 
original size incase the size does not change, if the function does run as user intended, newSize = the original size - the amount of indecies removed*/


/*sort LOGIC: the sort algorithm iterates through the array and creates a temp value that constantly gets reassigned to the 
current index value and the index and the current index switch if the proceeding index is larger than the current */

/*moveElements LOGIC: This function moves each odd index left by iterating through the array and reassigning indexes by doing arr[i]= arr[i+2]. 
It does this ONE at a time, until the for loop hits the user entered number, the roll over value is initially set to arr[1] because 
the last odd index in the array will always be arr[1], and every time the loop runs the rollOver value reassigns to the new arr[1] val.
depending on whether or not size is even or odd, the rollover value is changed from array size-2 to size-1 for even, and the index that 
gets assigned the rollover value changes from size-1 to size-2 for odd(order of changes is ignored in this explanation, simply the two options are listed)
*/




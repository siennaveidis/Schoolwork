/* Name: (Sienna Veidis)
Date: (4/11)
Section: (2)
Assignment: (6)
Due Date: (4/11)
About this project: takes in a string, checks if it is a palindrome, if it isnt will rotate by one letter until it is a palidrome, if it isnt then it is not returned, 
all palindromes are returned at the end
Assumptions: each string will only contain lower and uppercase letters, numerals, and spaces. maximum of 500 strings and 500 characters per string

All work below was performed by (Sienna) */
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;
//declarations
bool checkPalin(char str[]);
string checkPasscodes(char str2[500][500], int num);

int main ()
{
    //promting user
    cout<<"Enter the strings: "<<endl;
    //declare string and string arrays
    char str[500];
    char str2[500][500];
    //read in str
    cin.getline(str,500,'\n');

    //compy str onto str2 so it can be used in another function
    strcpy(str2[0],str);
    int num = 1;
    //loops and increments everytime a string is entered
    while(str[0] != NULL)
    {
        cin.getline(str,500,'\n');
        strcpy(str2[num],str);
        num++;
    }
    //call function
    cout<<"The palindromes passcodes are\n"<<checkPasscodes(str2,num);

    return 0;
    
}
bool checkPalin(char str[])
{
    int size = strlen(str);
    bool ans = true;
    int counter = 0;
    for (int i = 0, j = size-1; i < j, j > i; i++, j--)
    {
    
            if (isspace(str[i]))
            i++;
            if (isspace(str[j]))
            j--;

            if (toupper(str[i]) != toupper(str[j]))
            counter++;
    }

    if (counter > 0)
    ans = false;
    else
    ans = true;

    int counter2 =0;
    if (ans==false)
    { 
    while(ans == false && counter2 < size)
    {
        char temp = str[size-1];
        for (int i = size-1; i > 0; i--)
        {
            str[i]=str[i-1];
        }
        str[0] = temp;
        counter2++;
                
        for (int i = 0, j = size-1; i < j, j > i; i++, j--)
        {
    
            if (isspace(str[i]))
            i++;
            if (isspace(str[j]))
            j--;

            if (toupper(str[i]) != toupper(str[j]))
            counter++;
        }

    if (counter > 0)
    ans = false;
    else
    ans = true;
    counter = 0;
    }
    }
    return ans;
        
}
string checkPasscodes(char str[500][500], int num)
{
    string s = "";
    for(int i = 0; i < num; i++)
    {
        if (checkPalin(str[i]) == true)
        {
            //cout<<str[i];
            s += str[i];
            s+='\n';
        }
    }

    return s;

}
/*checkpalin logic: has a counter, iterates through the string and if there is a space increment i or j to skip over it and compare the next index,
if they are ever not equal the counter is set to 1 and never reset to 0 if a different index is equal. if the counter is greater than zero it is not a palindrome.
if it is not, the string shifts one character, if it still is not a palindrome it shifts and checks one less times than it would take for the string to go back to normal.
the comparisons look at the uppercase version of the char of each index using toupper to make it case insensitive*/
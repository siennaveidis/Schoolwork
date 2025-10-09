/*Sienna Veidis
COP 3330 Section 5
HW 3
The class Mixed creates the type of a mixed number, creates operator overloaded funcs, and other useful functions
such as turning it into a decimal number, simplifying it, and turning it into an improper fraction*/
#include <iostream>
#include <iomanip>
#include "mixed.h"
using namespace std;

//output operator
ostream& operator<<(ostream& s, const Mixed& f)
{ 
    if (f.whole != 0 && f.numerator != 0)                                   
    s << f.whole << " " <<f.numerator << '/' << f.denominator;                      //format for a full mixed num eg. 3 4/5
    else if (f.whole == 0 && f.numerator != 0)
    s << f.numerator << '/' << f.denominator;                                       //format for a reg fraction eg. 7/8
    else 
    s << f.whole;                                                                    //format for just the number eg. 9
    return s;
}   
//input operator
istream& operator>>(istream& s, Mixed& f) 
{ 
    char slash;
    s >> f.whole >> f.numerator >> slash >> f.denominator;                          //reading in
    if (f.isValid(f.whole, f.numerator, f.denominator) == false)                    //error checking
    {
        f.whole = 0;
        f.numerator = 0;                                                            //assigning default vals
        f.denominator = 1;
    }    

    return s;
}

//default constructor
 Mixed::Mixed(int integer)
 {
    whole = integer;
    numerator = 0;                                                                  //assigning
    denominator = 1;
 }
//constructor
 Mixed::Mixed(int integer, int num, int denom) 
 {
    if (isValid(integer, num, denom) == true)                                           //error checking
    {
        whole = integer;
        numerator = num;                                                                //assigning
        denominator = denom;
    }
    else
    {
        whole = 0;
        numerator = 0;                                                                  //assigning default vals
        denominator = 1;
    }    
 }
//helper function checking vals
bool Mixed::isValid(int integer, int num, int denom) const
{
    if (integer < 0 || integer > 0)
    {
        if(num < 0 || denom <= 0)
        {
            return false;                                                           //info was not valid
        }
    }
    else if (integer == 0)
    {
        if (denom <= 0)
        {
            return false;                                                              //info was not valid
        }
    }
    
    return true;

}
//func returns mixed variable as a decimal value
double Mixed::Evaluate() const 
{
    
    double number = 0;
    double evNum = numerator;
    double evDenom = denominator;
    if (whole >= 0)
    {
        number += whole;                                                    //positive and 0 case
        number += evNum/evDenom;
    }
    else if (whole < 0)
    {
        number += whole;                                                       //negative case
        number -= evNum/evDenom;

    }

    return number;
}
//func returns mixed variable as an improper fraction
void Mixed::ToFraction()
{
    int placeholder = numerator;
    if (whole >= 0)
    {
        numerator += whole * denominator;                                             //positive and 0 case
        whole = 0;
    }
    else
    {
        numerator = 0;
        numerator += whole * denominator;                                           //negative case
        numerator -= placeholder;
        whole = 0;
    }
    
}
//func simplifies the mixed variable
void Mixed::Simplify()
{
    double div = 0;

    if ((numerator >= denominator || 0 - numerator >= denominator) && (numerator % denominator == 0) && whole >= 0)
    {
        whole += numerator / denominator;                           //positive case that results in a single whole number
        denominator = 0;
        numerator = 0;
    }
    else if ((numerator >= denominator) && (numerator % denominator == 0) && whole < 0)
    {
        whole -= numerator / denominator;
        denominator = 0;                                            //negative case that results in a single whole number
        numerator = 0;
    }
    else if (numerator >= denominator && whole >= 0)
    {
        whole += numerator/denominator;                             //positive or 0 mixed number case
        numerator = numerator%denominator;
    }
    else if (numerator >= denominator && whole < 0)
    {
        whole -= numerator /denominator;
        numerator = numerator%denominator;                                      //negative mixed number case
    }
    else if (numerator < 0 && whole == 0)
    {
        whole -= (numerator * -1)/denominator;                          //negative reg fraction case
        numerator = (numerator * -1 )%denominator;
    }
   

    if (numerator != 0 && denominator != 0) 
    {
        for (int i = 1; i < denominator; i++)
            {
                if(denominator%i == 0 && numerator%i == 0)              // further simplifying the fraction part
                div = i;
            }

        if (div != 0)
            {
                numerator = numerator / div;
                denominator = denominator / div;
            }
    }
}
//function to see if two fractions are equal
bool operator==(const Mixed& n1, const Mixed& n2)
{
    Mixed temp1, temp2;
    temp1 = n1;
    temp2 = n2;
    temp1.Simplify();                       //simplify both temp variables first
    temp2.Simplify();

    if ((temp1.denominator == temp2.denominator)&&(temp1.numerator == temp2.numerator)&&(temp1.whole == temp2.whole))
    return true;                                            // case if they are the exact same
    else if ((temp1.numerator * temp2.denominator) == (temp2.numerator * temp1.denominator) && temp1.whole == temp2.whole)
    return true;                                // case if they are equivelant
    else
    return false;
}
//function to see if two fractions are not equal
bool operator!=(const Mixed& n1, const Mixed& n2)
{
    if (n1 == n2)
    return false;                               //calling equals func
    else
    return true;
}
//function to see if first fraction is less than second
bool operator<(const Mixed& n1, const Mixed& n2)
{
    Mixed temp1, temp2;
    temp1 = n1;
    temp2 = n2;
    temp1.Simplify();
    temp2.Simplify();

    if (temp1.whole < temp2.whole && temp1 != temp2)
    return true;                                                                    //if whole is bigger in simplified version that fraction is automatically bigger
    else if (temp1.whole == temp2.whole && temp1 != temp2)
    {
        if ((temp1.numerator * temp2.denominator) < (temp2.numerator * temp1.denominator))     //if equation to see if one is bigger is true
            return true;                                                
        else
            return false;
    }
    else if ((temp1.whole > temp2.whole) || (temp1 == temp2))
    return false;
}
//function to see if second fraction is less than first
bool operator>(const Mixed& n1, const Mixed& n2)
{
    if (n1 < n2 == false && n1 != n2)                                           // calls != and <
    return true;
    else
    return false;
}
//function to see if second fraction is less than first or they are equal
bool operator>=(const Mixed& n1, const Mixed& n2)
{
    if ((n1 > n2) || (n1 == n2))                                                    // calls == and >
    return true;
    else
    return false;
}
//function to see if first fraction is less than second or they are equal
bool operator<=(const Mixed& n1, const Mixed& n2)
{
    if ((n1 < n2) || (n1 == n2))                                                // calls == and <
    return true;
    else
    return false;
}
//function to add two mixed variables together
Mixed operator+(const Mixed& n1, const Mixed& n2) //fix for negative nums
{
    Mixed temp1, temp2, result;
    temp1 = n1;
    temp2 = n2;
    temp1.ToFraction();
    temp2.ToFraction();                 //makes them improper fractions

    if (temp1.denominator != temp2.denominator)
    {
        result.numerator = ((temp1.denominator * temp2.numerator)+(temp2.denominator * temp1.numerator));       //make denoms even then add the numerators
        result.denominator = (temp1.denominator * temp2.denominator);
        result.whole = 0;
    }
    else if (temp1.denominator == temp2.denominator)
    {
        result.numerator = temp1.numerator + temp2.numerator;               //add the numerators
        result.denominator = temp1.denominator;
        result.whole = 0;
    }
    else if (n1.numerator == 0 || n2.numerator == 0)                        //case for 0
    {
        result.whole = n1.whole + n2.whole;
        if (n1.numerator > 0  && n2.numerator == 0 )
        {
            result.numerator = n1.numerator;
            result.denominator = n1.denominator;
        }
        else if (n2.numerator > 0  && n1.numerator == 0)
        {
            result.numerator = n2.numerator;
            result.denominator = n2.denominator;
        }
        else if (n1.numerator == 0 && n2.numerator == 0)
        {
            result.numerator = 0;
            result.denominator = 0;
        }
    }

     result.Simplify();
     return result;

    
}
//function to subtract a mixed variable from another
Mixed operator-(const Mixed& n1, const Mixed& n2)
    {
        Mixed temp1, temp2, result;

        temp1.whole = n1.whole;
        temp1.numerator = temp2.denominator * temp1.numerator;
        temp1.denominator = temp1.denominator * temp2.denominator;                              //assigning temp vals

        temp2.whole = n2.whole;
        temp2.numerator = temp1.denominator * temp2.numerator;
        temp2.denominator = temp1.denominator * temp2.denominator;

        result.whole = n1.whole - n2.whole;
        
        if (temp1.numerator - temp2.numerator < 0)
        {
            result.whole -= ((temp1.numerator + temp2.numerator)/temp1.denominator);                //subtract whole
            result.numerator = ((temp1.numerator + temp2.numerator)%temp1.denominator);             //subtract fraction
        }
        else 
        {
            result.numerator = temp1.numerator - temp2.numerator;
        }

        result.denominator = temp1.denominator;

        result.Simplify();
        return result;
    }
    //helper increment func
    void increment(Mixed& a)
    {
        a = a + 1;                          //adds one to Mixed variable
    }

    Mixed operator++(Mixed& n1) //pre
    {
        increment(n1);
        return n1;                                      //returns incremented Mixed variable
    }

    Mixed operator++(Mixed& n1, int) //post
    {
        Mixed copy = n1;
        increment(n1);
        return copy;                                    //returns original val of Mixed variable but also increments
    }
    void decrement(Mixed& a)
    {
        a = a - 1;
    }
    Mixed operator--(Mixed& n1) //pre
    {
        decrement(n1);
        return n1;                                                          //returns decremented Mixed variable
    }

    Mixed operator--(Mixed& n1, int) //post
    {
        Mixed copy = n1;
        decrement(n1);
        return copy;                                                    //returns original val of Mixed variable but also decrements
    }
    //operator function to do fraction multiplication
    Mixed operator*(const Mixed& n1, const Mixed& n2)
    {
        Mixed c1,c2,result;
        c1 = n1;
        c2 = n2;                                                        //temps because params are const ref

        c1.ToFraction();                                                    //make them improper fractions
        c2.ToFraction();

        result.denominator = c1.denominator * c2.denominator;               //fraction multiplication
        result.numerator = c1.numerator * c2.numerator;
        result.whole = 0;

        result.Simplify();                                                  
        
        return result;
    }

    Mixed operator/(const Mixed& n1, const Mixed& n2)
    {
        Mixed c1,c2,result;
        c1 = n1;
        c2 = n2;                                                    //temps because params are const ref

        c1.ToFraction();
        c2.ToFraction();                                            //make them improper fractions

        result.denominator = c1.denominator * c2.numerator;
        result.numerator = c2.denominator * c1.numerator;           //fraction division
        result.whole = 0;

        if(n2 == 0)
        {
            result = 0;                                             //divide by 0 special case
        }

        result.Simplify();
        
        return result;

    };

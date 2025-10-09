/*Sienna Veidis
COP 3330 Section 5
HW 3
Header file for the class Mixed creates the type of a mixed number, creates operator overloaded funcs, and other useful functions
such as turning it into a decimal number, simplifying it, and turning it into an improper fraction*/
#include <iostream>		// for ostream, istream
using namespace std;
class Mixed
{
    //arithmetic func overloading
    friend Mixed operator+(const Mixed& n1, const Mixed& n2);
    friend Mixed operator-(const Mixed& n1, const Mixed& n2);
    friend Mixed operator/(const Mixed& n1, const Mixed& n2);
    friend Mixed operator*(const Mixed& n1, const Mixed& n2);

    //operator overloading funcs
    friend bool operator>(const Mixed& n1, const Mixed& n2);
    friend bool operator<(const Mixed& n1, const Mixed& n2);
    //helper funcs
    friend void increment(Mixed& a);
    friend void decrement(Mixed& a);
    //operator overloading funcs
    friend Mixed operator++(Mixed& n1);
    friend Mixed operator++(Mixed& n1, int);
    friend Mixed operator--(Mixed& n1);
    friend Mixed operator--(Mixed& n1, int);


    friend bool operator==(const Mixed& n1, const Mixed& n2);
    friend bool operator!=(const Mixed& n1, const Mixed& n2);
    friend bool operator<=(const Mixed& n1, const Mixed& n2);
    friend bool operator>=(const Mixed& n1, const Mixed& n2);


    //iostream overloading funcs
    friend istream& operator>>(istream& s, Mixed& f);
    friend ostream& operator<<(ostream& s, const Mixed& f);

    public:

    //constructors
    Mixed(int integer = 0);
    Mixed(int integer, int num, int denom);
    //helper func
    bool isValid(int integer, int num, int denom) const;
    
    //decimal func
    double Evaluate() const;
    //improper frac func
    void ToFraction();
    //simplifying func
    void Simplify();
    
    private:
    //member data
    int whole;
    int numerator;
    int denominator;

};
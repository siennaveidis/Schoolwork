cyclic strings: 
About this project: takes in a string, checks if it is a palindrome, if it isnt will rotate by one letter until it is a palidrome, if it isnt then it is not returned, 
all palindromes are returned at the end
Assumptions: each string will only contain lower and uppercase letters, numerals, and spaces. maximum of 500 strings and 500 characters per string

The fucntion checkpalin logic: has a counter, iterates through the string and if there is a space increment i or j to skip over it and compare the next index,
if they are ever not equal the counter is set to 1 and never reset to 0 if a different index is equal. if the counter is greater than zero it is not a palindrome.
if it is not, the string shifts one character, if it still is not a palindrome it shifts and checks one less times than it would take for the string to go back to normal.
the comparisons look at the uppercase version of the char of each index using toupper to make it case insensitive*/

arrays:
About this project: (this project displays a menu and based on the users choice, calls a function that either prints the array, 
sorts the array in descending order, inserts a number after every instance of a value in the array and every time the number
is inserted it increments, removes all values between two values in the array inclusive, and circularly moves all odd indecies to the next odd
index to the left as many times as the user enters while simultaneously circularly moving all even indecies to the next even
index to the right as many times as the user enters)
Assumptions: The insertion values and the fourth parameter of the insert function will never be the same number. the array size will never drop
below 1 and will never rise above 99. the moveElements function will only be called when the array has at least 3 elements. move elements entered value will not be negative

functions logic:
readArray LOGIC: you cannot just cin an entire array. you have to do it one index at a time. 
this function uses a loop to iterate through every index of the array and reads it in

printArray LOGIC: similarly to how you cannot cin an entire array in one go, you also cannot cout an entire array. 
if you do cout<< arrayName it will give you the starting address. this function uses a loop to iterate through every index of the array and prints it

linearSearch LOGIC: the position of key is what we want to find and is also the return value. it is initialized to -1 because there can never be an array index of -1.
if the position stays at -1 that means no value has been found. the loop begins at the starting index the user enters, 
and goes through the entire array while the position has not been found, this is because of the && pos == -1, if it weren't for that
this function would return the last occurance of the key value, when it really needs to return the first value then exit the loop. 
the function checks if the value is in the array by the == operater and iterates through every index individually

insertValues LOGIC: First is error checking, using linear search to see if the third parameter is in the array. if the value is there it will proceed with the function. 
since size increments every time a value is added, if size the other size variable value in main are not equal, the value must have been inserted. the loop works by
first increasing the current size of the array making room for the new value then shifts all neccessary indecies right 
so that the value can be inserted into current index. after the for loop runs, current index is reassigned 
using the function linearSearch amd num is incremented

removeValues LOGIC: I decided to use boolean values to determine whether the fucntion should continue as intended or not.
The first two checks are initialized to false and they use the linearSearch function to see ONLY if both values are simply in the array,
the next check is initialized to true (but can also work by initializing to false then proving it to be true) and it compare the returned
indecies of the two values from the linearSearch function, if the expected "starting" value is larger than the expected "end" value the check is
set to be false, if all checks are true the function proceeds. The outer loop runs the amount of indecies there are from the start to end value,
the inner loop goes through all of those values and shifts them left, reassigning the starting value to the next value and repeating this as many
times as it needs to "remove" all the neccessary values, if all checks are false it prints out a message, it returns new size which is initialized to the 
original size incase the size does not change, if the function does run as user intended, newSize = the original size - the amount of indecies removed


sort LOGIC: the sort algorithm iterates through the array and creates a temp value that constantly gets reassigned to the 
current index value and the index and the current index switch if the proceeding index is larger than the current 

moveElements LOGIC: This function moves each odd index left by iterating through the array and reassigning indexes by doing arr[i]= arr[i+2]. 
It does this ONE at a time, until the for loop hits the user entered number, the roll over value is initially set to arr[1] because 
the last odd index in the array will always be arr[1], and every time the loop runs the rollOver value reassigns to the new arr[1] val.
depending on whether or not size is even or odd, the rollover value is changed from array size-2 to size-1 for even, and the index that 
gets assigned the rollover value changes from size-1 to size-2 for odd(order of changes is ignored in this explanation, simply the two options are listed)

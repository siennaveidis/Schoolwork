About this project: takes in a string, checks if it is a palindrome, if it isnt will rotate by one letter until it is a palidrome, if it isnt then it is not returned, 
all palindromes are returned at the end
Assumptions: each string will only contain lower and uppercase letters, numerals, and spaces. maximum of 500 strings and 500 characters per string

The fucntion checkpalin logic: has a counter, iterates through the string and if there is a space increment i or j to skip over it and compare the next index,
if they are ever not equal the counter is set to 1 and never reset to 0 if a different index is equal. if the counter is greater than zero it is not a palindrome.
if it is not, the string shifts one character, if it still is not a palindrome it shifts and checks one less times than it would take for the string to go back to normal.
the comparisons look at the uppercase version of the char of each index using toupper to make it case insensitive*/

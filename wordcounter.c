/*
 * Synopsis  - Takes input from a file and determines how
 *             many lines and words there are in the file.
 * A word does not include '-',':', and any space '\n','\t', and ' '            
 */

/* Include Files */
#include <stdio.h>
#include <ctype.h> //Cytpe.c is used for isspace to check for whitespace
#define TRUE 1     //For readablility I added in the define Headers
#define FALSE 0
int main(void) {

    int io_line = 0;
    int io_word = 0;    
    int io_empty = 0;
    int curr;
    int word = FALSE; //word changes from a F to a T if it meets
                 // the conditions to be in a word, like a boolean would
   
// Found in the notes CByDiscovery Ch2 inout2.c by Foster
    while ( ( curr = getchar() ) != EOF){ //waits till end of file
        
        io_empty++; //To check if the file is blank.

/* I found isspace definition found on
* "http://www.tutorialspoint.com/c_standard__
* library/c_function_isspace.htm"
*/
      if(!isspace(curr) && word == FALSE && curr != '-' && curr != ':'){
                word = TRUE;
                io_word++;
}
      if(isspace(curr) && word == TRUE || curr == '-' || curr == ':')
                 word = FALSE;

/* the first if statement checks to see if the current character is not 
*  whitespace and then it checks if it is in a word (by default it is
*  by default set to 0/false), it also checks to see if the curr
*  is not - or a :. This step increments the word counter, because
*  at this point you know that the curr is not in a blank space and
*  into a word. 
*  the second if statement will tell us when we are out of a word and 
*  change it word back into false(0)  
*/
  
        if(curr == '\n') //checks for new lines and increments
                io_line++;
}
 printf("%8d %7d\n",io_line,io_word); //output is right justified 
        if(io_empty == 0)             //and in column 8 field and 16
                return 1; 
        return 0;
        
} 
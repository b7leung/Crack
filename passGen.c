#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crackConstants.h"

/*
 * Method Name: passGen
 * Description: Given the last password attemt, this method will
 * return the next password attempted generated by incrementing
 * the 0th char of password's password element. 
 * Parameter(s): 
 *   > struct passwordInfo password -- last password
 * Side Effect(s): None.
 * Return: The generated password.
 */

char * passGen( char * password ){
  
  //char * passwordGuess = password.password;
  // if the first letter is not z, keep on incrementing
  if( password[0] != END_CHAR ){

    password[0]++;

  }else{

    // String becomes larger by 1 and 'a'-filled if string was filled with 'z's. 
    if(full(password)){
      int newPassLength = strlen(password) + 1; 
      char * tmp = realloc( password, newPassLength + sizeof(char) );
      if(tmp!=NULL){
        password = tmp;
      }
      int i;
      for( i = 0; i < newPassLength; i++ ){
        password[i] = START_CHAR;
      }
      password[newPassLength] = '\0';

    }else{
    // If string not filled with 'z's, increment the biggest possible non-z char
    // and reset the previous chars to 'a's
      
      int biggestCharIndex = 1;
      while( password[biggestCharIndex] == END_CHAR ){
        biggestCharIndex++;
      }
      password[biggestCharIndex]++;
      int i;
      for( i = 0; i < biggestCharIndex; i++){
        password[i] = START_CHAR;
      }

    }
  }  

  return password;
}




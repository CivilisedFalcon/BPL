#ifndef LEXAR_H /*if not defined*/
#define LEXER_H
#include "token.h"

/*Using Struct to store the current state of the Lexer*/
typedef struct LEXER_STRUCT
{
    char c; /*Current cahracter we are on*/
    unsigned int i; /*index*/
    char* contents; /*it is the Source Code*/

} lexer_T;

/*Methods in Lexer*/

/*Init Lexer function: it creates our Lexer*/
//it is going to take in some contents from a file (or wherever >.< )
lexer_T* init_lexer(char* contents);

/*Lexer Advance Function: is is going to move out pointer to the next character*/
//We will pass the lexer state into this
void lexer_advance(lexer_T* lexer);

/*Lexer Skip Whitespace: */
// it is going to skip Whitespace that we do neo care about.
//We will pass in the lexer state
void lexer_skip_whitespace(lexer_T* lexer);

/*We will call this function to get to the next token in the contents*/
//Most of our logic will be in this function. 
//We will pass in the lexer state
token_T* lexer_get_next_token(lexer_T* lexer);

/*this function is going to define how to parse the string "Civilised Falcon"*/
//We will pass in the lexer state
token_T* lexer_collect_string(lexer_T* lexer);

/*This function will be used as an identifier for something, like var, print, name*/
//We will pass in the lexer state
token_T* lexer_collect_id(lexer_T* lexer);

/*Helper method to make the code a bit cleaner*/
//We will pass in the lexer state
//we will also pass the token
token_T* lexer_advance_with_token(lexer_T* lexer, token_T* token);

/*This is going to return the char value in char c; as a string (line8) */
//We will pass in the lexer state
char* lexer_get_current_char_as_string(lexer_T* lexer);

#endif 

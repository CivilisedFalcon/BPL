#ifndef TOKEN_H /*if not defined*/
#define TOKEN_H

/*please refer to main.bpl to understand the comments*/
typedef struct TOKEN_STRUCT
{
    enum 
    {
        TOKEN_ID, /*it is an identifier for something, like var, print, name*/
        TOKEN_EQUALS, /* For = */
        TOKEN_STRING, /*Anything between "", like "Civilised Falcon"*/
        TOKEN_SEMI, /*For the semicolon*/
        TOKEN_LPAREN, /*Left Parentheses*/
        TOKEN_RPAREN /*Right Parentheses*/ 

    } type; /*Different types of token*/

    char* value;

} token_T;

/*Defining the Init so that we can create our token*/
// it will have two paremeters.
// 1. int type
// 2. char* value
token_T* init_token(int type, char* value);
#endif
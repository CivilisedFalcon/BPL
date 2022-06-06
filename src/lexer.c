#include "include/lexer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*Init Lexer function: it creates our Lexer*/
//it is going to take in some contents from a file (or wherever >.< )
lexer_T* init_lexer(char* contents)
{
    /*Allocate memory for the struct*/
    lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->contents = contents;
    lexer->i = 0; //because we are going to start at first character
    lexer->c = contents[lexer->i]; //current character 

    return lexer;
}

/*Lexer Advance Function: is is going to move out pointer to the next character*/
//We will pass the lexer state into this
void lexer_advance(lexer_T* lexer)
{
    if (lexer->c != '\0' && lexer->i < strlen(lexer->contents))
    {
        /*Increnenting the characters and going to the next character*/
        lexer->i += 1;
        lexer->c = lexer->contents[lexer->i]; //current character

    }
}

/*Lexer Skip Whitespace: */
// it is going to skip Whitespace that we do neo care about.
//We will pass in the lexer state
void lexer_skip_whitespace(lexer_T* lexer)
{
    while(lexer->c == ' ' || lexer->c == 10) // a newline character is denoted by 10
    {
        lexer_advance(lexer); 
    }
}

/*We will call this function to get to the next token in the contents*/
//Most of our logic will be in this function. 
//We will pass in the lexer state
token_T* lexer_get_next_token(lexer_T* lexer)
{
    /*if we still have characters to parse, we will continue*/
    while (lexer->c != '\0' && lexer->i < strlen(lexer->contents))
    {
        if (lexer->c == ' ' || lexer->c == 10)
        {
            lexer_skip_whitespace(lexer);
        }

        if (lexer->c == '"')
        {
            return lexer_collect_string(lexer); // because we will skip the " that we are encountering
        }

        if(isalnum(lexer->c))
        {
            return lexer_collect_id(lexer);
        }

        switch(lexer->c)
        {
            case '=': return lexer_advance_with_token(lexer, init_token(TOKEN_EQUALS, lexer_get_current_char_as_string(lexer)));
                break;
            case ';': return lexer_advance_with_token(lexer, init_token(TOKEN_SEMI, lexer_get_current_char_as_string(lexer)));
                break;
            case '(': return lexer_advance_with_token(lexer, init_token(TOKEN_LPAREN, lexer_get_current_char_as_string(lexer)));
                break;
            case ')': return lexer_advance_with_token(lexer, init_token(TOKEN_RPAREN, lexer_get_current_char_as_string(lexer)));
                break;
        }
    }


}

/*this function is going to define how to parse the string "Civilised Falcon"*/
//We will pass in the lexer state
token_T* lexer_collect_string(lexer_T* lexer)
{
    lexer_advance(lexer); // because we will skip the " that we are encountering, i.e. the opening "

    /*Allocating Memory for our string*/
    char* value = calloc(1, sizeof(char));
    value[0] = '\0';



    while(lexer->c !='"')
    {
        //we will keep appending characters to the variable value until it reaches "
        char* s = lexer_get_current_char_as_string(lexer);

        //reallocarting the variable value so that we can fit the string thet we are creating in the above statement
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));

        strcat(value, s); //appending the current character ('s') to value

    }

    lexer_advance(lexer); // because we will skip the " that we are encountering, i.e. the closing "

    return init_token(TOKEN_STRING, value);

}

/*This function will be used as an identifier for something, like var, print, name*/
//We will pass in the lexer state
token_T* lexer_collect_id(lexer_T* lexer)
{
    lexer_advance(lexer); // because we will skip the " that we are encountering, i.e. the opening "

    /*Allocating Memory for our string*/
    char* value = calloc(1, sizeof(char));
    value[0] = '\0';



    while(isalnum(lexer->c))
    {
        //we will keep appending characters to the variable value until it reaches "
        char* s = lexer_get_current_char_as_string(lexer);

        //reallocarting the variable value so that we can fit the string thet we are creating in the above statement
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));

        strcat(value, s); //appending the current character ('s') to value

    }

    lexer_advance(lexer); // because we will skip the " that we are encountering, i.e. the closing "

    return init_token(TOKEN_ID, value);
}


/*Helper method to make the code a bit cleaner*/
//We will pass in the lexer state
//we will also pass the token
token_T* lexer_advance_with_token(lexer_T* lexer, token_T* token)
{
    lexer_advance(lexer);

    return token;
}

/*This is going to return the char value in char c; as a string (line8) */
//We will pass in the lexer state
char* lexer_get_current_char_as_string(lexer_T* lexer)
{
    char* str =  calloc(2, sizeof(char));
    str[0] = lexer->c;
    str[1] = '\0';

    return str;
}
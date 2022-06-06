#include <stdio.h>
#include "include/lexer.h"

int main(int argc, char* argv[])
{
    lexer_T* lexer = init_lexer(
        "var name = \"Civilised Falcon\";"
        "print(name);"
    );

    /*iterate through all the tokens*/
    token_T* token = (void*)0;

    while 
    return 0;
}
#include <stdio.h>
#include <stdlib.h>


typedef enum {
    SEMI,
    OPEN_PAREN,
    CLOSE_PAREN,
} TypeSeparator;

typedef enum {
    EXIT,
} TypeKeyword;

typedef enum {
    INT,
} TypeLiteral;


typedef struct {
    TypeSeparator type;
} TokenSeparator;

typedef struct {
    TypeKeyword type;
} TokenKeyword;

typedef struct {
    TypeLiteral type;
    int value;
} TokenLiteral;

void lexer(FILE *file){
    char current_char = fgetc(file);

    while(current_char != EOF){
        if(current_char == ';'){
            printf("Found semicolon\n");
        } else if( current_char == '('){
            printf("Found open paren");
        } else if (current_char == ')'){
            printf("Found close paren");
        }
        current_char = fgetc(file);
    }
}

int main(){
    FILE *file;
    file = fopen("test.cap","r");
    
    lexer(file);
    return 0;
}
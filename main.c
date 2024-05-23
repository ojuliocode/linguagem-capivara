#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
    char current = fgetc(file);

    while(current != EOF){
        if(current == ';'){
            printf("Found semicolon\n");
        } else if( current == '('){
            printf("Found open paren\n");
        } else if (current == ')'){
            printf("Found close paren\n");
        } else if (isdigit(current)){
            printf("Found digit: ");
            printf("%d\n", current - '0');
        } else if (isalpha(current)){
            printf("Found char: %c\n", current);
        } else if(current == '\n'){
            printf("Found new line\n");
        }
        current = fgetc(file);
    }
}

int main(){
    FILE *file;
    file = fopen("test.cap","r");
    
    lexer(file);
    return 0;
}
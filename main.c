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

void generateNumber(char current, FILE *file){
    while( isdigit(current) && current != EOF){
        if(!isdigit(current)){
            return;
        }
        printf("%c", current);
        current = fgetc(file);
    }
}

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
            generateNumber(current, file);
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
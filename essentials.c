#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "essentials.h"

char* make_lower(char* s){
    int h;
    char word_lower[strlen(s)+1];
    for(h=0; h<strlen(s); h++){
        s[h] = tolower(s[h]);
    }
    return s;
}

void red () {
  printf("\033[1;31m");
}

void yellow(){
    printf("\033[0;33m");
}

void purple(){
    printf("\033[0;35m");
}

void reset () {
  printf("\033[0m");
}

void printRedinside(char* s, char* till, int len){
    int i=0;
    for(i=0; i<strlen(s); i++){
        if(s + i == till) break;
        else{
            printf("%c", s[i]);
        }
    }
    red();
    for(; i<strlen(s); i++){
        if(s + i == till+len) break;
        else printf("%c", s[i]);
    }
    reset();
    printf("%s", s+i);
}

void printRedonly(char* s, char* till, int len){
    int i=0;
    red();
    
    for(i=0; i<strlen(s); i++){
        if(s + i < till) continue;
        else{
            if(s + i == till+len) break;
            printf("%c", s[i]);
        }
    }
    reset();

    return;
}

void printinRed(char* s, int l){
    red();
    int i;
    for(i=0; i<strlen(s); i++){
        if(i == l) break;
        else printf("%c", s[i]);
    }
    reset();
    printf("%s", s+i);
}

void printinYellow(int n){
    yellow();
    printf("%d", n);
    reset();
}

void printinPurple(char* s){
    purple();
    printf("%s", s);
    reset();
}
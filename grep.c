#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "essentials.h"
#include "queue.h"
#include <dirent.h>
#include "grep.h"

char* list_of_files[50];
int idx_of_files = 0;
int num_of_files;
char name_here[20] = {'\0'};

void flag_c(char* here, char* search, FILE* fp, char* fname){
    int cnt = 0;
    while(fgets(here, 400, fp) > 0){
        if(strstr(here, search)){
        cnt++;
        }
    }

    if(num_of_files > 1){
    printinPurple(fname);
    printf(":");
    }
    printf("%d\n", cnt);

    return;
}

void flag_h(char* here, char* search, FILE* fp){
    char* chr_here;
    char word[100];
        
        while(fgets(here, 400, fp) > 0){
            here[strlen(here)+1] = '\0';
            chr_here = strstr(here, search);

            if(chr_here != NULL){
               word[0] = '\0';
               char* ptr;

                for(int i=0; i<strlen(here); i++){
                    int done = 0;
                  
                    while(isalnum(here[i]) || (here[i] > 32 && here[i] <= 47) || (here[i] >= 58 && here[i] <= 64) || (here[i] >= 91 && here[i] <= 96)){
                        strncat(word, &here[i], 1);
                        i++;
                    }

                    if((ptr = strstr(word, search))){
                        printRedinside(word, ptr, strlen(search));
                        printf(" ");
                        done = 1;
                    }

                    if(!done){
                        printf("%s ", word);
                    }

                    word[0] = '\0';
                }

                printf("\n");
            }
        }
    return;
}

void flag_i(char* here, char* search, FILE* fp, char* fname){
    char word[100];
    char word_lower[100];        
    char tmp[strlen(search)+1];
    char word_converted[strlen(search)+1];
    bool done = 0;
    bool found = 0;

        strcpy(tmp, search);
        strcpy(word_converted, make_lower(tmp));
        word_converted[strlen(search)+1] = '\0';

        while(fgets(here, 400, fp) > 0){
        found = 0;
        here[strlen(here)+1] = '\0';
        word[0] = '\0';

            for(int i=0; i<strlen(here); i++){
                done = 0;

                while(isalnum(here[i]) || (here[i] > 32 && here[i] <= 47) || (here[i] >= 58 && here[i] <= 64) || (here[i] >= 91 && here[i] <= 96)){
                    strncat(word, &here[i], 1);
                    i++;
                }

                strcpy(tmp, word);
                strcpy(word_lower, make_lower(tmp));

                if( strstr(word_lower, word_converted) ){
                    found = 1;
                }

                word[0] = '\0';
            }
            
        if(found){
            if(num_of_files > 1){
            printinPurple(fname);
            printf(":");
            }

            for(int i=0; i<strlen(here); i++){
                done = 0;
                while(isalnum(here[i]) || (here[i] > 32 && here[i] <= 47) || (here[i] >= 58 && here[i] <= 64) || (here[i] >= 91 && here[i] <= 96)){
                    strncat(word, &here[i], 1);
                    i++;
                }

                strcpy(tmp, word);
                strcpy(word_lower, make_lower(tmp));

                if( strstr(word_lower, word_converted) ){
                    int idx = 0;
                    bool got_it = 1;

                    for(int k=0; k<=strlen(word); k++){
                        idx = 0;
                        got_it = 1;

                        for(int j=k; j<=strlen(word); j++){
                            if(tolower(word[j]) != tolower(search[idx++])){
                                got_it = 0;
                                break;
                            }
                            if(idx+1 == strlen(search)) break;
                        }

                        if(got_it){
                            int l;
                            for(l=0; l<k; l++){
                                printf("%c", word[l]);
                            }
                            l += strlen(search);
                            printinRed(word+k, strlen(search));
                            l += strlen(search);
                            
                            for(; l<strlen(word); l++)
                                printf("%c", word[l]);
                            done = 1;
                            break;    
                        }
                    }

                    printf(" ");
                }
                if(!done){
                    printf("%s ", word);
                }
                word[0] = '\0';
            }
            
            printf("\n");
        }
        }
    return;    
}

void flag_l(char* here, char* search, FILE* fp, char* fname){

    while(fgets(here, 400, fp) > 0){
        if(strstr(here, search)){
            list_of_files[idx_of_files++] = fname;
            break;
        }
    }
    return;
}

void flag_L(char* here, char* search, FILE* fp, char* fname){
    bool never = 1;

    while(fgets(here, 400, fp) > 0){
        if(strstr(here, search)){
            never = 0;
            break;
        }
    }

    if(never)
    list_of_files[idx_of_files++] = fname;

    return;
}

void flag_n(char* here, char* search, FILE* fp, int line_number, char* fname){
    char* chr_here;
    char word[100];
        
        while(fgets(here, 400, fp) > 0){
        here[strlen(here)+1] = '\0';
        chr_here = strstr(here, search);

            if(chr_here != NULL){

            if(num_of_files > 1){    
            printinPurple(fname);
            printf(":");
            }
            printinYellow(line_number);
            printf(":");
               word[0] = '\0';
               char* ptr;

                for(int i=0; i<strlen(here); i++){
                    int done = 0;
                    char* j = here+i;

                    while(isalnum(here[i]) || (here[i] > 32 && here[i] <= 47) || (here[i] >= 58 && here[i] <= 64) || (here[i] >= 91 && here[i] <= 96)){
                        strncat(word, &here[i], 1);
                        i++;
                    }

                    if((ptr = strstr(word, search))){
                        printRedinside(word, ptr, strlen(search));
                        printf(" ");
                        done = 1;
                    }

                    if(!done){
                        printf("%s ", word);
                    }

                    word[0] = '\0';
                }
                printf("\n");
            }
            line_number++;
        }

    return;    
}

void flag_w(char* here, char* search, FILE* fp, char* fname){
    char* chr_here;
    char word[100];
    bool present = 0;

        while(fgets(here, 400, fp) > 0){
            here[strlen(here)+1] = '\0';
            chr_here = strstr(here, search);

            if(chr_here != NULL){
               word[0] = '\0';
               present = 0;

                for(int i=0; i<strlen(here); i++){
                    while(isalnum(here[i]) || (here[i] > 32 && here[i] <= 47) || (here[i] >= 58 && here[i] <= 64) || (here[i] >= 91 && here[i] <= 96)){
                        strncat(word, &here[i], 1);
                        i++;
                    }
                    if(strcmp(word, search) == 0){
                        present = 1;
                    }
                    word[0] = '\0';
                }

            if(present){
                if(num_of_files > 1){
                printinPurple(fname);
                printf(":");
                }

                for(int i=0; i<strlen(here); i++){
                    int done = 0;

                    while(isalnum(here[i]) || (here[i] > 32 && here[i] <= 47) || (here[i] >= 58 && here[i] <= 64) || (here[i] >= 91 && here[i] <= 96)){
                        strncat(word, &here[i], 1);
                        i++;
                    }

                    if(strcmp(word, search) == 0){
                        printinRed(word, strlen(word));
                        printf(" ");
                        done = 1;
                    }
                    
                    if(!done ){
                        printf("%s ", word);
                    }

                    word[0] = '\0';
                }

                printf("\n");
                }
            }
        }
    return;
}

void flag_v(char* here, char* search, FILE* fp, char* fname){

    while(fgets(here, 400, fp) > 0){
            here[strlen(here)+1] = '\0';

            if((strstr(here, search) == NULL)){
                if(num_of_files > 1){
                printinPurple(fname);
                printf(":");
                }
                printf("%s", here);
            }
        }

    return;
}

void flag_o(char* here, char* search, FILE* fp, char* fname){
    char* chr_here;
    char word[100];

        while(fgets(here, 400, fp) > 0){
            here[strlen(here)+1] = '\0';
            chr_here = strstr(here, search);

            if(chr_here != NULL){
               word[0] = '\0';
               char* ptr;

                

                for(int i=0; i<strlen(here); i++){
                    int done = 0;

                    while(isalnum(here[i]) || (here[i] > 32 && here[i] <= 47) || (here[i] >= 58 && here[i] <= 64) || (here[i] >= 91 && here[i] <= 96)){
                        strncat(word, &here[i], 1);
                        i++;
                    }

                    if((ptr = strstr(word, search))){
                        if(num_of_files > 1){
                        printinPurple(fname);
                        printf(":");
                        }
                        printRedonly(word, ptr, strlen(search));
                        printf("\n");
                        done = 1;
                    }
                    
                    word[0] = '\0';
                }
            }
        }
    return;    
}

void flag_H(char* here, char* search, FILE* fp, char* fname){
    char* chr_here;
    char word[100];

        while(fgets(here, 400, fp) > 0){
            here[strlen(here)+1] = '\0';
            chr_here = strstr(here, search);

            if(chr_here != NULL){
               word[0] = '\0';
               char* ptr;

                printinPurple(fname);
                printf(":");

                for(int i=0; i<strlen(here); i++){
                    int done = 0;

                    while(isalnum(here[i]) || (here[i] > 32 && here[i] <= 47) || (here[i] >= 58 && here[i] <= 64) || (here[i] >= 91 && here[i] <= 96)){
                        strncat(word, &here[i], 1);
                        i++;
                    }

                    if((ptr = strstr(word, search))){
                        printRedinside(word, ptr, strlen(search));
                        printf(" ");
                        done = 1;
                    }
                    
                    if(!done){
                        printf("%s ", word);
                    }

                    word[0] = '\0';
                }

                printf("\n");
            }
        }
    return;    
}

void flag_0(char* here, char* search, FILE* fp, char* fname){
    char* chr_here;
    char word[100];

        while(fgets(here, 400, fp) > 0){
            here[strlen(here)+1] = '\0';
            chr_here = strstr(here, search);

            if(chr_here != NULL){
               word[0] = '\0';
               char* ptr;

                if(num_of_files > 1){
                printinPurple(fname);
                printf(":");
                }

                for(int i=0; i<strlen(here); i++){
                    int done = 0;

                    while(isalnum(here[i]) || (here[i] > 32 && here[i] <= 47) || (here[i] >= 58 && here[i] <= 64) || (here[i] >= 91 && here[i] <= 96)){
                        strncat(word, &here[i], 1);
                        i++;
                    }

                    if((ptr = strstr(word, search))){
                        printRedinside(word, ptr, strlen(search));
                        printf(" ");
                        done = 1;
                    }
                    
                    if(!done){
                        printf("%s ", word);
                    }

                    word[0] = '\0';
                }

                printf("\n");
            }
        }
    return;    
}


void search_in_file(char* search, queue files, char flag, int n){
    int line_number = 1;
    char* here = (char*)malloc(sizeof(char)*400);

    num_of_files = n;

    while(!isEmpty(files)){

    char* fname;
    fname = top(files);

    FILE* fp;
    fp = fopen(fname, "r");

    if(fp == NULL){
        if(num_of_files > 1 && flag == 'r'){
            pop(&files);
            continue;
        }
        printf("%s file not found\n", fname);
        return;
    }

    switch (flag){

    case 'c':       // count of the lines that match a pattern
        flag_c(here, search, fp, fname);
        break;

    case 'h':       // Display the matched lines, but do not display the filenames.
        flag_h(here,  search,  fp);
        break;

    case 'i':       // Ignores, case for matching
        flag_i(here, search, fp, fname);
        break;

    case 'l':       // Displays list of filenames only
        flag_l(here, search,fp,  fname);
        break;

    case 'n':       // Display the matched lines and their line numbers.
        flag_n(here, search, fp, line_number, fname);
        break;

    case 'r':       // Read all files under each directory
        flag_n(here, search, fp, line_number, fname);
        break;

    case 'w':       // Match whole word
        flag_w(here, search, fp, fname);
        break;

    case 'v':       // This prints out all the lines that do not matche the pattern
        flag_v(here, search, fp, fname);
        break;

    case 'L':       // Displays list of a filenames that do not contain the pattern
        flag_L(here, search,fp,  fname);
        break;

    // Print only the matched parts of a matching line, with each such part on a separate output line
    case 'o':       
        flag_o(here, search, fp, fname);
        break;

    case 'H':       // print file name with output lines
        flag_H(here, search, fp, fname);
        break;

    case '0':       // No flag
        flag_0(here, search, fp, fname);
        break;
    
    }
    fclose(fp);
    pop(&files);
    }

    list_of_files[idx_of_files] = NULL;
    if(flag == 'l' || flag == 'L'){
        for(int i=0; i<100; i++){
            if(!list_of_files[i]) return;

            printinPurple(list_of_files[i]);
            printf("\n");
        }
    }


    return;
}

// add files in a queue when flag is r
void addfiles(char* dirname, queue* files){

    DIR* dirp;    
    dirp = opendir(dirname);

    if(dirp == NULL){
        fputs("DIR not found\n", stdout);
        return ;
    }
    
    struct dirent* entity;
    entity = readdir(dirp);

    while(entity){
        
        if(entity->d_type == DT_DIR && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0){

            strcpy(name_here, dirname);
            strcat(name_here, entity->d_name);
            strcat(name_here, "/");

            addfiles(name_here, files);  // recursive call 
            name_here[0] = '\0';    // make the string empty while returning back
        }

        char tmp[50] = {0};

        if(name_here[0] != '\0'){
        strcat(tmp, name_here);
        }

        strcat(tmp, entity->d_name);

        if(strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0){
        push(files, tmp);
        }

        tmp[0] = '\0';
        entity = readdir(dirp);
    }

    closedir(dirp);
    return;
}

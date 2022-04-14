#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"
#include "grep.h"


int main(int argc, char** argv){
    char flag;
    queue files;
    init_queue(&files);
    int j = argc;
  
    if(argv[1][1] == '-'){
        FILE* fp = fopen("help.txt", "r");
        
        char str[400];
        while(fgets(str, 400, fp))
            fputs(str, stdout);


        fclose(fp);    
        return 0;
    }


    if(argv[1][0] == '-'){

        flag = argv[1][1];
        j -= 3;
        int idx = 3;


        if(flag == 'r'){
            addfiles(argv[3], &files);
            search_in_file(argv[2], files, flag, 2);
        }

        else{

        while(j--){
            push(&files, argv[idx++]);
        }

        if(idx == 4)
        search_in_file(argv[2], files, flag, 1);
        else
        search_in_file(argv[2], files, flag, 2);
        }
    }


    else{ 

        flag = '0';
        j -= 2;
        int idx = 2;
        while(j--){
            push(&files, argv[idx++]);
        }

       if(idx == 3) 
        search_in_file(argv[1], files, flag, 1);
        else
        search_in_file(argv[1], files, flag, 2);

    }


    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"

void init_queue(queue* s){
    *s = NULL;
    return;
}

void push(queue* q, char* d){
    queue tmp = *q;
    char* temp = (char*)malloc(sizeof(char)*100);

    queue nq = (queue)malloc(sizeof(struct node));
    strcpy(temp, d);
    if(!nq || !temp){
        printf("\nQueue Overflow");
        return;
    }
    nq->val = temp;
    nq->next = NULL;

    if(!tmp){
        *q = nq;
        tmp = nq;
        return;
    }

    while(tmp->next){
        tmp = tmp->next;
    }

    tmp->next = nq;
    return;
}

char* top(queue s){
    if(s) return s->val;
    return NULL;
}

char* back(queue s){
    
    if(s){
        
    while(s->next)
        s = s->next;

    return s->val;    

    } 
    return NULL;
    
}

bool isEmpty(queue s){
    return (s == NULL);
}

void pop(queue* s){
    if(!isEmpty(*s)){
        queue tmp = *s;
        *s = (*s)->next;
        free(tmp);
        return;
    }
    return;
}
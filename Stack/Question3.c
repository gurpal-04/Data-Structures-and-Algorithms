#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int stack[101];
int top = -1;

void createStack(){
    top = -1;
}

void push(int n){
    stack[++top]=n;
}

int pop(){
    return stack[top--];
}

int peek(){
    return stack[top];
}

bool isEmpty(){
    return top==-1;
}


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    scanf("%d", &T);
    for(int t=0;t<T;t++){
        char c[101];
        scanf("%s", c);
        
        createStack();
        
        while(strcmp(c,"?")!=0){
            if(strcmp(c,"+")==0 || strcmp(c,"-")==0 || strcmp(c,"*")==0 || strcmp(c,"/")==0){
                
                int n = pop();
                int m = pop();
                
                if(strcmp(c,"+")==0){
                    push(m+n);
                }
                else if(strcmp(c,"-")==0){
                    push(m-n);
                }
                else if(strcmp(c,"*")==0){
                    push(m*n);
                }
                else if(strcmp(c,"/")==0){
                    push(m/n);
                }
            }
            else{
                push(atoi(c));
            }
            scanf("%s", c);
        }
        printf("%d\n", peek());
    }
    return 0;
}
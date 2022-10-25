#include <iostream>
#include <stdlib.h> 
using namespace std;
#define MAX 20
void InfixToPostfix(char* infix, char* postfix);
int Priority(char op);
int Eval(char* infix);
double cal(char op, double p1, double p2);
int main(int argc, char *argv[])
{
   char infix[MAX] = {'\0'}; 
   scanf("%s", infix);
   cout<<Eval(infix);
   return 0;
}
void InfixToPostfix(char* infix, char* postfix) { 
    char stack[MAX] = {'\0'};
    int i, j, top;
    for(i = 0, j = 0, top = 0; infix[i] != '\0'; i++) switch(infix[i]) { 
        case '(':  
            stack[++top] = infix[i]; 
            break; 
        case '+': case '-': case '*': case '/': 
            while(Priority(stack[top]) >= Priority(infix[i])) { 
                postfix[j++] = stack[top--];
            } 
            stack[++top] = infix[i]; 
            break; 
        case ')': 
            while(stack[top] != '(') { 
                postfix[j++] = stack[top--];
            } 
            top--;
            break; 
        default:
            postfix[j++] = infix[i];
    }
    while(top > 0) { 
        postfix[j++] = stack[top--];
    }
} 
int Priority(char op) { 
    switch(op) { 
        case '+': case '-':
        return 1;
        case '*': case '/':
        return 2;
        default:           
        return 0;
    } 
} 
int Eval(char* infix) {
    char postfix[MAX]= {'\0'};
    char opnd[2] = {'\0'};
    double stack[MAX] = {0.0}; 
    InfixToPostfix(infix, postfix);    
    int top, i;
    for(top = 0, i = 0; postfix[i] != '\0'; i++) switch(postfix[i]) { 
        case '+': case '-': case '*': case '/': 
            stack[top - 1] = cal(postfix[i], stack[top - 1], stack[top]); 
            top--; 
            break; 
        default: 
            opnd[0] = postfix[i];
            stack[++top] = atof(opnd);
    }             
    
    return stack[top];
}
double cal(char op, double p1, double p2) { 
    switch(op) { 
        case '+': return p1 + p2; 
        case '-': return p1 - p2; 
        case '*': return p1 * p2; 
        case '/': return p1 / p2; 
    } 
}

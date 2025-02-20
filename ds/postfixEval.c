#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

double stack[MAX];
int top = -1;

void push(double val) {
    if(top >= MAX - 1) {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = val;
}

double pop() {
    if(top < 0) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

int main() {
    char expr[256];
    printf("Enter postfix expression: ");
    if(!fgets(expr, sizeof(expr), stdin)) {
        fprintf(stderr, "Error reading input\n");
        return EXIT_FAILURE;
    }
    
    char *token = strtok(expr, " \n");
    while(token != NULL) {
        if(isdigit(token[0])) {
            push(atof(token));
        } else {
            double op2 = pop();
            double op1 = pop();
            switch(token[0]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': 
                    if(op2 == 0) {
                        fprintf(stderr, "Division by zero error\n");
                        exit(EXIT_FAILURE);
                    }
                    push(op1 / op2); 
                    break;
                default:
                    fprintf(stderr, "Unknown operator: %s\n", token);
                    exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " \n");
    }
    
    double result = pop();
    if(top != -1) {
        fprintf(stderr, "Error: The input expression is invalid.\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Result = %lf\n", result);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
    else {
        printf("Stack Overflow\n");
        exit(1);
    }
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    int i, j = 0;
    char c;
    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        if (isalnum(c))
            postfix[j++] = c;
        else if (c == '(')
            push(c);
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            if (top != -1 && stack[top] == '(')
                pop();
        }
        else if (isOperator(c)) {
            while (top != -1 && isOperator(stack[top]) && precedence(c) <= precedence(stack[top]))
                postfix[j++] = pop();
            push(c);
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n')
        infix[len - 1] = '\0';
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

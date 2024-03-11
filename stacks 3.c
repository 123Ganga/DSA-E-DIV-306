
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define size 30

struct stack {
    char data[size];
    int top;
};

typedef struct stack stack;

int isfull(stack s) {
    return s.top == size - 1;
}

int isempty(stack s) {
    return s.top == -1;
}

void push(stack *s, char val) {
    if (isfull(*s)) {
        printf("Stack is overflow\n");
        return;
    }
    s->top++;
    s->data[s->top] = val;
}

char pop(stack *s) {
    if (isempty(*s)) {
        printf("Stack is underflow\n");
        return '\0';
    }
    char temp = s->data[s->top];
    s->top--;
    return temp;
}

char peek(stack *s) {
    if (isempty(*s)) {
        return '\0';
    }
    return s->data[s->top];
}

int check_operand(char op) {
    return (op >= 'a' && op <= 'z');
}

void conversion(char exp[]) {
    stack s;
    s.top = -1;
    stack st;
    st.top = -1;
    char postfix[100];
    int i, j = -1;

    for (i = 0; exp[i]; i++) {
        push(&s, exp[i]);
    }

    while (!isempty(s)) {
        if (peek(&s) == '\\' || peek(&s) == '/') {
            pop(&s);
            while (!isempty(st)) {
                postfix[++j] = pop(&st);
            }
        } else {
            if (check_operand(peek(&s))) {
                push(&st, pop(&s));
            }
             // Make sure to remove the character from the stack
        }
    }

    postfix[++j] = '\0';
    printf("%s", postfix);
}

int main() {
    char exp[100];
    printf("Enter the expression: ");
    scanf("%s", exp);
    conversion(exp);
    return 0;
}

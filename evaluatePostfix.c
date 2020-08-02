#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

char stack[100];
char* top = &stack[0];

// Push function
char* push(char letter) {
    *top = letter;
    top++;
    return top;
}

//Pop function
void pop(int doPrint) {
    if (doPrint == 1) {
        printf("%c", *(top - 1));
    }
    *(top - 1) = '\0';
    top--;
}

//converts character to int
int ctoi(char n) {
    return (n - '0');
}

void main() {
    char exp[100] = {0};
    int i;
    int temp;

    printf("Enter postfix expression : ");
    gets(exp);

    for (i = 0;i < strlen(exp);i++) {
        //Here ctoi() converts character into integer. It takes char as an argument
        switch (exp[i]) {
        case '+':
            temp = ctoi(*(top - 2)) + ctoi(*(top - 1));
            pop(0);pop(0);
            push(temp+'0');
            break;
        case '-':
            temp = ctoi(*(top - 2)) - ctoi(*(top - 1));
            pop(0);pop(0);
            push(temp + '0');
            break;
        case '*':
            temp = ctoi(*(top - 2)) * ctoi(*(top - 1));
            pop(0);pop(0);
            push(temp + '0');
            break;
        case '/':
            if (ctoi(*(top - 1)) != 0) {
                temp = ctoi(*(top - 2)) / ctoi(*(top - 1));
                pop(0);pop(0);
                push(temp + '0');
            }
            break;
        default:
            push(exp[i]);
            break;
        }
    }

    printf("%c", stack[0]);
}

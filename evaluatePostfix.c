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
    switch (n){
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return -1;
            break;
    }
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
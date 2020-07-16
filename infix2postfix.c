#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define stcsize 100

//Global stack array
char stackarr[stcsize] = {0}; //Initializing stack with 0
char* top = &stackarr[0];

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
	*(top-1) = '\0';
	top--;
}

//function that return precedence of given operator
int getPrecedence(char letter,int isInsideStack) {
	int prec = 0;

	//For character/variable operator
	if ((letter >= 'a' && letter <= 'z') 
		|| (letter >= 'A' && letter <= 'Z')) {
		if (isInsideStack == 1) {
			return 8;
		}else {
			return 7;
		}
	}

	//For other operators
	switch (letter) {
		case '+':
		case '-':
			prec = isInsideStack == 1 ? 2 : 1; //if Inside stack then prec = 2 otherwise prec = 1
			break;
		case '/':
		case '*':
			prec = isInsideStack == 1 ? 4 : 3;
			break;
		case '$':
		case '^':
			prec = isInsideStack == 1 ? 5 : 6;
			break;
		case '(':
			prec = isInsideStack == 1 ? 0 : 9;
			break;
		case ')':
			prec = isInsideStack == 1 ? -1 : 0; //For dash precedence I've taken -1
			break;
		default:
			prec = -1;
			break;
	}

	//Returning precedence
	return prec;
}

void main() {
	//Initializing expression string with 0 unless taken input
	char exp[100] = { 0 };
	int i = 0;

	//Getting expression string from user
	printf("Enter expression : ");
	gets(exp);

	//Appending ) operator to the given string
	exp[strlen(exp)] = ')';

	//Push ( operator on the stack according to the algorithm
	push('(');

	//Main Infix to postfix operation

	/*
		Please note that here my Top pointer points to empty space above the
		last variable like this :

						Top pointer
						↓
		stack = 5 8 2 1 0 0 0 0 0 0 0
	*/

	while(1) {

		/* If ')' is detected then pop everything until you find
		'(' and print it. Also remove '(' in the end. */
		if (exp[i] == ')') {
			while (*(top - 1) != '(') {
				pop(1);
			}
			pop(0);
		}

		/* Otherwise compare the precedence of the operator on the stack
		and operator on the string */
		else {
			/* While the precedence of operator on the stack is greater than
			the operator on the string then Pop & print*/
			while (getPrecedence(exp[i], 0) < getPrecedence(*(top - 1), 1)) {
				pop(1);
			}

			/*Always push the operator on the stack in the end.*/
			push(exp[i]);
		}

		/* Increment the index of given string */
		i++;

		/* If the stack is empty then breake the loop */
		if (*(top-1) == '\0') {
			break;
		}
	}
}
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void move(char from,char to) {
	printf("\nMove disk from %c to %c",from,to);
}

void hanoi(int dskcount,char from,char via,char to) {
	if (dskcount != 0) {
		hanoi(dskcount - 1, from, to, via);
		move(from, to);
		hanoi(dskcount - 1, via, from, to);
	}
}

void main() {
	int n;
	printf("Enter number of disk : ");
	scanf_s("%d",&n);

	hanoi(n,'A','B','C');
}
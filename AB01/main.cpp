/*
 * main.c
 *
 *  Created on: 17.02.2014
 *      Author: Florian
 */
#include <iostream>
#define MAX(a,b) ((a) < (b) ? b : a)

int main() {
	int x = 5, y = 10;
	int z = MAX(x++, y++);
	std::cout << z;
}





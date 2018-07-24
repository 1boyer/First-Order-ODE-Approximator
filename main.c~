#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INPUT_LENGTH 128

#include "variables.h"
#include "tree_calc.h"
#include "variables.c"
#include "tree_calc.c"
#include "clean.c"

/*
	Local Linear Approximator - Eulers Method
        - Becomes viciously inaccurate at low step sizes
	- Currently does computations involving decimals with + - * / ( )
        - Idea: Try to reverse input for parsing, may make more sense
*/

struct tree_node* get_function(){
	char function[INPUT_LENGTH];
	struct tree_node* base;

	printf("f'(x,y):");
	fgets(function, INPUT_LENGTH, stdin);
	clean(function);

	base = create_tree(function);

	if(base <= 0){
		printf("Bad tree!\n");
		exit(-1);
	}

	return base;
}

int main(){
	double step_size, x, y;
	unsigned int steps;
	struct tree_node* base;

	initialize_lists();
	base = get_function();

	printf("Step size:");
	scanf("%lf", &step_size);

	printf("Steps:");
	scanf("%d", &steps);

	printf("Initial x:");
	scanf("%lf", &x);

	printf("Initial y:");
	scanf("%lf", &y);	

	while(steps--){ // LOCAL LINEAR APPROXIMATION y = f'dx + y_0
		printf("(%f,%f)\n", x, y);
		set_variables(xlist, x);
		set_variables(ylist, y);
		x += step_size;
		y += step_size*compute_tree(base);
	}

	system("PAUSE");

	return 0;
}

/* tree_calc.h
   tree_calc.c
*/

struct tree_node{
	double data;
	int operation;
	struct tree_node* left;
	struct tree_node* right;
};

enum operations{
	addition = 1,
	subtraction,
	multiplication,
	division,
	exponent,
	paranthesis
};

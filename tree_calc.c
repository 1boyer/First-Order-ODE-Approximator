int define_node(char *function, struct tree_node *base){
	int i = 0, depth = 0, j = 0;

	base->data = 0;
	base->operation = 0;

	for(i = 0; function[i] != 0; i++){
		if(function[i] == '('){
			depth++;
			while(depth){
				i++;
				if(function[i] == '(') depth++;
				else if(function[i] == ')') depth--;
			}
		}
		if(function[i] == '+'){
			base->operation = addition;
			function[i] = 0;
			return (i+1);
		}
	}

	for(i = 0; function[i] != 0; i++){
		if(function[i] == '('){
			depth++;
			while(depth){
				i++;
				if(function[i] == '(') depth++;
				else if(function[i] == ')') depth--;
			}
		}
		else if(function[i] == '-'){
			base->operation = subtraction;
			function[i] = 0;
			return (i+1);
		}
	}

	for(i = 0; function[i] != 0; i++){
		if(function[i] == '('){
			depth++;
			while(depth){
				i++;
				if(function[i] == '(') depth++;
				else if(function[i] == ')') depth--;
			}
		}
		else if(function[i] == '*'){
			base->operation = multiplication;
			function[i] = 0;
			return (i+1);
		}
	}

	for(i = 0; function[i] != 0; i++){
		if(function[i] == '('){
			depth++;
			while(depth){
				i++;
				if(function[i] == '(') depth++;
				else if(function[i] == ')') depth--;
			}
		}
		else if(function[i] == '/'){
			base->operation = division;
			function[i] = 0;
			return (i+1);
		}
	}

	for(i = 0; function[i] != 0; i++){
		if(function[i] == '('){
			depth++;
			while(depth){
				i++;
				if(function[i] == '(') depth++;
				else if(function[i] == ')') depth--;
			}
		}
		else if(function[i] == '^'){
			base->operation = exponent;
			function[i] = 0;
			return (i+1);
		}
	}

	depth = 0;
	for(i = 0; function[i] != 0; i++){
		if(function[i] == '('){
			depth++;
			j = i+1;
			function[i] = 0; // '(' -> 0
			while(depth > 0){
				i++;
				if(function[i] == '('){
					depth++;
				}
				else if(function[i] == ')'){
					depth--;
				}
			}
			function[i] = 0; // ')' -> 0
			break;
		}
	}

	if(j > 0){
		base->operation = paranthesis;
		return j;
	}

	if(base->operation == 0){
		if(function[0] == 'x'){
			base->data = 2;
			addvar(xlist, base);
		}
		else if(function[0] == 'y'){
			base->data = 3;
			addvar(ylist, base);
		}
		else{
			base->data = strtod(function, 0);
		}
	}
	return 0; 
}

struct tree_node* create_tree(char* function){
	struct tree_node* base = malloc(sizeof(struct tree_node));
	int i = 0;

	if(base == 0){
		printf("Some error!\n");
		return 0;
	}

	i = define_node(function, base);

	if(base->operation == paranthesis){
		base->right = create_tree(function+i);
		base->left = 0;
	}
	else if(base->operation > 0){
		base->left = create_tree(function); 
		base->right = create_tree(function+i);
	}

	return base;
}

double compute_tree(struct tree_node* base){
	if(base->data)
		return base->data;

	switch(base->operation){
		case 0:
			return 0;
		case addition:
			return compute_tree(base->left) + compute_tree(base->right);
		case subtraction:
			return compute_tree(base->left) - compute_tree(base->right);
		case multiplication:
			return compute_tree(base->left) * compute_tree(base->right);
		case division:
			return compute_tree(base->left) / compute_tree(base->right);
		case exponent: 
			return pow(compute_tree(base->left), compute_tree(base->right));
		case paranthesis:
			return compute_tree(base->right);
		default:
			printf("Error occurred!");
	}
}


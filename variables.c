struct list_node *xlist, *ylist;

void initialize_lists(){
	xlist = malloc(sizeof(struct list_node));
	xlist->location = 0;
	xlist->next = 0;

	ylist = malloc(sizeof(struct list_node));
	ylist->location = 0;
	ylist->next = 0;
}

void addvar(struct list_node* list, struct tree_node* base){
	struct list_node* current = list;

	while(current->next){
		current = current->next;
	}

	current->location = base;
	current->next = malloc(sizeof(struct list_node));
	current = current->next;
	current->location = 0;
	current->next = 0;
}

void set_variables(struct list_node* root, double value){
	struct list_node* current;
	
	current = root;
	while(current->next != 0){
		(current->location)->data = value;
		current = current->next;
	}
}

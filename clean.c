/* clean(char*)
  This function filters the input to take out unexpected
  or unwanted spaces or other such characters.
*/
void clean(char* function){
	int i = 0;

	while(function[i] != 0){
		if(function[i] == '\n')
			function[i] = 0;
		i++;
	}

	i = 0;
	while(function[i] != 0){
		if(function[i] == 0x20){
			while(function[i] != 0){
				function[i] = function[i+1];
				i++;
			}
			function[i] = 0;
			i = 0;
			continue;
		}
		i++;
	}
}

#include <stdio.h>
#include <string.h>

int count_occurrences(const char* text, const char* word) {
	int count = 0;
	char* p;
   	p = strtok(text, ",. ");

	while (p != NULL) {
		if (strcmp(p, word) == 0)
			count++;

		p = strtok(NULL, ",. ");
	}


	return count;
}


int main() {
	/*const char *text = (char*)malloc(100 * sizeof(char));
	const char *word = (char*)malloc(20 * sizeof(char));
	
	scanf("%s ", word);
	fgets(text, 100, stdin);
	printf("%s\n", word);
	printf("%s\n", text);
	int res = count_occurrences(text, word);
	
	printf("%d\n", res);


	free(word);
	free(text);
	*/

	int n, i, j, a[100][100];
	scanf("%d", &n);

	// int* matrix = (int*)malloc(n*n*sizeof(int));


	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {	
			scanf("%d", &a[i][j]);
		}
	}



	return 0;
}

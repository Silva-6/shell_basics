#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	char *buffer = NULL, *copy_buffer = NULL;
	ssize_t num_read;
	size_t n = 0;
	char *token;
	char *delim = " \n";
	int num_tokens = 0, i;
	char **argv;

	printf("$ ");
	num_read = getline(&buffer, &n, stdin);
	printf(">>> %s\n", buffer);
	//printf("%ld\n", num_read);

	/* allocate enough space for user's input */
	copy_buffer = malloc(sizeof(char) * num_read);

	/* copy the content of buffer to copy_buffer */
	strcpy(copy_buffer, buffer);

	/* get the number of tokens to be created */
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;

	argv = malloc(sizeof(char *) * num_tokens);

	/* get the tokens, save them as args in argv */
	token = strtok(copy_buffer, delim);
	while (token != NULL)
	{
		/* allocate space for each token */
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);

		/* debugging */
		printf(">>>>> %s\n", argv[i]);
		/**************/
		i++;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	printf(">>>>> %s\n", argv[i]);

	printf("Number of tokens: %d\n", num_tokens);
}

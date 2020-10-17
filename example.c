#include "vardump.h"

int main(int argc, char* argv[], char **env) {
	char* str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
	fprintf(stdout, "String dump:\n");
	vardump(str, strlen(str) + 1, 16);
	
	char* s = *env;
	while (s[0] != 0) s += strlen(s) + 1;
	fprintf(stdout, "Save dump of environment block to 'env.txt'... ");
	fvardump("env.txt", *env, (size_t)(s - *env + 1), 16, 0);
	fprintf(stdout, "Done\n");
	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

long fsize(FILE *file) {
	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	fseek(file, 0, SEEK_SET);
	return size;
}

int part_1(char* chars) {
    int floor = 0;
    for (int i = 0; chars[i] != '\0'; i++) {
        switch(chars[i]) {
            case '(': floor++; break;
            case ')': floor--; break;
		}
	}
    return floor;
}

int part_2(char* chars) {
    int floor = 0;
	int pos = 1;
    for (int i = 0; chars[i] != '\0'; i++) {
        switch(chars[i]) {
            case '(': floor++; break;
            case ')': floor--; break;
		}
		if (floor == -1) {
			return pos;
		}
		pos++;
	}
    return -1;
}

int main(void) {
	assert(part_1("(())") == 0);
	assert(part_1("()()") == 0);
	assert(part_1("(((") == 3);
	assert(part_1("(()(()(") == 3);
	assert(part_1("))(((((") == 3);
	assert(part_1("())") == -1);
	assert(part_1("))(") == -1);
	assert(part_1(")))") == -3);
	assert(part_1(")())())") == -3);
	printf("**part_1 tests pass**\n");
	
	assert(part_2(")") == 1);
	assert(part_2("()())") == 5);
	printf("**part_2 tests pass**\n");

	FILE* file = fopen("input.txt", "r");
	if (file == NULL) {
       fprintf(stderr, "fopen() failed in file %s at line #%d", __FILE__, __LINE__);
       exit(EXIT_FAILURE);
    }

	long file_size = fsize(file);
	
	char contents[file_size];
	fread(contents, sizeof(file_size), file_size, file);

	printf("Part 1: %d\nPart 2: %d", part_1(contents), part_2(contents));

	fclose(file);

	return EXIT_SUCCESS;
}

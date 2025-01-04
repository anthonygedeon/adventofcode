#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define SIZE(x) (sizeof(x)/sizeof(x[0]))

long fsize(FILE *file) {
	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	fseek(file, 0, SEEK_SET);
	return size;
}

void parse(const char* dest, int* src) {
	int l, w, h;
	sscanf(dest, "%dx%dx%d", &l, &w, &h);
	src[0] = l;
	src[1] = w;
	src[2] = h;
}

int surface_area(int l, int w, int h) {
    return 2 * (l*w + w*h + h*l);
}

int smallest_side(int l, int w, int h) {
    int smallest[] = { l * w, w * h, h * l };
	int min = smallest[0];
	for (int i = 0; i < SIZE(smallest); i++) {
		if (smallest[i] < min) {
			min = smallest[i];
		}
	}
	return min;
}

int part_1(char* chars) {
	int d[3];
	parse(chars, d);
	return surface_area(d[0], d[1], d[2]) + smallest_side(d[0], d[1], d[2]);
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // For ascending order
}

int part_2(char* chars) {
	int d[3];
	parse(chars, d);
	qsort(d, SIZE(d), sizeof(int), compare);
	
	int total = 1;
	for (int i = 0; i < SIZE(d); i++) {
		total *= d[i];
	}

	return total + (2 * (d[0] + d[1]));
}

int main(void) {
	FILE* file = fopen("input.txt", "r");
	if (file == NULL) {
       fprintf(stderr, "fopen() failed in file %s at line #%d", __FILE__, __LINE__);
       exit(EXIT_FAILURE);
    }


	char *line = NULL;
    size_t len = 0;
    ssize_t read;

	int total_1 = 0;
	int total_2 = 0;
	while ((read = getline(&line, &len, file)) != -1) {
		total_1 += part_1(line);
		total_2 += part_2(line);
    }

	printf("Part 1: %d\n", total_1);
	printf("Part 2: %d", total_2);

	fclose(file);

	return EXIT_SUCCESS;
}

/*

def part_2(lines: List[str]) -> int:
    total: int = 0
    for line in lines:
        dimensions = parse_dimensions(line)
        dimensions.sort() 
        total += reduce(mul, dimensions, 1) + (2 * (dimensions[0] + dimensions[1]))
    return total
*/

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int dial = 50;
static int sum = 0;

int part_1(const char *directions) {
    int number;
    char rotation;
    sscanf(directions, "%c%d", &rotation, &number);
    switch (rotation) {
    case 'L':
        dial -= number;
        dial %= 100;
        if (dial < 0) {
            dial += 100;
        }
        break;
    case 'R':
        dial += number;
        dial %= 100;
        if (dial >= 100) {
            dial -= 100;
        }
        break;
    }

    if (dial == 0)
        sum++;

    return sum;
}

int part_2(const char *directions) {
    int number;
    char rotation;
    sscanf(directions, "%c%d", &rotation, &number);

    for (int _i = 0; _i < number; _i++) {
        switch (rotation) {
        case 'L':
            dial--;
            dial %= 100;
            if (dial == 0) {
                sum++;
            } else if (dial < 0) {
                dial += 100;
            }
            break;
        case 'R':
            dial++;
            dial %= 100;
            if (dial == 0) {
                sum++;
            } else if (dial >= 100) {
                dial -= 100;
            }
            break;
        }
    }

    return sum;
}

int main(void) {
#ifdef DEBUG
    part_1("L68");
    assert(dial == 82);

    part_1("L30");
    assert(dial == 52);

    part_1("R48");
    assert(dial == 0);

    part_1("L5");
    assert(dial == 95);

    part_1("R60");
    assert(dial == 55);

    part_1("L55");
    assert(dial == 0);

    part_1("L1");
    assert(dial == 99);

    part_1("L99");
    assert(dial == 0);

    part_1("R14");
    assert(dial == 14);

    int test_password = part_1("L82");
    assert(dial == 32);
    assert(test_password == 3);
    printf("**part_1 tests pass**\n");

    printf("**part_2 tests pass**\n");
#endif

    FILE *file = fopen("puzzle.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "fopen() failed in file %s at line #%d", __FILE__,
                __LINE__);
        return EXIT_FAILURE;
    }

    char buffer[255];
    int password = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        password = part_1(buffer);
    }
    printf("Part 1: %d\n", password);

    sum = 0;
    dial = 50;
    rewind(file);
    memset(buffer, '\0', sizeof(buffer));
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        password = part_2(buffer);
    }

    printf("Part 2: %d\n", part_2(buffer));

    fclose(file);

    return EXIT_SUCCESS;
}

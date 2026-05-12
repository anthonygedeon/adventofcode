#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

uint8_t grid[1000][1000] = {0};
int grid2[1000][1000] = {0};

void
part_1(char *line)
{
  int total = 0;

  char command[10] = {0}, state[4] = {0};
  int x1, y1, x2, y2;

  sscanf(line, "%s", command);

  if (strncmp(line, "turn", 4) == 0)
  {
    sscanf(line, "%s %s %d,%d through %d,%d", command, state, &x1, &y1, &x2, &y2);


    for (int row = x1; row <= x2; row++)
    {
	for (int col = y1; col <= y2; col++)
	{
	  if (strncmp(state, "off", 3) == 0)
	    grid[row][col] = 0;
	  else
	    grid[row][col] = 1;
	}
    }

  }
  else
  {
    sscanf(line, "%s %d,%d through %d,%d", command, &x1, &y1, &x2, &y2);
    for (int row = x1; row <= x2; row++)
    {
	for (int col = y1; col <= y2; col++)
	{
	    grid[row][col] ^= 1;
	}
    }
  }
}

void
part_2(char *line)
{
  int total = 0;

  char command[10] = {0}, state[4] = {0};
  int x1, y1, x2, y2;

  sscanf(line, "%s", command);

  if (strncmp(line, "turn", 4) == 0)
  {
    sscanf(line, "%s %s %d,%d through %d,%d", command, state, &x1, &y1, &x2, &y2);

    for (int row = x1; row <= x2; row++)
	for (int col = y1; col <= y2; col++)
	  if (strncmp(state, "off", 3) == 0)
	    {
	      if (grid2[row][col] > 0)
		grid2[row][col]--;
	    }
	  else
	    grid2[row][col]++;
  }
  else
  {
    sscanf(line, "%s %d,%d through %d,%d", command, &x1, &y1, &x2, &y2);
    for (int row = x1; row <= x2; row++)
	for (int col = y1; col <= y2; col++)
	  grid2[row][col] += 2;
    }
}

int
main(void)
{
  FILE* fp = fopen("input.txt", "r");
  assert(fp != NULL);

  char *line = NULL;
  size_t len = 0;
  ssize_t nread;

  int total1 = 0;
  int total2 = 0;

  while ((nread = getline(&line, &len, fp)) != -1) {
    part_1(line);
    part_2(line);
  }

  for (int i = 0; i < 1000; i++)
    for (int j = 0; j < 1000; j++)
      if (grid[i][j]) total1++; 

  for (int i = 0; i < 1000; i++)
    for (int j = 0; j < 1000; j++)
      total2 += grid2[i][j];
  

  printf("Part 1:%d\nPart 2:%d\n", total1, total2);

  return 0;
}

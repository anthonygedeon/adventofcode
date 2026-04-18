#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define VOWELS 5
#define BANNED 4
const char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
const char* banned[] = { "ab", "cd", "pq", "xy" };

bool is_vowel(const char c) {
  for (int i = 0; i < VOWELS; i++)
  {
      if (c == vowels[i])
      {
	return true;
      }
  }
  return false;
}

bool contains_vowels(const char *s)
{
  int result = 0;

  while (*s) { 
    if (is_vowel(*s)) result++;
    s++;
  }

  return result >= 3;
}

bool contains_banned(const char *s)
{
  for (int i = 0; i < BANNED; i++)
  {
      if (strcmp(banned[i], s) == 0)
	return true;
  }
  return false;
  
}

bool contains_doubles(const char *s)
{
  int result = 0;
  for (int i = 0; s[i] != '\0'; i++)
  {
    char doubles[2];
    memcpy(doubles, s+i , 2);
    if (contains_banned(doubles)) return false;
    if (doubles[0] == doubles[1]) result++;
  }
  return result >= 1;
}

int main(void)
{

  FILE* fp = fopen("input.txt", "r");
  assert(fp != NULL);

  char *line;
  size_t n;

  int total = 0;
  while ((n = getline(&line, &n, fp)) != -1)
  {
    if (contains_vowels(line) && contains_doubles(line)) total++;
  }

  printf("%d\n", total);

  return 0;
}

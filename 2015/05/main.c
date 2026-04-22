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

void substr(char *dest, const char *src, int start, size_t end)
{
    strncpy(dest, src + start, end - start);
}

bool contains_pair(const char *s)
{
  size_t len = strlen(s);
  for (size_t i = 0; i < len; i++)
    for (size_t j = i + 1; j < len; j++)
      if (strncmp(s + i, s + j, 2) == 0 && j - i > 1)
	return true;
  return false;
}

bool contains_triplet(const char *s)
{
  for (int i = 0; s[i] != '\0'; i++)
  {
    char triplet[4] = {'\0'};
    memcpy(triplet, s + i, 3);
    if (triplet[0] == triplet[2]) return true;
  }
  return false;
}

int main(void)
{
  assert(!contains_pair("aaa"));
  assert(contains_pair("qjhvhtzxzqqjkmpb"));
  assert(contains_pair("xxyxx"));
  assert(contains_pair("uurcxstgmygtbstg"));
  assert(!contains_pair("ieodomkazucvgmuy"));  
  assert(!contains_triplet("uurcxstgmygtbstg"));
  assert(contains_triplet("ieodomkazucvgmuy"));

  FILE* fp = fopen("input.txt", "r");
  assert(fp != NULL);

  char *line;
  size_t n;

  int total1 = 0;
  int total2 = 0;

  while ((n = getline(&line, &n, fp)) != -1)
  {
    // if (contains_vowels(line) && contains_doubles(line)) total1++;
    if (contains_pair(line) && contains_triplet(line)) total2++;
  }

  printf("%d\n", total1);
  printf("%d\n", total2);

  fclose(fp);

  return 0;
}

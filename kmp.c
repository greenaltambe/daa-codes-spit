#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void compute_lps_array(char *pattern, int *lps)
{
  int length = 0;
  int i = 1;
  lps[0] = 0;
  int pattern_length = strlen(pattern);

  while (i < pattern_length)
  {
    if (pattern[i] == pattern[length])
    {
      length++;
      lps[i] = length;
      i++;
    }
    else
    {
      if (length != 0)
      {
        length = lps[length - 1];
      }
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
}

// KMP search algorithm
void kmp_search(char *text, char *pattern)
{
  int text_length = strlen(text);
  int pattern_length = strlen(pattern);
  int *lps = (int *)malloc(sizeof(int) * pattern_length);

  compute_lps_array(pattern, lps);

  int text_index = 0;
  int pattern_index = 0;

  while (text_index < text_length)
  {
    if (text[text_index] == pattern[pattern_index])
    {
      text_index++;
      pattern_index++;
    }

    if (pattern_index == pattern_length)
    {
      printf("Pattern found at index %d\n", text_index - pattern_index);
      pattern_index = lps[pattern_index - 1];
    }
    else if (text_index < text_length && text[text_index] != pattern[pattern_index])
    {
      if (pattern_index != 0)
        pattern_index = lps[pattern_index - 1];
      else
        text_index++;
    }
  }

  free(lps);
}

int main(void)
{
  char text[] = "aabaacaadaabaaabaa";
  char pattern[] = "aaba";

  kmp_search(text, pattern);
  return 0;
}

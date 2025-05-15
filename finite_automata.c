#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

int get_next_state(char *pattern, int m, int state, char x)
{
  if (state < m && pattern[state] == x)
    return state + 1;

  for (int ns = state; ns > 0; ns--)
  {
    if (pattern[ns - 1] == x)
    {
      int i;
      for (i = 0; i < ns - 1; i++)
      {
        if (pattern[i] != pattern[state - ns + 1 + i])
          break;
      }
      if (i == ns - 1)
        return ns;
    }
  }

  return 0;
}

void compute_transition_function(char *pattern, int m, int TF[][ALPHABET_SIZE])
{
  for (int state = 0; state <= m; state++)
  {
    for (int a = 0; a < ALPHABET_SIZE; a++)
    {
      char ch = 'a' + a;
      TF[state][a] = get_next_state(pattern, m, state, ch);
    }
  }
}

void finite_automata_matcher(char *text, char *pattern)
{
  int n = strlen(text);
  int m = strlen(pattern);
  int TF[m + 1][ALPHABET_SIZE];

  compute_transition_function(pattern, m, TF);

  int state = 0;
  for (int i = 0; i < n; i++)
  {
    char ch = text[i];
    if (ch >= 'a' && ch <= 'z')
    {
      state = TF[state][ch - 'a'];
    }
    else
    {
      state = 0;
    }

    if (state == m)
    {
      printf("Pattern found at: %d\n", i - m + 1);
    }
  }
}

int main()
{
  char text[] = "aabaacaadaabaaabaa";
  char pattern[] = "aaba";

  finite_automata_matcher(text, pattern);

  return 0;
}

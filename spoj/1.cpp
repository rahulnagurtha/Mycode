
#include <cstdio>

#define maxn 30000000
#define maxp 2000000

int x[maxn];
int pn = 0, p[maxp];

int main()
{
  int i;
  for (i = 2; i < maxn; i++)
  {
    if (x[i] == 0)
      p[++pn] = i, x[i] = pn;
    for (int j = 1; j <= x[i] && p[j] * i < maxn; j++)
      x[p[j] * i] = j;
  }
  printf("pn=%d\n", pn);
  return 0;
}

#include <stdio.h>
#include <conio.h>
#include <string.h>

#define d 256
#define q 101
int S = 0;
void rk(char P[], char T[])
{
    int i, j, m, n, t, p, h;
    h = 1;
    int s;
    p = t = 0;
    m = strlen(P);
    n = strlen(T);
    for (i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }
    for (i = 0; i < m; i++)
    {
        p = (p * d + P[i]) % q;
        t = (t * d + T[i]) % q;
    }
    for (s = 0; s <= n - m; s++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (T[s + j] != P[j])
                {
                    break;
                }
            }
            if (j == m)
            {
                S++;
                printf("Pattern found at index %d\n", s);
            }
        }
        if (s < n - m)
        {
            t = ((t - T[s] * h) * d + T[s + m]) % q;
            if (t < 0)
            {
                t = t + q;
            }
        }
    }
}

void main()
{
    char P[] = "AABA";
    char T[] = "AABAACAADAABA";

    rk(P, T);
    if (S == 0)
        printf("No soln\n");
}
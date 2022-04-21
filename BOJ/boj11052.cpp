#include <stdio.h>

int N;
int P[1001];
int DP[1001];

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(void)
{

    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &P[i]);
    }
    DP[0] = 0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=i; j++)
        {
            printf("i = %d, j = %d\n", i, j);
            printf("%d  %d\n", DP[i], DP[i-j]+P[j]);
            DP[i] = max(DP[i],DP[i-j]+P[j]);
        }
    }

    printf("%d\n", DP[N]);


    return 0;
}
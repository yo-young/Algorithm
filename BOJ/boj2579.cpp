#include <stdio.h>
 
#define MAX 10010
 
int N;
int Arr[MAX];
int DP[MAX];

int max(int x, int y)
{
    return x > y ? x : y;
}

void solution()
{
    DP[1] = Arr[1];
    //첫 번째 계단에서의 최대 점수는 첫 번째 계단의 점수
    DP[2] = Arr[1]+Arr[2];
    //두 번째 계단에서의 최대 점수는 첫 번째 계단과 두 번째 계단 점수의 합

    for(int i=3; i<=N; i++)
    {
        DP[i] = max(DP[i-2]+Arr[i], DP[i-3]+Arr[i-1]+Arr[i]);
        /*if(i != N)
        {
            DP[i] = max(DP[i-1], DP[i]);
        }*/
    }
    /*printf("DP\n");
    for(int i=0; i<=N; i++)
    {
        printf("%d\n", DP[i]);
    }*/
    printf("%d", DP[N]);
}
 
int main(void)
{ 
    //freopen("Input.txt", "r", stdin);
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &Arr[i]);
    }

    solution();

    return 0;
}
#include <stdio.h>
 
#define endl "\n"
#define MAX 10010
 
int N;
int Arr[MAX];
int DP[MAX];
 
int Max(int A, int B)
{
    if (A > B) return A;
    return B;
}
 
void Input()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &Arr[i]);
    }
}
 
void Solution()
{
    DP[1] = Arr[1];
    DP[2] = DP[1] + Arr[2];
    //printf("calcurating...\n");
    for (int i = 3; i <= N; i++)
    {
        DP[i] = Max(DP[i - 3] + Arr[i - 1] + Arr[i], DP[i - 2] + Arr[i]);
        DP[i] = Max(DP[i - 1], DP[i]);
    }
    //for(int i=0; i<= N; i++)
    //{
        printf("%d\n", DP[N]);
    //}    
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{ 
    //freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}
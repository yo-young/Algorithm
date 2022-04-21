#include <stdio.h>
 
#define MAX 310
int N, K, Solution;
char Arr[MAX][MAX];
int visit[MAX][MAX];
int sum[MAX][MAX];
int Ans;

void init()
{
    Ans=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            Arr[i][j] = 0;
            visit[i][j] = 0;
        }
    }
}
void initV()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            visit[i][j] = 0;
        }
    }
}

int count(int x, int y, int _x, int _y)
{
    int cnt=0;
    for(int i=x; i<_x; i++)
    {
        for(int j=y; j<_y; j++)
        {
            if(Arr[i][j] == '1') cnt++;
            if(cnt>K) return cnt;
        }
    }

    return cnt;
}

void reculsive(int i, int j, int x_offset, int y_offset)
{
    int cnt = count(i, j, N-x_offset, N-y_offset);
    //printf("cnt : %d, offset : %d %d\n", cnt, x_offset, y_offset);
    if(cnt < K) return;
    if(cnt == K)
    {
        visit[x_offset][y_offset] = 1;
        Ans++;
    }
    if(visit[x_offset][y_offset+1] != 1)
    {
        reculsive(i, j, x_offset, y_offset+1);
    }
    if(visit[x_offset+1][y_offset] != 1)
    {
        reculsive(i, j, x_offset+1, y_offset);
    }
}

int sumFunc(int X, int Y, int x)
{
    int sum=0;

    for(int i=x; i<=X; i++)
    {
        if(Arr[i][Y] == '1')
        {
            sum++;
        }
    }
    return sum;
}

int calculate(int x, int y)
{
    sum[0][0] = Arr[0][0] - 48;

    int cnt=0;
    for(int i=x; i<N; i++)
    {
        if(i) sum[i][0] = sum[i-1][0]+Arr[i][0]-48;

        for(int j=y; j<N; j++)
        {
            if(!i && !j) continue;
            //printf("\n---%d %d---\n", i, j);
            int temp1 = (j-1)<y ? 0 :sum[i][j-1];
            int temp2 = sumFunc(i, j, x);
            //printf("i, j-1 : %d, temp: %d\n", sum[i][j-1], temp);
            sum[i][j] = temp1 + temp2;
            //printf("sum[%d][%d] : %d\n", i, j, sum[i][j]);
            if(sum[i][j] == K) cnt++;
        }//printf("\n");
    }
    //printf("cnt : %d\n\n", cnt);
    return cnt;
}

void solution2(int i, int j)
{
    /*int temp1=0, temp2=0, temp3=0;
    if(i) temp1 = sum[i-1][j];
    if(j) temp2 = sum[i][j-1];
    if(i && j) temp3 = sum[i-1][j-1];
    int cnt = sum[i][j] - (temp1 + temp2 - temp3);*/
    int temp = calculate(i, j);
    //printf("cnt %d\n", temp);
    Ans = Ans + temp;
    //printf("Ans %d\n", Ans);
    //printC();
}

int main(void)
{
    int test_case;

    scanf("%d", &test_case);

    for(int t=1; t<=test_case; t++)
    {
        scanf("%d %d %d", &N, &K, &Solution);
        init();
        for( int i=0; i<N; i++)
        {
            scanf("%s", &Arr[i]);
        }

        if(Solution == 1)
        {
             // first solution
            for(int i=0; i<N; i++)
            {
                for(int j=0; j<N; j++)
                {
                    //printf("\ni: %d, j: %d\n", i, j);
                    reculsive(i, j, 0, 0);
                    initV();
                }
            }
        }
        else
        {
            // second solution
            for(int i=0; i<N; i++)
            {
                for(int j=0; j<N; j++)
                {
                    //printf("i: %d, j: %d\n", i, j);
                    solution2(i, j);
                }
            }
        }
        printf("#%d %d\n", t, Ans);
    }
    return 0;
}
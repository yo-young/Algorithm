#include <stdio.h>
#include <iostream>

/*
......1
......
..xx..
......
.....x
.x...x
......
Ans = 26

.....
.....
....x
x....
x....
Ans = 13

.......
.......
..xx...
.......
.....x.
.x...x.
.......
.......
Ans = 34
*/

using namespace std;

int W, H;
char Map[10][10];
int visit[10][10];
int Ans;

bool check(int x, int y, int f, int cnt)
{
    //대각선 체크
    int dist1 = cnt - visit[x+1][y+1];
    int dist2 = cnt - visit[x+1][y-1];
    int dist3 = cnt - visit[x-1][y+1];
    int dist4 = cnt - visit[x-1][y-1];
    if(dist1 < 2 || dist2 < 2 || dist3 < 2 || dist4 < 2) return false;
    //십자체크
    if((visit[x+1][y] >= 1 && f != 3) 
       || (visit[x][y+1] >= 1 && f != 4) 
       || (visit[x-1][y] >= 1 && f != 1) 
       || (visit[x][y-1] >= 1 && f != 2))
       {
           return false;
       }

    return true;

}

void prt();

void dfs(int x, int y, int cnt)
{
    //printf("x : %d y : %d cnt : %d\n", x, y, cnt);
    if(x == W-1 && y == H-1)
    {
        //printf("\nANS : %d, cnt : %d\n", Ans, cnt);
        Ans = Ans > cnt ? Ans : cnt;
        //printf("ANS : %d\n", Ans);
        if(Ans == 33)
        {
            prt();
        }
        return;
    }
    cnt++;
    visit[x][y] = cnt;
    //prt();

    if(x+1 < W && Map[x+1][y] == '.' && visit[x+1][y] == 0 && check(x+1, y, 1, cnt+1))
    {
        dfs(x+1, y, cnt);
        //printf("end down next right\n");
    }
    if(y+1 < H && Map[x][y+1] == '.' && visit[x][y+1] == 0 && check(x, y+1, 2, cnt+1))
    {
        dfs(x, y+1, cnt);
        //printf("end right next up\n");
    }
    if(x-1 >= 0 && Map[x-1][y] == '.' && visit[x-1][y] == 0 && check(x-1, y, 3, cnt+1))
    {
        dfs(x-1, y, cnt);
        //printf("end up next left\n");
    }
    if(y-1 >= 0 && Map[x][y-1] == '.' && visit[x][y-1] == 0 && check(x, y-1, 4, cnt+1))
    {
        dfs(x, y-1, cnt);
        //printf("end left next return\n");
    }
    cnt--;
    visit[x][y] = 0;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        scanf("%d %d", &W, &H);

        for(int i=0; i<W; i++)
        {
            for(int j=0; j<H; j++)
            {
                cin >> Map[i][j];
                if(Map[i][j] == 'x') visit[i][j] = -1;
                else visit[i][j] = 0;
            }
        }
        dfs(0,0,0);

        printf("#%d %d", t, Ans+1);
    }

    return 0;
}

void prt()
{
    printf("\n");
    int cnt=1;
    for(int i=0; i<W; i++)
    {
        for(int j=0; j<H; j++)
        {
            printf("%d", visit[i][j]);
            //printf("%d", cnt++);
        }printf("\n");
    }
    printf("\n");
}
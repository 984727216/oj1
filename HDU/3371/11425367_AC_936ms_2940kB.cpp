#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3fff;
const int maxn = 550;
int pic[maxn][maxn];
int lowcost[maxn];
int visit[maxn];
int value[maxn];
int n, m, k;
int cnt = 0;

void readin()
{
	scanf("%d%d%d", &n, &m, &k);
	int a, b, c;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			pic[i][j] = INF;
		}
	}
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		if(pic[a][b] > c)
			pic[a][b] = pic[b][a] = c;
	}
	while(k--)
    {
        int l,t,p;
        scanf("%d",&p);
        for(l=0;l<p;l++)
        {
            scanf("%d",&value[l]);
        }
        for(t=0;t<p;t++)
            for(l=0;l<p;l++)
                pic[value[t]][value[l]]=pic[value[l]][value[t]]=0;
    }
}

void init(int start)
{
	for(int i = 1; i <= n; ++i)
	{
		lowcost[i] = pic[start][i];
		visit[i] = 0;
	}
	cnt = 1;
}

int prim(int start)
{
    int ans = 0;
    int min;
    init(start);

    visit[start] = 1;

    for(int i = 1; i <= n; ++i){
        min = INF;
        int flag = -1;
        for(int j = 1; j <= n; ++j){        //找到最小值
            if(!visit[j] && min > lowcost[j]){
                min = lowcost[j];
                flag = j;
            }
        }

        if(flag != -1){
            visit[flag] = 1;
            ans += min;                     //权值叠加
			cnt ++;
            for(int j = 1; j <= n; ++j){        //更新lowcost
                if(!visit[j] && pic[flag][j] < lowcost[j]){
                    lowcost[j] = pic[flag][j];
                }
            }
        }
    }
    return ans;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		readin();
		int ans = prim(1);
		if(cnt == n)
			printf("%d\n", ans);
		else
			printf("-1\n");
	}
	return 0;
}
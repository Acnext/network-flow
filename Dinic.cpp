#include<bits/stdc++.h>
#define N 1000
#define INF 100000000
#define ff(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
struct Edge
{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};

struct Dinic
{
    int n,m,s,t;//��������������������򻡣���Դ���ţ������
    vector<Edge>edges;//�߱�dges[e]��dges[e^1]��Ϊ����
    vector<int>G[N];//�ڽӱ�G[i][j]��ʾ���i�ĵ�j������e�����еı��
    bool vis[N]; //BFS��ʹ��
    int d[N]; //����㵽i�ľ���
    int cur[N]; //��ǰ���±�

    void init()
    {
        memset(vis,false,sizeof(vis));
        edges.clear();
        ff(i,0,N-1)
        G[i].clear();
    }

    void addedge(int from,int to,int cap)
    {
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        int  m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool bfs()
    {
        memset(vis,0,sizeof(vis));
        queue<int>Q;
        Q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!Q.empty())
        {
            int x=Q.front();Q.pop();
            for(int i=0;i<G[x].size();i++)
            {
                Edge&e=edges[G[x][i]];
                if(!vis[e.to]&&e.cap>e.flow)//ֻ���ǲ��������еĻ�
                {
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }

        }
        return vis[t];
    }

    int dfs(int x,int a)//x��ʾ��ǰ��㣬a��ʾĿǰΪֹ����С����
    {
        if(x==t||a==0)return a;//a����0ʱ��ʱ�˳�����ʱ�൱�ڶ�·��
        int flow=0,f;
        for(int&i=cur[x];i<G[x].size();i++)//���ϴο��ǵĻ���ʼ��ע��Ҫʹ�����ã�ͬʱ�޸�cur[x]
        {
            Edge&e=edges[G[x][i]];//e��һ����
            if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0)
            {
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(!a)break;//a����0��ʱ�˳�����a!=0,˵����ǰ�ڵ㻹������һ������·��֧��

            }
        }
        return flow;
    }

    int Maxflow(int s,int t)//������
    {
        this->s=s,this->t=t;
        int flow=0;
        while(bfs())//��ͣ����bfs����ֲ����磬Ȼ����dfs��������������
        {
            memset(cur,0,sizeof(cur));
            flow+=dfs(s,INF);
        }
        return flow;
    }
  };
Dinic ans;
int sumr[22],sumc[22];
int main()
{
    int t;
    scanf("%d",&t);
    int cnt=0;
    while(t--)
    {
        cnt++;
        ans.init();
        int r,c,sum=0;
        scanf("%d%d",&r,&c);
        ff(i,1,r)
        {
            scanf("%d",&sumr[i]);
            sumr[i]-=sum;
            sum+=sumr[i];
        }
        sum=0;
        ff(i,1,c)
        {
            scanf("%d",&sumc[i]);
            sumc[i]-=sum;
            sum+=sumc[i];
        }
        ff(i,1,r)
            ans.addedge(0,i,sumr[i]-c);
        ff(i,1,r)
        {
            ff(j,1,c)
                ans.addedge(i,j+r,19);
        }
        ff(i,1,c)
        ans.addedge(i+r,r+c+1,sumc[i]-r);
        ans.Maxflow(0,r+c+1);
        printf("Matrix %d\n",cnt);
        ff(i,1,r)
        {
            int psize=ans.G[i].size(),node=r+1;
            ff(j,0,psize-1)
            {
                if(ans.edges[ans.G[i][j]].to==node)
                {
                    node++;
                    if(node==r+2)
                        printf("%d",ans.edges[ans.G[i][j]].flow+1);
                    else
                        printf(" %d",ans.edges[ans.G[i][j]].flow+1);
                    if(node==r+c+1)break;
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}


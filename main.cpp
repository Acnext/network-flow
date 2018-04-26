#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <string.h>
#include <math.h>
#include <iostream>
#define ff(i,x,y)for(int i=x;i<=y;i++)
#define maxnode 65
#define size 2
using namespace std;
char transform[40];
int nn;
struct trie
{
    int ch[maxnode][size];//consider maxnode is how much
    int val[maxnode];
    int num;
    trie() {num=1; memset(ch[0],0,sizeof(ch[0])); memset(val,0,sizeof(val));}
    int id(char c) {return c-'a';}
    void insert(char *s,int v)
    {
        int u=0,len=strlen(s);
        ff(i,0,len-1)
        {
            int c=id(s[i]);
            if(!ch[u][c])
            {
                memset(ch[num],0,sizeof(ch[num]));
                ch[u][c]=num++;
            }
            u=ch[u][c];
        }
        val[u]++;
    }
    int query(char *s)
    {
        int u=0,len=strlen(s);
        ff(i,0,len-1)
        {
            int c=id(s[i]);
            if(!ch[u][c])
            return 0;
            u=ch[u][c];
        }
        return val[u];
    }
};
void into2()
{
    ff(i,0,31)
    {

    }
}
int main()
{
    int n;
    scanf("%")
    return 0;
}

//19581 트리의 지름

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<pair<int,int> > node[100001];
int visited[100001]={0};
int n;
int ans=0;
int end_point=0;
int a,b;
void dfs2(int point, int length)
{
    if(visited[point])
        return;
    visited[point] = 1;
    if(ans<length&&point!=a)
    {
        ans=length;
        end_point=point;
    }

    for(int i=0;i<node[point].size();i++)
    {
        dfs2(node[point][i].first,length+node[point][i].second);
    }

}
void dfs3(int point, int length)
{
    if(visited[point])
        return;
    visited[point] = 1;
    if(ans<length&&point!=b)
    {
        ans=length;
        end_point=point;
    }

    for(int i=0;i<node[point].size();i++)
    {
        dfs3(node[point][i].first,length+node[point][i].second);
    }

}
void dfs(int point, int length)
{
    if(visited[point])
        return;
    
    visited[point] = 1;
    if(ans<length)
    {
        ans=length;
        end_point=point;
    }

    for(int i=0;i<node[point].size();i++)
    {
        dfs(node[point][i].first,length+node[point][i].second);
    }

}
int main()
{
    int n;
    cin >> n;
    int parent,child,length;
    for(int i=0;i<n-1;i++)
    {
        cin >> parent >> child >> length;
        node[parent].push_back(make_pair(child,length));
        node[child].push_back(make_pair(parent,length));
    }

    dfs(1,0);
    a=end_point;
    ans = 0;
    memset(visited,0,sizeof(visited));
    dfs(end_point,0);

    b=end_point;
    int x;
    if(a==1) x=a+1;
    else if(a==n) x=a-1;
    else x=a;
    ans = 0;
    memset(visited,0,sizeof(visited));
    dfs2(x,0);
    ans = 0;
    memset(visited,0,sizeof(visited));
    dfs2(end_point,0);
    int r1=ans;

    if(b==1) x=b+1;
    if(b==n) x=b-1;
    else x=b;
    ans = 0;
    memset(visited,0,sizeof(visited));
    dfs3(x,0);
    ans = 0;
    memset(visited,0,sizeof(visited));
    dfs3(end_point,0);
    int r2=ans;

    cout << max(r1,r2) << endl;
    //cout << ans << endl;
    // << " " << a << " " << b<<endl;
    return 0;
}
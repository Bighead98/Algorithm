//1967 트리의 지름

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<pair<int,int> > node[100001];
int visited[100001]={0};
int n;
int ans=0;
int end_point=0;
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
    int a,b;
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
    cout << ans << endl;
    // << " " << a << " " << b<<endl;
    return 0;
}
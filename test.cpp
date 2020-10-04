//11055 가장 큰 증가 부분 수열 실버 2

#include <iostream>

using namespace std;
int n;
int sum = 0;
int num[1001];
int d[1001] = {0};
void f(int a)
{
    d[a]=num[a];
    if(a>n)
        return;
    int k=0;
    for(int i=0;i<a;i++)
    {
        if(num[i]<num[a])
            k=num[a]+d[i];
        d[a] = max(k,d[a]);
    }
    sum = max(sum,d[a]);
    f(a+1);

}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> num[i];
    f(0);
    cout << sum;
}
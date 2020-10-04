//1463 1로 만들기

#include <iostream>

using namespace std;
int sum = 0;
void f(int a, int s)
{

    if(sum!=0&&s>sum)
        return;
    if(a==1)
    {
        sum=s;
        return;
    }
    if(a%3==0)
        f(a/3,s+1);
    if(a%2==0)
        f(a/2,s+1);
    f(a-1,s+1);
    
}
int main()
{
    int n;
    cin >> n;
    f(n,0);
    cout << sum;
}
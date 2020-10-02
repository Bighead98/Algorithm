#include <iostream>

using namespace std;

bool x(int a, int b, int c)
{
    bool k = false;

    k |= a*a == b*b + c*c;
    k |= b*b == a*a + c*c;
    k |= c*c == b*b + a*a;

    return k;

}
int main()
{
    int n;
    cin >> n;
    int a[3][n];
    
    for(int i=0;i<n;i++)
    {
        cin >> a[0][i] >> a[1][i] >> a[2][i];

        cout << "Scenario #" << i+1 << ":" <<endl;
        if(x(a[0][i],a[1][i],a[2][i]))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
        
        cout << endl;
            
    }

    return 0;
}
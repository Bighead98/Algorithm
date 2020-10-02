//19572 small

#include <iostream>

using namespace std;

void f(int a, int b, int c)
{
    double s = double(a+b+c)/2;
    double a1,b1,c1;
    if(s>a && s>b && s>c)
    {
        a1=s-c;
        b1=s-b;
        c1=s-a;
        cout << 1 << endl;
        cout << fixed;
        cout.precision(1);
        cout << a1 << " " << b1 
        << " " << c1 << " " ;
    }
    else
    {
        cout << "-1";
    }
    
}

int main()
{
    int a,b,c;
    cin >> a >> b >> c;

    f(a,b,c);

    return 0;
}
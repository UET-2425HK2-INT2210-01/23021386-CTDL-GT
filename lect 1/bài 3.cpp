#include <iostream>
#include <string.h>
#include <math.h>
#include <iomanip>
using namespace std;

int solve (int a, int b)
{
    while (a != b)
    {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << solve(a, b);
}

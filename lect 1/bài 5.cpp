#include <iostream>
#include <string.h>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    int a[5]; for (int &x : a) cin >> x;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (a[j] < a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
    cout << a[0] + a[4];
}

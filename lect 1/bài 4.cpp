#include <iostream>
#include <string.h>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1]) swap (a[j], a[j + 1]);
        }
    }

    for (int x : a) cout << x << " ";
}

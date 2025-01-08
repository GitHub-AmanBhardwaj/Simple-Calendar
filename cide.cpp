#include <iostream>
#include <iomanip>
using namespace std;
int dayofweek(int m, int y)
{
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= (m < 3);
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + 1) % 7;
}
int main()
{
    int m, y, x;
    int d = 1;
    cout << "ENTER MONTH NO. ";
    cin >> m;
    cout << "ENTER YEAR: ";
    cin >> y;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        x = 31;
    }
    else if (m == 2)
    {
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        { // leap year
            x = 29;
        }
        else
        {
            x = 28;
        }
    }
    else
    {
        x = 30;
    }
    int sp = dayofweek(m, y);
    cout << "Su  Mo  Tu  We  Th  Fr  Sa " << endl;
    int i = 1;
    for (int k = 0; k < sp; k++)
    {
        cout << "    ";
        i++;
    }
    while (i <= 42)
    {
        if (d <= x)
        {
            cout << setw(2) << setfill('0') << d << "  ";
            d++;
        }
        else
        {
            cout << " ";
        }
        if (i % 7 == 0)
        {
            cout << endl;
        }
        i++;
    }
    return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    int t = 0, x = 0, y = 0;
    bool can_walk = false;
    for (int i = 1; i <= N; ++i)
    {
        can_walk = false;
        int tnext = 0, xnext = 0, ynext = 0;
        cin >> tnext >> xnext >> ynext;
        int dist = (tnext - t) - abs(xnext - x) - abs(ynext - y);
        if (dist >= 0 && dist % 2 == 0)
        {
            can_walk = true;
        }
        else
        {
            break;
        }
        t = tnext;
        x = xnext;
        y = ynext;
    }
    if (can_walk)
    {
        cout << "Yes\n";
        return 0;
    }
    else
    {
        cout << "No\n";
        return 0;
    }
}

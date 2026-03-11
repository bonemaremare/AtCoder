#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int count = 0;
    while (true)
    {
        bool all_even = true;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] % 2 != 0)
            {
                all_even = false;
                break;
            }
        }
        if (!all_even)
        {
            break;
        }
        for (int i = 0; i < n; ++i)
        {
            a[i] = a[i] / 2;
        }
        count += 1;
    }

    cout << count << "\n";
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    int result = 0;
    for (int i = 0; i < N; ++i)
    {
        if (i % 2 == 0)
        {
            result += a[i];
        }
        else
        {
            result -= a[i];
        }
    }

    cout << result << "\n";
}

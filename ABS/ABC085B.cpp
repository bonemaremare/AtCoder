#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    set<int> s;
    for (int i = 0; i < N; ++i)
    {
        int d = 0;
        cin >> d;
        s.insert(d);
    }
    cout << s.size() << "\n";
    return 0;
}

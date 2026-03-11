#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N = 0, A = 0, B = 0;
    cin >> N >> A >> B;
    int result = 0;
    for (int i = 1; i <= N; ++i)
    {
        string s = to_string(i);
        int sum = 0;
        for (char c : s)
        {
            sum += (c - '0');
        }
        if (A <= sum && sum <= B)
        {
            result += i;
        }
    }
    cout << result << "\n";
    return 0;
}

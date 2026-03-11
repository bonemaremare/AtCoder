#include <iostream>
using namespace std;
int main()
{
    int A = 0;
    cin >> A;
    int B = 0;
    cin >> B;
    int C = 0;
    cin >> C;
    int X = 0;
    cin >> X;

    int count = 0;

    for (int i = 0; i < A + 1; ++i)
    {
        if (X < 500 * i)
        {
            break;
        }
        int rest = X - 500 * i;
        for (int j = 0; j < B + 1; ++j)
        {
            if (rest < 100 * j)
            {
                break;
            }
            int final_rest = rest - 100 * j;
            if (final_rest % 50 == 0 and final_rest / 50 <= C)
            {
                count += 1;
            }
        }
    }
    cout << count << "\n";
    return 0;
}

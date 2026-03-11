#include <iostream>

using namespace std;

int main()
{
    int N = 0;
    int Y = 0;
    cin >> N >> Y;
    int y = Y / 1000;

    int max_num_ten = y / 10;
    for (int i = 0; i <= min(max_num_ten, N); ++i)
    {
        int rest_price = y - 10 * i;
        int rest_num = N - i;
        int max_num_one = rest_price / 5;
        for (int j = 0; j <= min(rest_num, max_num_one); ++j)
        {
            int final_price = rest_price - j * 5;
            int final_num = rest_num - j;
            if (final_num == final_price)
            {
                cout << i << " " << j << " " << final_num << "\n";
                return 0;
            }
        }
    }
    cout << "-1 -1 -1\n ";
    return 0;
}

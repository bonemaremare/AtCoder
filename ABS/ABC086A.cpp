#include <iostream>
using namespace std;
int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    if ((a * b) % 2 == 0)
    {
        cout << "Even\n";
    }
    else
    {
        cout << "Odd\n";
    }

    return 0;
}

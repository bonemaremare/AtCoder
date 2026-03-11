#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string S = "";
    cin >> S;
    reverse(S.begin(), S.end());
    string letters[4] = {"maerd", "remaerd", "esare", "resare"};
    int rest = S.size();
    while (rest > 0)
    {
        bool match = false;
        int idx = S.size() - rest;
        for (int i = 0; i < 4; ++i)
        {
            if (rest >= letters[i].size() && S.substr(idx, letters[i].size()) == letters[i])
            {
                match = true;
                rest -= letters[i].size();
                break;
            }
        }
        if (rest == 0)
        {
            cout << "YES\n";
            return 0;
        }

        if (!match)
        {
            cout << "NO\n";
            return 0;
        }
    }
}

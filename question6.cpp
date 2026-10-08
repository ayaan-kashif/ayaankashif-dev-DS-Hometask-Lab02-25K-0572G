#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int n = 3;
    int sz[n] = {2, 4, 6};
    string name[n] = {"First Class", "Business Class", "Economy Class"};
    int **a = new int *[n];
    for (int r = 0; r < n; r++)
    {
        a[r] = new int[sz[r]];
        for (int s = 0; s < sz[r]; s++)
            a[r][s] = 0;
    }

    while (true)
    {
        cout << "\nSeat map (0 = available, 1 = reserved):\n";
        for (int r = 0; r < n; r++)
        {
            cout << r << " = " << name[r] << ": ";
            for (int s = 0; s < sz[r]; s++)
            {
                cout << '[' << s << ": " << a[r][s] << "] ";
            }
            cout << '\n';
        }

        int r, s;
        cout << "Choose a row (0-2), or -1 to exit: ";
        if (!(cin >> r) || r == -1)
            break;
        if (r < 0 || r >= n)
        {
            cout << "Error: Invalid class row!\n";
            continue;
        }
        cout << "Choose a seat index (0-" << sz[r] - 1 << "): ";
        if (!(cin >> s))
            break;
        if (s < 0 || s >= sz[r])
        {
            cout << "Error: " << name[r] << " has only "
                 << sz[r] << " seat slots!\n";
            continue;
        }
        if (a[r][s] == 1)
        {
            cout << "Error: This seat is already reserved!\n";
        }
        else
        {
            a[r][s] = 1;
            cout << "Reserved " << name[r] << ", seat " << s << ".\n";
        }
    }

    for (int r = 0; r < n; r++)
        delete[] a[r];
    delete[] a;
    return 0;
}

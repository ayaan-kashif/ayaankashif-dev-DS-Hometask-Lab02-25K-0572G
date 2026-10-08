#include <iostream>
#include <string>
using namespace std;

void show(const int a[], int n)
{
    cout << "{ ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i < n - 1)
            cout << ", ";
    }
    cout << " }\n";
}

int main()
{
    const int n = 6;
    int a[n] = {102, 0, 305, 0, 401, 908};
    string cmd;

    cout << "Before: ";
    show(a, n);
    cout << "Enter compact to compact the shelf: ";
    if (!(cin >> cmd))
        return 0;

    if (cmd == "compact")
    {
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != 0)
                a[k++] = a[i];
        }
        while (k < n)
            a[k++] = 0;
    }
    else
    {
        cout << "Unknown command.\n";
    }

    cout << "After: ";
    show(a, n);
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

void addItem(string *&a, int &n, int &cap, const string &x)
{
    if (n == cap)
    {
        int nc = cap * 2;
        string *tmp = new string[nc];
        for (int i = 0; i < n; i++)
            tmp[i] = a[i];
        tmp[n] = x;
        delete[] a;
        a = tmp;
        cout << "Resize triggered: " << cap << " -> " << nc << '\n';
        cap = nc;
    }
    else
    {
        a[n] = x;
    }
    n++;
}

int main()
{
    int cap = 3;
    int n = 0;
    string *a = new string[cap];
    string b[7] = {"Bread", "Milk", "Eggs", "Rice", "Tea", "Sugar", "Apples"};

    for (int i = 0; i < 7; i++)
    {
        addItem(a, n, cap, b[i]);
        cout << "Added: " << b[i] << '\n';
    }

    cout << "\nCart (" << n << " items, capacity " << cap << "):\n";
    for (int i = 0; i < n; i++)
        cout << i + 1 << ". " << a[i] << '\n';
    delete[] a;
    return 0;
}

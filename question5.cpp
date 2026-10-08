#include <iostream>
using namespace std;

class SafeCommandCenter
{
private:
    int *a;
    static const int n = 5;

public:
    SafeCommandCenter()
    {
        a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = 0;
    }

    ~SafeCommandCenter() { delete[] a; }

    void safeWrite(int i, int v)
    {
        if (i < 0 || i >= n)
        {
            cout << "Critical error: command index out of bounds!\n";
            cout << '\a' << "Rover Emergency Braking Triggered!\n";
            return;
        }
        if (v < 0 || v > 100)
        {
            cout << "Critical error: motor speed must be between 0 and 100!\n";
            cout << '\a' << "Rover Emergency Braking Triggered!\n";
            return;
        }
        a[i] = v;
        cout << "Command " << i << " set to " << v << ".\n";
    }

    void show() const
    {
        cout << "Command sequence: ";
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
};

int main()
{
    SafeCommandCenter c;
    c.show();
    while (true)
    {
        int ch;
        cout << "\n1. Write command\n0. Exit\nChoice: ";
        if (!(cin >> ch) || ch == 0)
            break;
        if (ch != 1)
        {
            cout << "Invalid choice.\n";
            continue;
        }
        int i, v;
        cout << "Enter command index (0-4) and speed (0-100): ";
        if (!(cin >> i >> v))
            break;
        c.safeWrite(i, v);
        c.show();
    }
    return 0;
}

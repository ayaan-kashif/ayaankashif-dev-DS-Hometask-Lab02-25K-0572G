#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cout << "Enter the expected number of passengers: ";
    if (!(cin >> n) || n <= 0)
    {
        cout << "Please enter a positive passenger count.\n";
        return 0;
    }

    string *a = new string[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Passenger " << i + 1 << " name: ";
        if (!getline(cin >> ws, a[i]))
        {
            delete[] a;
            return 0;
        }
    }

    cout << "\nBoarding sequence (reverse check-in order):\n";
    for (int i = n - 1; i >= 0; i--)
    {
        cout << n - i << ". " << a[i] << '\n';
    }

    delete[] a;
    return 0;
}

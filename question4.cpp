#include <iostream>
using namespace std;

void freeArr(int **a, int n)
{
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}

void show(int **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < 3; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}

void addNewStudent(int **&a, int &n)
{
    int **tmp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
        tmp[i] = new int[3];
    cout << "Allocated new " << n + 1 << " x 3 grid at " << tmp << '\n';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            tmp[i][j] = a[i][j];
    }
    cout << "Existing grades copied.\nEnter the transfer student's 3 grades: ";
    for (int j = 0; j < 3; j++)
    {
        if (!(cin >> tmp[n][j]))
        {
            freeArr(tmp, n + 1);
            cout << "Invalid input. New grid released; original grid retained.\n";
            return;
        }
    }

    freeArr(a, n);
    cout << "Old grid released.\n";
    a = tmp;
    n++;
    cout << "Main pointer now uses " << a << " with " << n << " students.\n";
}

int main()
{
    int n;
    cout << "Enter the number of students: ";
    if (!(cin >> n) || n <= 0)
    {
        cout << "Please enter a positive student count.\n";
        return 0;
    }

    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[3];
    cout << "Initial " << n << " x 3 grid allocated at " << a << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << "Enter 3 grades for student " << i + 1 << ": ";
        for (int j = 0; j < 3; j++)
        {
            if (!(cin >> a[i][j]))
            {
                freeArr(a, n);
                cout << "Invalid grade input.\n";
                return 0;
            }
        }
    }

    cout << "\nBefore enrollment:\n";
    show(a, n);
    addNewStudent(a, n);
    cout << "\nAfter enrollment attempt:\n";
    show(a, n);
    freeArr(a, n);
    cout << "Final grid released.\n";
    return 0;
}

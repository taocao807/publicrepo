#include <iostream>
using namespace std;

void pascalTriangle(int n)
{
    string blank = " ";

    for (int i = 1; i <= n; i++)
    {
        int currentValue = 1;

        for (int j = 1; j < (n - i + 1); j++)
        {
            cout << blank;
        }

        for (int j = 1; j <= i; j++)
        {
            cout << currentValue << blank;
            currentValue = currentValue * (i - j) / j;
        }

        cout << "\n";
    }
}

int main()
{
    int height;
    cout << "Enter the number of rows :" << endl;
    cin >> height;
    pascalTriangle(height);
}
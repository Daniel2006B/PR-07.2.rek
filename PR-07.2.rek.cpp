#include <iostream>
#include <iomanip>
#include <climits>
#include <ctime>
#include <cstdlib>

using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High, int i, int j);
void Print(int** a, const int k, const int n, int i, int j);
int FindMinInRowRecursive(int* row, const int n, int i, int minElement);
int FindMinInRow(int* row, const int n);
int FindSumOfMinElementsRecursive(int** a, const int k, const int n, int i, int sum);
int FindSumOfMinElements(int** a, const int k, const int n);

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    int Low = -25;
    int High = 25;
    int k, n;

    cout << "Enter the number of rows (k): ";
    cin >> k;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High, 0, 0);

    cout << "Matrix:" << endl;
    Print(a, k, n, 0, 0);

    int sumOfMinElements = FindSumOfMinElements(a, k, n);

    cout << "Sum of minimum elements in each row: " << sumOfMinElements << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High, int i, int j)
{
    if (i < k) {
        if (j < n) {
            a[i][j] = Low + rand() % (High - Low + 1);
            Create(a, k, n, Low, High, i, j + 1);
        }
        else {
            Create(a, k, n, Low, High, i + 1, 0);
        }
    }
}

void Print(int** a, const int k, const int n, int i, int j)
{
    if (i < k) {
        if (j < n) {
            cout << a[i][j] << " ";
            Print(a, k, n, i, j + 1);
        }
        else {
            cout << endl;
            Print(a, k, n, i + 1, 0);
        }
    }
}

int FindMinInRowRecursive(int* row, const int n, int i, int minElement)
{
    if (i < n) {
        minElement = (row[i] < minElement) ? row[i] : minElement;
        return FindMinInRowRecursive(row, n, i + 1, minElement);
    }
    return minElement;
}

int FindMinInRow(int* row, const int n)
{
    return FindMinInRowRecursive(row, n, 0, INT_MAX);
}

int FindSumOfMinElementsRecursive(int** a, const int k, const int n, int i, int sum)
{
    if (i < k) {
        int minInRow = FindMinInRow(a[i], n);
        sum += minInRow;
        return FindSumOfMinElementsRecursive(a, k, n, i + 1, sum);
    }
    return sum;
}

int FindSumOfMinElements(int** a, const int k, const int n)
{
    return FindSumOfMinElementsRecursive(a, k, n, 0, 0);
}

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void FindMaxAboveDiagonal(int** a, const int n, int& maxElement, int& maxRow, int& maxCol);
void FindMinBelowDiagonal(int** a, const int n, int& minElement, int& minRow, int& minCol);
void SwapMaxMin(int** a, int maxRow, int maxCol, int minRow, int minCol);
int CalculateSum(int maxElement, int minElement);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 0;
    int High = 10;
    int n;
    cout << "n = "; cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    cout << "Original matrix:" << endl;
    Print(a, n);

    int maxElement, maxRow, maxCol, minElement, minRow, minCol;

    FindMaxAboveDiagonal(a, n, maxElement, maxRow, maxCol);
    FindMinBelowDiagonal(a, n, minElement, minRow, minCol);

    cout << "Maximum element above diagonal: " << maxElement << endl;
    cout << "Minimum element below diagonal: " << minElement << endl;

    SwapMaxMin(a, maxRow, maxCol, minRow, minCol);

    cout << endl;
    cout << "Modified matrix:" << endl;
    Print(a, n);

    int sum = CalculateSum(maxElement, minElement);
    cout << "Sum of maximum and minimum elements: " << sum << endl;


    // Free memory
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void FindMaxAboveDiagonal(int** a, const int n, int& maxElement, int& maxRow, int& maxCol)
{
    maxElement = a[0][1];
    maxRow = 0;
    maxCol = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] > maxElement) {
                maxElement = a[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
}

void FindMinBelowDiagonal(int** a, const int n, int& minElement, int& minRow, int& minCol)
{
    minElement = a[1][0];
    minRow = 1;
    minCol = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i][j] < minElement) {
                minElement = a[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }
}

void SwapMaxMin(int** a, int maxRow, int maxCol, int minRow, int minCol)
{
    int temp = a[maxRow][maxCol];
    a[maxRow][maxCol] = a[minRow][minCol];
    a[minRow][minCol] = temp;
}

int CalculateSum(int maxElement, int minElement)
{
    return maxElement + minElement;
}
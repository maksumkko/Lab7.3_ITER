#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int Part1_Count(int** a, const int rowCount, const int colCount, int& count);
void Part2_SaddlePoint(int** a, const int rowCount, const int colCount, int& rowWithLongestSeries);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -17;
	int High = 15;
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);

	int count = 0;
	if (Part1_Count(a, rowCount, colCount, count))
		cout << "count = " << count << endl;
	else
		cout << "there are no zero elements" << endl;

	cout << endl;

	int rowWithLongestSeries = -1;
	Part2_SaddlePoint(a, rowCount, colCount, rowWithLongestSeries);
	if (rowWithLongestSeries != -1)
		cout << "Row with the longest series of identical elements: " << rowWithLongestSeries << endl;
	else
		cout << "No series of identical elements found." << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Input(int** a, const int rowCount, const int colCount)
{
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
			cout << endl;
		}
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int Part1_Count(int** a, const int rowCount, const int colCount, int& count)
{
	count = 0;
	for (int j = 0; j < colCount; j++)
	{
		for (int i = 0; i < rowCount; i++)
		{
			if (a[i][j] == 0)
			{
				count++;
				break;
			}
		}
	}
	return count > 0;
}

void Part2_SaddlePoint(int** a, const int rowCount, const int colCount, int& rowWithLongestSeries)
{
	int maxSeriesLength = 0;
	rowWithLongestSeries = -1;

	for (int i = 0; i < rowCount; i++)
	{
		int currentSeriesLength = 1;
		int longestInRow = 1;

		for (int j = 1; j < colCount; j++)
		{
			if (a[i][j] == a[i][j - 1])
			{
				currentSeriesLength++;
			}
			else
			{
				if (currentSeriesLength > longestInRow)
				{
					longestInRow = currentSeriesLength;
				}
				currentSeriesLength = 1;
			}
		}

		if (currentSeriesLength > longestInRow)
		{
			longestInRow = currentSeriesLength;
		}

		if (longestInRow > maxSeriesLength)
		{
			maxSeriesLength = longestInRow;
			rowWithLongestSeries = i;
		}
	}
}
#include <iostream>
using namespace std;

bool compareNumbers(int num1, int num2)
{
	int lastDigitFirstNum = num1 % 10;
	int lastDigitSecNum = num2 % 10;
	if (lastDigitFirstNum > lastDigitSecNum)
	{
		return true; //trqbva da se razmenqt
	}
	else if ((lastDigitFirstNum == lastDigitSecNum) && (num1 >= num2))
	{
		return true;
	}
	return false;
}

void swapNumbers(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int* sortArray(int* myArr, int length, bool (*compareNumbers) (int, int), void (*swapNumbers) (int&, int&))
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (compareNumbers(myArr[i], myArr[j]))
			{
				swapNumbers(myArr[i], myArr[j]);
			}
		}
	}
	return myArr;
}

void printArr(int* myArr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << myArr[i] << " ";
	}
	cout << endl;
}

void createAndInitializeArr(int* myArr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cin >> myArr[i];
	}
}

int AbsoluteValue(int num1)
{
	if (num1 < 0)
	{
		num1 *= (-1);
	}
	return num1;
}

int main()
{
	int length = 0;
	cin >> length;

	void (*swapNums) (int&, int&) = swapNumbers;
	bool (*compareNumber) (int, int) = compareNumbers;

	int* arr = new int[length] {};
	createAndInitializeArr(arr, length);
	int* finalArr = sortArray(arr, length, compareNumber, swapNums);
	cout << "Task 02: " << endl;
	printArr(finalArr, length);
	int* absArr = sortArray(arr, length, [](int num1, int num2) {return AbsoluteValue(num1) < AbsoluteValue(num2); }, swapNums);
	cout << "Task 03: " << endl;
	printArr(absArr, length);
}

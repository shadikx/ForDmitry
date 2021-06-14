
#include <iostream>

using namespace std;

bool thisArray(int arr[], int size)
{
	cout << "|.... 2 ....|" << endl << endl;

	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return true;
}
int main()
{
	const int size = 7;
	int arr[] = { 0, 1, 1, 1, 0, 0, 1 };
	if (thisArray(arr, size))
	{
		for (size_t i=0; i < 7; i++)
		{
			switch (arr[i])
			{
				case 1:
				{
					arr[i] = 0;
					cout << arr[i] << " ";
				break;
				}

				case 0:
				{
					arr[i] = 1;
					cout << arr[i] << " ";
				break;
				}
			}
		}
		cout << endl;
	}
	return 0;
}
 #include <iostream>

namespace TheLibrary
{
	/*
	void creInitArr(float* array, short SIZE)
	{
		float array[]={ 1, -7, 15, 42, -61, -22, -39};

		std::cout << " " << array[] << " ";
	}

	void printArr(float* array, short SIZE)
	{
		for (size_t i = 0; i < SIZE; i++)
		{
			std::cout << array[i] << " ";
		}
		std::cout << std::endl;
	}
	*/

	void printArr(int* array, short SIZE)
	{
		std::cout << array[0];
		for (size_t i = 0; i < SIZE; i++)
		{
			std::cout << " " << array[i];
		}

		std::cout << std::endl;
	}


	/*
	void prPositNegat(float* array, short SIZE)
	{
		setlocale(LC_ALL, "Russian");

		int posit = 0, negat = 0;

		for (size_t i = 0; i < SIZE; i++)
		{
			if (array[i] > 0)
			{
				posit++;
			}
			else if (array[i] < 0)
			{
				negat++;
			}
		}
		std::cout << "Положительные: " << posit << std::endl << "Отрицательные: " << negat << std::endl;
	}
	*/




#define SwapINT(a, b) a=a^b; b=a^b; a=b^a;

	void sortirovka(int* arr, short size)
	{
		for(size_t i = 0; i < size - 1; i++)
		{
			for(size_t j = 0; j < size - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					SwapINT(arr[j], arr[j + 1]);
				}
			}
		}
	}
}
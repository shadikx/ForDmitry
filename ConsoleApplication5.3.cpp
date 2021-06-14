
#include <iostream>

using namespace std;

int main()
{
	int arr[8] = {};
		
	std::cout << "|...... 3 ......|"<< endl << endl;

	int i = 0;
		
		for (arr[i]=1; arr[i]<23; arr[i]+=3)
		{
			std::cout << arr[i] << " ";
		}

	std::cout << endl;
	
	return 0;
}
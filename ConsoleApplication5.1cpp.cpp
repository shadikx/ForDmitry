
#include <iostream>

using namespace std;

bool RandomArray(double arr[], double size)
{
    cout << "..................(1)....................." << endl << endl << "Double Array" << endl << endl;

    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
    return true;
}

int main()
{
    const double oursize = 6;
    double ourarr[] = { 1.59745, 3.403, 7.6924, 8.12, 5.20823, 9.421 };

    if (RandomArray(ourarr, oursize))
    {
        cout << "Double Array" << endl;
    }

    return 0;

}

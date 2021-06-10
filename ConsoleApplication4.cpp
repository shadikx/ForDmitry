
#include <iostream>

using namespace std;

// 1._______________________________________________________________________________

void task1()
{
    int x1;
    int x2;

    cout << "1. Введите первое число: ";
    cin >> x1;

    cout << "   Введите второе число: ";
    cin >> x2;

    if (x1 + x2 >= 10 && x1 + x2 <= 20)
    
        cout << "true" << endl << endl;
    
    else
    {
        cout << "false" << endl << endl;
    }

}


// 2._______________________________________________________________________________ 
//  ЗАПУТАЛСЯ, 


void task2()
{
    
    
    const int Y1 = 6;
    const int Y2 = 4;

    if (Y1 != 10 && Y2 != 10 || Y1+Y2 != 10)
        cout << "2. false" << endl << endl;
    else
        cout << "2. true" << endl << endl;
 } 

//3._______________________________________________________________________________

void task3()
{
    cout << "3. Ваши нечётные числа:" << endl;

    int i=1;
    while (i < 50)
    {
        cout << i << " ";
        i++;
        i++;
    }
}


int main()
{
    setlocale(LC_ALL, "Rus");

    task1();
    task2();
    task3();

    return 0; 
}



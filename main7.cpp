#include <iostream>

#include "mylib.h"



#define diapazonOtNulya(a, b) ((a >= 0 && a < b) ? "true" : "false")

inline void zadanie2()
{
    std::cout << "| ... 2 ... |" << std::endl;
    int vashe4islo;
    std::cin >> vashe4islo;
    std::cout << diapazonOtNulya(vashe4islo, 34) << std::endl;
}

#define ARRsIZE 8

inline void zadanie3()
{
    std::cout << "| ... 3 ... |" << std::endl;
    setlocale(LC_ALL, "Russian");
    int* array = new (std::nothrow) int[ARRsIZE];

    if (array != nullptr)
    {
        std::cout << "Введите " << ARRsIZE << " чисел: " << std::endl;

        for (size_t i = 0; i < ARRsIZE; i++)
        {
            std::cin >> array[i];
        }
        TheLibrary::sortirovka(array, ARRsIZE);
        TheLibrary::printArr(array, ARRsIZE);

        delete[] array;
    }
}

/*
inline void zadanie5()
{
    std::cout << "| ... 5 ... |" << std::endl;
    const short SIZE = 7;
    float* array = TheLibrary::creInitArr(SIZE) ;

    if (array != nullptr)
    {
        TheLibrary::printArr(array, SIZE);
        TheLibrary::prPositNegat(array, SIZE);

        delete[] array;
    }
}
*/

int main()
{
    
    zadanie2();
    zadanie3();
  //  zadanie5();

}
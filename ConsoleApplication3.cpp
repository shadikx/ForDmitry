
#include <iostream>

extern int q, w, e, r;
extern float t;


int main()
{

    setlocale(LC_ALL, "Rus");

// 1...........................................................................
   

    //int q = 5, w = 7, e = 9, r = 4;

    //float t = q * (w + (e / r)); 
    
    std::cout << "1. q=5,w=7,e=9,r=4" << std::endl << std::endl; 
    std::cout << "   q*(w+(e/r))=" << t << "        // без C-Style cast" << std::endl << std::endl; // выводит на экран целое число, нужно привести переменную "e" к типу float
    
      

    // Для этого можно использовать C-Style cast из языка C
    
    std::cout << "   q*(w+(e/r))=" << (((float)e / r) + w) * q << "     // используется C-Style cast" << std::endl << std::endl;


// 2...........................................................................

        int s = 21, x;
        x = (15 <= s) ? 15 - s : (15 - s) * 2;    // Истина
        std::cout << "2. s=21, x"<< std::endl<< "   x = (15 <= s) ? 15 - s : (15 - s) * 2" << "        // " << x << std::endl;

        x = (30 <= s) ? 30 - s : (30 - s) * 2;    // Ложь
        std::cout << "   x = (30 <= s) ? 30 - s : (30 - s) * 2" << "        // "<< x << std::endl;
      
}

// 3. 

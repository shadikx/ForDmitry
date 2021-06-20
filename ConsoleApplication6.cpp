#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printArr(int* arr, size_t size) 
{
    cout << "| ... 1 ... |" << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void part1()
{
    const size_t aSize = 14;
    int* aArr = new (nothrow) int[aSize];

    if (aArr != nullptr)
    {
        aArr[0] = 1;
        for (size_t i = 1; i < aSize; i++)
        {
            aArr[i] = aArr[i - 1] << 1;
        }
        printArr(aArr, aSize);
        delete[] aArr;
    }
}

void printMatx(int** arr, size_t sz1, size_t sz2)
{
    cout << "| ... 2 ... |" << endl;
    
    for (size_t i = 0; i < sz1; i++)
    {
        for (size_t j = 0; j < sz2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void part2()
{
    srand(time(NULL));
    const size_t mSize = 4;
    int** spnDtXst = new int* [mSize];
    for (size_t i = 0; i < mSize; i++)
    {
        spnDtXst[i] = new int[mSize];
    }

    for (size_t i = 0; i < mSize; i++)
    {
        for (size_t j = 0; j < mSize; j++)
        {
            spnDtXst[i][j] = rand() % 100;
        }
    }

    cout << endl;
    printMatx(spnDtXst, mSize, mSize);

    for (size_t i = 0; i < mSize; i++)
    {
        delete[] spnDtXst[i];
    }
    cout << endl;
    delete spnDtXst;
}

void writeToFile(ofstream& out, const string& fn, const string& str)
{
    out.open(fn);
    if (out.is_open())
    {
        out << str;
        out.close();
    }
}

void part3()
{
    setlocale(LC_ALL, "Russian");
    cout << "| ... 3 ... |" << endl;
    cout << "Введите название первого файла: ";
    string fn1, fn2;
    cin >> fn1;
    cout << "Введите название второго файла: ";
    cin >> fn2;

    ofstream fout1;
    const string str1 = "съешь ещё этих мягких французских булок да выпей чаю";
    writeToFile(fout1, fn1, str1);

    ofstream fout2;
    const string str2 = "the quick brown fox jumps over the lazy dog";
    writeToFile(fout2, fn2, str2);

}

int main()
{
    part1();
    part2();
    part3();
}
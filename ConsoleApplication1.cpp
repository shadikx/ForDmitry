

#include <iostream>

// 1. Создание и инициализация переменных

    short int z = -20'000;

    int timer = 333'222'111;

    long long sixApostrophe = 7'666'555'444'333'222'111;

    char Dog = '@';

    bool spnDsntExst = true;

    float pieceOfOrange = 0.75;

    double varVarVar = 101.101101;

// 2. Перечисление возможных символов в ячейке поля, для игры в крестики-нолики
    enum GameCell {

        GC_EMPTY = '_',
        GC_CROSS = 'X',
        GC_ZERO = '0'
    }; // Поле может содержать крестик, нолик или быть пустым

// 3. Создать массив, способный содержать значение такого перечисления и инициализировать его    
    GameCell array[3][3] = { {GC_EMPTY, GC_EMPTY, GC_EMPTY},
                             {GC_EMPTY, GC_EMPTY, GC_EMPTY},
                             {GC_EMPTY, GC_EMPTY, GC_EMPTY} }; //поле для игры в крестики-нолики 3x3

// 4. Создать структуру данных "Поле для игры в крестики-нолики" и снабдить её всеми необходимыми свойствами
    struct Game
    {
        GameCell array[3][3]; //обязательное наличие массива
        bool isDoomsday;
        bool isAlienWon;
        long long PredatorID, AlienID;
        GameCell ePredator, eAlien; //Чем ходят игроки "Хищник" и "Чужой"
        const unsigned int nFieldSize = 3;
};

// 5. Создать структуру объединяющую: union (int, float, char) и три битовых поля(флага)
// указывающими какого типа значениев данный момент содержится в объединении (isInt, isFloat, isChar)

    union MyVariantData
    {
        int MyInt;
        float MyFloat;
        char MyChar;
    };

    struct MyVariant
    {
        MyVariantData data;

        unsigned int isInt : 1;
        unsigned int isChar : 1;
        unsigned int isFloat : 1;
    };

//---------------------------------------------------------------------------------------------------
    int main()
    {
        MyVariant var;

        var.data.MyChar = 'R';
        var.isChar = 1;
        var.isFloat = 0;
        var.isInt = 0;

        var.data.MyInt = 255;
        var.isChar = 0;
        var.isFloat = 0;
        var.isInt = 1;

        return 0;
    }


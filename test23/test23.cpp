// test23.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int writeVariant()
{
errorNum:
    std::cout << "Ваш вариант: ";
    int num;
    std::cin >> num;
    if (num < 0 || num>999)
    {
        std::cout << "Диапозон от 0 до 999!!!";
        goto errorNum;
    }
    return num;
}

int main()
{
    srand((time(0)));
    std::setlocale(LC_ALL, "rus");
    std::cout << "Компьютер загадал трехзначное число. Вы должны его отгадать." << std::endl <<
        "После очередного числа вам будет сообщено, " << std::endl<<
    "сколько цифр угадано и сколько из них находится на своих местах." << std::endl;
    //Создание рандомного числа
    int randNum = getRandomNumber(000,999);
    //Разделение рандоного числа на сотни, десятки и единицы
    //Сотня
    int randNumH = randNum / 100;
    //Десятка
    int randNumT = (randNum - randNumH) / 10;
    //Единица
    int randNumO = randNum - ((randNumH*100) + (randNumT*10));
    //Массив рандомног числа для сравнения с введённым
    int randNumArray[3] = { randNumH, randNumT, randNumO };
    int variant = 0;
    //Счётчик правильных чисел
    int rigthNum = 0;
    //Счётчик правильного расположения
    int rigthPlase = 0;
    //Игра не будет завершённой пока число не будет угаданно полностью
    do 
    {
        //Ввод числа 
        variant = writeVariant();
        //Сотня введённая
        int variantH = variant / 100;
        //Десятка введённая
        int variantT = (variant - variantH) / 10;
        //Единица введённая
        int variantO = variant - ((variantH*100) + (variantT*10));
        //Массив введённого числа для сравнения
        int variantArray[3] = { variantH, variantT, variantO };
       
        //Проверка вариантов совпадения чисел
        for (int arrayOne = 0; arrayOne < 3; arrayOne++)
        {
            for (int arrayTwo = 0; arrayTwo < 3; arrayTwo++)
            {
                //Если числа равны, то счётчик похожих чисел увеличивается
                if (randNumArray[arrayOne] == variantArray[arrayTwo])
                {
                    if (arrayOne == arrayTwo)
                    {
                        rigthNum++;
                    }
                    //Если число равно рандомному и стоит на своём месте, то счётчик увеличивается
                    if (arrayOne == arrayTwo&&randNumArray[arrayOne]==randNumArray[arrayTwo])
                    {
                        if (arrayOne == arrayTwo)
                        {
                            rigthPlase++;
                        }
                    }
                }
            }
        }
        std::cout << "Угадано: " << rigthNum << " На своих местах: " << rigthPlase << std::endl;
    } while (variant != randNum);
    std::cout << "Вы угадали число: " << variant << " !!!" << std::endl;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#include "pch.h"
#include "input.h"
#include <iostream>
/// <summary>
/// Функция для ввода количества тройников и количества разъемов.
/// </summary>
/// <param name="NumbersTroniks">Ссылка на переменную типа unsigned int, в которую будет сохранено количество тройников</param>
/// <param name="Troniks">Ссылка на массив типа int, в который будут сохранены количество разъемов</param>
void getInput(unsigned int& NumbersTroniks, int*& Troniks) {
    std::cout << "Введите количество тройников: ";

    double input;
    std::cin >> input;

    if (std::cin.fail() || input < 1 || input > 1000 || input != static_cast<unsigned int>(input)) {
        std::cout << "Введено неверное количество тройников. Введите целое число в диапазоне от 1 до 1000" << std::endl;
        throw std::invalid_argument("Неверное количество тройников");
    }

    NumbersTroniks = static_cast<unsigned int>(input);

    Troniks = new int[NumbersTroniks];

    for (unsigned int i = 0; i < NumbersTroniks; i++) {
        std::cout << "Тройник " << i + 1 << ": ";
        std::cin >> Troniks[i];
        if ((Troniks[i] < 1) || (Troniks[i] > 1000)) {
            std::cout << "Введено неверное количество разъёмов. Введите в диапазоне от 1 до 1000" << std::endl;
            throw std::invalid_argument("Неверное количество разъёмов");
        }
    }
}

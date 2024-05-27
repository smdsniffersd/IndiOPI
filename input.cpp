#include "pch.h"
#include "input.h"
#include <iostream>
/// <summary>
/// ������� ��� ����� ���������� ��������� � ���������� ��������.
/// </summary>
/// <param name="NumbersTroniks">������ �� ���������� ���� unsigned int, � ������� ����� ��������� ���������� ���������</param>
/// <param name="Troniks">������ �� ������ ���� int, � ������� ����� ��������� ���������� ��������</param>
void getInput(unsigned int& NumbersTroniks, int*& Troniks) {
    std::cout << "������� ���������� ���������: ";

    double input;
    std::cin >> input;

    if (std::cin.fail() || input < 1 || input > 1000 || input != static_cast<unsigned int>(input)) {
        std::cout << "������� �������� ���������� ���������. ������� ����� ����� � ��������� �� 1 �� 1000" << std::endl;
        throw std::invalid_argument("�������� ���������� ���������");
    }

    NumbersTroniks = static_cast<unsigned int>(input);

    Troniks = new int[NumbersTroniks];

    for (unsigned int i = 0; i < NumbersTroniks; i++) {
        std::cout << "������� " << i + 1 << ": ";
        std::cin >> Troniks[i];
        if ((Troniks[i] < 1) || (Troniks[i] > 1000)) {
            std::cout << "������� �������� ���������� ��������. ������� � ��������� �� 1 �� 1000" << std::endl;
            throw std::invalid_argument("�������� ���������� ��������");
        }
    }
}

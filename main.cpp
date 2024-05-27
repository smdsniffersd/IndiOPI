#include "input.h"
#include "calc.h"
#include "output.h"
#include <iostream>

using namespace calculate;
using namespace output;

/// <summary>
/// √лавна€ функци€, объ€вл€юща€ переменные и вызывающа€ побочные функции
/// </summary>
int main() {
    setlocale(LC_ALL, "RU");
    unsigned int NumbersTroniks;
    int* Troniks;

    getInput(NumbersTroniks, Troniks);
    int NumberTea = calculateMaxTeapots(NumbersTroniks, Troniks);
    output_data(NumberTea);

    delete[] Troniks;

    return 0;
}
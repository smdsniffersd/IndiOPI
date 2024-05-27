#include "calc.h"

namespace calculate {
    /// <summary>
    /// ‘ункци€ вычислени€ количества пустых отверстий в тройниках.
    /// </summary>
    /// <param name="NumbersTroniks"> Ч unsigned int-ва€ переменна€ количества тройников.</param>
    /// <param name="Troniks"> Ч целочисленный массив количества разъЄмов.</param>
    /// <returns>int-вое значение количества пустых разъЄмов.</returns>
    int calculateMaxTeapots(int NumbersTroniks, int* Troniks) {
        int NumberTea = 0;
        for (int i = 0; i < NumbersTroniks; i++) {
            NumberTea += Troniks[i];
        }
        return NumberTea - (NumbersTroniks - 1);
    }
}
///////////////////////////////////////////////////////////////////////////////
//Написать программу вычисления стоимости покупки с учётом скидки. Скидка в X
//процентов предоставляется, если сумма покупки больше A рублей, в Y процентов-
//если сумма больше B рублей.
//
//В стандартном вводе содержится пять вещественных чисел, разделённых пробелом:
//N, A, B, X, Y (A < B) - где N - исходная стоимость товара. Выведите стоимость
//покупки с учётом скидки.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>


using namespace std;

int main() {
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    if (n > b) {
        n *= (1 - y / 100);
    } else if (n > a) {
        n *= (1 - x / 100);
    }
    cout << n;

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//
// Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней.
// Найдите номера дней (в нумерации с нуля) со значением температуры выше
// среднего арифметического за все N дней.
// Гарантируется, что среднее арифметическое значений температуры является
// целым числом.
//
// Формат ввода
//   Вводится число N, затем N неотрицательных целых чисел — значения
//   температуры в 0-й, 1-й, ... (N−1)-й день.
//
// Формат вывода
//   Первое число K — количество дней, значение температуры в которых выше
//   среднего арифметического. Затем K целых чисел — номера этих дней.
//
// Пример:
//   Ввод:
//   5
//   7 6 3 0 9
//
//   Вывод:
//   3
//   0 1 4
//
///////////////////////////////////////////////////////////////////////////////
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, sum = 0, average;
    cin >> n;
    vector<int> v(n);
    for (int & s : v) {
        cin >> s;
        sum += s;
    }

    average = sum / n;

    vector<int> temperature;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > average) {
            temperature.push_back(i);
        }
    }
    cout << temperature.size() << endl;
    for (const auto& num : temperature) {
        cout << num << " ";
    }
    return 0;
}
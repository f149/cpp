///////////////////////////////////////////////////////////////////////////////
//
//   Задание по программированию: Имена и фамилии — 1
//   Реализуйте класс для человека, поддерживающий историю изменений человеком
//   своих фамилии и имени.
//
//   class Person {
//   public:
//     void ChangeFirstName(int year, const string& first_name) {
//       // добавить факт изменения имени на first_name в год year
//     }
//     void ChangeLastName(int year, const string& last_name) {
//       // добавить факт изменения фамилии на last_name в год year
//     }
//     string GetFullName(int year) {
//       // получить имя и фамилию по состоянию на конец года year
//     }
//   private:
//     // приватные поля
//   };
//
//   Считайте, что в каждый год может произойти не более одного изменения
//   фамилии и не более одного изменения имени. При этом с течением времени
//   могут открываться всё новые факты из прошлого человека, поэтому года́
//   в последовательных вызовах методов ChangeLastName и ChangeFirstName
//   не обязаны возрастать.
//
//   Гарантируется, что все имена и фамилии непусты.
//
//   Строка, возвращаемая методом GetFullName, должна содержать разделённые
//   одним пробелом имя и фамилию человека по состоянию на конец данного года.
//
//   Если к данному году не случилось ни одного изменения фамилии и имени,
//   верните строку "Incognito".
//   Если к данному году случилось изменение фамилии, но не было ни одного
//   изменения имени, верните "last_name with unknown first name".
//   Если к данному году случилось изменение имени, но не было ни одного
//   изменения фамилии, верните "first_name with unknown last name".
//
//  Пример
//   Код
//   int main() {
//     Person person;
//
//     person.ChangeFirstName(1965, "Polina");
//     person.ChangeLastName(1967, "Sergeeva");
//     for (int year : {1900, 1965, 1990}) {
//       cout << person.GetFullName(year) << endl;
//     }
//
//     person.ChangeFirstName(1970, "Appolinaria");
//     for (int year : {1969, 1970}) {
//       cout << person.GetFullName(year) << endl;
//     }
//
//     person.ChangeLastName(1968, "Volkova");
//     for (int year : {1969, 1970}) {
//       cout << person.GetFullName(year) << endl;
//     }
//
//     return 0;
//   }
//
// Вывод
//   Incognito
//   Polina with unknown last name
//   Polina Sergeeva
//   Polina Sergeeva
//   Appolinaria Sergeeva
//   Polina Volkova
//   Appolinaria Volkova
//
// Пояснение
//   В этой задаче вам надо прислать файл с реализацией класса Person.
//   Этот файл не должен содержать функцию main. Если в нём будет функция
//   main, вы получите ошибку компиляции.
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
        firstname[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        lastname[year] = last_name;
    }
    string GetFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year
        string first_name = GetFirstName(year, firstname);
        string last_name = GetLastName(year, lastname);
        string full_name = first_name + " " + last_name;
        if (first_name.size() == 0 && last_name.size() == 0) {
            full_name = "Incognito";
            return full_name;
        } else if (first_name.size() == 0) {
            full_name = last_name + " with unknown first name";
            return full_name;
        } else if (last_name.size() == 0) {
            full_name = first_name + " with unknown last name";
            return full_name;
        }
        return full_name;
    }
private:
    // приватные поля
    string GetFirstName(int year, map<int, string>& firstname) {
        while (firstname.count(year) == 0 && year > 0) {
            --year;
        }
        string first = firstname[year];
        return first;
    }
    string GetLastName(int year, map<int, string>& lastname) {
        while (lastname.count(year) == 0 && year > 0) {
            --year;
        }
        string last = lastname[year];
        return last;
    }

    map<int, string> firstname;
    map<int, string> lastname;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    return 0;
}


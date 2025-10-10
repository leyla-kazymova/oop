// file: src/todo_console.cpp
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

static string trim(const string& s) {  //не записываем пустые/пробельные задачи
    size_t b = 0, e = s.size();
    while (b < e && isspace(static_cast<unsigned char>(s[b]))) ++b;
    while (e > b && isspace(static_cast<unsigned char>(s[e - 1]))) --e;
    return s.substr(b, e - b);
}
//чтение числа с валидацией
static int readInt(const string& prompt, int lo, int hi) { //защищаемся от мусора в вводе
    for (;;) {
        cout << prompt;  //выскакивает подсказка перед чтением
        string line;
        if (!getline(cin, line)) { //удалось ли нам прочитать строку
            cin.clear();
            continue;
        }
        try {          //пробуем найти искл ошибку
                int v = stoi(line);  //разбираем строку лайн как целое число
                if (v >= lo && v <= hi) return v;
        }
        catch (...) { /* игнор */ }
        cout << "Введите число в диапазоне [" << lo << ".." << hi << "].\n";
    }
}
static void printTasks(const vector<string>& tasks) {   //список по константной ссылке
    if (tasks.empty()) {
        cout << "Список пуст.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {  //счётный цикл
        cout << (i + 1) << ". " << tasks[i] << "\n";
    }
}

int main() {     //основа 
    vector<string> tasks;     //динамический массив строк
    for (;;) {
        cout << "\n=== TODO ЛИСТ ===\n"
             << "1. Добавить задачу\n"
             << "2. Удалить задачу\n"
             << "3. Показать все задачи\n"
             << "0. Выйти\n";
        int choice = readInt("Выберите действие: ", 0, 3);

        if (choice == 1) {
            cout << "Введите задачу: ";
            string line;
            if (!getline(cin, line)) {
                cin.clear();
                continue;
            }
            string t = trim(line);
            if (t.empty()) {
                cout << "Пустая задача не добавлена.\n";
            } else {
                tasks.push_back(t);
                cout << "Задача добавлена.\n";
            }
        } else if (choice == 2) {
            if (tasks.empty()) {
                cout << "Нечего удалять — список пуст.\n";
                continue;
            }
            cout << "\nВаши задачи:\n";
            printTasks(tasks);
            int idx = readInt("Номер для удаления: ", 1, static_cast<int>(tasks.size()));
            tasks.erase(tasks.begin() + (idx - 1));
            cout << "Задача удалена.\n";
        }
        else if (choice == 3) {
            cout << "\nВаши задачи:\n";
            printTasks(tasks);
        }
        else if (choice == 0) {
            cout << "До свидания!\n";
            break;
        }
    }
    return 0;
}
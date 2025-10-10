// file: src/todo_console.cpp
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

static string trim(const string& s) { 
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
        try {
            \\пробуем найти искл ошибку
                int v = stoi(line);  \\разбираем строку лайн как целое число
                if (v >= lo && v <= hi) return v;
        }
        catch (...) { /* игнор */ }
        cout << "Введите число в диапазоне [" << lo << ".." << hi << "].\n";
    }
}
static void printTasks(const vector<string>& tasks) {   
    if (tasks.empty()) {
        cout << "Список пуст.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {  
        cout << (i + 1) << ". " << tasks[i] << "\n";
    }
}

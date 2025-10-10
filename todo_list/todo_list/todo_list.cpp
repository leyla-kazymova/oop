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
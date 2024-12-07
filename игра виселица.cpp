#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   
#include "Windows.h"
using namespace std;

// Функция для отображения состояния игры
void displayState(const string& word, const string& guessed)
{
    for (char c : word)
    {
        bool found = false;
        for (char g : guessed)
        {
            if (c == g)
            {
                found = true; // Буква найдена среди угаданных
                break;
            }
        }
        if (found)
        {
            cout << c << " "; // Если буква угадана, показываем её
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}
// Функция для проверки буквы
bool checkGuess(char guess, const string& word, string& guessed)
{
    for (char g : guessed)
    {
        if (g == guess)
        {
            return false; 
        }
    }
    guessed += guess;
    for (char c : word)// Проверяем, есть ли буква в слове
    {
        if (c == guess)
        {
            return true;
        }
    }

    return false;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    string words[] = { "программист", "алгоритм", "компьютер", "виселица", "разработка", "яблоко", "груша", "стол", "программа", "интернет", "телефон", "процессор", "ламинария" };
    srand(time(0));
    string word = words[rand() % (sizeof(words) / sizeof(words[0]))];
    cout << "Добро пожаловать в игру Виселица!" << endl;

    return 0;
}
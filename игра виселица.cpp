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

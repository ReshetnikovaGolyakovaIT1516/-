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
    // Проверяем, была ли уже угадана буква
    for (char g : guessed)
    {
        if (g == guess)
        {
            return false; // Буква уже угадана
        }
    }

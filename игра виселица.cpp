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
bool checkGuess(char guess, const string& word, string& guessed, int& attempts)
{
    for (char g : guessed)
    {
        if (g == guess)
        {
            cout << "Эта буква уже была угадана: " << guess << endl; 
            return false; 
        }
    }
    guessed += guess;
    bool found = false; // Переменная для отслеживания нахождения буквы в слове
    for (char c : word)// Проверяем, есть ли буква в слове
    {
        if (c == guess)
        {
            found = true;
            break;
        }
    }
    if (!found) // Если буква не найдена в слове
    {
        attempts++; // Увеличиваем кол-во попыток если буква не была угадана
    }
    return found; 
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    string words[] = { "программист", "алгоритм", "компьютер", "виселица", "разработка", "яблоко", "груша", "стол", "программа", "интернет", "телефон", "процессор", "ламинария" };
    srand(time(0));
    string word = words[rand() % (sizeof(words) / sizeof(words[0]))];
    int maxAttempts = 6; // макс кол-во попыток
    int attempts = 0; // кол-во неверных попыток
    string guessed; // для хранения угаданных букв
    cout << "Добро пожаловать в игру Виселица!" << endl;
    while (attempts < maxAttempts)
    {
        displayState(word, guessed); // текущее состояние слова
        cout << "Введите букву: ";
        char guess;
        cin >> guess;
        guess = tolower(guess);
        if (!checkGuess(guess, word, guessed, attempts)) // была ли буква угадана 
        {
            cout << "Неправильно! Осталось попыток: " << (maxAttempts - attempts) << endl;
        }
        else
        {
            cout << "Верно!" << endl;
        }
        bool wordGuessed = true;// угадано ли все слово
        for (char c : word)
        {
            bool found = false;
            for (char g : guessed)
            {
                if (c == g)
                {
                    found = true; // найдена в угаданных
                    break;
                }
            }
            if (!found)
            {
                wordGuessed = false; // если хотя бы одна буква не найдена
                break;
            }
        }

        if (wordGuessed)
        {
            cout << "Поздравляем! Вы угадали слово: " << word << endl;
            break;
        }
    }

    if (attempts == maxAttempts)
    {
        cout << "Вы проиграли! Загаданное слово было: " << word << endl;
    }

    return 0;
}
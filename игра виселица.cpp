#include <iostream>
#include <string>
#include <iomanip>
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

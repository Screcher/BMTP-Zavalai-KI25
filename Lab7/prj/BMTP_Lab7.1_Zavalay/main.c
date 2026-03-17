#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>

// Функція для реверсу слова (широкі символи Unicode)
void reverseWord(wchar_t* str) {
    int len = wcslen(str);
    for (int i = 0; i < len / 2; i++) {
        wchar_t temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// Функція відображення Анотації та About (псевдографіка)
void showIntro() {
    wprintf(L"╔══════════════════════════════════════════════════════╗\n");
    wprintf(L"║                  АНОТАЦІЯ ПРОГРАМИ                   ║\n");
    wprintf(L"╠══════════════════════════════════════════════════════╣\n");
    wprintf(L"║ Програма рахує кількість складів 'ку' у слові.       ║\n");
    wprintf(L"║ Якщо склад відсутній — виконує реверс рядка.         ║\n");
    wprintf(L"║ Обов'язкова перевірка символів: '/', '%%' або '$'.    ║\n");
    wprintf(L"╚══════════════════════════════════════════════════════╝\n");

    wprintf(L"\n╔══════════════════════════════════════════════════════╗\n");
    wprintf(L"║                ПРО РОЗРОБНИКА (About)                ║\n");
    wprintf(L"╠══════════════════════════════════════════════════════╣\n");
    wprintf(L"║ Розробник: Завалай Артем                             ║\n");
    wprintf(L"║ Група: КІ-25                                         ║\n");
    wprintf(L"╚══════════════════════════════════════════════════════╝\n\n");
}

int main() {
    // Налаштування Unicode UTF-8 для консолі
    setlocale(LC_ALL, ".UTF8");
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    showIntro();

    // --- ЗАДАЧА 7.1 ---
    wprintf(L"--- ЗАДАЧА 7.1 (Символьна інформація) ---\n");
    wchar_t word[256];
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD read;

    wprintf(L"Введіть слово (має закінчуватись на '/', '%%' або '$'):\n> ");
    ReadConsoleW(hStdin, word, 256, &read, NULL);

    // Видаляємо \r\n (символи Enter)
    while (read > 0 && (word[read - 1] == L'\r' || word[read - 1] == L'\n')) {
        read--;
    }
    word[read] = L'\0';

    if (read == 0) {
        wprintf(L"\nПомилка: порожній ввід.\n");
    } else {
        wchar_t lastChar = word[read - 1];
        // Перевірка символів завершення згідно з Варіантом 7
        if (lastChar != L'/' && lastChar != L'%' && lastChar != L'$') {
            wprintf(L"\nУВАГА: слово має закінчуватися на '/', '%%' або '$'\n");
        } else {
            // Тимчасово прибираємо знак для аналізу тексту
            word[read - 1] = L'\0';

            int count = 0;
            wchar_t *p = word;
            // Пошук складу "ку"
            while ((p = wcsstr(p, L"ку")) != NULL) {
                count++;
                p += 2;
            }

            wprintf(L"\n╔════════════════════════════════════════╗\n");
            if (count > 0) {
                wprintf(L"║  РЕЗУЛЬТАТ: склад 'ку' знайдено %d раз. ║\n", count);
            } else {
                reverseWord(word);
                wprintf(L"║  Склад не знайдено. Реверс: %-10ls ║\n", word);
                wprintf(L"║  Символ завершення: %-18c ║\n", lastChar);
            }
            wprintf(L"╚════════════════════════════════════════╝\n");
        }
    }

    wprintf(L"\nНатисніть Enter для виходу...");
    fflush(stdin);
    getwchar();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>

void showInfo72() {
    wprintf(L"╔══════════════════════════════════════════════════════╗\n");
    wprintf(L"║                  АНОТАЦІЯ ПРОГРАМИ                   ║\n");
    wprintf(L"╠══════════════════════════════════════════════════════╣\n");
    wprintf(L"║ Програма обробляє масив із 16 дійсних чисел.         ║\n");
    wprintf(L"║ Знаходить порядкові номери (індекси + 1)             ║\n");
    wprintf(L"║ найбільшого та найменшого елементів масиву.          ║\n");
    wprintf(L"╚══════════════════════════════════════════════════════╝\n");

    wprintf(L"\n╔══════════════════════════════════════════════════════╗\n");
    wprintf(L"║                ПРО РОЗРОБНИКА (About)                ║\n");
    wprintf(L"╠══════════════════════════════════════════════════════╣\n");
    wprintf(L"║ Розробник: Завалай Артем                             ║\n");
    wprintf(L"║ Група: КІ-25                                         ║\n");
    wprintf(L"╚══════════════════════════════════════════════════════╝\n\n");
}

int main() {
    setlocale(LC_ALL, ".UTF8");
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    showInfo72();

    wprintf(L"--- ЗАДАЧА 7.2 (Обробка масивів) ---\n");
    double arr[16];
    wprintf(L"Введіть 16 дійсних чисел по черзі:\n");

    for (int i = 0; i < 16; i++) {
        wprintf(L"Число №%d: ", i + 1);
        if (wscanf(L"%lf", &arr[i]) != 1) {
            wprintf(L"Помилка: введено не число. Спробуйте ще раз.\n");
            while (getwchar() != L'\n'); // Очищення буфера
            i--;
            continue;
        }
    }

    int minIdx = 0;
    int maxIdx = 0;

    for (int i = 1; i < 16; i++) {
        if (arr[i] < arr[minIdx]) minIdx = i;
        if (arr[i] > arr[maxIdx]) maxIdx = i;
    }

    wprintf(L"\n┌──────────────────────────────────────────────────────┐\n");
    wprintf(L"│                 РЕЗУЛЬТАТ ОБЧИСЛЕНЬ                  │\n");
    wprintf(L"├──────────────────────────────────────────────────────┤\n");
    wprintf(L"│ Порядковий номер НАЙБІЛЬШОГО елемента: %-13d │\n", maxIdx + 1);
    wprintf(L"│ Порядковий номер НАЙМЕНШОГО елемента:  %-13d │\n", minIdx + 1);
    wprintf(L"└──────────────────────────────────────────────────────┘\n");

    wprintf(L"\nНатисніть Enter для виходу...");
    fflush(stdin);
    getwchar(); getwchar();
    return 0;
}

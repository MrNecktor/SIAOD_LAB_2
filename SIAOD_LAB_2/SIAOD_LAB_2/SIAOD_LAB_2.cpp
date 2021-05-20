
#include <iostream>
#include <clocale>
#include <algorithm>
#include<ctime>
//#include <iostream.h>
// #include "stdafx.h"

using namespace std;

const int A = 10;


int fibbonachi(const int arr[], int key, int A)
{
    
    int fibM2 = 0;
    int fibM1 = 1;
    int fibM0 = fibM1 + fibM2;

    while (fibM0 < A)
    {
        fibM2 = fibM1;
        fibM1 = fibM0;
        fibM0 = fibM1 + fibM2;
    }

    int offset = -1;

    while (fibM0 > 1)
    {
        int i = std::min(fibM2 + offset, key - 1);

        if (arr[i] < key)
        {
            fibM0 = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM0 - fibM1;
        }

        else if (arr[i] > key)
        {
            fibM0 = fibM2;
            fibM1 -= fibM2;
            fibM2 = fibM0 - fibM1;
        }
        else
            return i;
    }

    if (offset + 1 < A && arr[offset + 1] == key)
        return offset + 1;

    return -1;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0)));

    bool flag = false;
    int l = 0; // левая граница
    int r = 9; // правая граница
    int min = 0;
    int max = 100;
    int mid;
    int arr[A]; // создали массив на 10 элементов
    int key; // создали переменную в которой будет находиться ключ

    for (int i = 0; i < A; i++)
    {
        arr[i] = rand() % (max - min) + min;
    }

    cout << "Оригтнальный массив: " << endl;
    for (int j = 0; j < A; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;

    sort(arr, arr + 10);
    cout << "Сортированный массив: " << endl;
    for (int j = 0; j < A; j++)
    {
        cout << arr[j] << " ";
    }
    int caseA = 0;



    cout << "Выберите задачу: " << endl << "1. Бинарный поиск"  << endl << "2. Фибоначчиев" << endl << "3. Интерполяционный" << endl;
    cin >> caseA;
    cout << endl;


    switch (caseA)
    {
        case 1:
        {


            

            cout << endl << "Введите ключ: ";

            cin >> key; // считываем ключ



            while ((l <= r) && (flag != true))
            {
                mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

                if (arr[mid] == key) flag = true; //проверяем ключ со серединным элементом
                if (arr[mid] > key) r = mid - 1; // проверяем, какую часть нужно отбросить
                else l = mid + 1;
            }

            if (flag)
            {
                cout << "Индекс элемента " << key << " в массиве равен: " << mid << endl;
            }
            else
            {
                cout << "Извините, но такого элемента в массиве нет" << endl;
            }
            system("pause");
            return 0;
        }

        case 2:
        {
            cout << endl << "Введите ключ: ";
            cin >> key;
            cout << fibbonachi(arr, key, A) << endl;
            
        }
        
        case 3:
        {
            int x = 0;
            bool found;

            cout << endl << "Введите ключ: ";
            cin >> key;
            for (found = false; (arr[l] < key) && (arr[r] > key) && !found; )
            {
                //Вычисление интерполяцией следующего элемента, который будет сравниваться с искомым
                x = l + ((key - arr[l]) * (r - l)) / (arr[r] - arr[l]);
                //Получение новых границ области, если искомое не найдено
                if (arr[x] < key)
                    l = x + 1;
                else if (arr[x] > key)
                    r = x - 1;
                else
                    found = true;
            }

            /************** Конец интерполяции ***************************/

            //Если искомое найдено на границах области поиска, показать на какой границе оно
            if (arr[l] == key)
                cout << key << " founded in element " << l << endl;
            else if (arr[r] == key)
                cout << key << " founded in element " << r << endl;
            else
                cout << "Sorry. Not found" << endl;

            return 0;
        }
        case 4:
        {

        }
    }
}
    



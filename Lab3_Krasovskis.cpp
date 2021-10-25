﻿#define _CRT_SECURE_NO_DEPRECATE 
#include <windows.h> 
#include <cstdio> 
#include <cstdlib> 
#include <ctime> 
#include <iostream>

using namespace std;

#define LIGHTGRAY 7 
#define LIGHTRED  12

int IdentNumb(int A[], int N) { // поиск одинаковых чисел в масиве
	int i;
	for (i = 0; i < N; i++) {  // проверяет все числа == i

		for (int j = i + 1; j < N; j++) { // так же проверяет все числа тоько тепер == j

			if (A[i] == A[j]) // если числа одинаковые возращает значение одинакового числа
			{
				return A[i];
			}
		}
	}
	return 0; // если в массиве нету одинаковых чисел тогда нечего не возращает

}



void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ShowArray(int A[], int N, int IdentNumber) {

	for (int i = 0; i < N; i++) {
		TextColor(A[i] == IdentNumber ? LIGHTRED : LIGHTGRAY); // A[i] == IdentNumbet - это условие чо делает ? Если условие верное, то будет LighRed, в противном случае LightGray. 
		printf("%d ", A[i], i % 10 == 9 ? "\r\n" : " ");
	}
	if (N % 10) printf("\n");
}

int main()
{
	int n, * a; // * показывает значение переменной по заданному адресу
	cout << "Please enter amount of number in array = "; cin >> n;

	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ShowArray(a, n, IdentNumb(a, n));
	return 0;


}


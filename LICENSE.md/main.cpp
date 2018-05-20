/*	Дана бесконечная последовательность случайно расставленных символов из алфавита А [а, b, c].
	Реализовать генератор случайной последовательности из символов А и посчитать количество триад "ааа", "bbb", "ссс".
	Каждые триады считать отдельно	*/
#include <cstdlib>
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

//int rand(); //предобъявление рабочих функций

void main()
{
	vector<char> genarr; //рабочий вектор
	int ABC[3] = { 0,0,0 }; //количество триад

	cout << "Press Enter to stop generating" << endl;

	for(int i = 0; ; i++) //генерация последовательности
	{
		int temp = rand() % 3;
		switch (temp)
		{
		case 0:
			genarr.push_back('a');
			break;
		case 1:
			genarr.push_back('b');
			break;
		case 2:
			genarr.push_back('c');
			break;
		}
		if (GetAsyncKeyState(VK_RETURN) == -32767) break; //завершение генерации при нажатии клавиши Enter на клавиатуре
	}

	cout << "Generation complete" << endl;

	for (int i = 0; i < genarr.size()-2; i++) //подсчет триад
	{
		if ((genarr[i] == genarr[i + 1]) && (genarr[i] == genarr[i + 2]))
		{
			switch (genarr[i])
			{
			case 'a':
				ABC[0]++;
				break;
			case 'b':
				ABC[1]++;
				break;
			case 'c':
				ABC[2]++;
				break;
			}
			i += 3;
		}
	}
	cout << "Sequence length: " << genarr.size() << endl;
	cout << "'a' triads: " << ABC[0] << endl;
	cout << "'b' triads: " << ABC[1] << endl;
	cout << "'c' triads: " << ABC[2] << endl;
	system("PAUSE");
}

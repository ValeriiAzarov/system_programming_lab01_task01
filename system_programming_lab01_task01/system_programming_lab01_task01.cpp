// system_programming_lab01_task01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#define SIZE LLONG_MAX

using namespace std;

int main(INT argc, CHAR** argv)
{
	LPTSTR errorText;

	if (argc != 2) {
		cout << "Invalid number of argument = " << argc << endl;
		return 0;
	}

	if (strcmp(argv[1], "-e") == 0) {
		LocalAlloc(LMEM_MOVEABLE, SIZE);
		DWORD dw = GetLastError();
		FormatMessage(
			// use system message tables to retrieve error text
			FORMAT_MESSAGE_FROM_SYSTEM
			// allocate buffer on local heap for error text
			| FORMAT_MESSAGE_ALLOCATE_BUFFER
			// Important! will fail otherwise, since we're not
			// (and CANNOT) pass insertion parameters
			| FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, dw,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR)&errorText,
			0, NULL);
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << errorText << endl;
		_setmode(_fileno(stdout), _O_U8TEXT);
	}
	else if (strcmp(argv[1], "-s") == 0) {
		SYSTEM_INFO info;
		GetSystemInfo(&info);
		cout << "Hardware information:" << endl;
		cout << "OEM ID = " << info.dwOemId << endl;
		cout << "Number of processors = " << info.dwNumberOfProcessors << endl;
		cout << "Page size = " << info.dwPageSize << endl;
		cout << "Processor type = " << info.dwProcessorType << endl;
		cout << "Minimum application address = " << info.lpMinimumApplicationAddress << endl;
		cout << "Maximum application address = " << info.lpMaximumApplicationAddress << endl;
		cout << "Active processor mask = " << info.dwActiveProcessorMask << endl;
	}
	else {
		cout << "Invalid argument = " << argv[1] << endl;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

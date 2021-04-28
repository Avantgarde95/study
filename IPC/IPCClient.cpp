#include <windows.h>
#include <iostream>

#include "IPCCommon.hpp"

int main() {
	setlocale(LC_ALL, "");

	Data data = {
		Gender::Woman,
		{ 2, 3 },
		"Cindy",
		L"½Åµð"
	};

	std::wcout << "Data: " << data.toString() << "\n";

	HWND hwnd;

	for (;;) {
		hwnd = FindWindow(nullptr, "IPCServer");

		if (hwnd == 0) {
			std::cout << "Server is not running! Press Enter to retry the connection.";
			std::cin.get();
		}
		else {
			break;
		}
	}

	std::cout << "Connected to the server!\n";

	for (;;) {
		std::cout << "Press Enter to send the data.";
		std::cin.get();

		COPYDATASTRUCT copyData;
		copyData.cbData = sizeof(data);
		copyData.dwData = 1;
		copyData.lpData = &data;

		SendMessage(hwnd, WM_COPYDATA, 0, (LPARAM)(&copyData));
		std::cout << "Sent the data\n";
	}

	return 0;
}

#include <windows.h>
#include <iostream>

#include "IPCCommon.hpp"

int main() {
	Data data = Data(
		Gender::Woman,
		Vector(2, 3),
		"Cindy"
	);

	std::cout << "Data: " << data.toString() << "\n";

	HWND hwnd = FindWindow(nullptr, "IPCServer");

	if (hwnd == 0) {
		std::cout << "Server is not running!\n";
		return 0;
	}

	std::cout << "Press Enter to send the data.";
	std::cin.get();

	COPYDATASTRUCT copyData;
	copyData.cbData = sizeof(data);
	copyData.dwData = 1;
	copyData.lpData = &data;

	SendMessage(hwnd, WM_COPYDATA, 0, (LPARAM)(&copyData));
	std::cout << "Sent the data\n";

	return 0;
}

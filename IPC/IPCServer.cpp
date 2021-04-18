// Reference: https://m.blog.naver.com/kavenger/50079778587.

#include <windows.h>
#include <iostream>
#include <sstream>

#include "IPCCommon.hpp"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	if (message == WM_COPYDATA) {
		COPYDATASTRUCT* copyDataAddr = (COPYDATASTRUCT*)lParam;

		if (copyDataAddr->dwData == 1) {
			Data* dataAddr = (Data*)(copyDataAddr->lpData);
			std::stringstream ss;
			ss << "Received the data: " + dataAddr->toString();
			std::string result = ss.str();
			MessageBox(0, result.data(), "Result", MB_OK);
		}

		return 0;
	}
	else if (message == WM_DESTROY) {
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd
) {
	WNDCLASS windowClass;

	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	windowClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	windowClass.hInstance = hInstance;
	windowClass.lpfnWndProc = WndProc;
	windowClass.lpszClassName = "IPCServer";
	windowClass.lpszMenuName = nullptr;
	windowClass.style = 0;

	ATOM atom = RegisterClass(&windowClass);

	if (atom == 0) {
		MessageBox(0, "Failed to register the window class!", "Error", MB_OK);
		return 0;
	}

	HWND hwnd = CreateWindowEx(
		0,
		"IPCServer",
		"IPCServer",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	if (hwnd == 0) {
		MessageBox(0, "Failed to create the window!", "Error", MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	MSG message;

	while (GetMessage(&message, 0, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return 0;
}

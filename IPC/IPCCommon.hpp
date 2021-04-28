#pragma once

#include <sstream>

std::wstring string2wstring(std::string str) {
	std::wstring wstr(str.length(), L' ');
	copy(str.begin(), str.end(), wstr.begin());
	return wstr;
}

struct MyString {
	char data[100];
};

struct MyWString {
	wchar_t data[100];
};

enum class Gender {
	Man,
	Woman
};

struct MyVector {
	int x;
	int y;
};

struct Data {
	Gender gender;
	MyVector vector;
	MyString name;
	MyWString nickname;

	std::wstring toString() const {
		std::wstringstream wss;

		wss
			<< "Gender: " << static_cast<int>(gender)
			<< ", vector: (" << vector.x << ", " << vector.y << ")"
			<< ", name: " << name.data
			<< ", nickname: " << nickname.data;

		return wss.str();
	}
};

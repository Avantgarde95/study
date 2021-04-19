#pragma once

#include <sstream>

std::wstring string2wstring(std::string str) {
	std::wstring wstr(str.length(), L' ');
	copy(str.begin(), str.end(), wstr.begin());
	return wstr;
}

enum class Gender {
	Man,
	Woman
};

class Vector {
public:
	Vector(int x, int y) : m_x(x), m_y(y) {}

	int getX() const { return m_x; }
	int getY() const { return m_y; }

private:
	int m_x;
	int m_y;
};

class Data {
public:
	Data(
		const Gender& gender,
		const Vector& vector,
		const std::string& name,
		const std::wstring& nickname
	) :
		m_gender(gender),
		m_vector(vector),
		m_name(name),
		m_nickname(nickname)
	{
		// Do nothing.
	}

	Gender getGender() const { return m_gender; }
	Vector getVector() const { return m_vector; }
	std::string getName() const { return m_name; }
	std::wstring getNickname() const { return m_nickname; }

	std::wstring toString() const {
		std::wstringstream wss;

		wss
			<< "Gender: " << static_cast<int>(m_gender)
			<< ", vector: (" << m_vector.getX() << ", " << m_vector.getY() << ")"
			<< ", name: " << string2wstring(m_name)
			<< ", nickname: " << m_nickname;

		return wss.str();
	}

private:
	Gender m_gender;
	Vector m_vector;
	std::string m_name;
	std::wstring m_nickname;
};

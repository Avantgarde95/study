#pragma once

#include <sstream>

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
		const std::string& name
	) :
		m_gender(gender),
		m_vector(vector),
		m_name(name)
	{
		// Do nothing.
	}

	Gender getGender() const { return m_gender; }
	Vector getVector() const { return m_vector; }
	std::string getName() const { return m_name; }

	std::string toString() const {
		std::stringstream ss;

		ss
			<< "Gender: " << static_cast<int>(m_gender)
			<< ", vector: (" << m_vector.getX() << ", " << m_vector.getY() << ")"
			<< ", name: " << m_name;

		return ss.str();
	}

private:
	Gender m_gender;
	Vector m_vector;
	std::string m_name;
};

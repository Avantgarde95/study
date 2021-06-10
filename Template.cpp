#include <iostream>
#include <string>

namespace CompileTimeComputation {

template <int N>
constexpr int fibonacci() {
    return fibonacci<N - 1>() + fibonacci<N - 2>();
}

template <>
constexpr int fibonacci<1>() {
    return 1;
}

template <>
constexpr int fibonacci<0>() {
    return 0;
}

void run() {
    constexpr int n = 10;
    std::cout << n << "th fibonacci number: " << fibonacci<n>() << "\n";
}

}

namespace CRTP {

template <typename Derived>
class Singleton {
public:
    static const Derived* getInstance() {
        if (m_instance == nullptr) {
            m_instance = new Derived();
        }

        return m_instance;
    }

private:
    static Derived* m_instance;
};

template <typename Derived>
Derived* Singleton<Derived>::m_instance = nullptr;

class Manager : public Singleton<Manager> {
public:
    Manager() {
        m_status = "Manager is created!";
    }

public:
    const std::string& getStatus() const {
        return m_status;
    }

private:
    std::string m_status;
};

void run() {
    std::cout << Manager::getInstance()->getStatus() << "\n";
}

}

int main() {
    CompileTimeComputation::run();
    CRTP::run();

    return 0;
}

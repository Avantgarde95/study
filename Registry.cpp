#include <Windows.h>
#include <iostream>
#include <string>

int readKey() {
    HKEY hKeyRoot = HKEY_CURRENT_USER;
    LPCSTR lpSubKey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
    DWORD ulOptions = 0;
    REGSAM samDesired = KEY_ALL_ACCESS;
    HKEY hKey;

    LONG openResult = RegOpenKeyEx(
        hKeyRoot,
        lpSubKey,
        ulOptions,
        samDesired,
        &hKey
    );

    if (openResult != ERROR_SUCCESS) {
        std::cout << "Failed to open the key!\n";
        return -2;
    }

    DWORD dwType;
    DWORD value;
    DWORD dwBytes = 100; // Should I initialize this?

    LONG queryResult = RegQueryValueEx(
        hKey,
        "Test",
        0,
        &dwType,
        (BYTE*)&value,
        &dwBytes
    );

    if (queryResult != ERROR_SUCCESS) {
        std::cout << "Failed to query the key!\n";
        return -1;
    }

    std::cout << "Parsed the key: " << value << "\n";
    return value;
}

bool createKey() {
    HKEY hKeyRoot = HKEY_CURRENT_USER;
    LPCSTR lpSubKey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
    DWORD ulOptions = 0;
    REGSAM samDesired = KEY_ALL_ACCESS;
    HKEY hKey;

    LONG openResult = RegOpenKeyEx(
        hKeyRoot,
        lpSubKey,
        ulOptions,
        samDesired,
        &hKey
    );

    if (openResult != ERROR_SUCCESS) {
        std::cout << "Failed to open the key!\n";
        return false;
    }

    char buffer[100];
    DWORD dwOptions = REG_OPTION_NON_VOLATILE;
    DWORD dwDesc;
    DWORD ulReserved = 0;

    LONG createResult = RegCreateKeyEx(
        hKeyRoot,
        lpSubKey,
        ulReserved,
        buffer,
        dwOptions,
        samDesired,
        NULL,
        &hKey,
        &dwDesc
    );
 
    if (createResult != ERROR_SUCCESS) {
        std::cout << "Failed to create the key!\n";
        return false;
    }
    
    std::cout << "Created the key!\n";
    return true;
}

bool writeKey(int value) {
    HKEY hKeyRoot = HKEY_CURRENT_USER;
    LPCSTR lpSubKey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
    DWORD ulOptions = 0;
    REGSAM samDesired = KEY_ALL_ACCESS;
    HKEY hKey;

    LONG openResult = RegOpenKeyEx(
        hKeyRoot,
        lpSubKey,
        ulOptions,
        samDesired,
        &hKey
    );

    if (openResult != ERROR_SUCCESS) {
        std::cout << "Failed to open the key!\n";
        return false;
    }

    DWORD dwOptions = REG_OPTION_NON_VOLATILE;
    DWORD dwDesc;
    DWORD ulReserved = 0;

    RegSetValueEx(
        hKey,
        "Test",
        ulReserved,
        REG_DWORD,
        (BYTE*)&value,
        sizeof(value)
    );

    std::cout << "Wrote the key!\n";
    return true;
}

int main() {
    int previousKey = readKey();
    int newKey;

    if (previousKey < -1) {
        return 0;
    }
    else if (previousKey == -1) {
        if (!createKey()) {
            return 0;
        }

        newKey = 0;
    }
    else {
        newKey = previousKey + 1;
    }

    writeKey(newKey);
    return 0;
}

#include <iostream>
#include <memory>
#include <map>

int main() {
	std::map<std::string, std::shared_ptr<std::string>> nicknameMap;

	nicknameMap["Cindy"] = std::make_shared<std::string>("Girl");
	nicknameMap["Paul"] = std::make_shared<std::string>("Boy");

	std::cout << *nicknameMap["Cindy"] << "\n";

	return 0;
}

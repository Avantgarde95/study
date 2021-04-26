#include <iostream>
#include <memory>
#include <map>

int main() {
	auto cindyNickname = std::make_shared<std::string>("Girl");

	{
		std::map<std::string, std::shared_ptr<std::string>> nicknameMap;

		nicknameMap["Cindy"] = cindyNickname;
		nicknameMap["Paul"] = std::make_shared<std::string>("Boy");

		auto& value1 = nicknameMap["Cindy"];
		std::cout << *value1 << "(Count: " << value1.use_count() << ")\n";
	}

	auto& value2 = cindyNickname;
	std::cout << *value2 << "(Count: " << value2.use_count() << ")\n";

	return 0;
}

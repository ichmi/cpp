#include "utils.hpp"

std::string initPhoneNumber(std::string str) {
	std::string buff;
	std::string::iterator it;
	it = str.begin();

	while (it != str.end() && std::isspace(*it)) {
		it++;
	}

	while (it != str.end() && !std::isspace(*it)) {
		if (!std::isdigit(*it)) {
			return "";
		}
		buff += *it;
		it++;
	}

	if (buff.size() < 9 || buff.size() > 13) {
		return "";
	}

	return buff;
}

std::string initMessage(std::string str) {
	std::string buff;
	std::string::iterator it;
	it = str.begin();

	while (it != str.end() && std::isspace(*it)) {
		it++;
	}

	while (it != str.end()) {
		if (*it == '"' || *it == '\'') {
			return "";
		}

		buff += *it;
		it++;
	}

	return buff;
}

std::string initName(std::string str) {
	std::string buff;
	std::string::iterator it;
	it = str.begin();

	while (it != str.end() && std::isspace(*it)) {
		it++;
	}

	while (it != str.end() && !std::isspace(*it)) {
		if (*it == '-' || std::isalnum(*it)) {
			buff += *it;
		} else if (!std::isalnum(*it)) {
			return "";
		}
		it++;
	}

	return buff;
}

std::string truncateStr(std::string str) {
    if (str.length() > 9) {
        return (str.substr(0, 9) + ".");
	}
    return (str);
}

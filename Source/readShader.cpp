#include <functions.h>
#include <fstream>

std::string readShader(const std::string fileName) {
	std::ifstream file(fileName);
	if (!file) {
		class IncorrectFileName { };
		throw IncorrectFileName();
	}
	return std::string(
		std::istreambuf_iterator<char>(file),
		std::istreambuf_iterator<char>()
	);
}
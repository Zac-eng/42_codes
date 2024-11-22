#include "BitCoin.hpp"

int main(int argc, char* argv[]) {
	BitCoin btc("data.csv");

	if (argc != 2) {
		std::cerr << "please pass a file as an argument" << std::endl;
		return 1;
	}
	if (btc.readDataBase() != 0)
		return 1;
	btc.printPrice(argv[1]);
	return 0;
}

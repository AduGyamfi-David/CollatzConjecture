using namespace std;

#include <iostream>
#include <fstream>

const char* d = "FINE";

void cc(unsigned long n, int *count) {
	// printf("%d\n", *count);

	if (n == 1l) {

	} else if (n % 2 == 0){
		*count += 1;
		cc(n / 2, count);
	} else {
		*count += 1;
		cc((3 * n) + 1, count);
	}
	// printf("%s\n", d);
}

int main(int argc, char const *argv[]) {

	string input = "";
	std::cin >> input;

	unsigned long n = stoi(input);

	int count = 0;

	cc(n, &count);

	printf("\n%d\n", count);

	ofstream MyFile;

	MyFile.open("collatz_numbers.txt", std::ios::app);

	MyFile << to_string(n) + " " + to_string(count) + "\n";

	MyFile.close();

	return 0;
}

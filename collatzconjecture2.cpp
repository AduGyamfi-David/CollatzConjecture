using namespace std;

#include <iostream>
#include <fstream>

const char* d = "FINE";

void print(unsigned long *l, int len) {
	for (int i = 0; i < len; i++) {
		// printf("%lu\n", l[i]);
		std::cout << to_string(l[i]) << '\n';
	}
	// printf("-------%d-------\n\n", len);
	std::cout << "-------" + to_string(len) + "-------\n" << '\n';
}

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



void all_steps(unsigned long *l, int *s) {
	// print(l, *s);

	if (l[(*s) - 1] == 1l) {
		print(l, *s);
		string line;
		fstream listFile;
		listFile.open("lists.txt", ios::in);
		while (getline(listFile, line)) {
			std::cout << line + "\n" << '\n';
		}
		listFile.close();

		listFile.open("lists.txt", ios::app);
		for (int i = 0; i < *s; i++) {
			line += (i == (*s) - 1 ? to_string(l[i]) : to_string(l[i]) + " ");
		}
		line += ", " + to_string(*s);
		listFile << "\n" + line;
		listFile.close();
	} else if (l[(*s) - 1] % 2 == 0){
		*s += 1;
		l = (unsigned long *) realloc(l, (*s) * sizeof(unsigned long));
		l[(*s) - 1] = l[(*s) - 2] / 2;
		// print(l, *s);
		all_steps(l, s);
	} else {
		*s += 1;
		l = (unsigned long *) realloc(l, (*s) * sizeof(unsigned long));
		l[(*s) - 1] = (3 * l[(*s) - 2]) + 1;
		// print(l, *s);
		all_steps(l, s);
	}

}

int main(int argc, char const *argv[]) {

	string input = "";
	std::cin >> input;

	if (input == "l") {

		std::cout << "Enter a number\n";
		string str_val = "";
		std::cin >> str_val;
		unsigned long val = stoi(str_val);

		int steps = 1;
		unsigned long *l = (unsigned long *) calloc(steps, sizeof(unsigned long));
		l[steps - 1] = val;

		printf("\n");
		all_steps(l, &steps);

		// print(l, steps);
	}

	// unsigned long n = stoi(input);
	//
	// int count = 0;
	//
	// cc(n, &count);
	//
	// printf("\n%d\n", count);
	//
	// ofstream MyFile;
	//
	// MyFile.open("collatz_numbers.txt", std::ios::app);
	//
	// MyFile << to_string(n) + " " + to_string(count) + "\n";
	//
	// MyFile.close();

	return 0;
}

// int all_numbers(int n) {
//
//
// }

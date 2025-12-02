#include <fstream>
#include <iostream>

void pt1(std::ifstream &input) {
	std::string strInput{};
	int current = 50;
    int password = 0;
    int rotations = 0;

    while (std::getline(input, strInput)) {
        // L is counter clockwise, R is clockwise.
	    if (strInput[0] == 'L') strInput[0] = '-';
		if (strInput[0] == 'R') strInput[0] = '0';

		rotations = std::stoi(strInput) % 100;
     	current = current + rotations;
        if (current < 0) current += 100;
        if (current > 99) current -= 100;
        if (current == 0) password++;
    }

    std::cout << "Part 1:" << password << '\n';
}

void pt2(std::ifstream &input) {
	std::string strInput{};
	int current = 50;
    int password = 0;
    int rotations = 0;

    while (std::getline(input, strInput)) {
        // L is counter clockwise, R is clockwise.
	    if (strInput[0] == 'L') strInput[0] = '-';
		if (strInput[0] == 'R') strInput[0] = '0';

		rotations = std::stoi(strInput) % 100;
		// Don't want to waste time going round and round
		password += abs( std::stoi(strInput)) / 100;

        while (rotations != 0) {
            if (current == 0) password++;
            if (rotations < 0) {
                if (current == 0) current = 99;
                else current--;
                rotations++;
            }
            if (rotations > 0) {
                if (current == 99) current =  0;
                else current++;
                rotations--;
            }
        }
    }
    std::cout << "Part 2:" << password << '\n';
}

int main() {
    // Part 1
    std::ifstream inf1{ "input.txt" };
    if (!inf1) {
        std::cerr << "Uh oh, the file couldn't be opened for reading\n";
        return 1;
    }
    pt1(inf1);
    inf1.close();

    // Part 2
    std::ifstream inf2{ "input.txt" };
    if (!inf2) {
        std::cerr << "Uh oh, the file couldn't be opened for reading\n";
        return 1;
    }
    pt2(inf2);
    inf2.close();

    return 0;
}

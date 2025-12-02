#include <fstream>
#include <iostream>

void pt1(std::ifstream &input) {
	std::string strInput{};
	int current = 50;
    int password = 0;
    int rotations = 0;
    while (std::getline(input, strInput)) {
	    if (strInput[0] == 'L') strInput[0] = '-';
		if (strInput[0] == 'R') strInput[0] = '0';
		rotations = std::stoi(strInput) % 100;
     	current = current + rotations;
        if (current < 0) current += 100;
        if (current > 99) current -= 100;
        if (current == 0) password += 1;
    }
    std::cout << password << '\n';
}

void pt2(std::ifstream &input) {
	std::string strInput{};
	int current = 50;
    int password = 0;
    int rotations = 0;

    while (std::getline(input, strInput)) {
	    if (strInput[0] == 'L') strInput[0] = '-';
		if (strInput[0] == 'R') strInput[0] = '0';

		rotations = std::stoi(strInput);

        while (rotations != 0) {
        	if(rotations < 0) {
         		current -= 1;
         		rotations += 1;
         	} elif (rotations > 0) {
          		current += 1;

          }
        }
    }
    std::cout << password << '\n';
}

int main() {
    std::ifstream inf{ "test.txt" };
    if (!inf) {
        std::cerr << "Uh oh, the file couldn't be opened for reading\n";
        return 1;
    }

    //pt1(inf);
    pt2(inf);

    inf.close();
    return 0;
}

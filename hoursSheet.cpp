#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream dataFile;
	std::ofstream outFile;
	std::string line;
	std::string insertedFile, outputFile;

	std::cout << "Enter the name of the text file that has the class schedule in it(please include the file extension; ex: thisFile.txt): ";
	std::cin >> insertedFile;
	dataFile.open(insertedFile);
	if (!dataFile.is_open()) std::cout << "That file cannot be found, please restart the program!\n";
	else std::cout << "File opened succesfully!";

	std::cout << "\nNow enter the name that you want the outFile to be called(please include the file extension; ex: thisFile.txt): ";
	std::cin >> outputFile;
	outFile.open(outputFile);

	if (dataFile.is_open()) {
		int i = 0;
		while (getline(dataFile, line)) {
			if (outFile.is_open()) {
				if (line[0] != '<') {
					if (line[0] == '&') outFile << "\t\t\t\t" << line.substr(6) << "\t\t";
					else if (line[0] >= '0' && line[0] <= '9') outFile << line<< "\t\t";
					else {
						if (line.size() >= 8) outFile << line.substr(0, 10) << "\t";
						else if (line == "TBA") {
							if(i == 3 || i == 5) outFile << line << "\t\t\t";
							else outFile << line << "\t\t";
						}
						else outFile << line << "\t\t";
					}
					i++;
				}
				else if (line == "</tr>") {
					outFile << "\n";
					i = 0;
				}
			}
		}
		std::cout << "All done!" << std::endl;
	}
	else std::cout << "Nothing happened!";

	dataFile.close();
	outFile.close();

	return 0;
}

// LoC counter.cpp : Program counts the number of lines of code
//program integrated from https://github.com/aleccaputo/locCounter/blob/master/loc.cpp

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;


int main() {
	string fileName;
	int numLines = 0;
	int totalLines = 0;
	int blank = 0;
	int comments = 0;
	string line;

	cout << "Enter the name of your file with the proper extension (must be .cpp)" << endl;
	cin >> fileName;

	//cout<< fileName;

	int size = fileName.length();
	if (size <= 3) {
		while (size <= 3) {
			cout << "File name is too short or only contains an extension, please use a differnt file \n";
			cout << "Enter the name of your file with the proper extension (must be .cpp)" << endl;
			cin >> fileName;
		}
	}

	if (fileName.substr(size - 4, size) !=".cpp"){
			cout << "Invalid extension, please use .cpp" << endl;
			while (fileName.substr(size - 4, size) != ".cpp") {
				cout << "Enter the name of your file with the proper extension (must be .cpp)" << endl;
				cin >> fileName;
			}
		}
	else if (fileName.substr(size - 4, size) == ".cpp") {	//checks if file ends in .cpp
		ifstream file(fileName);
		while (getline(file, line)) {
			numLines++;
			totalLines++;

			if (line.length() == 0) {						//is line blank?
				blank++;
				numLines--;
			}

			if (line.find("//") == true) {					//is it a comment?
				comments++;
				numLines--;
			}
		}

		cout << "Number of lines in " << fileName << " is: " << totalLines << endl;
		cout << "Net lines of code in " << fileName << " is: " << numLines << endl;
		cout << "Number of comments in " << fileName << " is: " << comments << endl;
		cout << "Number of blank lines in " << fileName << " is: " << blank << endl;
	}	

	return 0;
}


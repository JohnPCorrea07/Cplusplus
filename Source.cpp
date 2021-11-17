#include<iostream>

#include<string>

#include<fstream>

using namespace std;

enum letter_grade { A, A_PLUS, A_MINUS, B, B_PLUS, B_MINUS, C, C_PLUS, C_MINUS, D, D_PLUS, D_MINUS, F };

letter_grade deriveGrade(double average);

string convertToText(letter_grade grade);

int main() {
	
	ifstream inFile("Student_grades.txt");
	ifstream outfile("Final Report");
	if (inFile.fail()) {

		cout << "Unable to open file" << endl;

		return 0;

	}

	string firstName, lastName, SSN;

	double test1, test2, test3, test4, avg;

	cout << "LastName\tFistName\tSSN\t\tTest1\tTest2\tTest3\tTest4\tFinal Grade" << endl;

	while (!inFile.eof()) {

		avg = 0.0;

		inFile >> firstName >> lastName >> SSN >> test1 >> test2 >> test3 >> test4;

		avg = (test1 + test2 + test3 + test4) / 4.0;

		letter_grade l_g = deriveGrade(avg);

		string grade = convertToText(l_g);

		cout << firstName << "\t" << lastName << "\t" << SSN << "\t" << test1 << "\t" << test2 << "\t" << test3 << "\t" << test4 << "\t" << grade << endl;
		
		

	}
	inFile.close();
	return 0;
}

letter_grade deriveGrade(double average) {//convert average grade from a number to a string

	if (average >= 97)
		return A_PLUS;
	else if (average >= 93)
		return A;
	else if (average >= 90)
		return A_MINUS;
	else if (average >= 87)
		return B_PLUS;
	else if (average >= 83)
		return B;
	else if (average >= 80)
		return B_MINUS;
	else if (average >= 77)
		return C_PLUS;
	else if (average >= 73)
		return C;
	else if (average >= 70)
		return C_MINUS;
	else if (average >=67)
		return D_PLUS;
	else if (average >= 63)
		return D;
	else if (average >= 60)
		return D_MINUS;
	else
		return F;
}
string convertToText(letter_grade grade) {// converting bact to grade letters with + and -  signs

	switch (grade) {

	case A_PLUS:
		return "A+";
	case A:
		return "A";
	case A_MINUS:
		return "A-";
	case B_PLUS:
		return "B+";
	case B:
		return "B";
	case B_MINUS:
		return "B-";
	case C_PLUS:
		return "C+";
	case C:
		return "C";
	case C_MINUS:
		return "C-";
	case D_PLUS:
		return "D+";
	case D:
		return "D";
	case D_MINUS:
		return "D-";
	case F:
		return "F";
	}
}

/*
Part B :

#include<iostream>

#include<string>

#include<fstream>

using namespace std;

void processFile(ifstream& inFile, string& word, int& wordCount, int& nonVowelCount);

void displayResult(string word, int wordCount, int nonVowelCount);

int main() {

	string word;

	cout << "Enter word to search in file: ";

	cin >> word;

	ifstream in;

	in.open("paragraph.dat");

	if (in.fail()) {

		cout << "Unable to open file...";

		return 0;

	}

	int wordCount = 0, nonVowelsCount = 0;

	processFile(in, word, wordCount, nonVowelsCount);

	displayResult(word, wordCount, nonVowelsCount);

	return 0;

}

void processFile(ifstream& inFile, string& word, int& wordCount, int& nonVowelCount) {

	string w;

	wordCount = 0;

	nonVowelCount = 0;

	while (!inFile.eof()) {

		inFile >> w;

		if (w == word)

			wordCount++;

		for (int i = 0; i < w.length(); i++) {

			if (w[i] != 'a' && w[i] != 'e' && w[i] != 'i' && w[i] != 'o' && w[i] != 'u' && w[i] != 'A' && w[i] != 'E' && w[i] != 'I' && w[i] != 'O' && w[i] != 'U')

				nonVowelCount++;

		}

	}

}

void displayResult(string word, int wordCount, int nonVowelCount) {

	cout << "Word: " << word << endl;

	cout << "Word Count: " << wordCount << endl;

	cout << "Non Vowel Count: " << nonVowelCount << endl;

}*/

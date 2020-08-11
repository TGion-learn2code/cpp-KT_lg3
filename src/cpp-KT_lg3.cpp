//============================================================================
// Name        : cpp-KT_lg3.cpp
// Author      : Tobias Gion <tgion>
// Version     :
// Copyright   : Your copyright notice
// Description : KT Übungsblatt LG3 - Objektorientierte Programmierung mit C++
//============================================================================

#include <iostream>
#include <array>		// use of modern arrays
#include <fstream>		// file access
#include <string>		// strings
#include <vector>		// vectors

using namespace std;

constexpr size_t N = 3;

//============================================================================
// Aufgabe 1
//============================================================================

/// @brief	saves numbers from user input in an array for later use
/// @param	array<int, N> &numbers: pointer to array to store N numbers
void getNumUser(array<int, N> &numbers) {
	for (long unsigned int i {0}; i < numbers.size(); ++i) {		// changed int to long unsigned int to avoid overflow with big arrays
		cout << "Nummer " << (i + 1) << ": ";
		cin >> numbers[i];
	}
}

//============================================================================
// Aufgabe 1
//============================================================================

/// @brief	uses user inputed numbers from array and checks if modulo 2 returns 0
/// @param	array<int, N> &numbers: pointer to array to read N numbers
void printAbs(array<int, N> &numbers) {
	for (auto n:numbers) {							// for every item in numbers put into n
		if (n % 2 == 0)	cout << n << "\n";				// calculate the modulo (check if number is even)
	}
}

//============================================================================
// Aufgabe 2
//============================================================================

/// @brief	generates some random numbers and writes them to a file
/// @param	string filename: writes to the filename
/// @param	int count: how many random numbers to write
void writeDummyNumbers (string filename, int count) {

	// open file to write some random numbers in it
	ofstream NumFile (filename);

	// seed random generator
	srand(time(0));

	if (NumFile.is_open()) {
		for (int i {0}; i < count; ++i) {
			NumFile << rand() << "\n";
		}
	}
	else {
		cerr << "Konnte Dummy File nicht öffnen.\n";
	}

}

/// @brief	saves numbers from user input in an array into a file
/// @param	array<int, N> &numbers: pointer to array to store N numbers
void getNumFile(array<int, N> &numbers) {

	// Input Filename to read numbers from
	string filename;
	cout << "Bitte geben Sie den Dateinamen zum Lesen der Zahlen ein > ";
	cin >> filename;

	// write dummy numbers file
	// writeDummyNumbers(filename, N);

	// open file to read numbers
	ifstream NumFile (filename);

	// check if file is open
	if (NumFile.is_open())
	{
		// string for getline
		string strGetline;

		for (long unsigned int i {0}; i < numbers.size(); ++i) {	// changed int to long unsigned int to avoid overflow with big arrays
			getline(NumFile, strGetline);				// read a line from file and store it strGetline string
			numbers[i] = stoi(strGetline);				// convert string to integer and store in numbers array
		}
	}
	else {
		cerr << "Konnte Datei nicht öffnen." << endl;
	}
}

//============================================================================
// Aufgabe 2
//============================================================================

/// @brief	uses user inputed numbers from array and checks if modulo 2 returns 0
/// @param	array<int, N> &numbers: pointer to array to read N numbers
void writeAbsFile(array<int, N> &numbers) {

	// Input Filename to write numbers to
	string filename;
	cout << "Bitte geben Sie den Dateinamen zum Schreiben gerader Zahlen ein > ";
	cin >> filename;

	// open file to read numbers
	ofstream NumFile (filename);

	// check if file is open
	if (NumFile.is_open()) {
		for (auto n:numbers) {						// for every item in numbers put into n
			if (n % 2 == 0) NumFile << n << "\n";			// calculate the modulo (check if number is even)
		}
	}
	else {
		cerr << "Konnte Datei " << filename << " nicht öffnen.\n";
	}
}

//============================================================================
// Aufgabe 3
//============================================================================

/// @brief	saves numbers from user input in an array for later use
/// @param	array<int, N> &numbers: pointer to array to store N numbers
void getNumUser_vector(vector<int> &numbers) {
	int i {0};
	int input;

	cout << "Geben Sie bitte Zahlen ein. Eine Null beendet die Eingabe." << endl;
	cin >> input;

	while (input != 0) {							// continue unless user inputs '0'
		cout 	<< "Nummer "
			<< ++i
			<< "-> "
			<< input
			<< endl;

		numbers.push_back(input);					// put user input into vector with push_back
		cin >> input;
	}
}
//============================================================================
// Aufgabe 3
//============================================================================

/// @brief	uses user inputed numbers from array and checks if modulo 2 returns 0
/// @param	vector<int> &numbers: pointer to array to read numbers
void printAbs_vector(vector<int> &numbers) {
	for (auto n:numbers) {							// for every item in numbers put into n
		if (n % 2 == 0)	cout << n << "\n";				// calculate the modulo (check if number is even)
	}
}

int main() {
	array<int, N> numbers;
	vector<int> numbers_vector;

	//============================================================================
	// Aufgabe 1
	//============================================================================
	//getNumUser(numbers);
	//printAbs(numbers);

	// 1.4 - Falsche Übung ???


	//============================================================================
	// Aufgabe 2
	//============================================================================
	//getNumFile(numbers);
	//writeAbsFile(numbers);

	//============================================================================
	// Aufgabe 2
	//============================================================================
	getNumUser_vector(numbers_vector);
	printAbs_vector(numbers_vector);

	return 0;
}

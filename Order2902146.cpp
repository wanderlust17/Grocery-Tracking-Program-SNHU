// Order2902146.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Python.h>
#include <conio.h>
#include <Windows.h>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>
#include <iterator>
#include <vector>
#include <algorithm>
#include <sstream>

#pragma warning(disable : 4996)

using namespace std;

vector<int> Vector;
string line;

void histochart(int max);
int main()
{
	char filename[] = "groceryTracker.py";
	FILE* fp;

	Py_Initialize();

	fp = _Py_fopen(filename, "r");
	PyRun_SimpleFile(fp, filename);

	cout << fp << endl;
    cout << "Chart drawing program ( Histogram) \n";
    cout << "Enter the series of values from above in order to draw your histogram. \n";
    cout << "Seperate with a space, press <ENTER> TWICE to end input \n";
    cout << " (e.g  2 3 4 5 6)  >  ";

    if (!getline(cin, line)) return 1;
    istringstream iss(line);

    copy(istream_iterator<int>(iss), istream_iterator<int>(), back_inserter(Vector));

    copy(Vector.begin(), Vector.end(), ostream_iterator<int>(cout, ", "));

    cout << "\nDrawing chart.. \n\n";

    histochart(Vector.size());


    cout << "Press enter key to close.\n\n";
    cin.ignore(); cin.get();

}

void histochart(int max) {
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < Vector[i]; j++)  cout << "*";
        cout << endl;
    }
}
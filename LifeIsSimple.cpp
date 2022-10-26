// https://www.codeabbey.com/index/task_view/life-is-simple


#include <iostream>
#include <vector>
#include <string>

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION "0.1"

using namespace std;

int main()
{
	cout << "LifeIsSimple v" << VERSION << "!\n\n";
	string path = "Test.txt";
	//string path = "Try.txt";
	vector<string> raw_data = loadData(path);
	//printVector(raw_data);
	const int ROW = 5;
	const int COL = 7;
	const int TURNS = 5;

	vector<vector<string>> data(ROW, vector<string>(COL, ""));
	for (int r = 0; r < raw_data.size(); r++) {
		vector<string> row = splitString(raw_data[r]);
		data.at(r) = row;
	}
	print2DVector(data);
}

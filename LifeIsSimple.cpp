// https://www.codeabbey.com/index/task_view/life-is-simple


#include <iostream>
#include <vector>
#include <string>

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION "1.0"
#define ROW 5
#define COL 7

using namespace std;

vector<vector<string>> performTurn(vector<vector<string>>& inputData);
int countNB(vector<vector<string>>& inputData, int x, int y);
int countLife(vector<vector<string>>& inputData);

int main()
{
	cout << "LifeIsSimple v" << VERSION << "!\n\n";
	string path = "Test.txt";
	//string path = "Try.txt";
	vector<string> raw_data = loadData(path);
	const int TURNS = 5;

	vector<vector<string>> data(ROW, vector<string>(COL, ""));
	for (int r = 0; r < raw_data.size(); r++) {
		vector<string> row = splitString(raw_data[r]);
		data.at(r) = row;
	}

	print2DVector(data);

	vector<int> solution;
	for (int t = 0; t < TURNS; t++) {
		data = performTurn(data);
		print2DVector(data);
		solution.push_back(countLife(data));
	}
	cout << "Solution: " << joinVector(solution, " ") << endl;;
}

int countLife(vector<vector<string>>& inputData) {
	int life = 0;
	for (int x = 0; x < inputData.size(); x++) {
		for (int y = 0; y < inputData[x].size(); y++) {
			if (inputData[x][y] == "X") life++;
		}
	}
	return life;
}

vector<vector<string>> performTurn(vector<vector<string>>& inputData) {
	vector<vector<string>> data(ROW, vector<string>(COL, "-"));

	for (int x = 0; x < inputData.size(); x++) {
		for (int y = 0; y < inputData[x].size(); y++) {
			int NB = countNB(inputData, x, y);
			if (inputData[x][y] == "X") {
				if (NB == 2 || NB == 3) {
					data[x][y] = "X";
				}
			}
			else if (inputData[x][y] == "-") {
				if (NB == 3) {
					data[x][y] = "X";
				}
			}
		}
	}
	return data;
}

int countNB(vector<vector<string>>& inputData, int x, int y) {
	int NB = 0;
	int XR, YC;
	for (int r = -1; r <= 1; r++) {
		XR = x + r;
		if (XR < 0 || XR >= ROW) continue;
		for (int c = -1; c <= 1; c++) {
			if (r == 0 && c == 0) continue;
			YC = y + c;
			if (YC < 0 || YC >= COL) continue;
			if (inputData[XR][YC] == "X") {
				NB++;
			}
		}
	}
	return NB;
}

#pragma once
#ifndef CONSOLE
#define CONSOLE

void printArray(int* data, int lenght);
void printVector(std::vector<int>& vct);
void printVector(std::vector<std::string>& vct);
void print2DVector(std::vector<std::vector<int>>& vct);
void print2DVector(std::vector<std::vector<std::string>>& vct);
void print2DVector(std::vector<std::vector<char>>& vct);

#endif // !CONSOLE

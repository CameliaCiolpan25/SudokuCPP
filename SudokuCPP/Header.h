#pragma once
#include<iostream>
#include <random>
#include <ctime>
#include <fstream>
using namespace std;

class SudokuCPP {
private:
	int** a;
	int dificultate;
public:
	SudokuCPP(int);
	~SudokuCPP();
	void Random();
	void Numere();
	bool check(int, int, int);
	void ajutor(int, int);
	void rezolva();
	friend ostream& operator<<(ostream&, const SudokuCPP&);
};
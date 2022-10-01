#include"Header.h"

SudokuCPP::SudokuCPP(int dificultate) {
	this->dificultate = dificultate;
	this->a = new (nothrow) int* [dificultate];
	if (this->a == nullptr) {
		cout << "Alocare esuata" << endl;
		exit(1);
	}
	for (int i = 0; i < dificultate; i++) {
		this->a[i] = new(nothrow)int[dificultate];
		if (this->a[i] == nullptr) {
			cout << "Alocare esuata" << endl;
			exit(1);
		}
	}
	if (this->dificultate == 3) {
		ifstream reader("D3.txt");
		for (int i = 0; i < this->dificultate; i++) {
			for (int j = 0; j < this->dificultate; j++) {
				reader >> a[i][j];
			}
		}
		reader.close();
	}
	if (this->dificultate == 6) {
		ifstream reader("D6.txt");
		for (int i = 0; i < this->dificultate; i++) {
			for (int j = 0; j < this->dificultate; j++) {
				reader >> a[i][j];
			}
		}
		reader.close();
	}
	if (this->dificultate == 9) {
		ifstream reader("D9.txt");
		for (int i = 0; i < this->dificultate; i++) {
			for (int j = 0; j < this->dificultate; j++) {
				reader >> a[i][j];
			}
		}
		reader.close();
	}
}

SudokuCPP::~SudokuCPP() {
	for (int i = 0; i < this->dificultate; i++) {
		delete[] this->a[i];
	}
	delete[] this->a;
}

void SudokuCPP::Random() {
	int* v = new (nothrow) int[this->dificultate];
	if (v == nullptr) {
		cout << "Alocare esuata" << endl;
		exit(1);
	}
	int* col = new (nothrow)int[this->dificultate];
	if (col == nullptr) {
		cout << "Alocare esuata" << endl;
		exit(1);
	}
	mt19937 generator;
	generator.seed(time(0));
	if (this->dificultate == 3) {
		uniform_int_distribution<uint32_t> dice(0, 2);
		int row1 = dice(generator);
		int row2 = dice(generator);
		int col1 = dice(generator);
		int col2 = dice(generator);
		for (int i = 0; i < this->dificultate; i++) {
			v[i] = a[row1][i];
			col[i] = a[i][col1];
		}
		for (int i = 0; i < this->dificultate; i++) {
			a[row1][i] = a[row2][i];
			a[row2][i] = v[i];
			a[i][col1] = a[i][col2];
			a[i][col2] = col[i];
		}
	}
	else if (this->dificultate == 6) {
		uniform_int_distribution<uint32_t> dice(0, 5);
		int row1 = dice(generator);
		int row2 = dice(generator);
		int col1 = dice(generator);
		int col2 = dice(generator);

		for (int i = 0; i < this->dificultate; i++)
		{
			v[i] = a[row1][i];
			col[i] = a[i][col1];
		}
		for (int i = 0; i < this->dificultate; i++)
		{
			a[row1][i] = a[row2][i];
			a[row2][i] = v[i];
			a[i][col1] = a[i][col2];
			a[i][col2] = col[i];
		}
	}
	else if (this->dificultate == 9)
	{
		uniform_int_distribution<uint32_t> dice(0, 8);
		int row1 = dice(generator);
		int row2 = dice(generator);
		int col1 = dice(generator);
		int col2 = dice(generator);

		for (int i = 0; i < this->dificultate; i++)
		{
			v[i] = a[row1][i];
			col[i] = a[i][col1];
		}
		for (int i = 0; i < this->dificultate; i++)
		{
			a[row1][i] = a[row2][i];
			a[row2][i] = v[i];
			a[i][col1] = a[i][col2];
			a[i][col2] = col[i];
		}
	}
}

void SudokuCPP::Numere() {
	mt19937 g;
	g.seed(time(0));
	if (this->dificultate == 3) {
		uniform_int_distribution<uint32_t> dice(0, 2);
		ofstream out("O3.txt");
		for (int i = 0; i < this->dificultate; i++) {
			for (int j = 0; j < this->dificultate; j++) {
				if (j == dice(g) || i == dice(g)) {
					out << "_ ";
					cout << "_ ";
					a[i][j] = 0;
				}
				else {
					out << a[i][j] << " ";
					cout << a[i][j] << " ";
				}
			}
			out << endl;
			cout << endl;
		}
		out.close();
	}
	else if (this->dificultate == 6) {
		uniform_int_distribution<uint32_t> dice(0, 5);
		ofstream out("O6.txt");
		for (int i = 0; i < this->dificultate; i++) {
			for (int j = 0; j < this->dificultate; j++) {
				if (j == dice(g) || i == dice(g)) {
					out << "_ ";
					cout << "_ ";
					a[i][j] = 0;
				}
				else {
					out << a[i][j] << " ";
					cout << a[i][j] << " ";
				}
			}
			out << endl;
			cout << endl;
		}
		out.close();
	}
	else if(this->dificultate==9){
		uniform_int_distribution<uint32_t> dice(0, 8);
		ofstream out("O9.txt");
		for (int i = 0; i < this->dificultate; i++) {
			for (int j = 0; i < this->dificultate; j++) {
				if (j == dice(g) || i == dice(g)) {
					out << "_ ";
					cout << "_ ";
					a[i][j] = 0;
				}
				else {
					out << a[i][j] << " ";
					cout << a[i][j] << " ";
				}
			}
			out << endl;
			cout << endl;
		}
		out.close();
	}
}

bool SudokuCPP::check(int p, int i, int j) {
	for (int k = 1; k <= 9; k++) {
		if (a[i][k] == p)
			return false;
	}
	for (int k = 1; k <= 9; k++) {
		if (a[k][j] == p)
			return false;
	}
	if ((j == 1 || j == 4 || j == 7) && (i == 1 || i == 4 || i == 7))
	{
		if (a[i][j + 1] == p || a[i][j + 2] == p || a[i + 1][j] == p ||
			a[i + 2][j] == p || a[i + 1][j + 1] == p || a[i + 1][j + 2] == p ||
			a[i + 2][j + 1] == p || a[i + 2][j + 2] == p)return false;
	}

	if ((j == 1 || j == 4 || j == 7) && (i == 3 || i == 6 || i == 9))
	{
		if (a[i - 1][j] == p || a[i - 2][j] == p || a[i][j + 1] == p ||
			a[i][j + 2] == p || a[i - 1][j + 1] == p || a[i - 1][j + 2] == p ||
			a[i - 2][j + 1] == p || a[i - 2][j + 2] == p)return false;
	}

	if ((j == 1 || j == 4 || j == 7) && (i == 2 || i == 5 || i == 8))
	{
		if (a[i - 1][j] == p || a[i + 1][j] == p || a[i - 1][j + 1] == p ||
			a[i][j + 1] == p || a[i + 1][j + 1] == p || a[i + 1][j + 2] == p ||
			a[i][j + 2] == p || a[i + 1][j + 2] == p)return false;
	}

	if ((j == 2 || j == 5 || j == 8) && (i == 1 || i == 5 || i == 7))
	{
		if (a[i - 1][j] == p || a[i + 1][j] == p || a[i - 1][j + 1] == p ||
			a[i][j + 1] == p || a[i + 1][j + 1] == p || a[i + 1][j + 2] == p ||
			a[i][j + 2] == p || a[i + 1][j + 2] == p)return false;
	}

	if ((j == 2 || j == 5 || j == 8) && (i == 2 || i == 5 || i == 8))
	{
		if (a[i - 1][j] == p || a[i - 1][j - 1] == p || a[i - 1][j + 1] == p ||
			a[i][j + 1] == p || a[i][j - 1] == p || a[i + 1][j + 1] == p ||
			a[i][j] == p || a[i + 1][j - 1] == p)return false;
	}

	if ((j == 2 || j == 5 || j == 8) && (i == 3 || i == 6 || i == 9))
	{
		if (a[i][j - 1] == p || a[i][j + 1] == p || a[i - 1][j] == p ||
			a[i - 1][j + 1] == p || a[i - 1][j - 1] == p || a[i - 2][j] == p ||
			a[i - 1][j + 1] == p || a[i - 2][j - 1] == p) return false;
	}

	if ((j == 3 || j == 6 || j == 9) && (i == 1 || i == 4 || i == 7))
	{
		if (a[i][j - 1] == p || a[i][j - 2] == p || a[i + 1][j] == p ||
			a[i + 1][j - 1] == p || a[i + 1][j - 2] == p || a[i + 2][j] == p ||
			a[i + 2][j - 1] == p || a[i + 2][j - 2] == p) return false;
	}

	if ((j == 3 || j == 6 || j == 9) && (i == 2 || i == 5 || i == 8))
	{
		if (a[i - 1][j] == p || a[i - 1][j - 1] == p || a[i - 1][j - 2] == p ||
			a[i][j - 1] == p || a[i][j - 2] == p || a[i + 1][j] == p ||
			a[i + 1][j - 1] == p || a[i + 1][j - 2] == p) return false;
	}

	if ((j == 3 || j == 6 || j == 9) && (i == 3 || i == 6 || i == 9))
	{
		if (a[i][j - 1] == p || a[i - 1][j] == p ||
			a[i - 1][j - 1] == p || a[i - 1][j - 2] == p || a[i - 2][j] == p ||
			a[i - 2][j - 1] == p || a[i - 2][j - 2] == p) return false;
	}
	return true;
}

void SudokuCPP::ajutor(int i, int j) {
	if (j <= 0) {
		i = i - 1;
		j = 9;
	}
	if (a[i][j] == 0)
		return ajutor(i, j - 1);
	for(int p = 1; p <= 9; p++) {
		if (check(p, i, j)) {
			a[i][j] = p;
			return;
		}
	}
	return ajutor(i, j - 1);
}

void SudokuCPP::rezolva() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (a[i][j] == 0) {
				ajutor(i, j);
			}
		}
	}

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (a[i][j] == 0) ajutor(i, j);
		}
	}
}

ostream& operator<<(ostream& out, const SudokuCPP& A)
{
	for (int i = 0; i < A.dificultate; i++)
	{
		for (int j = 0; j < A.dificultate; j++)
		{
			out << A.a[i][j] << " ";
		}
		out << endl;
	}
	return out;
}
void PrintMessage(string message, bool printTop = true, bool printBottom = true)
{
	if (printTop)
	{
		cout << "+---------------------------------+" << endl;
		cout << "|";
	}
	else
	{
		cout << "|";
	}
	bool front = true;
	for (int i = message.length(); i < 33; i++)
	{
		if (front)
		{
			message = " " + message;
		}
		else
		{
			message = message + " ";
		}
		front = !front;
	}
	cout << message.c_str();

	if (printBottom)
	{
		cout << "|" << endl;
		cout << "+---------------------------------+" << endl;
	}
	else
	{
		cout << "|" << endl;
	}
}


int main() {
	SudokuCPP S(3);
	PrintMessage("Sudoku");
	S.Random();
	PrintMessage("Sudoku Random",false);
	cout << S;
	S.Numere();
	PrintMessage("Sudoku unsolved");
	cout << S;
	S.rezolva();
	PrintMessage("Sudoku solved");
	system("pause");
}
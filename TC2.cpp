
//-----------------------------------------------------------------STATUS WIP(Work in progress) ver 0.3-------------------------------------------------------------------------------
#include <iostream>
using namespace std;
void createBlackField(int, int, int(*)[5]);
class Figure
{
public:
	int icon[5][5];
	Figure(int coordY, int coordX, int(*icon)[5]) {
		this->coordX = coordX;
		this->coordY = coordY;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++)
			{
				this->icon[i][j] = icon[i][j];
			}
		}
	};
	
	Figure() {
		coordX = -1;
		coordY = -1;
		createBlackField(5, 5, this->icon);
	};
	void printObject()
	{
		cout << "coordX =" << coordX << endl;
		cout << "coordY =" << coordY << endl;
		cout << "the icon" << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
				cout << (char)this->icon[i][j];
			cout << endl;
		}
	}
	void setXCord(int coordX) { this->coordX = coordX; };
	int getXCord() { return coordX; };
	void setYCord(int coordY) { this->coordY = coordY; };
	int getYCord() { return coordY; };
private:
	int coordX;
	int coordY;
};
class Board {
public:


	Board() {
		// TODO: выписать все методы создания и передать соответствующие переменные(массивы 5х5)
		createFigureBlack(5, 5, shaskaBlack);
		createFigureKingBlack(5,5, damkaWhite);//
		createFigureKingWhite(5, 5, damkaBlack);//
		createBlackField(5, 5, blackField);
	}




private:
	int massiveForTable[49][49];
	Figure figureStore[24];
	int shaskaBlack[5][5];
	int shaskaWhite[5][5];
	int damkaWhite[5][5];
	int damkaBlack[5][5];
	int blackField[5][5];
	void createFigureBlack(int nlines, int ncol, int(*figure)[5]);
	void createFigureKingBlack(int nlines, int ncol, int(*figure)[5]);
	void createFigureKingWhite(int nlines, int ncol, int(*figure)[5]);
	void createBlackField(int nlines, int ncol, int(*figure)[5]);
	void createFigureWhite(int nlines, int ncol, int(*figure)[5]);
	void printFigure(int nlines, int ncol, int(*figure)[5]);
	void fillingAxis(int nlines, int ncol, int(*newField)[49]);
	void makeSymbols(int nlines, int ncol, int(*newField)[49]);
	void setFieldsToSharps(int ncol, int nlines, int(*newField)[49]);
	void fillingNumAndLetters(int nlines, int ncol, int(*newField)[49]);
	void printField(int ncol, int nlines, int(*newField)[49]);
	void setFigure(int ncolB, int nlinesB, int(*bigMassive)[49], int ncolS, int nlinesS, int(*smallMassive)[5], int x, int y);
	void convertCords(char x, int y, int(*figure)[5]);
	void removeFigure(Figure F1, int(*blackField)[5]);
	void moveFigure(Figure F1, int x, int y, int(*blackField)[5]);
	void placeFigureOnBoard();
};
void Board::placeFigureOnBoard() {



}


void Board::createFigureBlack(int nlines, int ncol, int(*figure)[5]) {
	for (int i = 0; i < ncol; i++)
	{
		for (int j = 0; j < nlines; j++)
		{
			figure[i][j] = 177;
			if (i == 0) figure[i][j] = 178;
			if (i == 4) figure[i][j] = 178;
			if (j == 0) figure[i][j] = 178;
			if (j == 4) figure[i][j] = 178;
			if (i == 2) figure[i][2] = 178;
		}
	}
}

void Board::createFigureKingBlack(int nlines, int ncol, int(*figure)[5]) {
	for (int i = 0; i < ncol; i++)
	{
		for (int j = 0; j < nlines; j++)
		{
			figure[i][j] = 177;
			if (i == 0) figure[i][j] = 178;
			if (i == 4) figure[i][j] = 178;
			if (j == 0) figure[i][j] = 178;
			if (j == 4) figure[i][j] = 178;
		}
	}

}

void Board::createFigureKingWhite(int nlines, int ncol, int(*figure)[5]) {
	for (int i = 0; i < ncol; i++)
	{
		for (int j = 0; j < nlines; j++)
		{
			figure[i][j] = 176;
			if (i == 0) figure[i][j] = 178;
			if (i == 4) figure[i][j] = 178;
			if (j == 0) figure[i][j] = 178;
			if (j == 4) figure[i][j] = 178;
		}
	}

}

void Board::createBlackField(int nlines, int ncol, int(*figure)[5]) {
	for (int i = 0; i < ncol; i++)
	{
		for (int j = 0; j < nlines; j++)
			figure[i][j] = 178;
	}
}

void Board::createFigureWhite(int nlines, int ncol, int(*figure)[5]) {
	for (int i = 0; i < ncol; i++)
	{
		for (int j = 0; j < nlines; j++)
		{
			figure[i][j] = 176;
			if (i == 0) figure[i][j] = 178;
			if (i == 4) figure[i][j] = 178;
			if (j == 0) figure[i][j] = 178;
			if (j == 4) figure[i][j] = 178;
			if (i == 2) figure[i][2] = 178;
		}
	}

}
void Board::printFigure(int nlines, int ncol, int(*figure)[5]) {
	for (int i = 0; i < nlines; i++)
	{
		for (int j = 0; j < ncol; j++)
		{
			cout << (char)figure[i][j];
		}
		cout << endl;
	}

}



void Board::fillingAxis(int nlines, int ncol, int(*newField)[49]) {
	for (int i = 0; i < nlines; i++)
	{
		for (int j = 0; j < ncol; j++)
		{
			if (j % 6 == 0) newField[i][j] = '#';//столбец

			if (i % 6 == 0) newField[i][j] = '#';
		}
	}
}
void Board::makeSymbols(int nlines, int ncol, int(*newField)[49]) {
	int k = 490;
	int s = 48;
	for (int i = 0; i < nlines; i++)
	{
		for (int j = 0; j < ncol; j++)
		{
			if (j == 0)
			{
				newField[0][0] = ' ';
				newField[i][j] = k--;
			}
			if (j == 11) {
				newField[11][0] = ' ';
				if (s == 58) s = ' ';
				if (s == 33) s = ' ';
				if (s == 34) s = ' ';
				if (i >= 1) newField[11][i] = s++;
			}
		}
	}
}
void Board::setFieldsToSharps(int ncol, int nlines, int(*newField)[49]) {
	for (int i = 0; i < ncol; i++)
	{
		for (int j = 0; j < nlines; j++)
		{
			newField[i][j] = ' ';
			if ((j / 6) % 2 == 0 || (i / 6) % 2 == 0) newField[i][j] = 178;//столбец
			if ((j / 6) % 2 == 0 && (i / 6) % 2 == 0) newField[i][j] = ' ';
		}
	}
}
void Board::fillingNumAndLetters(int nlines, int ncol, int(*newField)[49]) {
	int numNum = 56;
	int symbolNum = 65;
	for (int i = 0; i < nlines; i++)
	{
		for (int j = 0; j < ncol; j++)
		{
			if (j == 0 && numNum > 48 && i % 6 == 0)
			{
				newField[i + 3][j] = numNum;
				newField[i + 3][ncol - 1] = numNum--;
			}
			if (i == 0 && j % 6 == 0 && symbolNum < 73)
			{
				newField[i][j + 3] = symbolNum;
				if (j < ncol - 1) newField[nlines - 1][j + 3] = symbolNum++;
			}
		}
	}
};
void Board::printField(int ncol, int nlines, int(*newField)[49]) {
	for (int i = 0; i < ncol; i++)
	{
		for (int j = 0; j < nlines; j++)
		{
			cout << (char)newField[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void Board::setFigure(int ncolB, int nlinesB, int(*bigMassive)[49], int ncolS, int nlinesS, int(*smallMassive)[5], int x, int y) {
	for (int i = y; i < ncolB; i++)
	{
		for (int j = x; j < nlinesB; j++)
		{
			if (i < y + ncolS && j < x + nlinesS)
			{
				bigMassive[i][j] = smallMassive[i - y][j - x];
			}
		}
	}
}

void placeFiguresInStPos(int ncol, int lines, int(*masiveFigure)[5]) {

}
void Board::convertCords(char x, int y, int(*figure)[5]) {
	int first = (int)x - 64;//TO DO
	int second = (int)y - 64;
}
void Board::removeFigure(Figure F1, int(*blackField)[5]) {

	setFigure(49, 49, massiveForTable, 5, 5,blackField, 5, 5);

}
void Board::moveFigure(Figure F1,int x ,int y,int(*blackField)[5]) {
	removeFigure(F1,blackField);
}

int main()
{
	int mFT[49][49];
	/*createFigureBlack(5, 5, shaskaBlack);
	printFigure(5, 5, shaskaBlack);
	createFigureWhite(5, 5, shaskaWhite);
	printFigure(5, 5, shaskaWhite);
	createFigureKingBlack(5, 5, damkaBlack);
	printFigure(5, 5, damkaBlack);
	createFigureKingWhite(5, 5, damkaWhite);
	printFigure(5, 5, damkaWhite);
	makeSymbols(49, 49, mFT);
	createBlackField(5, 5, blackField);*/
	/*setFieldsToSharps(49, 49, mFT);
	fillingAxis(49, 49, mFT);
	fillingNumAndLetters(49, 49, mFT);*/
	//convertCords(5, 5, damkaWhite);//!!
	//setFigure(49, 49, mFT, 5, 5, shaskaWhite, 1, 1);//!!
	//printFigure(5, 5, damkaWhite);//!!
	/*printField(49, 49, mFT);*/
	/*setFigure(49, 49, mFT, 5, 5, shaskaWhite, 7, 1);*/
	//printField(49, 49, mFT);
	
	/*placeFiguresInStPos(5, 5, shaskaBlack);
	Figure figure(1, 1, shaskaWhite);
	figure.printObject();
	figureStore[0] = figure;
	return 0;*/
}

#include <iostream>
#include <list>

using namespace std;

class Constants {
public:
	static const int CHESSBOARD_LENGTH = 10;
};

class Figure : Constants
{
private:
	int PosX;
	int PosY;
	// 0 - white, 1 - black
	bool color;
	char rank;
	char value;
public:
	Figure(){}
	void SetValue(int value)
	{
		this->value = value;
	}
	int GetValue()
	{
		return value;
	}
	void SetRank(char rank)
	{
		this->rank = rank;
	}
	void SetColor(bool color)
	{
		this->color = color;
	}
	Figure(char rank)
	{
		// b-слон, r-ладья, n-конь
		if (rank == 'p' || rank == 'k' || rank == 'b' || rank == 'r' || rank == 'n' || rank == 'q')
		{
			color = 0;
			this->rank = rank;
			return;
		}
		if (rank == 'P' || rank == 'K' || rank == 'B' || rank == 'R' || rank == 'N' || rank == 'Q')
		{
			color = 1;
			this->rank = rank;
			return;
		}

		cout << "Wrong rank set" << endl;

	}
	char GetRank()
	{
		return rank;
	}
	bool GetColor()
	{
		return color;
	}

	void SetPos(int x, int y)
	{
		if (x >= 1 && x < CHESSBOARD_LENGTH - 1)
		{
			PosX = x;
		}
		else {
			cout << "Wrong x set" << endl;
		}
		if (y >= 1 && y < CHESSBOARD_LENGTH - 1)
		{
			PosY = y;
		}
		else {
			cout << "Wrong y set" << endl;
		}
	}
	int GetPosX()
	{
		return PosX;
	}
	int GetPosY()
	{
		return PosY;
	}


};

class Chessboard : public Constants
{
private:
	// Y, X
	char Cells[CHESSBOARD_LENGTH][CHESSBOARD_LENGTH];
	void ClearCells() 
	{
		for (int i = 0; i < CHESSBOARD_LENGTH; i++)
		{
			for (int j = 0; j < CHESSBOARD_LENGTH; j++)
			{
				Cells[j][i] = ' ';
			}
		}
	}
public:
	void PutMark(char value, int x, int y)
	{
		if (value >= '1' && value <= '9')
		{
			Cells[y][x] = value;
		}
	}

	void ClearFromMarks()
	{
		for (int i = 1; i < CHESSBOARD_LENGTH - 1; i++)
		{
			for (int j = 1; j < CHESSBOARD_LENGTH - 1; j++)
			{
				if (Cells[i][j] >= '1' && Cells[i][j] <= '9')
				{
					Cells[i][j] = ' ';
				}
			}
		}
	}
	Chessboard() 
	{
		ClearCells();
		char a = 'a';
		char numeric = '1';
		// заполняем границы
		for (int i = 1; i < CHESSBOARD_LENGTH-1; i++)
		{
			Cells[0][i] = a;
			Cells[CHESSBOARD_LENGTH - 1][i] = a;
			Cells[i][0] = numeric;
			Cells[i][CHESSBOARD_LENGTH - 1] = numeric;
			numeric++;
			a++;
		}
		
	}
	bool isEmpty(int x, int y)
	{
		if (x > 0 && x < CHESSBOARD_LENGTH - 1 && y > 0 && y < CHESSBOARD_LENGTH - 1)
		{
			if (Cells[y][x] == ' ')
			{
				return true;
			}
		}
		else {
			cout << "Wrong pos set in the isEmpty method" << endl;
		}
		return false;
	}

	void PutOn(Figure f)
	{
		int x = f.GetPosX();
		int y = f.GetPosY();
		if (isEmpty(x, y)) 
		{
			Cells[y][x] = f.GetRank();
		}
	}
	

	void Show() {
		for (int i = 0; i < CHESSBOARD_LENGTH; i++)
		{
			for (int j = 0; j < CHESSBOARD_LENGTH; j++)
			{
				cout << Cells[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

};

class Pawn : public Figure
{
public:
	Pawn(char rank){
		SetValue('1');
		if (rank == 'p')	
		{
			SetColor(0);
			SetRank(rank);
			return;
		}
		if (rank == 'P')
		{
			SetColor(1);
			SetRank(rank);
			return;
		}
		
	}
	void ShowTarget(Chessboard& c, list<Figure> figures)
	{
		int x = GetPosX();
		int y = GetPosY();
		list<Figure>::iterator i;
		if (GetColor() == 0)
		{
			if (!c.isEmpty(x-1, y-1))
			{
				for (i = figures.begin(); i != figures.end(); ++i)
				{
					if (i->GetColor() != 0 && i->GetPosX() == x - 1 && i->GetPosY() == y - 1)
					{
						c.PutMark(GetValue(), x - 1, y - 1);
					}
				}
			}
			if (!c.isEmpty(x + 1, y - 1))
			{
				for (i = figures.begin(); i != figures.end(); ++i)
				{
					if (i->GetColor() != 0 && i->GetPosX() == x + 1 && i->GetPosY() == y - 1)
					{
						c.PutMark(GetValue(), x + 1, y - 1);
					}
				}
			}
		}
	}

};



void main() {
	// 0 - white
	// small - white
	list<Figure> figures;

	Chessboard c;
	c.Show();
	Pawn p('p'), P('P');
	p.SetPos(5, 7); 
	P.SetPos(3, 2);
	Pawn P2('P');
	P2.SetPos(4, 6);
	c.PutOn(P2);
	c.PutOn(p);
	c.PutOn(P);
	c.Show();
	figures.push_front(P2);
	figures.push_front(p);
	figures.push_front(P);
	p.ShowTarget(c, figures);
	c.Show();
	system("pause");
}
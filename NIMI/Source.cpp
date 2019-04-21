#include<iostream>
#include<string>
#include <iomanip>
#include<cmath>
using namespace std;


void SetParameters(int&, bool&); //parameter beallito
void Tabla(int, char[]);
void TablaKiirat(char[], int);
void GepKorje(char[], int&, int);
void JatekosKorje(char[], int&, int);





int main()
{
	int pieces, size, piecesSlection = 0;
	char GamePieces[20];
	bool  COMPUTER_TURN = false;


	SetParameters(pieces, COMPUTER_TURN);
	size = pieces - 1;
	Tabla(pieces, GamePieces);
	//TablaKiirat(GamePieces, pieces);
	do
	{
		if (COMPUTER_TURN == true)
		{
			GepKorje(GamePieces, piecesSlection, pieces);
			TablaKiirat(GamePieces, pieces);
			COMPUTER_TURN = false;
		}
		else
		{
			JatekosKorje(GamePieces, piecesSlection, size);
			TablaKiirat(GamePieces, pieces);
			COMPUTER_TURN = true;
		}
	} while (GamePieces[0] != '_');
	//cout << "Nyertel!" << endl;
	return 0;
}


void GepKorje(char GamePieces[], int& piecesChoice, int pieces)
{
	int computerMove = piecesChoice + 1;
	cout << endl << endl << "OK, MOST EN JOVOK!" << endl;
	if (computerMove <= pieces && GamePieces[computerMove] != '_')
		GamePieces[computerMove] = '_';
}


void JatekosKorje(char GamePieces[], int& piecesSel, int size)
{
	char answer, count = 0;

	cout << "Most te josz! Melyik szamot akarod?";
	do {
		cin >> piecesSel;
		count = count++;
		if (piecesSel > size || GamePieces[piecesSel] == '_')
		{
			do
			{
				cout << "Ez egy helytelen lepes \n";
				cout << "Kerlek irj be mas szamot \n";
				cin >> piecesSel;


			} while (piecesSel > size || GamePieces[piecesSel] == '_');
		}
		GamePieces[piecesSel] = '_';
		cout << "Akarsz megegyet kivenni? \n";
		cin >> answer;
		if (answer == 'i'&&count < 3 || answer == 'I'&&count < 3)
			cout << "Ird be,hogy melyik szamot akarod kivenni\n";
		if (count > 2)
			cout << "Elerted a maximalis megengedett szamot. Maximalisan 3-at valaszthatsz egy korben" << endl;
	} while (answer == 'i'&&count < 3 || answer == 'I'&&count < 3);
}


void Tabla(int pieces, char GamePieces[])
{
	for (int i = 0; i < pieces; i++)

		GamePieces[i] = 'o';

}


void SetParameters(int& pieces, bool& COMPUTER_TURN)
{
	char answer;
	cout << "Udvozollek a NIM jatekban!" << endl << endl;
	do
	{

		cout << "Hany szammal szeretned jatszani a jatekot?" << endl;
		cin >> pieces;
		if (pieces < 5 || 20 < pieces)

			cout << "Csak 5 es 20 kozotti szamot valaszthatsz." << endl << endl;

	} while (pieces < 5 || 20 < pieces);

	cout << "Akarsz te kezdeni? (I/N)";
	cin >> answer;
	if (answer == 'i' || answer == 'I')
	{
		cout << "Rendben,kezdjel." << endl;
		COMPUTER_TURN = false;
	}


	else
	{
		COMPUTER_TURN = true;
		cout << "OK, akkor kezdek en." << endl;
	}


}



void TablaKiirat(char GamePieces[], int pieces)
{
	cout << endl << endl << "Ez a jelenlegi allas:" << endl << endl;

	for (int i = 0; i < pieces; i++)
		cout << left << setw(3) << i;
	cout << endl;
	for (int i = 0; i < pieces; i++)
		cout << setw(2) << GamePieces[i] << ' ';
	cout << endl;


}
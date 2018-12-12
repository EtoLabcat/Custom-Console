// DrawableConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "ConsoleWindow.h"
#include <math.h>
#include <time.h>
#include "Vector2.h"
#include "Board.h"
#include <stdlib.h> 
#include <string>

#include <windows.h>
#include <conio.h>
#include <fstream>
#include "AI.h"
const int windowHeight = 15;
const int windowWidth = 30;
const string dir = "BrainFiles\\";
ConsoleWindow window(windowHeight);

bool isScene = true;
int XWins = 0;
int OWins = 0;
int Draws = 0;

int generations = 0;
bool foundPath = false;
using namespace std;
// TRIANGLE GENERATION
vector<string> Split(string a_String, char splitter)
{
	int arraySize = 1;
	for (int i = 0; i < a_String.length(); i++)
	{
		if (a_String[i] == splitter)
		{
			arraySize++;
		}
	}
	vector<string> splitString(arraySize);
	int arrayNo = 0;
	while (arrayNo < arraySize - 1)
	{
		for (int i = 0; i < a_String.length(); i++)
		{
			if (a_String[i] == splitter)
			{
				splitString[arrayNo] = a_String.substr(0, i);
				a_String = a_String.substr(i + 1, a_String.length() - i);
				arrayNo++;
				break;
			}
		}
	}
	splitString[arraySize - 1] = a_String;
	return splitString;
}


void generateTriangle()
{
	window.ClearWindow(true);
	for (int i = 0; i < windowHeight; i++)
	{
		for (int j = 0; j < windowWidth; j++)
		{
			window.addToLine(j, " ", WHITE);
		}
	}
	Vector2 pointA(3, 7);
	Vector2 pointB(7, 7);
	Vector2 pointC(7, 2);
	window.setTextAtPoint(pointA, "*", WHITE);
	window.setTextAtPoint(pointB, "*", WHITE);

	window.setTextAtPoint(pointC, "*", WHITE);

	// SETTING LINES
	for (int i = pointA.getX() + 1; i < pointB.getX(); i++)
	{
		window.setTextAtPoint(Vector2(i, 7), "-", WHITE);
	}
	for (int i = pointC.getY() + 1; i < pointB.getY(); i++)
	{
		window.setTextAtPoint(Vector2(7, i), "|", WHITE);
	}
	for (int i = pointA.getY() - 1, x = pointA.getX(); i > pointC.getY(); i--, x++)
	{
		window.setTextAtPoint(Vector2(x,i), "/", WHITE);
	}
	window.setLine(10, "Hypotenuse Is " + to_string(sqrtf(powf(pointA.distance(pointB),2) + powf(pointB.distance(pointC), 2))) + " Units! (Assumption)", WHITE);
	window.setLine(11, "Area Is " + to_string(0.5 * pointA.distance(pointB) * pointB.distance(pointC)) + " Units^2! (Assumption)", WHITE);
	window.writeConsole();
}

void TicTacToe(bool isAIp1, bool isAIp2, int offset, string OBrain, string XBrain)
{
	// INITIALIZE THE WINDOW FOR USAGE
	window.ClearWindow(true);
	for (int i = 0; i < windowHeight; i++)
	{
		for (int j = 0; j < windowWidth; j++)
		{
			window.addToLine(j, " ", WHITE);
		}
	}

	// 15 LOGIC : https://www.braingle.com/brainteasers/teaser.php?op=2&id=5388&comm=0

	// CREATE THE 9 BOARD PIECES, EACH WITH A VALUE (HAS TO BE IN THIS ORDER FOR THE 15 LOGIC)
	vector<BoardPiece> pieces = {
		BoardPiece(Vector2(0,0), 4), BoardPiece(Vector2(1,0), 3), BoardPiece(Vector2(2,0), 8),
		BoardPiece(Vector2(0,1), 9), BoardPiece(Vector2(1,1), 5), BoardPiece(Vector2(2,1), 1),
		BoardPiece(Vector2(0,2), 2), BoardPiece(Vector2(1,2), 7), BoardPiece(Vector2(2,2), 6),
	};

	// CREATE THE BOARD, TARGET VALUE OF 15, MAX 9 TURNS
	Board ticTacToeBoard(pieces, 15, 9);
	for (int i = 0; i < ticTacToeBoard.getBoard().size(); i++)
	{
		window.setTextAtPoint(ticTacToeBoard.getBoard()[i].getPos().offset(offset), "*", WHITE);
	}

	// DRAW THE BOARD ON THE TERMINAL
	window.writeConsole();

	// SET UP THE VARIABLES
	string user = "X";
	bool isGameWon = false;
	int turns = 0;
	ColourClass colour = GREEN;
	AI OAI(OBrain);
	AI XAI(XBrain);
	string boardString;
	// GAME LOOP
	while (!isGameWon && turns < ticTacToeBoard.getMaxTurns())
	{
		string input;
		// AI TURN IF AI IS ON
		if (user == "O" && isAIp2)
		{
			if (!isAIp1 || !isAIp2)
			{
				window.setLine(10, "AI's Turn", WHITE);
				window.ClearWindow(false);
				window.writeConsole();
				//system("pause");
			}

			// NEURAL NETWORK
			boardString = "";
			for (int i = 0; i < ticTacToeBoard.getBoard().size(); i++)
			{
				boardString += ticTacToeBoard.getBoard()[i].getOccupier();
				if (i != ticTacToeBoard.getBoard().size() - 1)
				{
					boardString += ',';
				}
				else
				{
					boardString += ";";
				}
			}
			// CHECKS IF ALREADY KNOWS A WINNING MOVE
			Vector2 actualChoice = OAI.bestMove(boardString);
			input = to_string(actualChoice.getX()) + "," + to_string(actualChoice.getY());
		}

		else if (user == "X" && isAIp1)
		{
			if (!isAIp1 || !isAIp2)
			{
				window.setLine(10, "AI's Turn", WHITE);
				window.ClearWindow(false);
				window.writeConsole();
				system("pause");
			}

			// NEURAL NETWORK
			boardString = "";
			for (int i = 0; i < ticTacToeBoard.getBoard().size(); i++)
			{
				boardString += ticTacToeBoard.getBoard()[i].getOccupier();
				if (i != ticTacToeBoard.getBoard().size() - 1)
				{
					boardString += ',';
				}
				else
				{
					boardString += ";";
				}
			}
			// CHECKS IF ALREADY KNOWS A WINNING MOVE
			Vector2 actualChoice = XAI.bestMove(boardString);
			input = to_string(actualChoice.getX()) + "," + to_string(actualChoice.getY());
		}

		// IF NOT AN AI TURN, USER INPUTS A CO-ORDINATE TO PLACE THEIR MARKER
		else
		{
			cin >> input;
		}
		// CO-ORDINATE IS THEN SPLIT TO MAKE A VECTOR 2
		vector<string> command = Split(input, ',');
		// MAKE SURE NOT AN INCORRECT SIZE
		if (command.size() == 2)
		{
			Vector2 choice = Vector2(stoi(command[0]), stoi(command[1]));
			// CHECK IF THE PIECE IS ON THE BOARD
			if (ticTacToeBoard.pieceExists(choice))
			{
				// THEN CHECK IF IT'S ALREADY OCCUPIED
				if (ticTacToeBoard.getPieceAt(choice).getOccupier() == " ")
				{
					// IF NOT OCCUPIED, OCCUPY THE SPOT, THEN RE-PRINT THE CONSOLE WITH THE MARKER PLACED
					ticTacToeBoard.setOccupierAt(choice, user);
					window.setTextAtPoint(choice.offset(offset), user, colour);
					// CHECK TO SEE IF A WINNING MOVE HAS BEEN MADE
					isGameWon = ticTacToeBoard.checkWinner(user);
					if (isGameWon)
					{
						if (user == "O")
						{
							OWins++;
						}
						else if (user == "X")
						{
							XWins++;
						}
						if (user == "O" && isAIp2)
						{
							if (OAI.existingMove(boardString, choice))
							{
								window.setLine(11, user + " Won By Using It's Memory Of A Winning Move", WHITE);
								window.ClearWindow(false);
								window.writeConsole();
								//system("pause");
							}
							else
							{
								OAI.addWinMove(boardString, choice);
							}
						}
						else if(user == "X" && isAIp1)
						{
							if (XAI.existingMove(boardString, choice))
							{
								window.setLine(11, user + " Won By Using It's Memory Of A Winning Move", WHITE);
								window.ClearWindow(false);
								window.writeConsole();
								//system("pause");
							}
							else
							{
								XAI.addWinMove(boardString, choice);
							}
						}
						window.setLine(12, user + " Wins The Game!", WHITE);
					}
					// ADD A TURN
					turns++;
					if (turns >= ticTacToeBoard.getMaxTurns() && !isGameWon)
					{
						if (user == "O" && isAIp2)
						{
							if (OAI.existingMove(boardString, choice))
							{
								window.setLine(11, user + " Already Knew A Draw Was Inevitable", WHITE);
								window.ClearWindow(false);
								window.writeConsole();
								//system("pause");
							}
							else
							{
								OAI.addWinMove(boardString, choice);
							}
						}
						if (user == "X" && isAIp1)
						{
							if (XAI.existingMove(boardString, choice))
							{
								window.setLine(11, user + " Already Knew A Draw Was Inevitable", WHITE);
								window.ClearWindow(false);
								window.writeConsole();
								//system("pause");
							}
							else
							{
								XAI.addWinMove(boardString, choice);
							}
						}
						Draws++;
					}
					// SWAP USERS
					if (user == "X") {
						user = "O";
						colour = YELLOW;
					}
					else {
						user = "X";
						colour = GREEN;
					};
				}
			}
		}
		window.clearLine(10);
		window.ClearWindow(false);
		window.writeConsole();
		if (isAIp1 && isAIp2)
		{
			Sleep(25);
		}
	}
	// IF TURNS UP AND NO WINNERS, GAME IS DRAWN
	if (!isGameWon)
	{
		window.setLine(12, "Drawn Game!", WHITE);
		window.ClearWindow(false);
		window.writeConsole();
	}
}

void generateart()
{
	int asciiArt = rand() % 3;
	window.ClearWindow(true);
	switch (asciiArt)
	{
	case 0:
		window.setLine(0, "WINDOWS LOGO", WHITE);
		window.setLine(1, "             _.-;;-._ ", WHITE);
		window.setLine(2, "      '-..-'|   ||   |", WHITE);
		window.setLine(3, "      '-..-'|_.-;;-._|", WHITE);
		window.setLine(4, "      '-..-'|   ||   |", WHITE);
		window.setLine(5, "      '-..-'|_.-''-._|", WHITE);
		break;
	case 1:
		window.setLine(0, "PAINTBRUSH", WHITE);
		window.setLine(1, "              .------------------....___       ", YELLOW);
		window.setLine(2, "             /                      /  /'''---", YELLOW);
		window.setLine(3, "             \\                      \\__\\...---", YELLOW);
		window.setLine(4, "              '------------------''''           ", YELLOW);

		window.addToLine(1, ",;;", WHITE);
		window.addToLine(1, ";,", RED);
		window.addToLine(2, "/;;;;", WHITE);
		window.addToLine(2, ";;,.,", RED);
		window.addToLine(3, "\\;;;;", WHITE);
		window.addToLine(3, ";;;", RED);
		window.addToLine(4, "``", WHITE);
		window.addToLine(4, "``", RED);
		break;
	default:
		window.setLine(0, "WINDOWS LOGO ", WHITE); window.addToLine(0, "R", RED); window.addToLine(0, "A", YELLOW); window.addToLine(0, "I", GREEN); window.addToLine(0, "N", BLUE); window.addToLine(0, "B", PURPLE); window.addToLine(0, "O", RED); window.addToLine(0, "W", YELLOW);
		window.setLine(1, "             _.-;;-._", PURPLE);
		window.setLine(2, "      '-..-'|   ||   |", RED);
		window.setLine(3, "      '-..-'|_.-;;-._|", YELLOW);
		window.setLine(4, "      '-..-'|   ||   |", BLUE);
		window.setLine(5, "      '-..-'|_.-''-._|", GREEN);
		break;
	}
	window.writeConsole();

}


void scene1()
{
	window.ClearWindow(true);
	// DRAW THE POLICE OFFICER
	window.setLine(0, "                ,", WHITE);
	window.setLine(1, "       __  _.-'` `'-.", WHITE);
	window.setLine(2, "      /||\\'._ __{}_(", WHITE);
	window.setLine(3, "      ||||  |'--.__\\", WHITE);
	window.setLine(4, "      |  L.(   ^_\\^", WHITE);
	window.setLine(5, "      \\ .-' |   _ |", WHITE);
	window.setLine(6, "      | |   )\\___/", WHITE);
	window.setLine(7, "      |  \\-'`:._]", WHITE);
	window.setLine(8, "      \\__/;      '-.", WHITE);
	window.setLine(9, "      |   |o     __ \\", WHITE);
	window.setLine(10, "      |   |o     )( |", WHITE);
	window.setLine(11, "      |   |o     \\/ \\", WHITE);
	window.setLine(13, "POLICE OFFICER: STOP!! YOU HAVE VIOLATED THE LAW", AQUA);

	window.writeConsole();
}

void scene2()
{
	// DRAW THE COMPUTER GUY
	window.ClearWindow(true);
	window.setLine(2, "             __    __", WHITE);
	window.setLine(3, "            /  \\ /| |'-.", WHITE);
	window.setLine(4, "           .\\__/ || |   |", WHITE);
	window.setLine(5, "        _ /  `._ \\|_|_.-'", WHITE);
	window.setLine(6, "       | /  \\__.`=._) (_", WHITE);
	window.setLine(7, "       |/ ._/  |''''''''' | ", WHITE);
	window.setLine(8, "       |'.  `\\ |         |", WHITE);
	window.setLine(9, "       ;'''/ / |         |", WHITE);
	window.setLine(10, "        ) /_/| |.-------.|", WHITE);
	window.setLine(11, "       '  `-`' '         '", WHITE);
	window.setLine(13, "Player: Man computer graphics sure are", YELLOW);
	window.setLine(14, "impressive these days! ", YELLOW);
	window.writeConsole();
}

void scene3()
{
	window.ClearWindow(true);
	window.setLine(2, "             __    __", WHITE);
	window.setLine(3, "            /  \\ /| |'-.", WHITE);
	window.setLine(4, "           .\\__/ || |   |", WHITE);
	window.setLine(5, "        _ /  `._ \\|_|_.-'", WHITE);
	window.setLine(6, "       | /  \\__.`=._) (_", WHITE);
	window.setLine(7, "       |/ ._/  |''''''''' | ", WHITE);
	window.setLine(8, "       |'.  `\\ |         |", WHITE);
	window.setLine(9, "       ;'''/ / |         |", WHITE);
	window.setLine(10, "        ) /_/| |.-------.|", WHITE);
	window.setLine(11, "       '  `-`' '         '", WHITE);
	window.setLine(13, "Player: I thought I was being arrested", YELLOW);
	window.setLine(14, "in real life! ", YELLOW);
	window.writeConsole();
}
void scene4()
{
	window.ClearWindow(false);
	window.addLayerToLine(10, "Gang Weed", GREEN, '@', 14);
	window.clearLine(13);
	window.clearLine(14);
	window.writeConsole();
}

void scenes()
{
	scene1();
	system("pause");
	scene2();
	system("pause");
	scene3();
	system("pause");
	scene4();
}
void Test()
{
	window.ClearWindow(true);
	//window.setLine(0, "The quick brown fox jumped over the lazy dog", TESTCOLOUR);
	window.writeConsole();

}

// FOR GETTING ALL COMBOS
void outputVar()
{
	ifstream newFile("NoCombo.txt", ios::binary | ios::in);
	ofstream moveFile("NoCombo.txt");
	for (int a = 0; a < 3; a++)
	{
		string varA;
		switch (a)
		{
		case 0:
			varA = " ";
			break;
		case 1:
			varA = "X";
			break;
		default:
			varA = "O";
			break;
		}
		for (int b = 0; b < 3; b++)
		{
			string varB;
			switch (b)
			{
			case 0:
				varB = " ";
				break;
			case 1:
				varB = "X";
				break;
			default:
				varB = "O";
				break;
			}
			for (int c = 0; c < 3; c++)
			{
				string varC;
				switch (c)
				{
				case 0:
					varC = " ";
					break;
				case 1:
					varC = "X";
					break;
				default:
					varC = "O";
					break;
				}
				for (int d = 0; d < 3; d++)
				{
					string varD;
					switch (d)
					{
					case 0:
						varD = " ";
						break;
					case 1:
						varD = "X";
						break;
					default:
						varD = "O";
						break;
					}
					for (int e = 0; e < 3; e++)
					{
						string varE;
						switch (e)
						{
						case 0:
							varE = " ";
							break;
						case 1:
							varE = "X";
							break;
						default:
							varE = "O";
							break;
						}
						for (int f = 0; f < 3; f++)
						{
							string varF;
							switch (f)
							{
							case 0:
								varF = " ";
								break;
							case 1:
								varF = "X";
								break;
							default:
								varF = "O";
								break;
							}
							for (int g = 0; g < 3; g++)
							{
								string varG;
								switch (g)
								{
								case 0:
									varG = " ";
									break;
								case 1:
									varG = "X";
									break;
								default:
									varG = "O";
									break;
								}
								for (int h = 0; h < 3; h++)
								{
									string varH;
									switch (h)
									{
									case 0:
										varH = " ";
										break;
									case 1:
										varH = "X";
										break;
									default:
										varH = "O";
										break;
									}
									for (int i = 0; i < 3; i++)
									{
										string varI;
										switch (i)
										{
										case 0:
											varI = " ";
											break;
										case 1:
											varI = "X";
											break;
										default:
											varI = "O";
											break;
										}
										moveFile << varA << "," << varB << "," << varC << "," << varD << "," << varE << "," << varF << "," << varG << "," << varH << "," << varI << ";\n";
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
void drawBrain(string AIBrain)
{
	for (int i = 0; i < windowHeight; i++)
	{
		for (int j = 0; j < windowWidth; j++)
		{
			window.addToLine(j, " ", WHITE);
		}
	}
	vector<BoardPiece> pieces = {
		BoardPiece(Vector2(0,0), 4), BoardPiece(Vector2(1,0), 3), BoardPiece(Vector2(2,0), 8),
		BoardPiece(Vector2(0,1), 9), BoardPiece(Vector2(1,1), 5), BoardPiece(Vector2(2,1), 1),
		BoardPiece(Vector2(0,2), 2), BoardPiece(Vector2(1,2), 7), BoardPiece(Vector2(2,2), 6),
	};
	AI brain(AIBrain);
	int ii = 0;
	int max = brain.getBrainSize();
	while (ii < max)
	{
		for (int y = 1; y < 10; y = y + 4)
		{
			for (int x = 1; x < 10; x = x + 4)
			{
				Board ticTacToeBoard(pieces, 15, 9);
				vector<string> board = brain.returnBoard(ii);
				int k = 0;
				for (int j = 0; j < 3; j++)
				{
					for (int jj = 0; jj < 3; jj++)
					{
						bool print = true;
						string occupier = board[k];
						if (occupier[0] == '\n' || occupier[0] == '\r')
						{
							if (occupier.size() > 0)
							{
								occupier = occupier[1];
							}
							else
							{
								jj--;
								print = false;
							}
						}
						if (occupier == " ")
						{
							occupier = "*";
						}
						if (print)
						{
							window.setTextAtPoint(Vector2(jj + x, j + y), occupier, WHITE);
							k++;
						}
					}
				}
				vector<string> winningMove = brain.returnWinningMove(ii);
				if (winningMove.size() > 1)
				{
					Vector2 move(stoi(winningMove[0]), stoi(winningMove[1]));
					window.setTextAtPoint(move + Vector2(x, y), "*", BRIGHTRED);
				}
				ii++;
				if (ii >= max)
				{
					window.ClearWindow(false);
					window.writeConsole();
					return;
				}
			}
		}
		window.ClearWindow(false);
		window.writeConsole();
		system("pause");
		window.ClearWindow(true);
		for (int l = 0; l < windowHeight; l++)
		{
			for (int m = 0; m < windowWidth; m++)
			{
				window.addToLine(m, " ", WHITE);
			}
		}
	}
}

void playTicTacToe()
{
	int gameNO = 0;
	int gamesMax = 5;
	while (gameNO < gamesMax || gamesMax <= 0)
	{
		TicTacToe(false, true, 1, dir + "AIBrainO.txt", dir + "AIBrainX.txt"); //AI Boolean, Offset On Board's Position
		gameNO++;
		system("pause");
	}
	window.ClearWindow(false);
	window.setLine(10, " X Wins : " + to_string(XWins) + ", O Wins : " + to_string(OWins) + ", Draws : " + to_string(Draws), BRIGHTWHITE);
	window.writeConsole();
}
// NODE PATH
void nodePath()
{
	// CREATE A BOARD
	// DECLARE THE BOARD WITH VECTORS & VALUES
	// 1 = Path
	// 2 = Finish Node
	// 0 = Wall
	vector<BoardPiece> pieces = {
	BoardPiece(Vector2(0,0), 1), BoardPiece(Vector2(1,0), 0), BoardPiece(Vector2(2,0), 1), BoardPiece(Vector2(3,0), 1), BoardPiece(Vector2(4,0), 1), BoardPiece(Vector2(5,0), 0),  BoardPiece(Vector2(6,0), 1), BoardPiece(Vector2(7,0), 1), BoardPiece(Vector2(8,0), 1), BoardPiece(Vector2(9,0), 0), BoardPiece(Vector2(10,0), 1), BoardPiece(Vector2(11,0), 1), BoardPiece(Vector2(12,0), 1), BoardPiece(Vector2(13,0), 0),
	BoardPiece(Vector2(0,1), 1), BoardPiece(Vector2(1,1), 0), BoardPiece(Vector2(2,1), 1), BoardPiece(Vector2(3,1), 0), BoardPiece(Vector2(4,1), 1), BoardPiece(Vector2(5,1), 0),  BoardPiece(Vector2(6,1), 1), BoardPiece(Vector2(7,1), 0), BoardPiece(Vector2(8,1), 1), BoardPiece(Vector2(9,1), 0), BoardPiece(Vector2(10,1), 1), BoardPiece(Vector2(11,1), 0), BoardPiece(Vector2(12,1), 1), BoardPiece(Vector2(13,1), 0),
	BoardPiece(Vector2(0,2), 1), BoardPiece(Vector2(1,2), 0), BoardPiece(Vector2(2,2), 1), BoardPiece(Vector2(3,2), 0), BoardPiece(Vector2(4,2), 1), BoardPiece(Vector2(5,2), 0),  BoardPiece(Vector2(6,2), 1), BoardPiece(Vector2(7,2), 0), BoardPiece(Vector2(8,2), 1), BoardPiece(Vector2(9,2), 0), BoardPiece(Vector2(10,2), 1), BoardPiece(Vector2(11,2), 0), BoardPiece(Vector2(12,2), 1), BoardPiece(Vector2(13,2), 0),
	BoardPiece(Vector2(0,3), 1), BoardPiece(Vector2(1,3), 0), BoardPiece(Vector2(2,3), 1), BoardPiece(Vector2(3,3), 0), BoardPiece(Vector2(4,3), 1), BoardPiece(Vector2(5,3), 0),  BoardPiece(Vector2(6,3), 1), BoardPiece(Vector2(7,3), 0), BoardPiece(Vector2(8,3), 1), BoardPiece(Vector2(9,3), 0), BoardPiece(Vector2(10,3), 1), BoardPiece(Vector2(11,3), 0), BoardPiece(Vector2(12,3), 1), BoardPiece(Vector2(13,3), 0),
	BoardPiece(Vector2(0,4), 1), BoardPiece(Vector2(1,4), 1), BoardPiece(Vector2(2,4), 1), BoardPiece(Vector2(3,4), 0) ,BoardPiece(Vector2(4,4), 1), BoardPiece(Vector2(5,4), 1),  BoardPiece(Vector2(6,4), 1), BoardPiece(Vector2(7,4), 0), BoardPiece(Vector2(8,4), 1) ,BoardPiece(Vector2(9,4), 1), BoardPiece(Vector2(10,4), 1), BoardPiece(Vector2(11,4), 0), BoardPiece(Vector2(12,4), 1) ,BoardPiece(Vector2(13,4), 2)
	};

	Board nodePathBoard(pieces,0,0);

	// INITIALIZE THE CONSOLE WINDOW 
	// SIZE WIDTH & HEIGHT DECLARED AT TOP OF FILE AS CONST
	window.ClearWindow(true);
	for (int l = 0; l < windowHeight; l++)
	{
		for (int m = 0; m < windowWidth; m++)
		{
			window.addToLine(m, " ", WHITE);
		}
	}

	// SET UP THE VIEW
	for (int l = 0; l < nodePathBoard.getBoard().size(); l++)
	{
		// ONLY NEED TO VISUALLY REPRESENT IT IF IT's A WALL
		if (nodePathBoard.getBoard()[l].getValue() == 0)
		{
			nodePathBoard.setOccupierAt(nodePathBoard.getBoard()[l].getPos(), "|");
		}
		else
		{
			nodePathBoard.setOccupierAt(nodePathBoard.getBoard()[l].getPos(), " ");
		}
		window.setTextAtPoint(nodePathBoard.getBoard()[l].getPos(), nodePathBoard.getBoard()[l].getOccupier(), BRIGHTWHITE);
	}
	window.setLine(10, "Attempts : " + to_string(generations), WHITE);
	window.writeConsole();
	window.ClearWindow(false);
	Vector2 player(0,0);
	window.setTextAtPoint(player, "*", BRIGHTRED); // PLAYER MARKER
	// GAME LOOP
	int value = 1;
	int moveIndex = 0;
	while (true)
	{
		nodePathBoard.setValueAt(player, 0);
		int lastVal = value;
		// GET OLD MOVES
		ifstream newFile(dir + "PathFile.zz", ios::binary | ios::in);
		string line;
		vector<string> lines(0);
		int lineNo = 0;
		if (newFile.is_open())
		{
			while (getline(newFile, line, '\r'))
			{
				lines.push_back(line);
			}
		}
		Vector2 moveVec;
		if (moveIndex < lines.size())
		{
			vector<string> vec = Split(lines[moveIndex], ',');
			if (vec.size() > 1)
			{
				moveVec = Vector2(stoi(vec[0]), stoi(vec[1]));
			}
			else
			{
				int x = (rand() % 3) - 1;
				int y = 0;
				if (x == 0)
				{
					y = (rand() % 3) - 1;
				}
				moveVec = Vector2(x,y);
			}
		}
		else
		{
			int x = (rand() % 3) - 1;
			int y = 0;
			if (x == 0)
			{
				y = (rand() % 3) - 1;
			}
			moveVec = Vector2(x, y);
		}
		if (!nodePathBoard.pieceExists(player + moveVec))
		{
			return;
		}
		else if (nodePathBoard.getPieceAt(player + moveVec).getValue() == 0)
		{
			return;
		}
		else if (nodePathBoard.pieceExists(player + moveVec) && nodePathBoard.getPieceAt(player + moveVec).getValue() != 0) //do > lastVal to allow skips
		{
			window.setTextAtPoint(player, "X", BLUE_BLUE_BG);
			player += moveVec;
			value = nodePathBoard.getPieceAt(player).getValue();
			window.setTextAtPoint(player, "*", BRIGHTRED);
			ofstream moveFile(dir + "PathFile.zz");
			if (lines.size() > 0)
			{
				if (lines[moveIndex] == "" || lines[moveIndex] == "\n")
				{
					lines.push_back(to_string(moveVec.getX()) + ',' + to_string(moveVec.getY()) + "\n");
				}
			}
			else
			{
				lines.push_back(to_string(moveVec.getX()) + ',' + to_string(moveVec.getY()) + "\n");
			}
			for (int i = 0; i < lines.size(); i++)
			{
				moveFile << lines[i];
			}
			window.ClearWindow(false);
			window.writeConsole();
			moveIndex++;
			if (value == 2)
			{
				foundPath = true;
				return;
			}
			Sleep(75);
		}
	}
	//window.writeConsole();
}


int main()
{
	srand(time(NULL));
	//generateart();
	//scenes();
	//generateTriangle();
	//Test();
	//outputVar();
	//playTicTacToe();
	//window.ClearWindow(false);
	//drawBrain(dir + "AIBrainO.txt");
	while (!foundPath)
	{
		nodePath();
		generations++;
	}
	window.setLine(10, "Attempts Required For Path : " + to_string(generations), WHITE);
	window.ClearWindow(false);
	window.writeConsole();
	system("pause");
}

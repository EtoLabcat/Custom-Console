#pragma once
#include <vector>
#include <stdlib.h>
#include "Line.h"
#include <string>

#include "Vector2.h"
/*
	COLOUR CLASS ENUM
	Easier way of calling the colour value
	Black = 0, White = 7
*/
enum  ColourClass
{
	//BLACK CONSOLE BG
	BLACK, 
	BLUE, 
	GREEN,
	AQUA,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
	LIGHTGREY,
	DARKBLUE,
	BRIGHTGREEN,
	LIGHTBLUE,
	BRIGHTRED,
	LIGHTPURPLE,
	BRIGHTYELLOW,
	BRIGHTWHITE,
	//BLUE CONSOLE BG (ETC.. ETC..)
	BLACK_BLUE_BG,
	BLUE_BLUE_BG,
	GREEN_BLUE_BG,
	AQUA_BLUE_BG,
	RED_BLUE_BG,
	PURPLE_BLUE_BG,
	YELLOW_BLUE_BG,
	WHITE_BLUE_BG,
	LIGHTGREY_BLUE_BG,
	DARKBLUE_BLUE_BG,
	BRIGHTGREEN_BLUE_BG,
	LIGHTBLUE_BLUE_BG,
	BRIGHTRED_BLUE_BG,
	LIGHTPURPLE_BLUE_BG,
	BRIGHTYELLOW_BLUE_BG,
	BRIGHTWHITE_BLUE_BG,

	BLACK_GREEN_BG,
	BLUE_GREEN_BG,
	GREEN_GREEN_BG,
	AQUA_GREEN_BG,
	RED_GREEN_BG,
	PURPLE_GREEN_BG,
	YELLOW_GREEN_BG,
	WHITE_GREEN_BG,
	LIGHTGREY_GREEN_BG,
	DARKBLUE_GREEN_BG,
	BRIGHTGREEN_GREEN_BG,
	LIGHTBLUE_GREEN_BG,
	BRIGHTRED_GREEN_BG,
	LIGHTPURPLE_GREEN_BG,
	BRIGHTYELLOW_GREEN_BG,
	BRIGHTWHITE_GREEN_BG,

	BLACK_AQUA_BG,
	BLUE_AQUA_BG,
	GREEN_AQUA_BG,
	AQUA_AQUA_BG,
	RED_AQUA_BG,
	PURPLE_AQUA_BG,
	YELLOW_AQUA_BG,
	WHITE_AQUA_BG,
	LIGHTGREY_AQUA_BG,
	DARKBLUE_AQUA_BG,
	BRIGHTGREEN_AQUA_BG,
	LIGHTBLUE_AQUA_BG,
	BRIGHTRED_AQUA_BG,
	LIGHTPURPLE_AQUA_BG,
	BRIGHTYELLOW_AQUA_BG,
	BRIGHTWHITE_AQUA_BG,

	BLACK_RED_BG,
	BLUE_RED_BG,
	GREEN_RED_BG,
	AQUA_RED_BG,
	RED_RED_BG,
	PURPLE_RED_BG,
	YELLOW_RED_BG,
	WHITE_RED_BG,
	LIGHTGREY_RED_BG,
	DARKBLUE_RED_BG,
	BRIGHTGREEN_RED_BG,
	LIGHTBLUE_RED_BG,
	BRIGHTRED_RED_BG,
	LIGHTPURPLE_RED_BG,
	BRIGHTYELLOW_RED_BG,
	BRIGHTWHITE_RED_BG,

	BLACK_PURPLE_BG,
	BLUE_PURPLE_BG,
	GREEN_PURPLE_BG,
	AQUA_PURPLE_BG,
	RED_PURPLE_BG,
	PURPLE_PURPLE_BG,
	YELLOW_PURPLE_BG,
	WHITE_PURPLE_BG,
	LIGHTGREY_PURPLE_BG,
	DARKBLUE_PURPLE_BG,
	BRIGHTGREEN_PURPLE_BG,
	LIGHTBLUE_PURPLE_BG,
	BRIGHTRED_PURPLE_BG,
	LIGHTPURPLE_PURPLE_BG,
	BRIGHTYELLOW_PURPLE_BG,
	BRIGHTWHITE_PURPLE_BG,

	BLACK_YELLOW_BG,
	BLUE_YELLOW_BG,
	GREEN_YELLOW_BG,
	AQUA_YELLOW_BG,
	RED_YELLOW_BG,
	PURPLE_YELLOW_BG,
	YELLOW_YELLOW_BG,
	WHITE_YELLOW_BG,
	LIGHTGREY_YELLOW_BG,
	DARKBLUE_YELLOW_BG,
	BRIGHTGREEN_YELLOW_BG,
	LIGHTBLUE_YELLOW_BG,
	BRIGHTRED_YELLOW_BG,
	LIGHTPURPLE_YELLOW_BG,
	BRIGHTYELLOW_YELLOW_BG,
	BRIGHTWHITE_YELLOW_BG,

	BLACK_WHITE_BG,
	BLUE_WHITE_BG,
	GREEN_WHITE_BG,
	AQUA_WHITE_BG,
	RED_WHITE_BG,
	PURPLE_WHITE_BG,
	YELLOW_WHITE_BG,
	WHITE_WHITE_BG,
	LIGHTGREY_WHITE_BG,
	DARKBLUE_WHITE_BG,
	BRIGHTGREEN_WHITE_BG,
	LIGHTBLUE_WHITE_BG,
	BRIGHTRED_WHITE_BG,
	LIGHTPURPLE_WHITE_BG,
	BRIGHTYELLOW_WHITE_BG,
	BRIGHTWHITE_WHITE_BG,

	BLACK_LIGHTGREY_BG,
	BLUE_LIGHTGREY_BG,
	GREEN_LIGHTGREY_BG,
	AQUA_LIGHTGREY_BG,
	RED_LIGHTGREY_BG,
	PURPLE_LIGHTGREY_BG,
	YELLOW_LIGHTGREY_BG,
	WHITE_LIGHTGREY_BG,
	LIGHTGREY_LIGHTGREY_BG,
	DARKBLUE_LIGHTGREY_BG,
	BRIGHTGREEN_LIGHTGREY_BG,
	LIGHTBLUE_LIGHTGREY_BG,
	BRIGHTRED_LIGHTGREY_BG,
	LIGHTPURPLE_LIGHTGREY_BG,
	BRIGHTYELLOW_LIGHTGREY_BG,
	BRIGHTWHITE_LIGHTGREY_BG,

	BLACK_DARKBLUE_BG,
	BLUE_DARKBLUE_BG,
	GREEN_DARKBLUE_BG,
	AQUA_DARKBLUE_BG,
	RED_DARKBLUE_BG,
	PURPLE_DARKBLUE_BG,
	YELLOW_DARKBLUE_BG,
	WHITE_DARKBLUE_BG,
	LIGHTGREY_DARKBLUE_BG,
	DARKBLUE_DARKBLUE_BG,
	BRIGHTGREEN_DARKBLUE_BG,
	LIGHTBLUE_DARKBLUE_BG,
	BRIGHTRED_DARKBLUE_BG,
	LIGHTPURPLE_DARKBLUE_BG,
	BRIGHTYELLOW_DARKBLUE_BG,
	BRIGHTWHITE_DARKBLUE_BG,

	BLACK_BRIGHTGREEN_BG,
	BLUE_BRIGHTGREEN_BG,
	GREEN_BRIGHTGREEN_BG,
	AQUA_BRIGHTGREEN_BG,
	RED_BRIGHTGREEN_BG,
	PURPLE_BRIGHTGREEN_BG,
	YELLOW_BRIGHTGREEN_BG,
	WHITE_BRIGHTGREEN_BG,
	LIGHTGREY_BRIGHTGREEN_BG,
	DARKBLUE_BRIGHTGREEN_BG,
	BRIGHTGREEN_BRIGHTGREEN_BG,
	LIGHTBLUE_BRIGHTGREEN_BG,
	BRIGHTRED_BRIGHTGREEN_BG,
	LIGHTPURPLE_BRIGHTGREEN_BG,
	BRIGHTYELLOW_BRIGHTGREEN_BG,
	BRIGHTWHITE_BRIGHTGREEN_BG,

	BLACK_LIGHTBLUE_BG,
	BLUE_LIGHTBLUE_BG,
	GREEN_LIGHTBLUE_BG,
	AQUA_LIGHTBLUE_BG,
	RED_LIGHTBLUE_BG,
	PURPLE_LIGHTBLUE_BG,
	YELLOW_LIGHTBLUE_BG,
	WHITE_LIGHTBLUE_BG,
	LIGHTGREY_LIGHTBLUE_BG,
	DARKBLUE_LIGHTBLUE_BG,
	BRIGHTGREEN_LIGHTBLUE_BG,
	LIGHTBLUE_LIGHTBLUE_BG,
	BRIGHTRED_LIGHTBLUE_BG,
	LIGHTPURPLE_LIGHTBLUE_BG,
	BRIGHTYELLOW_LIGHTBLUE_BG,
	BRIGHTWHITE_LIGHTBLUE_BG,

	BLACK_BRIGHTRED_BG,
	BLUE_BRIGHTRED_BG,
	GREEN_BRIGHTRED_BG,
	AQUA_BRIGHTRED_BG,
	RED_BRIGHTRED_BG,
	PURPLE_BRIGHTRED_BG,
	YELLOW_BRIGHTRED_BG,
	WHITE_BRIGHTRED_BG,
	LIGHTGREY_BRIGHTRED_BG,
	DARKBLUE_BRIGHTRED_BG,
	BRIGHTGREEN_BRIGHTRED_BG,
	LIGHTBLUE_BRIGHTRED_BG,
	BRIGHTRED_BRIGHTRED_BG,
	LIGHTPURPLE_BRIGHTRED_BG,
	BRIGHTYELLOW_BRIGHTRED_BG,
	BRIGHTWHITE_BRIGHTRED_BG,

	BLACK_LIGHTPURPLE_BG,
	BLUE_LIGHTPURPLE_BG,
	GREEN_LIGHTPURPLE_BG,
	AQUA_LIGHTPURPLE_BG,
	RED_LIGHTPURPLE_BG,
	PURPLE_LIGHTPURPLE_BG,
	YELLOW_LIGHTPURPLE_BG,
	WHITE_LIGHTPURPLE_BG,
	LIGHTGREY_LIGHTPURPLE_BG,
	DARKBLUE_LIGHTPURPLE_BG,
	BRIGHTGREEN_LIGHTPURPLE_BG,
	LIGHTBLUE_LIGHTPURPLE_BG,
	BRIGHTRED_LIGHTPURPLE_BG,
	LIGHTPURPLE_LIGHTPURPLE_BG,
	BRIGHTYELLOW_LIGHTPURPLE_BG,
	BRIGHTWHITE_LIGHTPURPLE_BG,

	BLACK_BRIGHTYELLOW_BG,
	BLUE_BRIGHTYELLOW_BG,
	GREEN_BRIGHTYELLOW_BG,
	AQUA_BRIGHTYELLOW_BG,
	RED_BRIGHTYELLOW_BG,
	PURPLE_BRIGHTYELLOW_BG,
	YELLOW_BRIGHTYELLOW_BG,
	WHITE_BRIGHTYELLOW_BG,
	LIGHTGREY_BRIGHTYELLOW_BG,
	DARKBLUE_BRIGHTYELLOW_BG,
	BRIGHTGREEN_BRIGHTYELLOW_BG,
	LIGHTBLUE_BRIGHTYELLOW_BG,
	BRIGHTRED_BRIGHTYELLOW_BG,
	LIGHTPURPLE_BRIGHTYELLOW_BG,
	BRIGHTYELLOW_BRIGHTYELLOW_BG,
	BRIGHTWHITE_BRIGHTYELLOW_BG,

	BLACK_BRIGHTWHITE_BG,
	BLUE_BRIGHTWHITE_BG,
	GREEN_BRIGHTWHITE_BG,
	AQUA_BRIGHTWHITE_BG,
	RED_BRIGHTWHITE_BG,
	PURPLE_BRIGHTWHITE_BG,
	YELLOW_BRIGHTWHITE_BG,
	WHITE_BRIGHTWHITE_BG,
	LIGHTGREY_BRIGHTWHITE_BG,
	DARKBLUE_BRIGHTWHITE_BG,
	BRIGHTGREEN_BRIGHTWHITE_BG,
	LIGHTBLUE_BRIGHTWHITE_BG,
	BRIGHTRED_BRIGHTWHITE_BG,
	LIGHTPURPLE_BRIGHTWHITE_BG,
	BRIGHTYELLOW_BRIGHTWHITE_BG,
	BRIGHTWHITE_BRIGHTWHITE_BG,

	NULLCOLOUR
};
using namespace std;
class ConsoleWindow {
public:
	ConsoleWindow();
	ConsoleWindow(int size);
	ConsoleWindow(ConsoleWindow* window) { *this = window; }
	virtual ~ConsoleWindow() {}
	void ClearWindow(bool removeText);
	/// <summary>
	/// Add text to a line
	/// </summary>
	/// <param name="index"></param>
	/// <param name="a_line"></param>
	/// <param name="colour"></param>
	void addToLine(int index, string a_line, ColourClass colour) { if (index < m_Lines.size()) { m_Lines[index].addLine(a_line, colour); } }
	/// <summary>
	/// Add text ontop of a line
	/// </summary>
	/// <param name="index"></param>
	/// <param name="a_line"></param>
	/// <param name="colour"></param>
	/// <param name="blankSpace"></param>
	/// <param name="startPoint"></param>
	void addLayerToLine(int index, string a_line, ColourClass colour, char blankSpace, int startPoint);
	/// <summary>
	/// Change a line completely
	/// </summary>
	/// <param name="index"></param>
	/// <param name="a_line"></param>
	/// <param name="colour"></param>
	void setLine(int index, string a_line, ColourClass colour) { if (index < m_Lines.size()) { m_Lines[index].setLine(a_line, colour); } }
	/// <summary>
	/// Empty a line
	/// </summary>
	/// <param name="index"></param>
	void clearLine(int index) { if (index < m_Lines.size()) { m_Lines[index].setLine(" ", WHITE); } }

	/// <summary>
	/// Set the text at a certain point
	/// </summary>
	/// <param name="point"></param>
	/// <param name="text"></param>
	/// <param name="colour"></param>
	void setTextAtPoint(Vector2 point, string text, ColourClass colour);

	/// <summary>
	/// Get a colour from an int
	/// </summary>
	/// <param name="colour_int"></param>
	/// <returns></returns>
	ColourClass _intToColour(int colour_int);
	/// <summary>
	/// get the text colour at a certain point
	/// </summary>
	/// <param name="point"></param>
	/// <returns></returns>
	ColourClass getTextColourAtPoint(Vector2 point);
	/// <summary>
	/// set the offset for printing the window
	/// </summary>
	/// <param name="a_offset"></param>
	void setOffset(Vector2 a_offset) { offset.setX(a_offset.getX()); offset.setY(a_offset.getY()); }
	Line getLine(int index) { return m_Lines[index]; }
	/// <summary>
	/// Clear the console without removing the lines
	/// </summary>
	void eraseConsole();
	//init the console
	void initialize(int width, int height);

	/// <summary>
	/// Old write console func, outdated as of 27_01_2021
	/// </summary>
	void writeConsole();

	/// <summary>
	/// Optimized console write function
	/// </summary>
	void writeConsoleOptimized();
	/// <summary>
	/// Determine the colour at a point if you want to place a character over a blank tile
	/// </summary>
	/// <param name="point"></param>
	/// <param name="main"></param>
	/// <param name="onlyFG"></param>
	/// <returns></returns>
	ColourClass determineColourAtPoint(Vector2 point, ColourClass main, bool onlyFG);
	/// <summary>
	/// Only get the current background colour
	/// </summary>
	/// <param name="point"></param>
	/// <returns></returns>
	ColourClass get_BG_Colour_At_Point_Only(Vector2 point);

	void operator=(ConsoleWindow other);
	void setStartingLine(int i) { _StartingLine = i; }

private:
	vector<Line> m_Lines;
	Vector2 offset;
	int _StartingLine = 0;
};
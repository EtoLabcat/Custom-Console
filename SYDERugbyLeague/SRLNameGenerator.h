#pragma once

#include <string>

#include <vector>

using namespace std;


class SRLNameGenerator
{
public:
	static string generateRandomName();
	static string generateRandomTeamName();
private:
	static string generateRandomFirstName();
	static string generateRandomLastName();

	static string generateRandomCity();
	static string generateRandomTeam();

	static vector<string> FirstNames;
	static vector<string> LastNames;
	static vector<string> CityNames;
	static vector<string> TeamNames;
};
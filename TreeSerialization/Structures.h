#pragma once
#include <iostream>
#include <fstream>
#include <vector> 
#include <locale>
#include <clocale>

using namespace std;


typedef enum
{
	INT = 'i',
	DOUBLE = 'd',
	STRING = 's'
} data_type_t;

class Node
{
public:
	data_type_t type;
	int intValue;
	double doubleValue;
	string stringValue;
	vector<Node*> childs;
};

void RecursiveReading(ifstream& ifs, Node& node);
void WriteTreeInConsole(Node* node, int tabCount);
void WriteTreeInFile(ofstream& ofs, Node& node);
void CreateTree(Node& node);

vector<char> ConvertStringToChar(const string& convertToCharVector);

string ConvertCharVectorToString(const vector<char>& convertToString);

void WriteNodeInConsole(const Node& node);

ostream& operator <<(ostream& os, const Node& node);
istream& operator >>(istream& is, Node& node);
ostream& operator <<(ostream& os, const vector<char>& string);
istream& operator >>(istream& is, vector<char>& integ);

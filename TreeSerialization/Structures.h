#pragma once
#include <iostream>
#include <fstream>
#include <vector> 
#include <locale>
#include <clocale>

using namespace std;


struct MyInteger
{
	char typeSignal = 'i';
	int value;
};

struct MyDouble
{
	char typeSignal = 'd';
	double value;
};

struct MyString
{
	char typeSignal = 's';
	string value;
};

//template <typename typeName>
struct Tree
{
	//typeName Head;
	MyInteger Head;
	vector<Tree*> childs;
};

vector<char> ConvertStringToChar(const string& convertToCharVector);

string ConvertCharVectorToString(const vector<char>& convertToString);

ostream& operator <<(ostream& os, const MyInteger& integ);
ostream& operator <<(ostream& os, const MyDouble& doubleg);
ostream& operator <<(ostream& os, const vector<char>& string);
ostream& operator <<(ostream& os, const MyString& string);
istream& operator >>(istream& is, MyInteger& integ);
istream& operator >>(istream& is, MyDouble& integ);
istream& operator >>(istream& is, vector<char>& integ);
istream& operator >>(istream& is, MyString& integ);

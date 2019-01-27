#include "Structures.h"

vector<char> ConvertStringToChar(const string& convertToCharVector)
{
	vector<char> charString(convertToCharVector.begin(), convertToCharVector.end());
	charString.push_back('\0');
	return charString;
}

string ConvertCharVectorToString(const vector<char>& convertToString)
{
	string resultString = "";
	for (char symbol : convertToString)
		resultString += symbol;
	return resultString;
}

ostream& operator <<(ostream& os, const MyInteger& integ)
{
	os << integ.typeSignal << ' ' << integ.value << endl;
	return os;
}

istream& operator >>(istream& is, MyInteger& integ)
{
	is >> integ.typeSignal >> integ.value;
	return is;
}

ostream& operator <<(ostream& os, const MyDouble& doubleg)
{
	os << doubleg.typeSignal << ' ' << doubleg.value << endl;
	return os;
}

istream& operator >>(istream& is, MyDouble& doubleg)
{
	is >> doubleg.typeSignal >> doubleg.value;
	return is;
}

ostream& operator <<(ostream& os, const vector<char>& string)
{
	for (char symbol : string)
		os << symbol;
	return os;
}

istream& operator >>(istream& is, vector<char>& string)
{
	char c;
	streambuf* pbuf = is.rdbuf();
	while (pbuf->sgetc() != '\0')
	{
		is >> c;
		string.push_back(c);
	}
	return is;
}

ostream& operator <<(ostream& os, const MyString& string)
{
	os << string.typeSignal << ' ' << ConvertStringToChar(string.value) << endl;
	return os;
}

istream& operator >>(istream& is, MyString& string)
{
	is >> string.typeSignal >> string.value;
	return is;
}
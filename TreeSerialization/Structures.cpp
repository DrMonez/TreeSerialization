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

ostream& operator <<(ostream& os, const vector<char>& string)
{
	for (char symbol : string)
		os.write(&symbol, sizeof(char));
	return os;
}

istream& operator >>(istream& is, vector<char>& string)
{
	char c;
	streambuf* pbuf = is.rdbuf();
	while (pbuf->sgetc() != '\0')
	{
		is.read(reinterpret_cast<char*>(&c), sizeof(c));
		string.push_back(c);
	}
	is.read(reinterpret_cast<char*>(&c), sizeof(c));
	return is;
}

ostream& operator <<(ostream& os, const Node& node)
{
	vector<char> charVector;
	char type;
	double doubleValue;
	int intValue;
	switch (node.type)
	{
	case 's':
		type = 's';
		os.write(&type, sizeof(type));
		charVector = ConvertStringToChar(node.stringValue);
		os << charVector;
		break;
	case 'i':
		type = 'i';
		os.write(&type, sizeof(char));
		intValue = node.intValue;
		os.write(reinterpret_cast<const char*>(&intValue), sizeof(intValue));
		break;
	case 'd':
		type = 'd';
		os.write(&type, sizeof(char));
		doubleValue = node.doubleValue;
		os.write(reinterpret_cast<const char*>(&doubleValue), sizeof(doubleValue));
		break;
	}
	intValue = node.childs.size();
	os.write(reinterpret_cast<const char*>(&intValue), sizeof(intValue));
	return os;
}

istream& operator >>(istream& is, Node& node)
{
	char type;
	double doubleValue;
	int intValue;
	vector<char> string;
	is.read(reinterpret_cast<char*>(&type), sizeof(type));
	switch (type)
	{
	case 's':
		node.type = STRING;
		is >> string;
		node.stringValue = ConvertCharVectorToString(string);
		break;
	case 'i':
		node.type = INT;
		is.read(reinterpret_cast<char*>(&intValue), sizeof(intValue));
		node.intValue = intValue;
		break;
	case 'd':
		node.type = DOUBLE;
		is.read(reinterpret_cast<char*>(&doubleValue), sizeof(doubleValue));
		node.doubleValue = doubleValue;
		break;
	}
	return is;
}

void Node::WriteNodeInConsole()
{
	switch (type)
	{
	case 's':
		cout << '"' << ConvertStringToChar(stringValue) << '"';
		break;
	case 'i':
		cout << intValue;
		break;
	case 'd':
		cout << doubleValue;
	}
	cout << endl;
}

int du = 0;

void Node::CreateTree()
{
	if (du % 3 == 0)
	{
		type = DOUBLE;
		doubleValue = du + 0.015;
	}
	if (du % 3 == 1)
	{
		type = INT;
		intValue = du;
	}
	if (du % 3 == 2)
	{
		type = STRING;
		stringValue = to_string(du);
	}
	du++;

	if (du < 5)
	{
		Node* child1 = new Node;
		Node* child2 = new Node;
		Node* child3 = new Node;
		childs.push_back(child1);
		childs.push_back(child2);
		childs.push_back(child3);
		for (Node* child : childs)
			child->CreateTree();
	}
}

void Node::WriteTreeInFile(ofstream& ofs)
{
	ofs << *this;
	for (auto child : childs)
		child->WriteTreeInFile(ofs);
}

void Node::WriteTreeInConsole(int tabCount)
{
	cout << "|";
	for (int i = 0; i < tabCount; i++)
		cout << "___";
	WriteNodeInConsole();
	for (auto child : childs)
		child->WriteTreeInConsole(tabCount + 1);
}

void Node::RecursiveReading(ifstream& ifs)
{
	streambuf* pbuf = ifs.rdbuf();
	int s_int = pbuf->sgetc();
	if (s_int != -1)
	{
		int childsCount;

		ifs >> *this;
		ifs.read(reinterpret_cast<char*>(&childsCount), sizeof(childsCount));
		for (int i = 0; i < childsCount; i++)
		{
			Node* child = new Node;
			childs.push_back(child);
			child->RecursiveReading(ifs);
		}

	}
}
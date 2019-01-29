#include "Structures.h"


void main(int argc, char* argv[])
{
	/*Node startTree;
	CreateTree(startTree);

	ofstream ofss("test", ios::out | ios::binary);
	if (!ofss)
		return;
	WriteTreeInFile(ofss, startTree);
	ofss.close();*/

	string ifilename, ofilename;
	if (argc != 5)
	{
		cout << "Please, using '-i filename' and '-o filename'";
		return;
	}

	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "-i"))
		{
			if (ifilename == "")
			{
				i++;
				ifilename = argv[i];
			}
			else
			{
				cout << "'-i filename' was used before";
				return;
			}
		}
	
		if (!strcmp(argv[i], "-o"))
		{
			if (ofilename == "")
			{
				i++;
				ofilename = argv[i];
			}
			else
			{
				cout << "'-o filename' was used before";
				return;
			}
		}
	}
	if (ifilename == "")
	{
		cout << "Please, using '-i filename'";
		return;
	}
	if (ofilename == "")
	{
		cout << "Please, using '-o filename'";
		return;
	}

	ifstream ifs(ifilename, ios::in | ios::binary);
	if (!ifs)
		return;
	
	ofstream ofs(ofilename, ios::out | ios::binary);
	if (!ofs)
		return;

	Node tree;
	RecursiveReading(ifs, tree);
	
	ifs.close();

	WriteTreeInConsole(&tree, 0);
	WriteTreeInFile(ofs, tree);

	ofs.close();
}

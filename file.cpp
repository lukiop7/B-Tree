//#include "stdafx.h"
#include "structures.h"
#include "print_func.h"
#include "tree_func.h"
#include "file.h"
#include <iostream>
#include <fstream>
//#include <cctype>
#include <string>
#include <string.h>
#include <sstream>
#include <iomanip>

bool check_file(const char *x, const  char *format)
{
	unsigned long a = strlen(x), b = strlen(format);

	if (a <= b)
		return false;

	if (strcmp(&x[a - b], format) == 0)
		return true;

	return false;
}



void openfile(string &name, int &order, node *&root)
{
	ifstream file;
	int nline = 0;
	file.open(name.c_str(), ios_base::in);
	if (!file.is_open())
	{
		cout << "Cannot open the file. Check your input file.";
	}
	else
	{
		stringstream str;
		string check, rest, comm;
		double value;
		bool order_tree = false;
		while (getline(file, check, '\n'))
		{
			++nline;
			str = stringstream{ check.data() };
			while (str)
			{
				str >> comm;

				if (comm == "%")
				{
					while (str)
					{
						string tmp;
						str >> tmp;
					}


				}
				if (atoi(comm.c_str()) && order_tree == false)
				{
					size_t found = comm.find('%');
					if (found > 0 && found != string::npos)
					{
						comm.resize(found);
						while (str)
						{
							string tmp;
							str >> tmp;
						}
					}
					order = stoi(comm);
					if (order < 2)
					{
						cout << "Order cannot be less than 2";
						return;
					}
					order_tree = true;
					str >> comm;
				}
				if (comm == "add")
				{

					while (!str.eof())
					{
						str >> comm;
						size_t found = comm.find('%');
						if (found == 0)
						{
							while (str)
							{
								string tmp;
								str >> tmp;
							}
						}
						else
						{
							if (found > 0 && found != string::npos)
							{
								comm.resize(found);
								while (str)
								{
									string tmp;
									str >> tmp;
								}
							}
							if (stof(comm.c_str()))
							{
								value = stof(comm.c_str());
								add(root, value, order);

							}

							else
							{
								cout << "Invalid input at line: " << nline << endl;
								return;
							}

						}
					}
				}
				if (comm == "remove")
				{

					while (!str.eof())
					{
						str >> comm;
						size_t found = comm.find('%');
						if (found == 0)
						{
							while (str)
							{
								string tmp;
								str >> tmp;
							}
						}
						else
						{
							if (found > 0 && found != string::npos)
							{
								comm.resize(found);
								while (str)
								{
									string tmp;
									str >> tmp;
								}
							}
							if (stof(comm.c_str()))
							{
								value = stof(comm.c_str());
								deleteval(root, value);

							}
							else
							{
								cout << "Invalid input at line: " << nline << endl;
								return;
							}
						}
					}

				}
				if (comm == "graph")
				{
					bool append = false;
					bool standard = false;
					string outfile;

					str >> comm;

					if (comm == "+")
					{
						str >> comm;
						size_t found = comm.find('%');
						if (found > 0 && found != string::npos)
						{
							comm.resize(found);
							while (str)
							{
								string tmp;
								str >> tmp;
							}
						}
						append = true;
						outfile = comm;
						ofstream out;
						if (!check_file(outfile.c_str(), ".txt"))
						{
							cout << "Invalid input at line(check if file format is .txt): " << nline << endl;
						}
						out.open(outfile.c_str(), ios::app);

						graph(out, root, -1);
						out << endl;
						while (str)
						{
							string tmp;
							str >> tmp;
						}

						out.close();
					}

					if (comm == "%" || comm == "/n")
					{
						standard = true;
						graph(cout, root, -1);
						cout << endl;
						while (str)
						{
							string tmp;
							str >> tmp;
						}
					}
					if (append == false && standard == false)
					{
						size_t found = comm.find('%');
						if (found > 0 && found != string::npos)
						{
							comm.resize(found);
							while (str)
							{
								string tmp;
								str >> tmp;
							}
						}
						outfile = comm;
						ofstream out;
						if (!check_file(outfile.c_str(), ".txt"))
						{
							cout << "Invalid input at line(check if file format is .txt): " << nline << endl;
						}
						out.open(outfile.c_str());
						graph(out, root, -1);
						out << endl;
						out.close();
						while (str)
						{
							string tmp;
							str >> tmp;
						}
					}
				}
				if (comm == "print")
				{
					bool append = false;
					bool standard = false;
					string outfile;

					str >> comm;

					if (comm == "+")
					{
						str >> comm;
						size_t found = comm.find('%');
						if (found > 0 && found != string::npos)
						{
							comm.resize(found);
							while (str)
							{
								string tmp;
								str >> tmp;
							}
						}
						append = true;
						outfile = comm;
						ofstream out;
						if (!check_file(outfile.c_str(), ".txt"))
						{
							cout << "Invalid input at line(check if file format is .txt): " << nline << endl;
						}
						out.open(outfile.c_str(), ios::app);
						print(out, root);
						out << endl;
						while (str)
						{
							string tmp;
							str >> tmp;
						}
						out.close();
					}

					if (comm == "%" || comm == "/n")
					{
						standard = true;
						print(cout, root);
						cout << endl;
						while (str)
						{
							string tmp;
							str >> tmp;
						}
					}
					if (append == false && standard == false)
					{
						size_t found = comm.find('%');
						if (found > 0 && found != string::npos)
						{
							comm.resize(found);
							while (str)
							{
								string tmp;
								str >> tmp;
							}
						}
						outfile = comm;
						ofstream out;
						if (!check_file(outfile.c_str(), ".txt"))
						{
							cout << "Invalid input at line(check if file format is .txt): " << nline << endl;
						}
						out.open(outfile.c_str());
						print(out, root);
						out << endl;
						out.close();
						while (str)
						{
							string tmp;
							str >> tmp;
						}
					}


				}
				else if (comm != "%"&&comm != ""&&order_tree == false)
				{
					cout << "Wrong input, cannot create b-tree without the order(t>=2).\n Please check your input file";
					return;
				}
			}
		}
	}
	file.close();
}







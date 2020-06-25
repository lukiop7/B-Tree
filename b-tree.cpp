//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string.h>
#include <sstream>
#include "tree_func.h"
#include "struct_func.h"
#include "structures.h"
#include "print_func.h"
#include "file.h"
//#include <vld.h>

using namespace std;

int main(int argc, char**argv) {
	int order=0;
	node *root = nullptr;
	bool input_provided=false;
	char *input_file=nullptr;
if(argc==1)
	{
	cout << "No Extra Command Line Argument Passed Other Than Program Name(add -i + filename.txt)" << endl;
	}
    else
    {
        for(int j=1;j<argc;++j)
		{
			if(strcmp(argv[j],"-i")==0 &&j+1<argc)
			{
				++j;
				input_file=argv[j];
				if (!check_file(input_file, ".txt"))
				{
					cout << "Invalid file format"<<input_file<<endl;
					return 0;
				}
				input_provided=true;

			}
		}
    }
	if(!input_provided)
	{
		cout<<"filename is missing";
		return 0;
	}
	string s;
	s = input_file;
	openfile(s,order,root);







	free(root);
	return 0;
}

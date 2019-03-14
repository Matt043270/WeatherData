#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

#include "IOUtil.h"
#include "Record.h"
#include "BST.h"


using namespace std;


int main()
{
	IOUtil control;
	Record records;

	control.ReadFileNames("Data/inputFileNames.txt", records);
	control.Menu(records);

}
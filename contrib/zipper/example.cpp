// ZipExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "zipper.h"
#include "unzipper.h"
#include <fstream>

using namespace std;
using namespace ziputils;

void zip()
{
	const char* Filenames[] = {"unzipper.cpp", "unzipper.h", "zipper.cpp", "zipper.h"};
	unsigned int nCount = sizeof( Filenames )/sizeof( char* );

	zipper zipFile;
	zipFile.open("test.zip");

	// add files to the zip file
	for ( unsigned int i = 0; i < nCount; i++ )
	{
		ifstream file( Filenames[i], ios::in | ios::binary );
		if ( file.is_open() )
		{
			zipFile.addEntry( Filenames[i] );
			zipFile << file;
		}
	}
	zipFile.close();
}

void zipFolder()
{
	// append the existing file
	zipper zipFile;
	zipFile.open("test.zip", true);

	// add file into a folder
	ifstream file( "unzipper.cpp", ios::in | ios::binary );
	if ( file.is_open() )
	{
		zipFile.addEntry( "/Folder/unzipper.cpp" );
		zipFile << file;
	}
	zipFile.close();
}

void unzip()
{
	unzipper zipFile;
	zipFile.open("test.zip");
	auto filenames = zipFile.getFilenames();
	
	for ( auto it = filenames.begin(); it != filenames.end(); it++ )
	{
		zipFile.openEntry( (*it).c_str() );
		zipFile >> std::cout;
	}
}

int main(int argc, char* argv[])
{
	zip();
	zipFolder();
	unzip();
	return 0;
}


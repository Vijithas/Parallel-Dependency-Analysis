#include "ParallelDependencyExecutive.h"
#include <string>
/////////////////////////////////////////////////////////////////////
//  ParallelDependencyExecutive.cpp - Exeutive to output dependency//
//  ver 1.0                                                        //
//  Language:      Visual C++ 2008, SP1                            //
//  Platform:      Dell Inspiron 15 7000, Windows 10			   //
//  Application:   CSE687 PROJECT 3, Sp16		                   //
//  Author:		   Vijitha SathyanarayanaMurthy, CS				   //
//				   Syracuse University, CST 4-187				   //
//				   vsathyan@syr.edu								   //
/////////////////////////////////////////////////////////////////////
using namespace FileSystem;

void ParallelDependencyExecutive::fileAnalyzer(std::vector<std::string> files, std::string file)
{
	for (size_t i = 0; i < files.size(); i++) {
		inputFiles.push_back(file + files[i]);
	}
}

void ParallelDependencyExecutive::fetchDirectories(std::string path, std::string pattern) {
	std::vector<std::string> directories = FileSystem::Directory::getDirectories(path);

	for (size_t i = 2; i < directories.size(); i++)
	{
		fetchDirectories(path + directories[i] + '/', pattern);
	}
	std::vector<std::string> files = FileSystem::Directory::getFiles(path + '/', pattern);
	fileAnalyzer(files, path + '/');
}

#ifdef PARALLEL_DEP_EXEC

int main(int argc, char *argv[]) {
	ParallelDependencyExecutive parallelDependencyExec;
	for (int i = 2; i < argc; i++)
		parallelDependencyExec.fetchDirectories(argv[1], argv[i]);

	ParallelDependencyAnalysis analysis;
	analysis.Pass1(parallelDependencyExec.inputFiles);
	analysis.Pass2(parallelDependencyExec.inputFiles);
}

#endif
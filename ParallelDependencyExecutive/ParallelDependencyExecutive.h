#ifndef PARALLEL_DEPENDENCY_EXECUTIVE_H
#define PARALLEL_DEPENDENCY_EXECUTIVE_H
/////////////////////////////////////////////////////////////////////
//  ParallelDependencyExecutive.h - Exeutive to output dependency  //
//  ver 1.0                                                        //
//  Language:      Visual C++ 2008, SP1                            //
//  Platform:      Dell Inspiron 15 7000, Windows 10			   //
//  Application:   CSE687 PROJECT 3, Sp16		                   //
//  Author:		   Vijitha SathyanarayanaMurthy, CS				   //
//				   Syracuse University, CST 4-187				   //
//				   vsathyan@syr.edu								   //
/////////////////////////////////////////////////////////////////////
/*
Module Operations:
==================
This module is a test executive to output the results of the dependency analyser

Public Interface:
=================

ParallelDependencyExecutive fetchDirectories(std::string path, std::string pattern)
ParallelDependencyExecutive fileAnalyzer(std::vector<std::string> files, std::string file)

Build Process:
==============
Required files
- FileMgr.h, ParallelDependencyAnalysis.h

Build commands (either one)
- devenv Project_3.sln

Maintenance History:
====================
ver 1.0 : 15 Apr 16
- Initial release
*/
#include <string>
#include <vector>
#include "../FileMgr/FileMgr.h"
#include "../ParallelDependencyAnalysis/ParallelDependencyAnalysis.h"

class ParallelDependencyExecutive {
public:
	void fetchDirectories(std::string path, std::string pattern);
	void fileAnalyzer(std::vector<std::string> files, std::string file);
	std::vector<std::string> inputFiles;
};
#endif


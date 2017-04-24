#ifndef METRICEXECUTIVE_H
#define METRICEXECUTIVE_H
/////////////////////////////////////////////////////////////////////
//  MetricExecutive.h - Automated unit test suite				   //
//  ver 1.0                                                        //
//  Language:      Visual C++ 2008, SP1                            //
//  Platform:      Dell Inspiron 5000 Windows 10				   //
//  Application:   CSE687 PROJECT 3, Sp16		                   //
//  Author:		   Vijitha SathyanarayanaMurthy, CS				   //
//				   Syracuse University, CST 4-187				   //
//				   vsathyan@syr.edu								   //
//  Source:        Jim Fawcett, CST 4-187, Syracuse University     //
//                 (315) 443-3948, jfawcett@twcny.rr.com           //
/////////////////////////////////////////////////////////////////////
/*
Module Operations :
== == == == == == == == ==
This module defines the MetricExecutive class 
which automates the testing of analyser.

Public Interface:
=================
MetricExecutive exec
exec.MetricAnalyser(somefile); // does analysis

Build Process:
==============
Build commands
- devenv Project_3.sln /rebuild debug

Maintenance History:
====================
ver 1.0 : 14 Mar 16
- first release
*/
#include "string"

#include "../Parser/Parser.h"
#include "../FileMgr/FileMgr.h"

#define File std::string

class MetricExecutive {
public:
	void MetricAnalyser(File file);
};
#endif

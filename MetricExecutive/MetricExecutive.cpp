
#include "MetricExecutive.h"
#include <iostream>
#include <string>
#include "../Utilities/Utilities.h"
#include "../Parser/ConfigureParser.h"
#include "../Parser/Analyser.h"

using namespace Scanner;
using namespace Utilities;
using namespace FileSystem;

#define Util StringHelper

void MetricExecutive::MetricAnalyser(File file) {
	std::string fileSpec = FileSystem::Path::getFullFileSpec(file);
	std::string msg = "\nProcessing file " + fileSpec;
	Util::title(msg);
	putline();

	ConfigParseToConsole configure;
	Parser* pParser = configure.Build();
	try
	{
		if (pParser)
		{
			if (!configure.Attach(file))
			{
				std::cout << "\n  could not open file " << fileSpec << std::endl;
				return;
			}
		}
		else
		{
			std::cout << "\n\n  Parser not built\n\n";
			return;
		}
		// now that parser is built, use it

		while (pParser->next())
			pParser->parse();
		AbstractSyntaxTree ast = Repository::getInstance()->Tree();
		ast.TreeWalk(ast.getRoot());
		Analyser analyzer;
		analyzer.displayTable(file);
		analyzer.displayWarnings();
		std::cout << "\n";
	}
	catch (std::exception& ex)
	{
		std::cout << "\n\n    " << ex.what() << "\n\n";
	}
}

#ifdef METRICS
int main(int argc, char *argv[]) {
	MetricExecutive metricExcutive;
	DataStore ds;
	FileMgr fm(argv[1], ds);
	for (int i = 2; i < argc; i++)
		fm.addPattern(argv[i]);
	fm.search();
	std::vector<std::string> currfiles;
	for (auto fs : ds) {
		currfiles.push_back(fs);
	}
	for (size_t i = 0; i < currfiles.size(); i++)
	{
		metricExcutive.MetricAnalyser(argv[1] + ("/" + currfiles[i]));
	}
}
#endif


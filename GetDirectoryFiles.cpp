#pragnma once

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <filesystem> // std::tr2::sys::path etc.
#include <vector>

using namespace std;
namespace sys = std::tr2::sys;

namespace Test
{
	class Test
	{
	public:
		static std::vector<std::string> GetDirectoryFiles(const string& baseDirectory)
		{
			std::vector<std::string> fileNames;

			sys::path p(baseDirectory);
			// if recursive
			//  std::for_each(
			//		sys::recursive_directory_iterator(p),
			//		sys::recursive_directory_iterator(),
			//		...
			for (sys::directory_iterator iterator = sys::directory_iterator(p);
				 iterator != sys::directory_iterator(); ++iterator)
			{
				wstring ws = iterator->path();
				string s(ws.begin(), ws.end());
				wstring wss(s.begin(), s.end());
				fileNames.push_back(s);
			}
		}
	};
}
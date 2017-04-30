// ArbitraryStudy.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include <fstream>
#include <sstream>
#include <locale> 
#include <codecvt>


// 一覧取得
#include <filesystem>

#include <cstdio>
#include <cstdlib>
#include <vector>
//#include <dirent.h>

using namespace std;
//using namespace std::tr2::sys;

int main()
{
	namespace sys = std::tr2::sys;

	std::vector<std::string> fileNames;
	sys::path p("."); // 列挙の起点
	sys::directory_iterator start("C:/[BusinessUse]/Vs2015/ArbitraryCPPCode/ArbitraryStudy/ArbitraryStudy"), end;
	for (; start != end; ++start) {
		//Some code in here
		// get the path like this:
		wstring pth = start->path();
		//wstring aa = pth;
		string s(pth.begin(), pth.end());
		fileNames.push_back(s);
	}


	//sys::path p("."); // 列挙の起点
//
	for (sys::directory_iterator iterator = sys::directory_iterator(p);
		iterator != sys::directory_iterator(); ++iterator)
	{
		//std::ifstream infile(iterator->);

		auto pp = iterator->path();

		//aa.path;

//		sys::path* aa = &iterator->path;
		//fileNames.push_back(p.filename().string());
		//fileNames.push_back(p.filename());
	}
//
//	std::for_each(sys::directory_iterator(p), sys::directory_iterator(),
//		//  再帰的に走査するならコチラ↓
//		//  std::for_each(sys::recursive_directory_iterator(p), sys::recursive_directory_iterator(),
//		[](const sys::path& p) {
//		if (sys::is_regular_file(p)) { // ファイルなら...
//			cout << "file: " << p.filename() << endl;
//		}
//		else if (sys::is_directory(p)) { // ディレクトリなら...
//			cout << "dir.: " << p.string() << endl;
//		}
//	});

	// linux
	//const char* path = "./";
	//DIR *dp;       // ディレクトリへのポインタ
	//dirent* entry; // readdir() で返されるエントリーポイント

	//dp = opendir(path);
	//if (dp == NULL) exit(1);
	//do {
	//	entry = readdir(dp);
	//	if (entry != NULL)
	//		std::cout << path << entry->d_name << std::endl;
	//} while (entry != NULL);

	wstring a = L"漢c字英a数字1混じ5り";
	auto alen = a.length();
	auto asub = a.substr(2, 4);
	int32_t b = 1;

	locale("");

	// file read/write
	ifstream reading_file;
	wstring filename = L"C:\\Users\\amat_\\Desktop\\GitHorseRacingAppli\\HorseRacingAppli\\HorseRacingNew\\レース結果\\京都\\201701076R.csv";
	reading_file.open(filename, std::ios::in);
	std::string reading_line_buffer;

	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cv;
	while (!reading_file.eof())
	{
		// read by line
		std::getline(reading_file, reading_line_buffer);
		std::cout << reading_line_buffer << std::endl;

		string aa = "漢";
		wstring wline = cv.from_bytes(aa);
		//std::cout << wline << std::endl;

		// read by delimiter on reading "one" line
		const char delimiter = ',';
		std::string separated_string_buffer;
		std::istringstream line_separater(reading_line_buffer);
		std::getline(line_separater, separated_string_buffer, delimiter);

		std::cout << separated_string_buffer << std::endl;

	}

    return 0;
}


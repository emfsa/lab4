#pragma once

#include "executer.h"
#include "DoubleSign.h"
#include "bracketChk.h"

class checker
{
	Executerr logger;
	std::string _line;
	doubleSign chck_DS;
	Bracket_checker chck_Br;


public:
	checker(Table* table) :logger(table), chck_Br(table), chck_DS(table) {}

	bool checkLine(const std::string& line)
	{
		bool isOk = true;
		if (line.empty())
		{
			isOk = false;
			return isOk;
		}

		_line = line;
		_line = delspace(_line);
		isOk = chck_DS.isNormal(_line);
		if (isOk == false)
		{
			return false;
		}
		isOk = chck_Br.isNormal(_line);
		return isOk;
	}


	std::string delspace(std::string line)
	{
		std::string res = line;
		res.erase(std::remove(res.begin(), res.end(), ' '), res.end());
		return res;
	}

	~checker()
	{

	}



};


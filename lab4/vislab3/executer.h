#pragma once
#include <iostream>
#include <fstream>
#include "Table.h"
#include "logs.h"
class Executerr
{
	std::ofstream _File;
	Table* _table;
public:
	Executerr(Table* table) : _table(table) {
		_File.open("errors.txt", std::ios::app);
	};


	void thRow(const logs& errorCode)
	{
		std::string fullMessage = "[" + errorCode.time + "] Error: "
			+ _table->GetDescription(errorCode.code)
			+ " (Code: " + errorCode.code + ")\n";

		// Запись в файл
		if (_File.is_open())
		{
			_File << fullMessage << std::endl;

		}
		else
		{
			std::cout << "file is not open!";
		}
		/*std::string descript = _table->GetDescription(errorCode.code);
		std::cout << "Error: " << descript << " (Code: " << errorCode.code << ")\n";*/


	}


	~Executerr()
	{
		if (_File.is_open())
		{
			_File.close();
		}

	}

};


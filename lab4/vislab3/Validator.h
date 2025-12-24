#pragma once
#include "checker.h"

class Validator
{
public:
	Validator() = default;

	virtual bool isNormal(const std::string& line) = 0;


	~Validator() = default;

private:

};


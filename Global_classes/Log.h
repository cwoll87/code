#pragma once

#include <iostream>
#include <string>
class Log
{
public:
	Log(void);
	~Log(void);

	//actual: do nothing, Later init for the textfile
	void init();

	/********************************************************/
	/* function: write2										*/
	/* description: static function whos allowed to write in*/
	/* the cmd and textfile									*/
	/* param:												*/
	/* std::string text										*/
	/* int messageLevel: 0 = ERROR; 1 = OK					*/
	/* return:												*/
	/* Autor: Dennis Klapper     							*/
	/********************************************************/
	static void write2(std::string text, int messageLevel);

	//actual: do nothing, handle for the textfile
	static void appendToTextfile(std::string text, int messageLevel);
};


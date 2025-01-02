#pragma once

#include <string>
#include <iostream>
using namespace std;

class Book 
{
public:
	Book(string title, string author);

	string GetTitle() { return title; }
	string GetAuthor() { return author; }

	~Book() {
		title = "";
		author = "";
	}
private:
	string title;
	string author;
};


#pragma once

#include <string>
#include <iostream>
using namespace std;

class Book 
{
public:
	Book(string title, string author);

	string getTitle() { return title; }
	string getAuthor() { return author; }

	~Book() {
		title = "";
		author = "";
	}
private:
	string title;
	string author;
};


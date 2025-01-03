#pragma once

#include <string>
#include <unordered_map>
#include "Book.h"
using namespace std;

class BorrowManager {
public: 
	void InitializeStock(Book book, int quantity = 3);
	void borrowBook(string title);
	void returnBook(string title);
	void displayStock();

	~BorrowManager() {
		stock.clear();
		cout << "BorrowManager 소멸되었습니다." << endl;
	}
private:
	unordered_map<string, int> stock;
};
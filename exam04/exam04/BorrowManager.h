#pragma once

#include <string>
#include <unordered_map>
#include "Book.h"
using namespace std;

class BorrowManager {
public: 
	void InitializeStock(Book book, int quantity = 3);
	void BorrowBook(string title);
	void ReturnBook(string title);
	void DisplayStock();

	~BorrowManager() {
		stock.clear();
		cout << "BorrowManager 소멸되었습니다." << endl;
	}
private:
	unordered_map<string, int> stock;
};
#include "BorrowManager.h"
#include "Book.h"
#include <iostream>

using namespace std;

void BorrowManager::InitializeStock(Book book, int quantity)
{
	stock[book.GetTitle()] = quantity;
	cout << "대여시스템 - [" << book.GetTitle() << "](" << book.GetAuthor() << ")책" << quantity << "권 추가되었습니다." << endl;
}

void BorrowManager::BorrowBook(string title)
{
	if (stock[title] < 1) {
		cout << "책 [" << title << "]은 빌릴 수 있는 책이 없습니다." << endl;
	}

	stock[title]--;
	cout << "정상적으로 대여했습니다." << endl;
	cout << "책 [" << title << "]의 대여 가능한 수량: " << stock[title] << endl;
}

void BorrowManager::ReturnBook(string title)
{
	stock[title]++;
	cout << "정상적으로 반납되었습니다." << endl;
	cout << "책 [" << title << "]의 대여 가능한 수량: " << stock[title] << endl;
}

void BorrowManager::DisplayStock()
{
	cout << "모든 책의 대여 가능 수량을 표시합니다." << endl;
	for (auto book : stock) {
		cout << "[" << book.first << "] : " << book.second << endl;
	}
}

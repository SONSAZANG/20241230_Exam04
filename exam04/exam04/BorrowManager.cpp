#include "BorrowManager.h"
#include "Book.h"
#include <iostream>

using namespace std;

void BorrowManager::InitializeStock(Book book, int quantity)
{
	stock[book.GetTitle()] = quantity;
	cout << "�뿩�ý��� - [" << book.GetTitle() << "](" << book.GetAuthor() << ")å" << quantity << "�� �߰��Ǿ����ϴ�." << endl;
}

void BorrowManager::BorrowBook(string title)
{
	if (stock[title] < 1) {
		cout << "å [" << title << "]�� ���� �� �ִ� å�� �����ϴ�." << endl;
	}

	stock[title]--;
	cout << "���������� �뿩�߽��ϴ�." << endl;
	cout << "å [" << title << "]�� �뿩 ������ ����: " << stock[title] << endl;
}

void BorrowManager::ReturnBook(string title)
{
	stock[title]++;
	cout << "���������� �ݳ��Ǿ����ϴ�." << endl;
	cout << "å [" << title << "]�� �뿩 ������ ����: " << stock[title] << endl;
}

void BorrowManager::DisplayStock()
{
	cout << "��� å�� �뿩 ���� ������ ǥ���մϴ�." << endl;
	for (auto book : stock) {
		cout << "[" << book.first << "] : " << book.second << endl;
	}
}

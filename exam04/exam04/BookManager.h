#pragma once

#include <string>
#include <vector>
#include "Book.h"
using namespace std;

class BookManager {
public:
	void FindBookByTitle(string title);
	void FindBookByAuthor(string ahthor);
	void AddBook(Book newBook);
	void DisplayAllBooks();
	Book GetBookByTitle(string title);
	// Book GetBookByAuthor(string author);
	// �۰��� �˻� �� �������� �뿩 -> �۰��� �������� å�� ������ ����
	vector<Book> GetBooks() const { return books; }

	~BookManager() {
		books.clear();
		cout << "BookManager �Ҹ�Ǿ����ϴ�." << endl;
	}

private:
	vector<Book> books;
};
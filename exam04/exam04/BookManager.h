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
	// 작가로 검색 후 제목으로 대여 -> 작가가 여러개의 책이 있을수 있음
	vector<Book> GetBooks() const { return books; }

	~BookManager() {
		books.clear();
		cout << "BookManager 소멸되었습니다." << endl;
	}

private:
	vector<Book> books;
};
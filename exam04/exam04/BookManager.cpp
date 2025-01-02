#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Book.h"
#include "BookManager.h"
using namespace std;

struct FindTitle {
	string title;
	bool operator()(Book book) {
		return book.GetTitle() == title;
	}
};

void BookManager::FindBookByTitle(string title)
{
	FindTitle ft;
	ft.title = title;
	auto it = find_if(books.begin(), books.end(), ft);
	if (it == books.end()) {
		cout << title << "은 찾을 수 없습니다.\n";
	}
	else {
		cout << "찾으시는 책 " << title << "은 존재합니다.\n";
	}
}

struct FindAuthor {
	string author;
	bool operator()(Book book) {
		return book.GetAuthor() == author;
	}
};

void BookManager::FindBookByAuthor(string author)
{
	FindAuthor ft;
	ft.author = author;
	vector<Book> copyBooks(books);
	vector<Book> authorBooks;

	while (true) {
		auto it = find_if(copyBooks.begin(), copyBooks.end(), ft);
		if (it == copyBooks.end()) {
			for (int i = 0; i < authorBooks.size(); ++i) {
				cout << "작가의 책 제목: " << authorBooks[i].GetTitle() << endl;
			}
			break;
		}
		else {
			int index = it - copyBooks.begin();
			authorBooks.push_back(copyBooks[index]);
			copyBooks.erase(copyBooks.begin() + index);
		}
	}

	if (authorBooks.size() < 1) {
		cout << "요청하신 작가의 책이 없습니다." << endl;
	}

	cout << author << "작가의 책은 총 " << authorBooks.size() << "권 있습니다." << endl;
}

void BookManager::AddBook(Book newBook)
{
	books.push_back(newBook);
	cout << "관리자 시스템 - [" << newBook.GetTitle() << "](" << newBook.GetAuthor() << ")책이 생성 되었습니다." << endl;
}

void BookManager::DisplayAllBooks()
{
	for (int i = 0; i < books.size(); ++i) {
		cout << "책이름: " << books[i].GetTitle() << ", 저자: " << books[i].GetAuthor() << endl;
	}
}

Book BookManager::GetBookByTitle(string title)
{
	FindTitle ft;
	ft.title = title;
	auto it = find_if(books.begin(), books.end(), ft);
	if (it == books.end()) {
		cout << title << "은 찾을 수 없습니다.\n";
	}
	else {
		return books[it - books.begin()];
	}
}


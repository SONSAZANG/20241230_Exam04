﻿#include "Book.h"
#include "BookManager.h"
#include "BorrowManager.h"
#include <iostream>
#include <map>
using namespace std;

enum FUNCTION {
	DEFUALT = 0,
	ADD_BOOK = 1,
	FIND_TITLE,
	FIND_AUTHOR,
	DISPLAY_ALL_BOOK_INFO,
	BORROW_BOOK,
	RETURN_BOOK,
	DISPLAY_ALL_BORROW_INFO,
	SYSTEM_EXIT,
};

map<string, string> bookList;
void InitializeBooks() {
	bookList["손사장 이야기"] = "손사장";
	bookList["손리포터"] = "손사장";
	bookList["위대한 손사장"] = "손사장";
	bookList["진격의 언리얼"] = "언리얼";
	bookList["키보드 연구소"] = "키보드박사";
}

void PrintTitle() {
	cout << "---------------------------------------------" << endl;
	cout << "<--도서관 프로그램 가동!-->" << endl;
	cout << "---------------------------------------------" << endl;
}

void PrintLibraryFunction() {
	cout << "---------------------------------------------" << endl;
	cout << "도서관을 이용합니다. 원하시는 기능을 입력하세요." << endl;
	cout << "1. 책 추가하기" << endl;
	cout << "2. 제목으로 검색하기" << endl;
	cout << "3. 작가 이름으로 검색하기" << endl;
	cout << "4. 도서관에 있는 모든 책 보기" << endl;
	cout << "5. 책 빌리기" << endl;
	cout << "6. 책 반납하기" << endl;
	cout << "7. 대여 가능한 모든 책 보기" << endl;
	cout << "8. 도서관 시스템 종료" << endl;
	cout << "---------------------------------------------" << endl;
}

void SettingLibrary(BookManager& bookManager, BorrowManager& borrowManager) {
	cout << "도서관에 책을 추가합니다." << endl;

	for (auto it : bookList) {
		Book newBook = Book(it.first, it.second);
		bookManager.AddBook(newBook);
		borrowManager.InitializeStock(newBook);
	}

	cout << "5권의 책이 정상적으로 추가되었습니다." << endl;
}

void OperationLibrary(BookManager& bookManager, BorrowManager& borrowManager) {
	
	FUNCTION function = DEFUALT;
	int inputNum = 0;
	bool isOperation = true;
	string title = "";
	string author = "";
	while(isOperation == true) {
		title = "";
		author = "";
		PrintLibraryFunction();
		cin >> inputNum;
		switch ((FUNCTION)inputNum)
		{
		case ADD_BOOK: {
			cout << "1. 책 추가하기(제목과 작가명을 입력하세요)" << endl;
			cin >> title >> author;
			Book newBook = Book(title, author);
			bookManager.AddBook(newBook);
			break;
		}
		case FIND_TITLE: {
			cout << "2. 제목으로 검색하기(제목을 입력하세요)" << endl;
			cin >> title;
			bookManager.FindBookByTitle(title);
			break;
		}
		case FIND_AUTHOR: {
			cout << "3. 작가 이름으로 검색하기(작가명을 입력하세요)" << endl;
			cin >> author;
			bookManager.FindBookByAuthor(author);
			break;
		}
		case DISPLAY_ALL_BOOK_INFO: {
			cout << "4. 도서관에 있는 모든 책 보기" << endl;
			bookManager.DisplayAllBooks();
			break;
		}
		case BORROW_BOOK: {
			cout << "5. 책 빌리기(제목을 입력하세요)" << endl;
			cin >> title;
			borrowManager.BorrowBook(title);
			break;
		}
		case RETURN_BOOK: {
			cout << "6. 책 반납하기(제목을 입력하세요)" << endl;
			cin >> title;
			borrowManager.ReturnBook(title);
			break;
		}
		case DISPLAY_ALL_BORROW_INFO: {
			cout << "7. 대여 가능한 모든 책 보기" << endl;
			borrowManager.DisplayStock();
			break;
		}
		case SYSTEM_EXIT: {
			cout << "도서관 시스템을 종료합니다." << endl;
			isOperation = false;
			break;
		}
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}
}

int main() {
	BookManager* bookM = new BookManager();
	BorrowManager* borrowM = new BorrowManager();

	InitializeBooks();
	PrintTitle();
	SettingLibrary(*bookM, *borrowM);
	OperationLibrary(*bookM, *borrowM);

	delete bookM;
	delete borrowM;
}


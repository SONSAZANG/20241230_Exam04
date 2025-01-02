#include "Book.h"
#include "BookManager.h"
#include "BorrowManager.h"
#include <iostream>
#include <map>
using namespace std;

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
	cout << "8. 도서 시스템 종료" << endl;
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
	
	int num = 0;
	bool isOperation = true;
	string title = "";
	string author = "";
	while(isOperation == true) {
		title = "";
		author = "";
		PrintLibraryFunction();
		cin >> num;
		switch (num)
		{
		case 1: {
			cout << "---------------------------------------------" << endl;
			cout << "1. 책 추가하기(제목과 작가명을 입력하세요)" << endl;
			cin >> title >> author;
			Book newBook = Book(title, author);
			bookManager.AddBook(newBook);
			break;
		}
		case 2: {
			cout << "---------------------------------------------" << endl;
			cout << "2. 제목으로 검색하기(제목을 입력하세요)" << endl;
			cin >> title;
			bookManager.FindBookByTitle(title);
			break;
		}
		case 3: {
			cout << "---------------------------------------------" << endl;
			cout << "3. 작가 이름으로 검색하기(작가명을 입력하세요)" << endl;
			cin >> author;
			bookManager.FindBookByAuthor(author);
			break;
		}
		case 4: {
			cout << "---------------------------------------------" << endl;
			cout << "4. 도서관에 있는 모든 책 보기" << endl;
			bookManager.DisplayAllBooks();
			break;
		}
		case 5: {
			cout << "---------------------------------------------" << endl;
			cout << "5. 책 빌리기(제목을 입력하세요)" << endl;
			cin >> title;
			borrowManager.BorrowBook(title);
			break;
		}
		case 6: {
			cout << "---------------------------------------------" << endl;
			cout << "6. 책 반납하기(제목을 입력하세요)" << endl;
			cin >> title;
			borrowManager.ReturnBook(title);
			break;
		}
		case 7: {
			cout << "---------------------------------------------" << endl;
			cout << "7. 대여 가능한 모든 책 보기" << endl;
			borrowManager.DisplayStock();
			break;
		}
		case 8: {
			cout << "도서관 시스템을 종료합니다." << endl;
			cout << "---------------------------------------------" << endl;
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


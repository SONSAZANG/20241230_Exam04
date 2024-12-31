#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Book {
public:
	string title;
	string author;

	Book(string titleValue, string authorValue) : title(titleValue), author(authorValue) {}
};

class BookManager {
private:
	vector<Book> books;

public:
	void addBook(string titleValue, string authorValue) {
		Book newBook = Book(titleValue, authorValue);
		books.push_back(newBook);
	}

	void displayAllBooks() {
		for (int i = 0; i < books.size(); ++i) {
			cout << "책이름: " << books[i].title << ", 저자: " << books[i].author << endl;
		}
	}

	struct FindTitle {
		string title;
		bool operator()(Book book) {
			return book.title == title;
		}
	};

	void searchByTitle(string titleValue) {
		FindTitle ft;
		ft.title = titleValue;
		auto it = find_if(books.begin(), books.end(), ft);
		if (it == books.end()) {
			cout << titleValue << "은 찾을 수 없습니다.\n";
		}
		else {
			cout << "찾으시는 책 " << titleValue << "은 존재하며 인덱스는 " << it - books.begin() << " 입니다.\n";
		}
	}

	struct FindAuthor {
		string author;
		bool operator()(Book book) {
			return book.author == author;
		}
	};

	void searchByAuthor(string authorValue) {
		FindAuthor ft;
		ft.author = authorValue;
		
		vector<Book> copyBooks = books;
		vector<Book> authorBooks;

		while (true) {
			auto it = find_if(copyBooks.begin(), copyBooks.end(), ft);
			if (it == copyBooks.end()) {
				for (int i = 0; i < authorBooks.size(); ++i) {
					cout << "작가의 책 제목: " << authorBooks[i].title << endl;
				}

				break;
			}
			else {
				int index = it - copyBooks.begin();
				authorBooks.push_back(copyBooks[index]);
				copyBooks.erase(copyBooks.begin() + index);
			}
		}
		
	}
};

int main() {
	BookManager bm;
	bm.addBook("손사장이야기", "손사장");
	bm.addBook("손사장이야기2", "손사장");
	bm.searchByTitle("손사장이야기"); 
	bm.searchByAuthor("손사장");
}




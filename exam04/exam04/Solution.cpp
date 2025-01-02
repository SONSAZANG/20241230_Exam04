#include "Book.h"
#include "BookManager.h"
#include "BorrowManager.h"
#include <iostream>
#include <map>
using namespace std;

map<string, string> bookList;
void InitializeBooks() {
	bookList["�ջ��� �̾߱�"] = "�ջ���";
	bookList["�ո�����"] = "�ջ���";
	bookList["������ �ջ���"] = "�ջ���";
	bookList["������ �𸮾�"] = "�𸮾�";
	bookList["Ű���� ������"] = "Ű����ڻ�";
}

void PrintTitle() {
	cout << "---------------------------------------------" << endl;
	cout << "<--������ ���α׷� ����!-->" << endl;
	cout << "---------------------------------------------" << endl;
}

void PrintLibraryFunction() {
	cout << "---------------------------------------------" << endl;
	cout << "�������� �̿��մϴ�. ���Ͻô� ����� �Է��ϼ���." << endl;
	cout << "1. å �߰��ϱ�" << endl;
	cout << "2. �������� �˻��ϱ�" << endl;
	cout << "3. �۰� �̸����� �˻��ϱ�" << endl;
	cout << "4. �������� �ִ� ��� å ����" << endl;
	cout << "5. å ������" << endl;
	cout << "6. å �ݳ��ϱ�" << endl;
	cout << "7. �뿩 ������ ��� å ����" << endl;
	cout << "8. ���� �ý��� ����" << endl;
}

void SettingLibrary(BookManager& bookManager, BorrowManager& borrowManager) {
	cout << "�������� å�� �߰��մϴ�." << endl;

	for (auto it : bookList) {
		Book newBook = Book(it.first, it.second);
		bookManager.AddBook(newBook);
		borrowManager.InitializeStock(newBook);
	}

	cout << "5���� å�� ���������� �߰��Ǿ����ϴ�." << endl;
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
			cout << "1. å �߰��ϱ�(����� �۰����� �Է��ϼ���)" << endl;
			cin >> title >> author;
			Book newBook = Book(title, author);
			bookManager.AddBook(newBook);
			break;
		}
		case 2: {
			cout << "---------------------------------------------" << endl;
			cout << "2. �������� �˻��ϱ�(������ �Է��ϼ���)" << endl;
			cin >> title;
			bookManager.FindBookByTitle(title);
			break;
		}
		case 3: {
			cout << "---------------------------------------------" << endl;
			cout << "3. �۰� �̸����� �˻��ϱ�(�۰����� �Է��ϼ���)" << endl;
			cin >> author;
			bookManager.FindBookByAuthor(author);
			break;
		}
		case 4: {
			cout << "---------------------------------------------" << endl;
			cout << "4. �������� �ִ� ��� å ����" << endl;
			bookManager.DisplayAllBooks();
			break;
		}
		case 5: {
			cout << "---------------------------------------------" << endl;
			cout << "5. å ������(������ �Է��ϼ���)" << endl;
			cin >> title;
			borrowManager.BorrowBook(title);
			break;
		}
		case 6: {
			cout << "---------------------------------------------" << endl;
			cout << "6. å �ݳ��ϱ�(������ �Է��ϼ���)" << endl;
			cin >> title;
			borrowManager.ReturnBook(title);
			break;
		}
		case 7: {
			cout << "---------------------------------------------" << endl;
			cout << "7. �뿩 ������ ��� å ����" << endl;
			borrowManager.DisplayStock();
			break;
		}
		case 8: {
			cout << "������ �ý����� �����մϴ�." << endl;
			cout << "---------------------------------------------" << endl;
			isOperation = false;
			break;
		}
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
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


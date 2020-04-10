// Original code from the web: 
// https://github.com/kamal-choudhary/singly-linked-list
// https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr

#include<iostream>
using namespace std;
struct Node {
	int data;
	Node *next;
};

class List {
private:
	friend ostream &operator<<(ostream &strm, const List &list);
	friend istream &operator>>(istream &istrm, List &list);
	Node *head, *tail;
public:
	List() {
		head = NULL;
		tail = NULL;
	}

	//Deep copy ctor
	List(const List& list) : head(nullptr), tail(nullptr) {
		delete head;
		delete tail;

		if (list.head != nullptr)
		{
			head = new Node;
			head = list.head;
		}
		else
			head = nullptr;

		if (list.tail != nullptr)
		{
			tail = new Node;
			tail = list.tail;
		}
		else
			tail = nullptr;
	}

	// Assignment operator
	List& operator=(const List & list)
	{
		if (this == &list)
			return *this;

		delete head;
		delete tail;

		if (list.head != nullptr)
		{
			head = new Node;
			head = list.head;
		}
		else
			head = nullptr;

		if (list.tail != nullptr)
		{
			tail = new Node;
			tail = list.tail;
		}
		else
			tail = nullptr;

		return *this;
	}

	void createnode(int value) {
		Node *temp = new Node;
		temp->data = value;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}
	void display() {
		Node *temp = new Node;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}
	void insert_start(int value) {
		Node *temp = new Node;
		temp->data = value;
		temp->next = head;
		head = temp;
	}
	void insert_position(int pos, int value) {
		Node *pre = new Node;
		Node *cur = new Node;
		Node *temp = new Node;
		cur = head;
		for (int i = 1;i < pos;i++) {
			pre = cur;
			cur = cur->next;
		}
		temp->data = value;
		pre->next = temp;
		temp->next = cur;
	}
	void delete_first() {
		Node *temp = new Node;
		temp = head;
		head = head->next;
		delete temp;
	}
	void delete_last() {
		Node *current = new Node;
		Node *previous = new Node;
		current = head;
		while (current->next != NULL) {
			previous = current;
			current = current->next;
		}
		tail = previous;
		previous->next = NULL;
		delete current;
	}
	void delete_position(int pos) {
		Node *current = new Node;
		Node *previous = new Node;
		current = head;
		for (int i = 1;i < pos;i++) {
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		delete current;
	}

	//stream output operator (<<)
	friend ostream &operator<<(ostream &ostrm, const List &list) {
		
		Node *temp = new Node;
		temp = list.head;
		while (temp != NULL) {
			ostrm << temp->data << "\t";
			temp = temp->next;
		}

		return ostrm;
	}

	//stream input operator (>>)
	friend istream &operator>>(istream &istrm, List &list) {
		
		Node *temp = new Node;
		cout << "Please enter an integer value: ";
		istrm >> temp->data;
		temp->next = NULL;

		cout << "\nAdding " << temp->data << " to the end of the list\n\n";

		if (list.head == NULL) {
			list.head = temp;
			list.tail = temp;
			temp = NULL;
		}
		else {
			list.tail->next = temp;
			list.tail = temp;
		}

		return istrm;
	}

	//addition operator (operator+)
	friend const List operator+(const List&, const List&);
};

const List operator+(const List& a, const List& b) {
	List sum;
	int val;
	Node *tempListA = new Node;
	Node *tempListB = new Node;
	tempListA = a.head;
	tempListB = b.head;

	while (tempListA != NULL && tempListB != NULL) {
		val = tempListA->data + tempListB->data;
		sum.createnode(val);
		tempListA = tempListA->next;
		tempListB = tempListB->next;
	}

	return sum;
}


int main() {
	List obj;
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(40);
	cout << "\n--------------------------------------------------\n";
	cout << "---------------Displaying All nodes---------------";
	cout << "\n--------------------------------------------------\n";
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "-----------------Inserting At End-----------------";
	cout << "\n--------------------------------------------------\n";
	obj.createnode(55);
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "----------------Inserting At Start----------------";
	cout << "\n--------------------------------------------------\n";
	obj.insert_start(50);
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "-------------Inserting At Particular--------------";
	cout << "\n--------------------------------------------------\n";
	obj.insert_position(5, 60);
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "----------------Deleting At Start-----------------";
	cout << "\n--------------------------------------------------\n";
	obj.delete_first();
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "-----------------Deleting At End-------------------";
	cout << "\n--------------------------------------------------\n";
	obj.delete_last();
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "--------------Deleting At Particular--------------";
	cout << "\n--------------------------------------------------\n";
	obj.delete_position(4);
	obj.display();

	cout << "\n--------------------------------------------------\n";
	cout << "--------------Using answer code-----------------";
	cout << "\n--------------------------------------------------\n";

	cout << "\n--------------------------------------------------\n";
	cout << "--------------Using copy constructor-----------------";
	cout << "\n--------------------------------------------------\n";
	List obj1(obj);
	cout << obj1 << endl;

	cout << "\n--------------------------------------------------\n";
	cout << "--------------Using assignment operator-----------------";
	cout << "\n--------------------------------------------------\n";
	List obj2;
	obj2 = obj1;
	cout << obj2 << endl;

	cout << "\n--------------------------------------------------\n";
	cout << "--------------Using stream input------------------";
	cout << "\n--------------------------------------------------\n";
	cin >> obj1 >> obj1;
	cout << obj1 << endl;

	cout << "\n--------------------------------------------------\n";
	cout << "--------------Using operator+------------------";
	cout << "\n--------------------------------------------------\n";
	List obj3, obj4;
	obj3.createnode(1);
	obj3.createnode(2);
	obj3.createnode(3);
	obj3.createnode(3);
	obj4.createnode(4);
	obj4.createnode(5);
	obj4.createnode(6);
	cout << "obj3 List: " << endl << obj3 << endl;
	cout << "obj4 List: " << endl << obj4 << endl;
	cout << "obj3 + obj4: " << endl << obj3 + obj4 << endl;

	int x; cin >> x;
	return 0;
}
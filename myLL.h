#include"LinkedList.h"
class myLL : public LinkedList {

public:
	void insertAtTail(int);
	void display();
	void insertAtHead(int);
	int deleteFromHead();
	int deleteFromTail();
	void removeDuplicate();
};
void myLL::insertAtHead(int value) {
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;
	if (head == nullptr && tail == nullptr) {
		head = nn;
		tail = nn;
	}
	else {
		nn->next = head;
		head = nn;
	}
	
}
int myLL::deleteFromTail()
{
	if (head == nullptr && tail == nullptr)
	{
		cout << "Your Linked list is empty " << endl;
		return NULL;
	}
	else if (head == tail)
	{
		int returningValue = tail->data;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return returningValue;
	}
	else {
		int returningValue = tail->data;
		Node* t = new Node;
		t = head;
		while (1)
		{
			if (t->next->next == nullptr)
				break;
			else
			{
				t = t->next;
			}
		}
		delete tail;
		tail = t;
		tail->next = nullptr;
	
		return returningValue;

	}
}
int myLL::deleteFromHead() {
	if (head == nullptr && tail == nullptr)
	{
		cout << "Your Linked List is Empty" << endl;
		return NULL;
	}
	else if (head == tail)
	{
		int returningValue = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;

		return returningValue;
	}
	else {
		int returningValue = head->data;
		Node* temp = new Node;
		temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
		return returningValue;
	}
}

void myLL::insertAtTail(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;
	if (head == nullptr && tail == nullptr) {
		head= nn;
		tail = nn;
	}
	else {
		tail -> next = nn;
		tail= nn;
	}
}
void myLL::display()
{
	if (head == nullptr && tail == nullptr) {
		cout << "Link List is empty" << endl;
	}
	else {
		Node* t = head;
		while (true) {
			cout << t->data << endl;
			t = t->next;
			if (t == nullptr) break;
		}
	}
}
void myLL:: removeDuplicate() {
	if (!head) return; 

	Node* current = head;
	while (current) {
		Node* temp = current; 
		while (temp->next) { 
			if (temp->next->data == current->data) {
				Node* duplicate = temp->next;
				temp->next = temp->next->next; 
				if (duplicate == tail) {
					tail = temp; 
				}
				delete duplicate; 
			}
			else {
				temp = temp->next; 
			}
		}
		current = current->next; 
	}
}


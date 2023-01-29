#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *prev;
	Node *next;

	Node(int d)
	{
		this->data = d;
		this->prev = NULL;
		this->next = NULL;
	}
	~Node()
	{
		int val = this->data;
		if (next != NULL)
		{
			delete next;
			next = NULL;
		}
		cout << "memory free for the Node with data " << val << endl;
	}
};

void print(Node *head)
{

	int len = 0;
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
}

int getLength(Node *head)
{
	int len = 0;
	Node *temp = head;

	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}

	return len;
}

void insertAtHead(Node *&head, Node *&tail, int d)
{
	if (head == NULL)
	{
		Node *temp = new Node(d);
		head = temp;
		tail = temp;
	}
	else
	{
		Node *temp = new Node(d);
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}

void insertAtTail(Node *&head, Node *&tail, int d)
{

	if (tail == NULL)
	{
		Node *temp = new Node(d);
		tail = temp;
		head = temp;
	}

	else
	{
		Node *temp = new Node(d);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}
void insertAtPosition(Node *&tail, Node *&head, int pos, int d)
{
	if (pos == 1)
	{
		insertAtHead(head, tail, d);
		return;
	}
	Node *temp = head;
	int cnt = 1;
	while (cnt < pos - 1)
	{
		temp = temp->next;
		cnt++;
	}
	if (temp->next == NULL)
	{
		insertAtTail(head, tail, d);
		return;
	}

	Node *nodeToInsert = new Node(d);

	nodeToInsert->next = temp->next;
	temp->next->prev = nodeToInsert;
	temp->next = nodeToInsert;
	nodeToInsert->prev = temp;
}

void deleteNode(int pos, Node *&head)
{
	if (pos == 1)
	{
		Node *temp = head;
		temp->next->prev = NULL;
		head = temp->next;
		temp->next = NULL;
		delete temp;
	}
	else
	{
		Node *curr = head;
		Node *prev = NULL;
		int cnt = 1;
		while (cnt < pos)
		{
			prev = curr;
			curr = curr->next;
			cnt++;
		}
		curr->prev = NULL;
		prev->next = curr->next;
		curr->next = NULL;
		delete curr;
	}
}

int main()
{
	Node *head = NULL;
	Node *tail = NULL;

	insertAtHead(head, tail, 10);
	print(head);

	insertAtHead(head, tail, 20);
	print(head);

	insertAtHead(head, tail, 30);
	print(head);

	insertAtHead(head, tail, 40);
	print(head);

	insertAtTail(head, tail, 30);
	print(head);

	insertAtPosition(tail, head, 4, 50);
	print(head);

	deleteNode(4, head);
	print(head);
}

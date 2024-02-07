#include<iostream>
#include<algorithm>

// * Course Data Structure from Mohemd Dsoki  *
// -> covered:
// - Arrays using pointers 
// - LinkedList using Node
// - Stack using LinkedList
// - Queue using LinkedList
// - Binary Tree using Nodes

using namespace std;

/////////////////////////////////////////////////////////
//Array
class MyArray
{
	int size, length;
	int* ptr;
public:
	MyArray(int arrsize)
	{
		ptr = new int[arrsize];
		size = arrsize;
		length = 0;
	}
	void fill()
	{
		cout << "How many items you want to fill ?" << endl;
		int no_of_nums; cin >> no_of_nums;
		if (no_of_nums > size) { cout << "You can not exeed array size" << endl; return; }
		else
		{
			for(int i =0 ; i<no_of_nums ; i++)
			{
				cout << "Enter array item " << i + 1 << " : ";
				cin >> ptr[i];
				length++;
			}
		}
	}
	void display()
	{
		cout << "Array items : ";
		for (int i = 0; i < length; i++)
		{
			cout << ptr[i] << " ";
		}
		cout << endl;
	}
	int getsize() { return size; }
	int getlength() { return length; }
	int* getptr() { return ptr; }
	int search(int num)
	{
		int index = -1;
		for (int i = 0; i < length; i++)
		{
			if (num == ptr[i]) { index = i; break; }
		}
		return index;
	}
	void append()
	{
		if (length == size) cout << "Array is full" << endl;
		else if(length < size)
		{
			cout << "Enter number to append to array : "; int n; cin >> n;
			ptr[length] = n;
			length++;
		}
	}
	void insert(int index, int num)
	{
		if (index - 1 > size || index - 1 < 0) cout << "Not avilable index" << endl;
		else
		{
			for (int i = length; i > index - 1; i--)
			{
				ptr[i] = ptr[i - 1];
			}
			ptr[index - 1] = num;
			length++;
		}
	}
	void Delete(int index)
	{
		if (index - 1 > size || index - 1 < 0) cout << "Error - out of range!" << endl;
		else
		{
			for (int i = index - 1; i < length - 1; i++)
			{
				ptr[i] = ptr[i + 1];
			}
			length--;
		}
	}
	void enlarge(int newsize)
	{
		if (newsize <= size) { cout << "New size must be lager than old size" << endl; return; }
		else
		{
			size = newsize;
			int* old_ptr = ptr;
			ptr = new int[newsize];
			for (int i = 0; i < length; i++)
			{
				ptr[i] = old_ptr[i];
			}
			delete[] old_ptr; 
		}
	}
	void merge(MyArray Ma2)
	{
		size += Ma2.getsize(); 
		int* newptr = Ma2.getptr();
		for (int i = length; i < length + Ma2.getlength(); i++)
		{
			ptr[i] = newptr[i - length];
		}
		length += Ma2.getlength();
		delete[]newptr;
	}
	
};
void ArrayMenu(MyArray Ma)
{

	cout << "Choose : \n 1 - Display \n 2 - Get Size \n 3 - Get Length \n 4 - Search "<<
		"\n 5 - Append \n 6 - Insert \n 7 - Delete \n 8 - Enlarge \n 9 - Merge \n 0 - Back" << endl;
	cout << "Enter your choice : "; string choice; cin >> choice;
	cout << "**************************" << endl;
	if (choice == "Display" || choice == "display" || choice == "1")
	{
		Ma.display();
		cout << "**************************" << endl;
		ArrayMenu(Ma);
	}
	else if (choice == "Get Size" || choice == "get size" || choice == "2")
	{
		cout << "Array size equal : " << Ma.getsize() << endl;
		cout << "**************************" << endl;
		ArrayMenu(Ma);
	}
	else if (choice == "Get Length" || choice == "get length" || choice == "3")
	{
		cout << "Array length equal : " << Ma.getlength() << endl;
		cout << "**************************" << endl;
		ArrayMenu(Ma);
	}
	else if (choice == "Search" || choice == "search" || choice == "4")
	{
		cout << "Enter a number to search for : "; int num; cin >> num;
		int index = Ma.search(num);
		if (index == -1) cout << "Not found" << endl;
		else cout << "Found at index : " << index + 1 << endl;
		cout << "**************************" << endl;
		ArrayMenu(Ma);
	}
	else if (choice == "Append" || choice == "append" || choice == "5")
	{
		Ma.append();
		cout << "**************************" << endl;
		ArrayMenu(Ma);
	}
	else if (choice == "Insert" || choice == "insert" || choice == "6")
	{
		cout << "Enter the index you want to put in : "; int index; cin >> index;
		cout << "Enter the number : "; int num; cin >> num;
		Ma.insert(index, num);
		cout << "**************************" << endl;
		ArrayMenu(Ma);
	}
	else if (choice == "Delete" || choice == "delete" || choice == "7")
	{
		cout << "Enter the index you want to delete  : "; int index; cin >> index;
		Ma.Delete(index);
		cout << "**************************" << endl;
		ArrayMenu(Ma);
	}
	else if (choice == "Enlarge" || choice == "enlarge" || choice == "8")
	{
		cout << "Enter the new size : "; int newsize; cin >> newsize;
		Ma.enlarge(newsize);
		cout << "**************************" << endl;
		ArrayMenu(Ma);
	}
	else if (choice == "Merge" || choice == "merge" || choice == "9")
	{
		int size; cout << "Enter the New Array size : "; cin >> size;
		MyArray newarr(size);
		cout << "**************************" << endl;
		newarr.fill();
		Ma.merge(newarr);
		cout << "**************************" << endl;
		ArrayMenu(Ma);
	}
}
/////////////////////////////////////////////////////////
// Node for : LinkedList & Stack & Queue
struct Node
{
	int data;
	Node* next;

};
/////////////////////////////////////////////////////////
//LinkedList
class MyLinkedList
{
	
public:
	int size = 0;
	Node* head;
	MyLinkedList()
	{
		head = NULL;
	}
	bool is_empty() { return (head == NULL) ; }
	void inser_first(int num)
	{
		Node* newnode = new Node;
		newnode->data = num;
		if (is_empty())
		{
			head = newnode;
			newnode->next = NULL;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}
		size++;
	}
	void inser_before(int before_num, int newnum)
	{
		if (is_empty())
		{
			inser_first(newnum);
			return;
		}
		if (is_found(before_num))
		{
			Node* newnode = new Node();
			Node* temp = head;
			newnode->data = newnum;

			if (head->data == before_num)
			{
				inser_first(newnum);
				return;
			}

			while (temp != NULL && temp->next != NULL && temp->next->data != before_num)
			{
				temp = temp->next;
			}

			if (temp != NULL && temp->next != NULL)
			{
				newnode->next = temp->next;
				temp->next = newnode;
				size++;
			}
		}
		else
		{
			cout << "Number Not Found!!" << endl;
		}
	}
	void insert_last(int num)
	{
		if (!is_empty())
		{
			Node* temp = head;
			Node* newnode = new Node();
			newnode->data = num;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->next = NULL;
		}
		else
			inser_first(num);
	}

	void display()
	{
		if (!is_empty())
		{
			cout << "Linked List items : ";
			Node* temp = head;
			while (temp != NULL)
			{
				cout << temp->data ;
				if (temp->next != NULL) cout << " , ";
				temp = temp->next;
			}
			cout << endl;
		}
		else
			cout << "List is Empty!!!" << endl;
	}
	bool is_found(int num)
	{
		if (is_empty()) return false;
		else
		{
			Node* newnode = head;
			while (newnode != NULL)
			{
				if (newnode->data == num) return true;
				newnode = newnode->next;
			}
			return false;
		}
	}
	void Delete(int num)
	{
		if (is_found(num))
		{
			if (head->data == num)
			{
				Node* n = head;
				head = head->next;
				delete n;
			}
			else
			{
				Node* temp = head;
				Node* temp2 = head;
				while (temp->data != num)
				{
					temp2 = temp;
					temp = temp->next;
				}
				temp2->next = temp->next;
				delete temp;
			}
			size--;
		}
		else
			cout << "Error - number not found!!" << endl;
	}
};
void linkedlistmenu(MyLinkedList linkedlist)
{
	cout << "Choose : \n 1 - Insert \n 2 - Size \n 3 - Display \n 4 - Search For a Number \n 5 - Delete Item \n 0 - Back" << endl;
	cout << "Enter your choise : "; string n; cin >> n;
	
	cout << "**************************" << endl;
	if (n == "Insert" || n == "insert" || n == "1")
	{
		string cho; cout << "Choose : \n 1 - Insert First \n 2 - Insert Before \n 3 - Insert Last \n 0 - Back" << endl;
		cout << "Enter your choice : "; cin >> cho;
		if (cho == "Insert First" || cho == "insert first" || cho == "1")
		{
			int num; cout << "Enter the number you want to insert : "; cin >> num;
			linkedlist.inser_first(num);
		}
		else if (cho == "Insert Before" || cho == "insert before" || cho == "2")
		{
			int num2; cout << "Enter the number you want to insert before : "; cin >> num2;
			int num; cout << "Enter the number you want to insert : "; cin >> num;
			linkedlist.inser_before(num2,num);
		}
		else if (cho == "Insert Last" || cho == "insert last" || cho == "3")
		{
			int num; cout << "Enter the number you want to insert : "; cin >> num;
			linkedlist.insert_last(num);
		}
		cout << "**************************" << endl;
		linkedlistmenu(linkedlist);
	}
	else if (n == "Size" || n == "size" || n == "2")
	{
		if (!linkedlist.is_empty())
			cout << "Linked List size : " << linkedlist.size << endl;
		else
			cout << "List is empty!!" << endl;
		cout << "**************************" << endl;
		linkedlistmenu(linkedlist);
	}
	else if (n == "Display" || n == "display" || n == "3")
	{
		linkedlist.display();
		cout << "**************************" << endl;
		
		linkedlistmenu(linkedlist);
	}
	else if (n == "Search For a Number" || n == "search for a number" || n == "4")
	{
		cout << "Enter a Number you want to check it is in the list or not : "; int num; cin >> num;
		cout << "**************************" << endl;
		cout << "-------->";
		if (linkedlist.is_found(num)) cout << "Found" << endl;
		else cout << "Not found" << endl;
		cout << "**************************" << endl;

		linkedlistmenu(linkedlist);
	}
	else if (n == "Delete Item" || n == "delete item" || n == "5")
	{
		if (linkedlist.is_empty()) {
			cout << "List is Empty!!" << endl;
		}
		else
		{
			cout << "Enter the item you want to delete : "; int num; cin >> num;
			linkedlist.Delete(num);
		}
		
		cout << "**************************" << endl;

		linkedlistmenu(linkedlist);
	}

}
/////////////////////////////////////////////////////////
//Stack
class Mystack
{
	Node* top;
	int size = 0;
public:
	Mystack() { top = NULL; }
	bool is_empty() { return (top == NULL); } // return ( size == 0 ) ;
	void push(int num)
	{
		Node* newnode = new Node();
		newnode->data = num;
		if (is_empty())
		{
			top = newnode;
		}
		else
		{
			newnode->next = top;
			top = newnode;
		}
		size++;
	}
	int pop()
	{
		if (!is_empty())
		{
			int ret = top->data;
			Node* t = top;
			top = top->next;
			delete t;
			size--;
			return ret;
		}
		else
			return -1;
	}
	int peek() { return top->data; }
	void display()
	{
		if (!is_empty())
		{
			cout << "Stack items equal : ";
			Node* temp = top;
			while (temp != NULL)
			{
				cout << temp->data;
				if (temp->next != NULL) cout << " , ";
				temp = temp->next;
			}
			cout << endl;
		}
		else
			cout << "Stack is Emplty!!\n";
	}
	int getsize() { return size; }
	bool is_Found(int num)
	{
		Node* temp = top;
		while (temp != NULL)
		{
			if (temp->data == num) return true;
			temp = temp->next;
		}
		return false;
	}
};
void stackmenu(Mystack mystack)
{
	cout << "Choose : \n 1 - Push \n 2 - Pop \n 3 - Display \n 4 - Peek \n 5 - Size \n 6 - Find \n 0 - Exit" << endl;
	cout << "Enter your choice : "; string choice1; cin >> choice1;
	if (choice1 == "Push" || choice1 == "push" || choice1 == "1")
	{
		cout << "Enter the number you want to push : "; int num; cin >> num;
		mystack.push(num);
		cout << "**************************" << endl;
		stackmenu(mystack);
	}
	else if (choice1 == "Pop" || choice1 == "pop" || choice1 == "2")
	{
		
		if (!mystack.is_empty()) cout << "Pop : "<< mystack.pop() << endl;
		else cout << "Stack is Emplty!!\n";
		cout << "**************************" << endl;
		stackmenu(mystack);
	}
	else if (choice1 == "Display" || choice1 == "display" || choice1 == "3")
	{
		mystack.display();
		cout << "**************************" << endl;
		stackmenu(mystack);
	}
	else if (choice1 == "Peek" || choice1 == "peek" || choice1 == "4")
	{
		if (!mystack.is_empty())
		{
			cout << "Top item : " << mystack.peek() << endl;
		}
		else
			cout << "Stack is empty!!" << endl;
		cout << "**************************" << endl;
		stackmenu(mystack);
	}
	else if (choice1 == "Size" || choice1 == "size" || choice1 == "5")
	{
		if (!mystack.is_empty()) {
			cout << "stack size : " << mystack.getsize() << endl;
		}
		else
			cout << "Stack is empty!!" << endl;
		cout << "**************************" << endl;
		stackmenu(mystack);
	}
	else if (choice1 == "Find" || choice1 == "find" || choice1 == "6")
	{
		if (!mystack.is_empty())
		{
			cout << "Enter the number you are searching for : "; int num; cin >> num;
			if (mystack.is_Found(num)) cout << "Found" << endl;
			else
				cout << "Not Found" << endl;
		}
		else
			cout << "Stack is empty!!" << endl;
		cout << "**************************" << endl;
		stackmenu(mystack);
	}


}
/////////////////////////////////////////////////////////
//Queue
class MyQueue
{
	Node* front;
	Node* rear;
	int size = 0;
public:
	MyQueue()
	{
		front = NULL;
		rear = NULL;
	}
	bool is_empty() { return (front == NULL); }
	int GetSize() { return size; }
	void Enqueue(int num)
	{
		Node* temp = new Node();
		temp->data = num;
		if (is_empty())
		{
			rear = temp;
			front = temp;
		}
		else
		{
			rear->next = temp;
			rear = temp;
		}
		
		size++;
	}
	int peek() { return front->data; }
	int getrear(){ return rear->data; }
	int Dequeue()
	{
			Node* temp = front;
			int value = temp->data;
			if (front == rear)
				front = rear = NULL;
			else
				front = front->next;
			delete temp;
			size--;
			return value;
		
	}
	void Display()
	{
		if (is_empty()) {
			cout << "Queue Is Empty!!!" << endl; return;
		}
		else
		{
			Node* temp = front;
			cout << "Queue items :";
			while (temp != NULL)
			{
				cout << temp->data;
				if (temp->next != NULL) cout << " , ";
				temp = temp->next;
			}
			cout << endl;
		}
	}
	bool if_found(int num)
	{
		Node* temp = front;
		while (temp != NULL)
		{
			if (temp->data == num) return true;
			temp = temp->next;
		}
		return false;
	}
	void clear()
	{
		while (!is_empty())
			Dequeue();
	}
};
void QueueMenu(MyQueue Mq)
{
	cout << "Choose : \n 1 - Enqueue \n 2 - Dequeue \n 3 - Display \n 4 - Peek \n 5 - Search \n 6 - Clear \n 7 - Size \n 8 - Get Back \n 0 - Back" << endl;
	cout << "Enter you choice : "; string cho3; cin >> cho3;
	cout << "**************************" << endl;
	if (cho3 == "Enqueue" || cho3 == "enqueue" || cho3 == "1")
	{
		cout << "Enter The number you want to Enqueue : "; int num; cin >> num;
		Mq.Enqueue(num);
		cout << "**************************" << endl;
		QueueMenu(Mq);
	}
	else if (cho3 == "Dequeue" || cho3 == "dequeue" || cho3 == "2")
	{
		if (Mq.is_empty()) {
			cout << "Queue Is Empty!!!" << endl;
		}
		else
		{
			cout << "Dequeue : " << Mq.Dequeue() << endl;
		}
		cout << "**************************" << endl;
		QueueMenu(Mq);
	}
	else if (cho3 == "Display" || cho3 == "display" || cho3 == "3")
	{
		Mq.Display();
		cout << "**************************" << endl;
		QueueMenu(Mq);
	}
	else if (cho3 == "Peek" || cho3 == "peek" || cho3 == "4")
	{
		if (!Mq.is_empty())
			cout << "Item : " << Mq.peek() << endl;
		else
			cout << "Queue is Empty!!!" << endl;
		cout << "**************************" << endl;
		QueueMenu(Mq);
	}
	else if (cho3 == "Search" || cho3 == "search" || cho3 == "5")
	{
		if (!Mq.is_empty())
		{
			int num; cout << "Enter the number you are searching for : "; cin >> num;
			if (Mq.if_found(num))
				cout << "Found" << endl;
			else
				cout << "Not Found" << endl;
		}
		else
			cout << "Queue is Empty!!!" << endl;
		cout << "**************************" << endl;
		QueueMenu(Mq);
	}
	else if (cho3 == "Clear" || cho3 == "clear" || cho3 == "6")
	{
		if (!Mq.is_empty())
		{
			Mq.clear(); cout << "Queue is cleared" << endl;
		}
		else
			cout << "Queue is Empty!!!" << endl;
		cout << "**************************" << endl;
		QueueMenu(Mq);
	}
	else if (cho3 == "Size" || cho3 == "size" || cho3 == "7")
	{
		if (!Mq.is_empty())
		{
			cout << "Queue size : " << Mq.GetSize() << endl;
		}
		else
			cout << "Queue is Empty!!!" << endl;
		cout << "**************************" << endl;
		QueueMenu(Mq);
	}
	else if (cho3 == "Get Back" || cho3 == "get back" || cho3 == "8")
	{
		if (!Mq.is_empty())
		{
			cout << "Back item is : " << Mq.getrear() << endl;
		}
		else
			cout << "Queue is Empty!!!" << endl;
		cout << "**************************" << endl;
		QueueMenu(Mq);
	}
}
/////////////////////////////////////////////////////////
//Binary Tree
struct BTN // Binary Tree Node
{
	int data;
	BTN* left;
	BTN* right;
	BTN(int item) { data = item; left = right = NULL; }
};
BTN* insert(BTN* root, int item)
{
	BTN* newnode = new BTN(item);
	if (root == NULL)
	{
		root = newnode;
		return newnode;
	}
	else
	{
		if (newnode->data < root->data)
		{
			root->left = insert(root->left, item);
		}
		else
		{
			root->right = insert(root->right, item);
		}
	}
	return root;

}
void preorder(BTN* r) // root->left->right
{
	if (r == NULL)
	{
		return;
	}
	else
	{
		cout << r->data << " ";
		preorder(r->left);
		preorder(r->right);
	}
}
void inorder(BTN* r) // left->root->right
{
	if (r == NULL)
	{
		return;
	}
	else
	{
		inorder(r->left);
		cout << r->data << " ";
		inorder(r->right);
	}
}
void postrder(BTN* r) // left->root->right
{
	if (r == NULL)
	{
		return;
	}
	else
	{
		postrder(r->left);
		postrder(r->right);
		cout << r->data << " ";
	}
}
bool search(BTN* r , int item)
{
	if (r == NULL) return false;
	else if (r->data == item)
	{
		return true;
	}
	else
	{
		if (item < r->data)
		{
			return search(r->left, item);
		}
		else
			return search(r->right, item);
	}
	return false;
}
BTN* FindMin(BTN* r)
{
	if (r == NULL) return NULL;
	else if (r->left == NULL) return r;
	else return FindMin(r->left);
}
BTN* FindMax(BTN* r)
{
	if (r == NULL) return NULL;
	else if (r->right == NULL) return r;
	else return FindMax(r->right);
}
BTN* Delete(BTN* r, int item)
{
	if (r == NULL) return NULL;
	else if (item < r->data)
	{
		r->left = Delete(r->left, item);
	}
	else if (item > r->data)
	{
		r->right = Delete(r->right, item);
	}
	else
	{
		if (r->left == NULL && r->right == NULL)
		{
			r = NULL;
		}
		else if (r->left == NULL && r->right != NULL)
		{
			r->data = r->right->data;
			delete r->right;
			r->right = NULL;
		}
		else if(r->left != NULL && r->right == NULL)
		{
			r->data = r->left->data;
			delete r->left;
			r->left = NULL;
		}
		else
		{
			BTN* MAX = FindMax(r->left);
			r->data = MAX->data;
			r->left = Delete(r->left, MAX->data);
		}
	}
	return r;
}
class binary_tree
{
	BTN* root; 
	int size = 0;
public:
	bool is_empty() { return (root == NULL); }
	binary_tree() { root = NULL; }
	void Insert(int item) { root = insert(root, item); }
	void display() { preorder(root); }
	void display2() { inorder(root); }
	void display3() { postrder(root); }
	bool Search(int item) { return search(root, item); }
	void DELETE(int item) { root = Delete(root, item); }
	int MinNum() { return FindMin(root)->data; }
	int MaxNum() { return FindMax(root)->data; }
};
void binary_tree_menu(binary_tree bt)
{
	cout << "Choose : \n 1 - Insert \n 2 - Display \n 3 - Search \n 4 - Delete \n 5 - Fill \n 0 - Back" << endl;
	string cho4; cout << "Enter your choice : "; cin >> cho4;
	cout << "**************************" << endl;
	if (cho4 == "Insert" || cho4 == "insert" || cho4 == "1")
	{
		cout << "Enter the item : "; int num; cin >> num;
		bt.Insert(num);	
		cout << "**************************" << endl;
		binary_tree_menu(bt);
	}
	else if (cho4 == "Display" || cho4 == "display" || cho4 == "2")
	{
		if (!bt.is_empty())
		{
			cout << "Choose : \n 1 - Preorder \n 2 - Inorder \n 3 - Postorder \n 0 - Back" << endl;
			cout << "Enter your choice : "; string s; cin >> s;
			if (s == "Preorder" || s == "preorder" || s == "1")
			{
				cout << "Tree Items : ";
				bt.display();
				cout << endl;
			}
			else if (s == "Inorder" || s == "inorder" || s == "2")
			{
				cout << "Tree Items : ";
				bt.display2();
				cout << endl;
			}
			else if (s == "Postorder" || s == "postorder" || s == "3")
			{
				cout << "Tree Items : ";
				bt.display3();
				cout << endl;
			}
		}
		else
			cout << "Tree is Empty!!" << endl;
		cout << "**************************" << endl;
		binary_tree_menu(bt);
	}
	else if (cho4 == "Search" || cho4 == "search" || cho4 == "3")
	{
		cout << "Enter the item : "; int num; cin >> num;
		if (bt.Search(num)) cout << "Found" << endl;
		else cout << "Not Found" << endl;
		cout << "**************************" << endl;
		binary_tree_menu(bt);
	}
	else if (cho4 == "Delete" || cho4 == "delete" || cho4 == "4")
	{
		cout << "Enter the item : "; int num; cin >> num;
		if (num < bt.MinNum() || num > bt.MaxNum()) {
			cout << "Item not Found" << endl;
		}
		else
			bt.DELETE(num);
		cout << "**************************" << endl;
		binary_tree_menu(bt);
	}
	else if (cho4 == "Fill" || cho4 == "fill" || cho4 == "5")
	{
		bt.Insert(45);
		bt.Insert(15);
		bt.Insert(79);
		bt.Insert(55);
		bt.Insert(50);
		bt.Insert(90);
		bt.Insert(10);
		bt.Insert(12);
		bt.Insert(20);
		bt.Insert(60);
		bt.Insert(100);
		cout << "**************************" << endl;
		binary_tree_menu(bt);
	}
}
/////////////////////////////////////////////////////////
//Menu of all
void menu()
{
	cout << "Choose : \n 1 - Array \n 2 - LinkedList \n 3 - Stack ( Using Linked List ) \n 4 - Queue ( Using Linked List ) \n 5 - BinaryTree "<<
		" \n 0 - Exit" << endl;
	cout << "Enter your choice : "; string choice; cin >> choice;
	if (choice == "Array" || choice == "array" || choice == "1")
	{
		cout << "Enter Array Size : ";
		int size; cin >> size;
		cout << "**************************" << endl;
		MyArray Ma(size);
		Ma.fill();
		ArrayMenu(Ma);
		cout << "**************************" << endl;
		menu();
	}
	else if (choice == "Linked List" || choice == "linkedlist" || choice == "2")
	{
		MyLinkedList linkedlist;
		linkedlistmenu(linkedlist);
		cout << "**************************" << endl;
		menu();
	}
	else if (choice == "Stack" || choice == "stack" || choice == "3")
	{
		Mystack mystack;
		stackmenu(mystack);
		cout << "**************************" << endl;
		menu();
	}
	else if (choice == "Queue" || choice == "queue" || choice == "4")
	{
		MyQueue My;
		QueueMenu(My);
		cout << "**************************" << endl;
		menu();
	}
	else if (choice == "Binary Tree" || choice == "binarytree" || choice == "5")
	{
		binary_tree bt;
		binary_tree_menu(bt);
		cout << "**************************" << endl;
		menu();
	}
}
/////////////////////////////////////////////////////////
//Main
int main()
{
	menu();
	cout << "***************************" << endl;
	cout << "**Thank you :) ... ByeBye**" << endl;
	cout << "***************************" << endl;

	return 0;
}
/////////////////////////////////////////////////////////
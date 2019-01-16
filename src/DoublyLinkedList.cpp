/*	Copyright 2019 heiyedeshengyin All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST
#include<iostream>
using namespace std;

//================双链表的结点================
template <typename T>
struct Node
{
	T data;	//结点存储的数据
	Node *next;	//指向下一个结点的指针
	Node *prev;	//指向上一个结点的指针
	//结点的构造函数
	Node(T x)
	{
		data = x;
		next = NULL;
		prev = NULL;
	}
};

//================双链表================
template <typename T>
class DoublyLinkedList
{
private:
	Node<T> *head;	//头结点
	Node<T> *tail;	//尾结点
	int size;	//元素的个数
public:
	DoublyLinkedList();	//无参构造函数
	DoublyLinkedList(T x);	//含参构造函数
	~DoublyLinkedList();	//析构函数
	void creatList();	//按流程创建一个链表
	int getSize();	//获取链表的元素个数
	bool isEmpty();	//判断链表是否为空
	void addAtHead(T _cur);	//添加元素到第一个元素前
	void addAtTail(T _cur);	//添加元素到最后一个元素后
	void addAtIndex(int index, T _cur);	//添加元素到指定位置
	T getHead();	//获取第一个元素
	T getTail();	//获取最后一个元素
	T get(int index);	//获取指定元素
	T removeHead();	//删除第一个元素
	T removeTail();	//删除最后一个元素
	T remove(int index);	//删除指定元素
	T setHead(T _cur);	//修改第一个元素
	T setTail(T _cur);	//修改最后一个元素
	T set(int index, T _cur);	//修改指定元素
	void show();	//输出链表
};

//================函数的实现================
/*
	双链表的无参构造函数
*/
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

//------------------------------------------------------------------
/*
	双链表的含参构造函数
	T x:第一个元素的值
*/
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(T x)
{
	head = new Node<T>(x);
	tail = head;
	size = 1;
}

//------------------------------------------------------------------
/*
	双链表的析构函数
*/
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	if (size == 0)
		return;
	else
	{
		Node<T> *p;
		Node<T> *q;
		p = head;
		q = tail;
		while (p->next != q && p != q)
		{
			p = p->next;
			delete head;
			head = p;
			q = q->prev;
			delete tail;
			tail = q;
		}
		if (p == q)
		{
			delete p;
			p = NULL;
			q = NULL;
		}
		else
		{
			delete q;
			delete p;
			p = NULL;
			q = NULL;
		}
	}
}

//------------------------------------------------------------------
/*
	按流程创建一个链表

	@Return void
*/
template <typename T>
void DoublyLinkedList<T>::creatList()
{
	if (size == 0)
	{
		int length;
		cout << "该链表无头结点,请输入链表的长度:";
		cin >> length;
		if (length > 0)
		{
			T *n;
			n = new T[length];
			cout << "请依次输入" << length << "个存储进链表的元素:" << endl;
			for (int i = 0; i < length; i++)
				cin >> n[i];
			for (int i = 0; i < length; i++)
				addAtTail(n[i]);
			delete n;
		}
		else
			cout << "输入的值不符合规范,请输入大于0的整数" << endl;
	}
	else if (size == 1)
	{
		int length;
		cout << "该链表有头结点,头结点的值为" << head->data << ",请输入链表的长度:";
		cin >> length;
		if (length > 0)
		{
			T *n;
			n = new T[length - 1];
			cout << "请依次输入" << length - 1 << "个存储进链表的元素:" << endl;
			for (int i = 0; i < length - 1; i++)
				cin >> n[i];
			for (int i = 0; i < length - 1; i++)
				addAtTail(n[i]);
			delete n;
		}
		else
			cout << "输入的值不符合规范,请输入大于0的整数" << endl;
	}
	else
		cout << "该链表的长度大于1,请使用链表的其它函数" << endl;
}

//------------------------------------------------------------------
/*
	获取链表的元素个数

	@Return int
*/
template <typename T>
int DoublyLinkedList<T>::getSize()
{
	return size;
}

//------------------------------------------------------------------
/*
	判断链表是否为空

	@Return bool
*/
template <typename T>
bool DoublyLinkedList<T>::isEmpty()
{
	return size == 0;
}

//------------------------------------------------------------------
/*
	添加一个新元素到第一个元素之前
	T _cur:添加的新元素

	@Return void
*/
template <typename T>
void DoublyLinkedList<T>::addAtHead(T _cur)
{
	if (size != 0)
	{
		Node<T> *cur;
		cur = new Node<T>(_cur);
		cur->next = head;
		head->prev = cur;
		cur->prev = NULL;
		head = cur;
		size++;
	}
	else
	{
		head = new Node<T>(_cur);
		tail = head;
		size = 1;
	}
}

//------------------------------------------------------------------
/*
	添加一个新元素到最后一个元素之后
	T _cur:添加的新元素

	@Return void
*/
template <typename T>
void DoublyLinkedList<T>::addAtTail(T _cur)
{
	if (size != 0)
	{
		Node<T> *cur;
		cur = new Node<T>(_cur);
		cur->prev = tail;
		tail->next = cur;
		cur->next = NULL;
		tail = cur;
		size++;
	}
	else
	{
		tail = new Node<T>(_cur);
		head = tail;
		size = 1;
	}
}

//------------------------------------------------------------------
/*
	添加一个新元素到指定位置
	int index:新元素在链表中的位置
	T _cur:添加的新元素

	@Return void
*/
template <typename T>
void DoublyLinkedList<T>::addAtIndex(int index, T _cur)
{
	if (index < 0 || index > size)
		cout << "addAtIndex函数错误,错误原因:index的值不符合规范" << endl;
	else
		if (index == 0)
			addAtHead(_cur);
		else if (index == size)
			addAtTail(_cur);
		else if (index < (size / 2))
		{
			Node<T> *cur;
			cur = new Node<T>(_cur);
			Node<T> *temp;
			temp = head;
			for (int i = 0; i < index - 1; i++)
				temp = temp->next;
			cur->next = temp->next;
			temp->next->prev = cur;
			temp->next = cur;
			cur->prev = temp;
			size++;
		}
		else
		{
			Node<T> *cur;
			cur = new Node<T>(_cur);
			Node<T> *temp;
			temp = tail;
			for (int i = size - 1; i > index; i--)
				temp = temp->prev;
			cur->prev = temp->prev;
			temp->prev->next = cur;
			temp->prev = cur;
			cur->next = temp;
			size++;
		}
}

//------------------------------------------------------------------
/*
	获取链表的第一个元素

	@Return T
*/
template <typename T>
T DoublyLinkedList<T>::getHead()
{
	if (size == 0)
	{
		cout << "getHead函数错误,错误原因:链表为空" << endl;
		return NULL;
	}
	else
		return head->data;
}

//------------------------------------------------------------------
/*
	获取链表的最后一个元素

	@Return T
*/
template <typename T>
T DoublyLinkedList<T>::getTail()
{
	if (size == 0)
	{
		cout << "getTail函数错误,错误原因:链表为空" << endl;
		return NULL;
	}
	else
		return tail->data;
}

//------------------------------------------------------------------
/*
	获取指定位置的元素
	int index:获取的元素在链表中的位置

	@Return T
*/
template <typename T>
T DoublyLinkedList<T>::get(int index)
{
	if (index < 0 || index >= size)
	{
		cout << "get函数错误,错误原因:index的值不符合规范" << endl;
		return NULL;
	}
	else
		if (index < (size / 2))
		{
			Node<T> *temp;
			temp = head;
			for (int i = 0; i < index; i++)
				temp = temp->next;
			return temp->data;
		}
		else
		{
			Node<T> *temp;
			temp = tail;
			for (int i = size - 1; i > index; i--)
				temp = temp->prev;
			return temp->data;
		}
}

//------------------------------------------------------------------
/*
	删除第一个元素,并返回被删除的元素

	@Return T
*/
template <typename T>
T DoublyLinkedList<T>::removeHead()
{
	if (size == 0)
	{
		cout << "removeHead函数错误,错误原因:链表为空" << endl;
		return NULL;
	}
	else
	{
		Node<T> *temp;
		Node<T> *removed;
		temp = head->next;
		removed = head;
		temp->prev = NULL;
		head->next = NULL;
		head = temp;
		size--;
		T _data = removed->data;
		delete removed;
		return _data;
	}
}

//------------------------------------------------------------------
/*
	删除最后一个元素,并返回被删除的元素

	@Return T
*/
template <typename T>
T DoublyLinkedList<T>::removeTail()
{
	if (size == 0)
	{
		cout << "removeTail函数错误,错误原因:链表为空" << endl;
		return NULL;
	}
	else
	{
		Node<T> *temp;
		Node<T> *removed;
		temp = tail->prev;
		removed = tail;
		temp->next = NULL;
		tail->prev = NULL;
		tail = temp;
		size--;
		T _data = removed->data;
		delete removed;
		return _data;
	}
}

//------------------------------------------------------------------
/*
	删除指定位置的元素,并返回被删除的元素
	int index:要删除的元素所在的位置

	@Return T
*/
template <typename T>
T DoublyLinkedList<T>::remove(int index)
{
	if (index < 0 || index >= size)
	{
		cout << "remove函数错误,错误原因:index的值不符合规范" << endl;
		return NULL;
	}
	else
		if (index == 0)
			return removeHead();
		else if (index == size - 1)
			return removeTail();
		else if (index < (size / 2))
		{
			Node<T> *temp;
			temp = head;
			for (int i = 0; i < index - 1; i++)
				temp = temp->next;
			Node<T> *removed;
			removed = temp->next;
			temp->next = removed->next;
			removed->next->prev = temp;
			size--;
			T _data = removed->data;
			delete removed;
			return _data;
		}
		else
		{
			Node<T> *temp;
			temp = tail;
			for (int i = size - 1; i > index + 1; i--)
				temp = temp->prev;
			Node<T> *removed;
			removed = temp->prev;
			temp->prev = removed->prev;
			removed->prev->next = temp;
			size--;
			T _data = removed->data;
			delete removed;
			return _data;
		}
}

//------------------------------------------------------------------
/*
	修改第一个元素,并返回被修改的元素
	T _cur:要修改上去的元素

	@Return T
*/
template <typename T>
T DoublyLinkedList<T>::setHead(T _cur)
{
	if (size == 0)
	{
		cout << "setHead函数错误,错误原因:链表为空" << endl;
		return NULL;
	}
	else
	{
		T _data = head->data;
		head->data = _cur;
		return _data;
	}
}

//------------------------------------------------------------------
/*
	修改最后一个元素,并返回被修改的元素
	T _cur:要修改上去的元素

	@Return T
*/
template <typename T>
T DoublyLinkedList<T>::setTail(T _cur)
{
	if (size == 0)
	{
		cout << "setTail函数错误,错误原因:链表为空" << endl;
		return NULL;
	}
	else
	{
		T _data = tail->data;
		tail->data = _cur;
		return _data;
	}
}

//------------------------------------------------------------------
/*
	修改指定位置的元素,并返回被修改的元素
	int index:要修改的元素的位置
	T _cur:要修改上去的元素

	@Return T
*/
template <typename T>
T DoublyLinkedList<T>::set(int index, T _cur)
{
	if (index < 0 || index >= size)
	{
		cout << "set函数错误,错误原因:index的值不符合规范" << endl;
		return NULL;
	}
	else
		if (index < (size / 2))
		{
			Node<T> *temp;
			temp = head;
			for (int i = 0; i < index; i++)
				temp = temp->next;
			T _data = temp->data;
			temp->data = _cur;
			return _data;
		}
		else
		{
			Node<T> *temp;
			temp = tail;
			for (int i = size - 1; i > index; i--)
				temp = temp->prev;
			T _data = temp->data;
			temp->data = _cur;
			return _data;
		}
}

//------------------------------------------------------------------
/*
	输出链表

	@Return void
*/
template <typename T>
void DoublyLinkedList<T>::show()
{
	for (int i = 0; i < size - 1; i++)
		cout << this->get(i) << " -> ";
	cout << tail->data << endl;
}

//------------------------------------------------------------------
/*
	输出链表

	@Return ostream
*/
template <typename T>
ostream &operator<<(ostream &os, DoublyLinkedList<T> &m)
{
	for (int i = 0; i < m.getSize() - 1; i++)
		os << m.get(i) << " -> ";
	os << m.getTail();
	return os;
}

#endif // !DOUBLYLINKEDLIST

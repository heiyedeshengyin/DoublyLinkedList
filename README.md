# DoublyLinkedList
其它数据结构:[单链表](https://github.com/heiyedeshengyin/LinkedList) [二叉树](https://github.com/heiyedeshengyin/BinaryTree) [二叉搜索树](https://github.com/heiyedeshengyin/BinarySearchTree) [AVL树](https://github.com/heiyedeshengyin/AVLTree)

### 简介
双链表,链表的进阶版,基本的数据结构  
与单链表不同的是,它的每个结点有两个指针,一个指向下一个结点,一个指向上一个结点

### 数据结构
双链表的结点的数据结构
```cpp
template <typename T>
struct Node
{
	T data;	//结点存储的数据
	Node *next;	//指向下一个结点的指针
	Node *prev;	//指向上一个结点的指针
	Node(T x) //双链表的结点的构造函数
	{
		data = x;
		next = NULL;
		prev = NULL;
	}
};
```  

双链表的数据结构
```cpp
template <typename T>
class DoublyLinkedList
{
	Node<T> *head;	//头结点
	Node<T> *tail;	//尾结点
	int size;	//元素的个数
};
```  

### 函数列表
DoublyLinkedList();	//无参构造函数  
DoublyLinkedList(T x);	//含参构造函数  
DoublyLinkedList(vector\<T\> arr);	//含参构造函数  
~DoublyLinkedList();	//析构函数  
void creatList();	//按流程创建一个链表  
int getSize();	//获取链表的元素个数  
bool isEmpty();	//判断链表是否为空  
void clear();	//清空链表  
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
vector\<T\> list2Vector();	//链表转vector型数组  
T* list2Array();	//链表转普通数组  
void show();	//输出链表  
T operator[] (int r);	//重载[]运算符  

### 使用说明
把src/DoublyLinkedList.cpp添加到你的源文件中  
以下为示例代码
```cpp
#include"DoublyLinkedList.cpp"

int main()
{
	DoublyLinkedList<int> l1;
	l1.addAtHead(1);
	l1.addAtHead(2);
	l1.addAtHead(3);
	l1.addAtHead(4);
	l1.addAtTail(5);
	l1.show();
	cout << l1.getSize() << endl;

	l1.addAtIndex(3, 998);
	l1.show();
	cout << l1.getSize() << endl;

	cout << l1.getHead() << endl;
	cout << l1.getTail() << endl;
	cout << l1.get(4) << endl;

	l1.show();
	cout << l1.getSize() << endl;
	cout << l1.remove(0) << endl;
	l1.show();
	cout << l1.getSize() << endl;

	l1.show();
	cout << l1.set(3, 342) << endl;
	l1.show();

	DoublyLinkedList<double> l2;
	l2.creatList();
	cout << l2 << endl;
	cout << l2.getSize() << endl;

	return 0;
}
```

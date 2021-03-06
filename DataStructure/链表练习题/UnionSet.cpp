/*************************************************************************
	> File Name: UnionSet.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 六  7/15 14:43:59 2017
 ************************************************************************/

//求两个已排序链表的相同的数据
//思路：
//两个指针分别指向两个链表，谁小谁先走，找到相等的就保存起来，然后接着让小的走，一直找，直到有一个链表走完。
#include <iostream>
#include <vector>
using namespace std;

typedef struct ListNode
{
	int _data;
	ListNode *_next;

	ListNode(int data)
		:_data(data)
		 ,_next(NULL)
	{}
}Node;

vector<int> UnionSet(Node *head1, Node *head2)
{
	vector<int> ret;
	Node *cur1 = head1;
	Node *cur2 = head2;
	while(cur1 && cur2)
	{
		if(cur1->_data == cur2->_data)
		{
			ret.push_back(cur1->_data);
			cur1 = cur1->_next;
			cur2 = cur2->_next;
		}
		else if(cur1->_data < cur2->_data)
			cur1 = cur1->_next;
		else  //cur2->_data < cur1->_data
			cur2 = cur2->_next;
	}
	return ret;
}

int main()
{
	Node *head1;
	Node *head2;
	Node *node1 = new Node(1);
	Node *node2 = new Node(2);
	Node *node3 = new Node(4);
	Node *node4 = new Node(6);
	Node *node5 = new Node(8);
	node1->_next = node2;
	node2->_next = node3;
	node3->_next = node4;
	node4->_next = node5;

	Node *node6 = new Node(1);
	Node *node7 = new Node(3);
	Node *node8 = new Node(5);
	Node *node9 = new Node(5);
	Node *node10 = new Node(6);
	node6->_next = node7;
	node7->_next = node8;
	node8->_next = node9;
	node9->_next = node10;

	head1 = node1;
	head2 = node6;
	
	vector<int> ret = UnionSet(head1, head2);
	vector<int>::iterator it = ret.begin();
	while(it != ret.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}

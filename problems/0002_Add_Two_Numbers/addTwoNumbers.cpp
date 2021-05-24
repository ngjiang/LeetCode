#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode *l3, **node;
    	int sum=0;
    	l3=NULL, node=&l3;
    	while(l1!=NULL || l2!=NULL || sum>0){
    		if(l1!=NULL) sum+=l1->val, l1=l1->next;
    		if(l2!=NULL) sum+=l2->val, l2=l2->next;
    		*node = new ListNode(sum%10);
    		node = &((*node)->next);
    		sum/=10;
    	}
    	return l3;
    }
};

ListNode* intToList(int x){
	ListNode *l;
	l = new ListNode(x%10);
	if(x>9)	l->next = intToList(x/10);
	return l;
}

void printList(ListNode *l){
	ListNode *node;
	for(node=l; node!=NULL; node=node->next){
		cout << node->val;
		if(node->next!=NULL) cout << '-'; 
	}
	cout << endl;
}

int main(){
	int x1, x2;
	ListNode *l1, *l2;
	Solution s;

	// Example 1
	x1 = 342;
	x2 = 465;
	l1 = intToList(x1);
	l2 = intToList(x2);
	printList(s.addTwoNumbers(l1, l2));

	// Example 2
	x1 = 0;
	x2 = 0;
	l1 = intToList(x1);
	l2 = intToList(x2);
	printList(s.addTwoNumbers(l1, l2));

	// Example 3
	x1 = 9999999;
	x2 = 9999;
	l1 = intToList(x1);
	l2 = intToList(x2);
	printList(s.addTwoNumbers(l1, l2));

	return 0;
}

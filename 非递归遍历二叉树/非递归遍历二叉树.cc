#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

typedef struct TreeNode {
	char val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//创建结点
TreeNode* createNode(char val) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

//递归遍历
void preOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%c  ", root->val);
	preOrder(root->left);
	preOrder(root->right);
	return;
}

//非递归的先序遍历
void preOrderNoR(TreeNode* root) {
	//从根节点进入，根节点入栈，
	//打印根节点，根节点出栈，并将根节点的非空左孩子入栈
	//如果左孩子为空，就入其右孩子。
	if (root == NULL) {
		return;
	}
	//创建一个栈
	stack <TreeNode*> s;
	TreeNode* cur = root;
	//循环
	while (cur != NULL || !s.empty()) {	
		//先遍历所有左结点，打印后，再入栈
		while (cur) {
			printf("%c  ", cur->val);
			s.push(cur);
			cur = cur->left;
		}	
		//所有的左结点已经打印完毕，
		//取栈顶指针，更新cur为最后一个左结点的右子树
		TreeNode* top = s.top();
		s.pop();//更新栈顶指针，	
		cur = top->right;		
	}
}

//非递归的中序遍历
void inOrderNoR(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	//建栈
	stack<TreeNode*> s;
	TreeNode* cur = root;//遍历指针
	while (cur || !s.empty()) {
		while (cur) {
			s.push(cur);
			cur = cur->left;
		}
		TreeNode* top = s.top();
		printf("%c  ", top->val);
		s.pop();
		cur = top->right;
	}
}

//非递归的后序遍历
void postOrderNoR(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	stack<TreeNode*> s;
	TreeNode* cur = root;
	TreeNode* last = NULL;
	//由于后序不知道是第几次访问到该节点，
	//因此用last来记录最近一个被打印的结点
	while (cur != NULL || !s.empty()) {
		while (cur) {    //第一次
			s.push(cur);
			cur = cur->left;
		}
		//左子树走完了，
		//获取栈顶指针，右子树压栈,
		TreeNode* top = s.top();
		if (top->right == NULL) {
			printf("%c  ", top->val);
			s.pop();
			last = top;
		}
		//如果栈顶的右子树是上一次打印过的，就也让它打印
		else if (top->right == last) {
			printf("%c  ", top->val);
			s.pop();
			last = top;
		}
		else {
			cur = top->right;
		}

	}
}

void test() {

	//创建二叉树
	TreeNode* a = createNode('A');
	TreeNode* b = createNode('B');
	TreeNode* c = createNode('C');
	TreeNode* d = createNode('D');
	TreeNode* e = createNode('E');
	TreeNode* f = createNode('F');
	TreeNode* g = createNode('G');
	
	a->left = b; a->right = e;
	b->left = c;
	c->right = d;
	e->left = f; e->right = g;
	//递归遍历
	//preOrder(a);
	printf("\n\n");

	//非递归先序遍历
	preOrderNoR(a);
	printf("\n\n");
	
	//非递归中序遍历
	inOrderNoR(a);
	printf("\n\n");
	
	//非递归后序遍历
	postOrderNoR(a);
}





int main() {
	test();
	system("pause");
	return 0;
}
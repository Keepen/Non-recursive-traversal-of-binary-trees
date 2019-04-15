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

//�������
TreeNode* createNode(char val) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

//�ݹ����
void preOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%c  ", root->val);
	preOrder(root->left);
	preOrder(root->right);
	return;
}

//�ǵݹ���������
void preOrderNoR(TreeNode* root) {
	//�Ӹ��ڵ���룬���ڵ���ջ��
	//��ӡ���ڵ㣬���ڵ��ջ���������ڵ�ķǿ�������ջ
	//�������Ϊ�գ��������Һ��ӡ�
	if (root == NULL) {
		return;
	}
	//����һ��ջ
	stack <TreeNode*> s;
	TreeNode* cur = root;
	//ѭ��
	while (cur != NULL || !s.empty()) {	
		//�ȱ����������㣬��ӡ������ջ
		while (cur) {
			printf("%c  ", cur->val);
			s.push(cur);
			cur = cur->left;
		}	
		//���е������Ѿ���ӡ��ϣ�
		//ȡջ��ָ�룬����curΪ���һ�������������
		TreeNode* top = s.top();
		s.pop();//����ջ��ָ�룬	
		cur = top->right;		
	}
}

//�ǵݹ���������
void inOrderNoR(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	//��ջ
	stack<TreeNode*> s;
	TreeNode* cur = root;//����ָ��
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

//�ǵݹ�ĺ������
void postOrderNoR(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	stack<TreeNode*> s;
	TreeNode* cur = root;
	TreeNode* last = NULL;
	//���ں���֪���ǵڼ��η��ʵ��ýڵ㣬
	//�����last����¼���һ������ӡ�Ľ��
	while (cur != NULL || !s.empty()) {
		while (cur) {    //��һ��
			s.push(cur);
			cur = cur->left;
		}
		//�����������ˣ�
		//��ȡջ��ָ�룬������ѹջ,
		TreeNode* top = s.top();
		if (top->right == NULL) {
			printf("%c  ", top->val);
			s.pop();
			last = top;
		}
		//���ջ��������������һ�δ�ӡ���ģ���Ҳ������ӡ
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

	//����������
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
	//�ݹ����
	//preOrder(a);
	printf("\n\n");

	//�ǵݹ��������
	preOrderNoR(a);
	printf("\n\n");
	
	//�ǵݹ��������
	inOrderNoR(a);
	printf("\n\n");
	
	//�ǵݹ�������
	postOrderNoR(a);
}





int main() {
	test();
	system("pause");
	return 0;
}
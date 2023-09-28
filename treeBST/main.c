#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode * left, * right;
}TreeNode;

//��ȯ�� 
//TreeNode* search(TreeNode* node, int key) {
//	if (node == NULL) return NULL;
//	if (key == node->data) return node;
//	else if (key < node->data) return search(node->left, key);
//	else return search(node->right, key);
//}


TreeNode n1 = { 25,NULL,NULL };
TreeNode n2 = { 16,NULL,&n1 };
TreeNode n3 = { 42,NULL,NULL };
TreeNode n4 = { 46,&n3,NULL };
TreeNode n5 = { 55,NULL,NULL };
TreeNode n6 = { 53,&n4,&n5 };
TreeNode n7 = { 41,&n2,&n6 };
TreeNode n8 = { 62,NULL,NULL };
TreeNode n9 = { 64,NULL,NULL };
TreeNode n10 = { 63,&n8,&n9 };
TreeNode n11 = { 70,NULL,NULL };
TreeNode n12 = { 65,&n10,&n11 };
TreeNode n13 = { 74,&n12,NULL };
TreeNode n14 = { 60,&n7,&n13 };
TreeNode* root = &n14;

int count = 0;

TreeNode* search(TreeNode* node, int  key)
{
	count += 1;
	if (node == NULL)  return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		  search(node->left, key);
	else
		  search(node->right, key);
}

TreeNode* searchRe(TreeNode* node, int key)
{
	while (node != NULL) {
		if (key == node->key) return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return node; 	// Ž���� �������� ��� NULL ��ȯ
}
TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}


//���

TreeNode* insert_node(TreeNode* node, int key) {
	count += 1;
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�. 
	if (node == NULL) return new_node(key);

	// �׷��� ������ ��ȯ������ Ʈ���� ��������. 
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�. 
	return node;
}


//�ݺ� 
void insertIter(TreeNode* *root, int key)
{
	
	TreeNode* toinsert = new_node(key);
	TreeNode* curr = root;
	TreeNode* prev = NULL;

	while (curr != NULL) {//���� ��尡 ������� ������ ���� 
		count += 1;//�湮�� 
		prev = curr; //�� ���� �������� curr �� null�� ������ ������ ������ ������ ���� ��带 ���� 
		if (key < curr->key)
			curr = curr->left;
		else	
			curr = curr->right;// ����忡 �ٴٸ��� curr�� null�� ���� 
	}


	if (prev == NULL) {//�����尡 ��������� ���������� null ���� ���� 
		prev = toinsert;
		root = prev;
		//root = toinsert;
	}

	else if (key < prev->key)
		prev->left = toinsert;

	else
		prev->right = toinsert;
}

//


TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	// �� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;
	return current;
}
TreeNode* delete_node(TreeNode* root, int key) { // key ��� ���� �� ��Ʈ ��ȯ
	if (root == NULL) return root;
	if (key < root->key) 			// Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� ����
		root->left = delete_node(root->left, key);
	else if (key > root->key) 		// Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� ����
		root->right = delete_node(root->right, key);
	else {				// Ű�� ��Ʈ�� ������ �� ��带 ������
		if (root->left == NULL) {	// (1) or (2)
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {	// (1) or (2)
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		TreeNode* temp = min_value_node(root->right); 		// (3)
		root->key = temp->key; 				// ���� Ű ����
		root->right = delete_node(root->right, temp->key); 	// ���� ��� ����
	}
	return root;
}



int select() {
	printf("-------------------------------\n");
	printf("s :�˻�(�ݺ�)\n");
	printf("i : ��� �߰�(���)\n");
	printf("d : ������(���)\n");
	printf("t : ���� ��ȸ(���)\n");
	printf("u :��� �߰�(�ݺ�)\n");
	printf("o :��� ����(�ݺ�)\n");
	printf("c: ����\n");

	printf("-------------------------------\n");
	return 0;
}

//--------------------------------------------------------------------------------------------
TreeNode* initNode(int data, TreeNode* leftChild, TreeNode* rightChild) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode*));
	node->key = data;
	node->left = leftChild;
	node->right = rightChild;
	return node;
}


void inorder(TreeNode* node) {
	if (node) {
		inorder(node->left);
		printf("%d ", node->key);
		inorder(node->right);
	}
}
//-------------------------------------------------------------------

int start(char sel) {
	int input;
	int tempCount;

	switch (sel) {
	case 's':
		count = 0;//�湮�� �ʱ�ȭ
		printf("�˻��Ұ� �Է�:");
		scanf_s("%d", &input);
		TreeNode*a = search(root, input);
		tempCount = count;//�湮�� �ӽ� ���� 
	
		if (search(root, input) != NULL) {
			printf("�˻�����: %d \n", search(root, input)->key);
		}
		printf("�湮�� ����� ��: %d\n", tempCount);
		inorder(root);
		printf("\n");
	
		break;
	case 'i':
		count = 1; //�湮�� �ʱ�ȭ
		printf("������ �� �Է� :");
		scanf_s("%d", &input);
		insert_node(root, input);
		printf("�湮�� ����� ��: %d\n", count);
		inorder(root);
		printf("\n");
		break;
	case 'd':
		break;
	case 't':
		break;
	case 'u':
		count = 0;//�湮�� �ʱ�ȭ
		printf("������ �� �Է� :");
		scanf_s("%d", &input);
		insertIter(root, input);
		printf("�湮�� ����� ��: %d\n", count);
		inorder(root);
		printf("\n");
		break;
	case 'o':
		break;
	case 'c':
		break;
	}
}



int main() {

	
	
	inorder(&n14);
	select();

	char sel;
	
	do{
		

		printf("�޴��Է�:");
		scanf_s(" %c", &sel);
	
		start(sel);
	} while (sel != "c");

	


	TreeNode* tmp = NULL;


	return 0;
}
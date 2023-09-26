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
TreeNode n2 = { 16,&n1,NULL };
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
TreeNode n13 = { 74,&n13,NULL };
TreeNode n14 = { 60,&n7,&n13 };
TreeNode* root = &n14;

TreeNode* search(TreeNode* node, int  key)
{
	if (node == NULL)  return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return  search(node->left, key);
	else
		return  search(node->right, key);
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



TreeNode* insert_node(TreeNode* node, int key) {
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


void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

int start(char sel) {
	int input;


	switch (sel) {
	case 's':
		printf("�˻��Ұ� �Է�:");
		scanf_s("%d", &input);
		inorder(root);
		printf("�˻�����: %d \n", search(root, input)->key);
		if (search(root, input) != NULL) {
			printf("�˻�����: %d \n", search(root, input)->key);
		}


		break;
	case 'i':
		break;
	case 'd':
		break;
	case 't':
		break;
	case 'u':
		break;
	case 'o':
		break;
	case 'c':
		break;
	}
}





int main() {
	inorder(root);
	char sel;
	select();

	printf("�޴��Է�: ");
	scanf_s("%c",&sel);
	start(sel);


	

	
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;


	return 0;
}
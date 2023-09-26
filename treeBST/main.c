#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode * left, * right;
}TreeNode;

//순환적 
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
	return node; 	// 탐색에 실패했을 경우 NULL 반환
}
TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}



TreeNode* insert_node(TreeNode* node, int key) {
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	// 변경된 루트 포인터를 반환한다. 
	return node;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	// 맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL)
		current = current->left;
	return current;
}
TreeNode* delete_node(TreeNode* root, int key) { // key 노드 삭제 후 루트 반환
	if (root == NULL) return root;
	if (key < root->key) 			// 키가 루트보다 작으면 왼쪽 서브 트리에 있음
		root->left = delete_node(root->left, key);
	else if (key > root->key) 		// 키가 루트보다 크면 오른쪽 서브 트리에 있음
		root->right = delete_node(root->right, key);
	else {				// 키가 루트와 같으면 이 노드를 삭제함
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
		root->key = temp->key; 				// 직후 키 복사
		root->right = delete_node(root->right, temp->key); 	// 직후 노드 삭제
	}
	return root;
}



int select() {
	printf("-------------------------------\n");
	printf("s :검색(반복)\n");
	printf("i : 노드 추가(재귀)\n");
	printf("d : 노드삭제(재귀)\n");
	printf("t : 중위 순회(재귀)\n");
	printf("u :노드 추가(반복)\n");
	printf("o :노드 삭제(반복)\n");
	printf("c: 종료\n");

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
		printf("검색할값 입력:");
		scanf_s("%d", &input);
		inorder(root);
		printf("검색성공: %d \n", search(root, input)->key);
		if (search(root, input) != NULL) {
			printf("검색성공: %d \n", search(root, input)->key);
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

	printf("메뉴입력: ");
	scanf_s("%c",&sel);
	start(sel);


	

	
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;


	return 0;
}
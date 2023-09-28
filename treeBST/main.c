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
	return node; 	// 탐색에 실패했을 경우 NULL 반환
}
TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}


//재귀

TreeNode* insert_node(TreeNode* node, int key) {
	count += 1;
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


//반복 
void insertIter(TreeNode* *root, int key)
{
	
	TreeNode* toinsert = new_node(key);
	TreeNode* curr = root;
	TreeNode* prev = NULL;

	while (curr != NULL) {//현재 노드가 비어있지 않으면 실행 
		count += 1;//방문수 
		prev = curr; //이 루프 마지막엔 curr 이 null을 가질떄 루프가 끝나기 때문에 그전 노드를 가짐 
		if (key < curr->key)
			curr = curr->left;
		else	
			curr = curr->right;// 끝노드에 다다르면 curr이 null을 가짐 
	}


	if (prev == NULL) {//현재노드가 비어있을때 연쇄적으로 null 값을 가짐 
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
		count = 0;//방문수 초기화
		printf("검색할값 입력:");
		scanf_s("%d", &input);
		TreeNode*a = search(root, input);
		tempCount = count;//방문수 임시 저장 
	
		if (search(root, input) != NULL) {
			printf("검색성공: %d \n", search(root, input)->key);
		}
		printf("방문한 노드의 수: %d\n", tempCount);
		inorder(root);
		printf("\n");
	
		break;
	case 'i':
		count = 1; //방문수 초기화
		printf("삽입할 값 입력 :");
		scanf_s("%d", &input);
		insert_node(root, input);
		printf("방문한 노드의 수: %d\n", count);
		inorder(root);
		printf("\n");
		break;
	case 'd':
		break;
	case 't':
		break;
	case 'u':
		count = 0;//방문수 초기화
		printf("삽입할 값 입력 :");
		scanf_s("%d", &input);
		insertIter(root, input);
		printf("방문한 노드의 수: %d\n", count);
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
		

		printf("메뉴입력:");
		scanf_s(" %c", &sel);
	
		start(sel);
	} while (sel != "c");

	


	TreeNode* tmp = NULL;


	return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
// 二叉树结点的定义
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Tree;

// 创建新结点
Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 向二叉树插入结点
Node* insertNode(struct Node* root, int data) 
{
	
    if (root == NULL) 
	{
        root = createNode(data);
        return root;
    } 
    
	else
	{
        if (data <= root->data) 
            root->left = insertNode(root->left, data);
        
		else 
            root->right = insertNode(root->right, data);
            
        return root;
    }
}

// 在二叉树中查找结点
struct Node* findNode(struct Node* root, int data) 
{
	
    if (root == NULL || root->data == data) 
        return root;
        
	else if (data < root->data) 
        return findNode(root->left, data);

	else 
        return findNode(root->right, data);
}

// 找到二叉树中的最小值结点
struct Node* findMin(struct Node* root) 
{
	
    while (root->left != NULL)
        root = root->left;
    
    return root;
}

// 删除二叉树中的结点
struct Node* deleteNode(struct Node* root, int data) 
{
    if (root == NULL) 
        return root;
    
	else if (data < root->data) //寻找目标节点 
        root->left = deleteNode(root->left, data);
    
	else if (data > root->data) //寻找目标节点 
        root->right = deleteNode(root->right, data);
    
	else 
	{
        // 找到要删除的结点
        if (root->left == NULL && root->right == NULL) //后续无孩子，直接删除 
		{
            free(root);
            root = NULL;
        } 
        
		else if (root->left == NULL) //左孩子为空 
		{
            struct Node* temp = root;
            root = root->right;
            free(temp);
        } 
        
		else if (root->right == NULL) //右孩子为空 
		{
            struct Node* temp = root;
            root = root->left;
            free(temp);
        } 
        
		else//左右皆有孩子 
		{
            struct Node* temp = findMin(root->right);//找到右树中的最小节点 
            root->data = temp->data;
            
            root->right = deleteNode(root->right, temp->data);//删除右子树中的最小节点 
        }
        
    }
    return root;
}

// 中序遍历二叉树
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// 前序遍历二叉树
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
    	printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// 后序遍历二叉树
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;

    // 插入结点
    int arr[MAX],choice,data,num,n;
    
    printf("请输入数据个数：\n");
    
    scanf("%d",&n);
    
    printf("请输入数据：\n");
     
    //输入待插入数组 
	for(int i = 0; i < n ; i++)
    {
    	scanf("%d",&arr[i]);
	}
	
	//建立二叉树 
	for(int i = 0; i < n ; i++)
    {
    	root=insertNode(root, arr[i]);
	}
	
	
	while(1)
	{
		printf("1. 添加节点\n2. 删除节点\n3. 前序遍历\n4. 中序遍历\n5. 后序遍历\n6. 退出\n 请输入你的选择：");
        scanf("%d", &choice);
	
		//菜单 
        switch(choice) {
            case 1:
                printf("请输入要添加的数据：");
                scanf("%d", &data);
                root=insertNode(root, data);
                break;
            case 2:
                printf("请输入要删除的节点：");
                scanf("%d", &num);
                root=deleteNode(root, num);
                break;
            case 3:
                 printf("二叉树前序遍历结果：");
    			 preorderTraversal(root);
    		     printf("\n");
                break;
            case 4:
            	 printf("二叉树中序遍历结果：");
    			 inorderTraversal(root);
    		     printf("\n");
    		    break;
            case 5:
            	 printf("二叉树后序遍历结果：");
    			 postorderTraversal(root);
    		     printf("\n");
    		    break;
            case 6:
            	exit(0);
            default:
                printf("无效的选择\n");
        }
	}


    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
// ���������Ķ���
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Tree;

// �����½��
Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// �������������
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

// �ڶ������в��ҽ��
struct Node* findNode(struct Node* root, int data) 
{
	
    if (root == NULL || root->data == data) 
        return root;
        
	else if (data < root->data) 
        return findNode(root->left, data);

	else 
        return findNode(root->right, data);
}

// �ҵ��������е���Сֵ���
struct Node* findMin(struct Node* root) 
{
	
    while (root->left != NULL)
        root = root->left;
    
    return root;
}

// ɾ���������еĽ��
struct Node* deleteNode(struct Node* root, int data) 
{
    if (root == NULL) 
        return root;
    
	else if (data < root->data) //Ѱ��Ŀ��ڵ� 
        root->left = deleteNode(root->left, data);
    
	else if (data > root->data) //Ѱ��Ŀ��ڵ� 
        root->right = deleteNode(root->right, data);
    
	else 
	{
        // �ҵ�Ҫɾ���Ľ��
        if (root->left == NULL && root->right == NULL) //�����޺��ӣ�ֱ��ɾ�� 
		{
            free(root);
            root = NULL;
        } 
        
		else if (root->left == NULL) //����Ϊ�� 
		{
            struct Node* temp = root;
            root = root->right;
            free(temp);
        } 
        
		else if (root->right == NULL) //�Һ���Ϊ�� 
		{
            struct Node* temp = root;
            root = root->left;
            free(temp);
        } 
        
		else//���ҽ��к��� 
		{
            struct Node* temp = findMin(root->right);//�ҵ������е���С�ڵ� 
            root->data = temp->data;
            
            root->right = deleteNode(root->right, temp->data);//ɾ���������е���С�ڵ� 
        }
        
    }
    return root;
}

// �������������
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// ǰ�����������
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
    	printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// �������������
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;

    // ������
    int arr[MAX],choice,data,num,n;
    
    printf("���������ݸ�����\n");
    
    scanf("%d",&n);
    
    printf("���������ݣ�\n");
     
    //������������� 
	for(int i = 0; i < n ; i++)
    {
    	scanf("%d",&arr[i]);
	}
	
	//���������� 
	for(int i = 0; i < n ; i++)
    {
    	root=insertNode(root, arr[i]);
	}
	
	
	while(1)
	{
		printf("1. ��ӽڵ�\n2. ɾ���ڵ�\n3. ǰ�����\n4. �������\n5. �������\n6. �˳�\n ���������ѡ��");
        scanf("%d", &choice);
	
		//�˵� 
        switch(choice) {
            case 1:
                printf("������Ҫ��ӵ����ݣ�");
                scanf("%d", &data);
                root=insertNode(root, data);
                break;
            case 2:
                printf("������Ҫɾ���Ľڵ㣺");
                scanf("%d", &num);
                root=deleteNode(root, num);
                break;
            case 3:
                 printf("������ǰ����������");
    			 preorderTraversal(root);
    		     printf("\n");
                break;
            case 4:
            	 printf("������������������");
    			 inorderTraversal(root);
    		     printf("\n");
    		    break;
            case 5:
            	 printf("������������������");
    			 postorderTraversal(root);
    		     printf("\n");
    		    break;
            case 6:
            	exit(0);
            default:
                printf("��Ч��ѡ��\n");
        }
	}


    return 0;
}

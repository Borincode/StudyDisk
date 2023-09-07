
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("内存分配失败\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 添加节点到链表
Node* addNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// 在链表中插入节点
Node* insertNode(Node* head, int data, int position) {
    Node* newNode = createNode(data);
    if(position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        int i;
        for(i = 0; i < position-1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if(temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

// 从链表中删除节点
Node* deleteNode(Node* head, int position) {
    if(position == 0 && head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    } else {
        Node* temp = head;
        Node* prev = NULL;
        int i;
        for(i = 0; i < position && temp != NULL; i++) {
            prev = temp;
            temp = temp->next;
        }
        if(temp != NULL) {
            prev->next = temp->next;
            free(temp);
        }
    }
    return head;
}

// 打印链表
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 交换两个节点的数据
void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(Node* start) {
    int swapped, i;
    Node* ptr1;
    Node* lptr = NULL;

    // 检查链表是否为空
    if (start == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}


int main() {
    Node* head = NULL;
    int choice, data, position,n;

	printf("请输入你想要添加的节点数量：");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("请输入第 %d 个节点的数据：", i+1);
        scanf("%d", &data);
        head = addNode(head, data);
    }
    
    bubbleSort(head);
    while(1) {
        printf("1. 添加节点\n2. 删除节点\n3. 打印链表\n4. 退出\n请输入你的选择：");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("请输入要添加的数据：");
                scanf("%d", &data);
                head = addNode(head, data);
                bubbleSort(head);
                break;
            case 2:
                printf("请输入要删除的节点位置：");
                scanf("%d", &position);
                head = deleteNode(head, position);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("无效的选择\n");
        }
    }

    return 0;
}

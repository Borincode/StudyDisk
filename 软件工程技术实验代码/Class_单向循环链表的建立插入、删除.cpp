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
        newNode->next = head;
    } else {
        Node* current = head;
        Node* prev = NULL;
        while(current->next != head && current->data < data) {
            prev = current;
            current = current->next;
        }
        if(current->next == head && current->data < data) {
            current->next = newNode;
            newNode->next = head;
        } else if(prev == NULL) {
            Node* temp = head;
            while(temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            head = newNode;
            temp->next = head;
        } else {
            prev->next = newNode;
            newNode->next = current;
        }
    }
    return head;
}

// 从链表中删除节点
Node* deleteNode(Node* head, int data) {
    if(head == NULL) {
        return NULL;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp->data != data && temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    if(temp->data == data) {
        if(prev == NULL) {
            Node* temp2 = head;
            while(temp2->next != head) {
                temp2 = temp2->next;
            }
            head = head->next;
            temp2->next = head;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    } else {
        printf("元素 %d 不在链表中\n", data);
    }
    return head;
}

// 打印链表
void printList(Node* head) {
    if(head == NULL) {
        printf("链表为空\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("HEAD\n");
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

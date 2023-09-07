#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// �����½ڵ�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ��ӽڵ㵽����
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

// ��������ɾ���ڵ�
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
        printf("Ԫ�� %d ����������\n", data);
    }
    return head;
}

// ��ӡ����
void printList(Node* head) {
    if(head == NULL) {
        printf("����Ϊ��\n");
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

	printf("����������Ҫ��ӵĽڵ�������");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("������� %d ���ڵ�����ݣ�", i+1);
        scanf("%d", &data);
        head = addNode(head, data);
    }
    
    bubbleSort(head);
    while(1) {
        printf("1. ��ӽڵ�\n2. ɾ���ڵ�\n3. ��ӡ����\n4. �˳�\n���������ѡ��");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("������Ҫ��ӵ����ݣ�");
                scanf("%d", &data);
                head = addNode(head, data);
                bubbleSort(head);
                break;
            case 2:
                printf("������Ҫɾ���Ľڵ�λ�ã�");
                scanf("%d", &position);
                head = deleteNode(head, position);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("��Ч��ѡ��\n");
        }
    }

    return 0;
}


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
    } else {
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// �������в���ڵ�
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

// ��������ɾ���ڵ�
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

// ��ӡ����
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ���������ڵ������
void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(Node* start) {
    int swapped, i;
    Node* ptr1;
    Node* lptr = NULL;

    // ��������Ƿ�Ϊ��
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

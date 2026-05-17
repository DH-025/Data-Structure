#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertFirst(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    return newNode;
}

Node* insertLast(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;

    return head;
}

void insertAfter(Node* head, int targetValue, int newData) {
    Node* current = head;

    while (current != NULL) {
        if (current->data == targetValue) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = newData;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }

    printf("값 %d를 가진 노드를 찾을 수 없습니다. 삽입하지 않습니다.\n", targetValue);
}

Node* deleteHead(Node* head) {
    if (head == NULL) {
        printf("리스트가 비어 있습니다. 삭제할 노드가 없습니다.\n");
        return NULL;
    }

    Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

Node* deleteLast(Node* head) {
    if (head == NULL) {
        printf("리스트가 비어 있습니다. 삭제할 노드가 없습니다.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;

    return head;
}

Node* deleteNode(Node* head, int targetValue) {
    if (head == NULL) {
        printf("리스트가 비어 있습니다. 삭제할 노드가 없습니다.\n");
        return NULL;
    }

    if (head->data == targetValue) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data != targetValue) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("값 %d를 가진 노드를 찾을 수 없습니다.\n", targetValue);
        return head;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);

    return head;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int searchValue1(Node* head, int val) {
    Node* current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == val) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;
}

void searchValue2(Node* head, int val) {
    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data == val) {
            printf("\n[searchValue2 결과] 값 %d를 찾았습니다!\n", val);

            if (prev == NULL) {
                printf("  앞 노드 : 없음 (첫 번째 노드입니다)\n");
            } else {
                printf("  앞 노드 값 : %d\n", prev->data);
            }

            if (current->next == NULL) {
                printf("  뒤 노드 : 없음 (마지막 노드입니다)\n");
            } else {
                printf("  뒤 노드 값 : %d\n", current->next->data);
            }
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("\n[searchValue2 결과] 값 %d를 가진 노드를 찾을 수 없습니다.\n", val);
}

void freeList(Node* head) {
    Node* current = head;
    Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    printf("\n[freeList] 모든 노드의 메모리가 해제되었습니다.\n");
}

int main() {
    Node* head = NULL;

    head = insertFirst(head, 30);
    head = insertFirst(head, 20);
    head = insertFirst(head, 10);
    head = insertLast(head, 70);
    head = insertLast(head, 80);
    head = insertLast(head, 90);
    insertAfter(head, 30, 40);
    insertAfter(head, 40, 50);
    insertAfter(head, 50, 60);

    printf("=== 삽입 후 리스트 ===\n");
    printList(head);

    head = deleteHead(head);
    head = deleteLast(head);
    head = deleteNode(head, 40);
    head = deleteNode(head, 70);
    head = deleteNode(head, 100);

    printf("\n=== 삭제 후 리스트 ===\n");
    printList(head);

    printf("\n=== searchValue1 테스트 ===\n");

    int val = 30;
    int pos = searchValue1(head, val);
    if (pos != -1) {
        printf("%d의 위치는 %d번째\n", val, pos);
    } else {
        printf("%d는 리스트에 존재하지 않습니다.\n", val);
    }

    val = 80;
    pos = searchValue1(head, val);
    if (pos != -1) {
        printf("%d의 위치는 %d번째\n", val, pos);
    } else {
        printf("%d는 리스트에 존재하지 않습니다.\n", val);
    }

    val = 999;
    pos = searchValue1(head, val);
    if (pos != -1) {
        printf("%d의 위치는 %d번째\n", val, pos);
    } else {
        printf("%d는 리스트에 존재하지 않습니다.\n", val);
    }

    printf("\n=== searchValue2 테스트 ===\n");

    searchValue2(head, 30);
    searchValue2(head, 20);
    searchValue2(head, 80);
    searchValue2(head, 999);

    printf("\n=== freeList 테스트 ===\n");
    freeList(head);
    head = NULL;

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// 링크드 리스트의 노드 구조체 정의
typedef struct Node {
    int data;            // 노드의 값
    struct Node* next;   // 다음 노드를 가리키는 링크
} Node;

// 단일 링크드 리스트 생성 함수
Node* createLinkedList(int n) {
    Node* head = NULL;   // 헤드 포인터 초기화
    Node* tail = NULL;   // 꼬리 포인터 초기화

    // n개의 노드 생성 및 값 할당
    for (int i = 1; i <= n; i++) {
        // 새로운 노드 생성
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("메모리 할당에 실패했습니다.\n");
            exit(1);
        }
        
        // 노드의 값 할당
        newNode->data = i;
        newNode->next = NULL;

        // 노드 연결
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// 링크드 리스트의 노드 값 출력 함수
void printLinkedList(Node* head) {
    Node* currentNode = head;

    printf("링크드 리스트의 값: ");
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// 메모리 해제 함수
void freeLinkedList(Node* head) {
    Node* currentNode = head;
    while (currentNode != NULL) {
        Node* temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
}

int main() {
    int n;

    printf("노드의 개수를 입력하세요: ");
    scanf("%d", &n);

    // 단일 링크드 리스트 생성
    Node* head = createLinkedList(n);

    // 링크드 리스트 값 출력
    printLinkedList(head);

    // 메모리 해제
    freeLinkedList(head);

    return 0;
}
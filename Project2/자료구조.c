#include <stdio.h>

typedef struct NODE {
    int data;
    struct NODE* link;
}NODE;

void enterData(NODE** head) {
    NODE* prev, * x;
    int count = 0, a = 0;
    printf("node의 개수 : ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        printf("%d번 node : ", i + 1);
        scanf("%d", &a);
        x = (NODE*)malloc(sizeof(NODE));
        x->data = a; // X데이터
        x->link = NULL; // 링크
        if (*head == NULL)
        {
            *head = x;
        }
        else
        {
            prev->link = x;
        }
        prev = x;
    }
}
void printList(NODE** head) {
    NODE* x;
    x = *head;
    printf("linked list = ");
    while (1)
    {
        printf("%d", x->data);
        x = x->link;
        if (x == NULL)
        {
            break;
        }
        else {
            printf(" -> ");
        }
    }
}
void sumAndMaxData(NODE** head) {
    int sum = 0, max = 0;
    NODE* x;
    x = *head;
    max = x->data;
    while (x != NULL) {
        sum += x->data;
        if (max < x->data) {
            max = x->data;
        }
        x = x->link;
    }
    printf("\nsum of data = %d", sum);
    printf("\nmax of data : %d", max);
}
int main(void)
{
    NODE** head = NULL;

    enterData(&head); //데이터 입력
    printList(&head); //리스트 출력
    sumAndMaxData(&head); // sum값 max값 출

    NODE* next , *x;
    x = head;

    while (x != NULL) //리스트 free
    {
        next = x->link;
        free(x);
        x = next;
    }

    return 0;
}

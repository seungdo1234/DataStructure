#include <stdio.h>

typedef struct NODE {
    int data;
    struct NODE* link;
}NODE;

void enterData(NODE** head) {
    NODE* prev, * x;
    int count = 0, a = 0;
    printf("node�� ���� : ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        printf("%d�� node : ", i + 1);
        scanf("%d", &a);
        x = (NODE*)malloc(sizeof(NODE));
        x->data = a; // X������
        x->link = NULL; // ��ũ
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
   
    enterData(&head); //������ �Է�
    printList(&head); //����Ʈ ���
    sumAndMaxData(&head); // sum�� max�� ��

    NODE* next , *x;
    x = head;

    while (x != NULL) //����Ʈ free
    {
        next = x->link;
        free(x);
        x = next;
    }
  
    return 0;
}

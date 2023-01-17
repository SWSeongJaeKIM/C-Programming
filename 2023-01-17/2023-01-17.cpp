#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    struct node* next;
    int year;
    char name[10];
    int koka;
    int english;
    int math;
    int sum;

} ND;
ND* head = NULL;
int count = 0;

ND* creatNode()
{
    count++;
    int n_year;
    char n_name[10];
    int n_koka;
    int n_english;
    int n_math;
    ND* temp = (ND*)malloc(sizeof(ND));
    printf("�й���? : ");
    scanf("%d", &n_year);

    printf("�̸���? 3���ڷ� : ");
    scanf("%s", n_name);

    printf("���� ������? : ");
    scanf("%d", &n_koka);

    printf("���� ������? : ");
    scanf("%d", &n_math);

    printf("���� ������? : ");
    scanf("%d", &n_english);


    temp->sum = n_koka + n_english + n_math;
    temp->year = n_year;
    temp->koka = n_koka;
    temp->english = n_english;
    temp->math = n_math;

    for (int i = 0; i <= 10; i++)
    {
        temp->name[i] = n_name[i];
    }
    temp->next = NULL;
    return temp;
}

void addNode(ND** head)
{
    ND* newNode = creatNode();

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        ND* temp = *head;
        //�������� �O�� ����
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void print_node()
{
    ND* curr = head;
    printf("�ѤѤѤѤѤ� �л� ���� �ѤѤѤѤѤ�");
    while (curr != NULL)
    {
        printf("�ѤѤѤѤѤ� �л� �ѤѤѤѤѤ�");
        printf("�й� : ");
        printf("%d : \n", curr->year);
        printf("�̸� : ");
        printf("%s : \n", curr->name);
        printf("���� : ");
        printf("%d : \n", curr->koka);
        printf("���� : ");
        printf("%d : \n", curr->math);
        printf("���� : ");
        printf("%d : \n", curr->english);
        printf("�ѤѤѤѤѤ� �л� �ѤѤѤѤѤ�");
        curr = curr->next;

    }
    printf("�ѤѤѤѤѤ� �л� ���� �ѤѤѤѤѤ�");
}

void avr()
{

    ND* curr = head;
    ND* curr2 = head;
    ND* curr3 = head;
    for (int q = 0; q < 3; q++)
    {
        curr3 = curr;
        curr2 = curr2->next;
        if (curr->sum > curr2->sum)
        {
            curr3 = curr;
            curr = curr2;
            curr2 = curr3;

            curr2 = curr;
            curr = curr->next;
            curr2 = curr2->next;
        }
        else
        {
            curr2 = curr;
            curr = curr->next;
        }
    }

    for (int k = 0; k < 3; k++)
    {
        printf("�ѤѤѤѤѤ� �л� �ѤѤѤѤѤ�");
        printf("�й� : ");
        printf("%d : \n", curr->year);
        printf("�̸� : ");
        printf("%s : \n", curr->name);
        printf("���� : ");
        printf("%d : \n", curr->koka);
        printf("���� : ");
        printf("%d : \n", curr->math);
        printf("���� : ");
        printf("%d : \n", curr->english);
        printf("�ѤѤѤѤѤ� �л� �ѤѤѤѤѤ�");
        curr = curr->next;

    }

}




void free_node()      //���� �Լ�
{
    ND* curr = head;

    while (curr != NULL)
    {
        free(curr);
        curr = curr->next;
    }
}




int main()
{
    int menu = 0;
    while (menu != 5)
    {
        printf("�޴��� ������ �ּ��� ! \n");
        printf("1 : �߰�  2 : ����  3: �л����� �O��  4 : ������� �O��  5 : ����");
        scanf("%d", &menu);
        switch (menu)
        {
            //�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ� �߰�
        case 1:
            addNode(&head);
            break;
            //�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ� ���� ��
            //�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ� ���� �O��
        case 3:
            avr();
            break;
            //�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ� �����O�� ��
            //�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ� ��� ���� ���
        case 4:
            print_node();
            break;
            //�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ� ��� ���� ��� ��            
        case 5:
            free_node();
            break;


        }

    }


}
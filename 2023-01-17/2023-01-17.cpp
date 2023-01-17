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
    printf("학번은? : ");
    scanf("%d", &n_year);

    printf("이름은? 3글자로 : ");
    scanf("%s", n_name);

    printf("국어 점수는? : ");
    scanf("%d", &n_koka);

    printf("수학 점수는? : ");
    scanf("%d", &n_math);

    printf("영어 점수는? : ");
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
        //마지막을 찿는 루프
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
    printf("ㅡㅡㅡㅡㅡㅡ 학생 정보 ㅡㅡㅡㅡㅡㅡ");
    while (curr != NULL)
    {
        printf("ㅡㅡㅡㅡㅡㅡ 학생 ㅡㅡㅡㅡㅡㅡ");
        printf("학번 : ");
        printf("%d : \n", curr->year);
        printf("이름 : ");
        printf("%s : \n", curr->name);
        printf("국어 : ");
        printf("%d : \n", curr->koka);
        printf("수학 : ");
        printf("%d : \n", curr->math);
        printf("영어 : ");
        printf("%d : \n", curr->english);
        printf("ㅡㅡㅡㅡㅡㅡ 학생 ㅡㅡㅡㅡㅡㅡ");
        curr = curr->next;

    }
    printf("ㅡㅡㅡㅡㅡㅡ 학생 정보 ㅡㅡㅡㅡㅡㅡ");
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
        printf("ㅡㅡㅡㅡㅡㅡ 학생 ㅡㅡㅡㅡㅡㅡ");
        printf("학번 : ");
        printf("%d : \n", curr->year);
        printf("이름 : ");
        printf("%s : \n", curr->name);
        printf("국어 : ");
        printf("%d : \n", curr->koka);
        printf("수학 : ");
        printf("%d : \n", curr->math);
        printf("영어 : ");
        printf("%d : \n", curr->english);
        printf("ㅡㅡㅡㅡㅡㅡ 학생 ㅡㅡㅡㅡㅡㅡ");
        curr = curr->next;

    }

}




void free_node()      //종료 함수
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
        printf("메뉴를 설정해 주세요 ! \n");
        printf("1 : 추가  2 : 삭제  3: 학생정보 찿기  4 : 모든정보 찿기  5 : 종료");
        scanf("%d", &menu);
        switch (menu)
        {
            //ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ 추가
        case 1:
            addNode(&head);
            break;
            //ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ 삭제 끝
            //ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ 정보 찿기
        case 3:
            avr();
            break;
            //ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ 정보찿기 끝
            //ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ 모든 정보 출력
        case 4:
            print_node();
            break;
            //ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ 모든 정보 출력 끝            
        case 5:
            free_node();
            break;


        }

    }


}
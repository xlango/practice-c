#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//student
typedef struct _STU
{
    char *stuNum[10];
    char *stuName[10];
    int stuSorce;
    struct _STU *pnext;
} STUDENT;

//student linked list head/end
STUDENT *g_pHead = NULL;
STUDENT *g_pEnd = NULL;

//exit flag
int qFlag = 1;

void AddStuToLinkEnd(char *stuNum[10], char *stuName[10], int stuSorce);
void FreeStuLink();
void ShowStuLink();
void ShowOrder();


int main(int argc, char const *argv[])
{
    /* code */
    int iOrder = -1;

    //init student info attribute
    char *stuNum[10] = {"\0"};
    char *stuName[10] = {"\0"};
    int stuSorce = -1;

    ShowOrder();

    while (qFlag)
    {
        printf("please input operation command: \n");
        scanf("%d", &iOrder);

        switch (iOrder)
        {
        case 1:
            //TODO: add student info
            printf("please input student number : ");
            scanf("%s", stuNum);
            printf("please input student name : ");
            scanf("%s", stuName);
            printf("please input student score : ");
            scanf("%d", &stuSorce);
            AddStuToLinkEnd(stuNum, stuName, stuSorce);
            break;
        case 11:
            //TODO: add student info
            printf("please input student number : ");
            scanf("%s", stuNum);
            printf("please input student name : ");
            scanf("%s", stuName);
            printf("please input student score : ");
            scanf("%d", &stuSorce);
            AddStuToLinkHead(stuNum, stuName, stuSorce);
            break;
        case 9:
            ShowStuLink();
            break;
        case 10:
            ShowOrder();
            break;
        case 0:
            qFlag = 0;
            break;
        default:
            printf("input order error");
        }
    }

    //free student link
    FreeStuLink();
    return 0;
}

//add student info
void AddStuToLinkEnd(char *stuNum[10], char *stuName[10], int stuSorce)
{
    if (stuNum == NULL)
    {
        printf("student number error");
        return;
    }
    if (stuName == NULL)
    {
        printf("student name error");
        return;
    }
    if (stuSorce < 0)
    {
        printf("student sorce error");
        return;
    }

    STUDENT *pTemp = malloc(sizeof(STUDENT));
    strcpy(pTemp->stuNum, stuNum);
    strcpy(pTemp->stuName, stuName);
    pTemp->stuSorce = stuSorce;
    pTemp->pnext = NULL;

    if (g_pHead == NULL || g_pEnd == NULL)
    {
        g_pHead = pTemp;
    }
    else
    {
        g_pEnd->pnext = pTemp;
        g_pEnd = pTemp;
    }

    g_pEnd = pTemp;
}

//add student to link head
void AddStuToLinkHead(char *stuNum[10], char *stuName[10], int stuSorce){
    if (stuNum == NULL)
    {
        printf("student number error");
        return;
    }
    if (stuName == NULL)
    {
        printf("student name error");
        return;
    }
    if (stuSorce < 0)
    {
        printf("student sorce error");
        return;
    }
    
    STUDENT *pTemp = malloc(sizeof(STUDENT));
    strcpy(pTemp->stuName,stuName);
    strcpy(pTemp->stuNum,stuNum);
    pTemp->stuSorce = stuSorce;
    pTemp->pnext = NULL;
    if (g_pHead == NULL || g_pEnd == NULL)
    {
        g_pEnd = pTemp;
    }
    else
    {
        pTemp->pnext = g_pHead;
    }

    g_pHead = pTemp;
}

//free linked list 
void FreeStuLink()
{
    STUDENT *pTemp = g_pHead;
    while (g_pHead != NULL)
    {
        //record current free node 
        pTemp = g_pHead;
        //link move next node 
        g_pHead = g_pHead->pnext;
        //free node 
        free(pTemp);
    }
    
}

//print student linked list 
void ShowStuLink()
{
    STUDENT *pTemp = g_pHead;
    while (pTemp != NULL)
    {
        printf("number:%s ,name:%s ,score:%d \n",pTemp->stuNum,pTemp->stuName,pTemp->stuSorce);
        //link move next node 
        pTemp = pTemp->pnext;
    }
}

//show command prompt
void ShowOrder()
{
	printf("*******************学生信息管理系统*********************\n");
	printf("*******************本系统操作指令如下*******************\n");
	printf("***             1、 增加一个学生信息(尾添加)         ***\n");
	printf("***            11、 增加一个学生信息(头添加)         ***\n");
	printf("***           111、 增加一个学生信息(在指定位置添加) ***\n");
	printf("***             2、 查找指定学生的信息（姓名/学号）  ***\n");
	printf("***             3、 修改指定学生的信息               ***\n");
	printf("***             4、 保存业主的信息到文件中           ***\n");
	printf("***             5、 读取文件中的业主信息             ***\n");
	printf("***             6、 删除指定学生的信息               ***\n");
	printf("***             7、 恢复删除的学生的信息             ***\n");
	printf("***             9、 显示所有学生的信息               ***\n");
	printf("***             0、 退出系统                         ***\n");
	printf("********************************************************\n");
}
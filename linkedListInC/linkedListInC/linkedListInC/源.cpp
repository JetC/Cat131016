#include <stdio.h>
#include <stdlib.h>
 
/* �� char ���Ͷ������ datatype */
typedef char datatype;
 
/* ��������ڵ����� */
typedef struct node
{
        datatype data;
        struct node *next;
}linklist;
 
/* ������������ */
linklist* CreatList();
linklist* Get(linklist*, int);
linklist* Locate(linklist*, datatype);
void PrintList(linklist*);
void InsertAfter(linklist*, datatype);
void InsertBefore(linklist*, int, datatype);
void DeleteAfter(linklist*);
void Deleter(linklist*, int);
void FreeList(linklist*);
 
int main()
{
        int pos;
        datatype value;
 
        /* ���Դ��������� */
        printf("������һ���ַ����� $ ����\n");
        linklist *head, *p;
        head = CreatList();
 
        /* ���Դ�ӡ������ */
        printf("\n��ӡ����\n");
        PrintList(head);
 
        /* ���԰���Ų��Һ��� */
        printf("\n������Ҫ���ҵĽڵ����:\n");
        scanf("%d", &pos);
        getchar();
        p = Get(head, pos);
        if(p != NULL)
        {
                printf("%c\n", p -> data);
        }
        else
        {
                printf("Can't Get This Key!\n");
        }
 
        /* ���԰�ֵ���Һ��� */
        printf("\n������Ҫ���ҵ�ֵ:\n");
        scanf("%c", &value);
        p = Locate(head, value);
        if(p != NULL)
        {
                printf("%c\n", p -> data);
        }
        else
        {
                printf("Can't Get This Key!\n");
        }
 
        /* ���Բ���ڵ㺯�� */
        printf("\n�����ڵڼ����ڵ�ǰ���룿\n");
        scanf("%d", &pos);
        getchar();
        printf("������Ҫ�����ֵ\n");
        scanf("%c", &value);
        InsertBefore(head, pos, value);
        PrintList(head);        
 
        /* ����ɾ���ڵ㺯�� */
        printf("\n����ɾ���ڼ����ڵ㣿\n");
        scanf("%d", &pos);
        Deleter(head, pos);
        PrintList(head);
 
        /* �������� */
        FreeList(head);
 
        system("pause");
        return 0;
}
 
/* ��ͷ����巨���������� */
linklist* CreatList()
{
        datatype key;
        /* head Ϊͷָ��, s Ϊ�½ڵ�, r Ϊβָ�� */
        linklist *head, *s, *r;
        head = (linklist*) malloc(sizeof(linklist));
        r = head;
        key = getchar();
        /* ���� $ ��ֹͣ���� */
        while(key != '$')
        {
                s = (linklist*) malloc(sizeof(linklist));
                s -> data = key;
                /* �½ڵ�����β */
                r -> next = s;
                /* βָ��ָ���µı�β */
                r = s;
                key = getchar();
        }
        r -> next = NULL;
        /* ����ͷָ�� */
        return head;
}
 
/* ��ӡ������ */
void PrintList(linklist* head)
{
        linklist *p;
        p = head -> next;
        while(p != NULL)
        {
                printf("%c", p -> data);
                p = p -> next;
        }
        printf("\n");
}
 
/* ���������е� i ���ڵ� */
linklist* Get(linklist* head, int i)
{
        /* j Ϊɨ������� */
        int j = 0;
        linklist *p;
        /* p ָ��ͷ�ڵ� */
        p = head;
        /* �����β����Ų��Ϸ����˳�ѭ�� */
        while((p -> next != NULL) && (j < i))
        {
                p = p -> next;
                j++;
        }
        if (i == j)
        {
                return p;
        }
        else
        {
                return NULL;
        }
}
 
/* �������в���ֵ key ���������ڽڵ� */
linklist* Locate(linklist* head, datatype key)
{
        linklist *p;
        /* p ָ��ʼ��� */
        p = head -> next;
        while(p != NULL)
        {
                if(p -> data != key)
                {
                        p = p -> next;
                }
                else
                {
                        break;
                }
        }
        return p;
}
 
/* �ڽڵ� p ����� key */
void InsertAfter(linklist* p, datatype key)
{
        linklist *s;
        s = (linklist*) malloc(sizeof(linklist));
        s -> data = key;
        /* �Ƚ� s ָ���һ���ڵ㣬�ٽ�ǰһ���ڵ�ָ�� s */
        s -> next = p -> next;
        p -> next = s;
}
 
/* �� key ��������� i ���ڵ�֮ǰ */
void InsertBefore(linklist* head, int i, datatype key)
{
        linklist *p;
        int j = i - 1;
        /* �ҵ��� i-1 ���ڵ� p */
        p = Get(head, j);
        if (p == NULL)
        {
                printf("Insert Error!\n");
        }
        else
        {
                /* �� key ����ڵ� p ֮�� */
                InsertAfter(p, key);
        }
}
 
/* ɾ�� p �ڵ�ĺ�̽ڵ� */
void DeleteAfter(linklist* p)
{
        linklist *r;
        /* r ָ��Ҫɾ���Ľڵ� */
        r = p -> next;
        /* �� p ֱ���� r ��һ���ڵ����� */
        p -> next = r -> next;
        /* �ͷŽڵ� r */
        free(r);
}
 
/* ɾ������ĵ� i ���ڵ� */
void Deleter(linklist* head, int i)
{
        linklist *p;
        int j = i - 1;
        /* �ҵ��� i-1 ���ڵ� p */
        p = Get(head, j);
        if ((p != NULL) && (p -> next != NULL))
        {
                /* ɾ�� p �ĺ�̽ڵ� */
                DeleteAfter(p);
        }
        else
        {
                printf("Delete Error!\n");
        }
}
 
/* �ݹ��ͷŵ����� */
void FreeList(linklist* p)
{
        if (p -> next != NULL)
        {
                FreeList(p -> next);
        }
        free(p);
}
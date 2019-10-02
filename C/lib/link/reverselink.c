#include <stdio.h>

typedef struct Link{
    int item;
    struct Link *next;
}LINK;

void showLink(const LINK *head);
LINK *reverse(LINK *head);
LINK *delete(LINK *head,int item);

int main()
{
    LINK a = {1,NULL};
    LINK b = {2,&a};
    LINK c = {3,&b};
    LINK d = {4,&c};

    showLink(&d);

    LINK *newHead = reverse(&d);

    showLink(newHead);

    newHead = delete(newHead,1);

    showLink(newHead);

    return 0;
}

void showLink(const LINK *head)
{
    const LINK *p = head;

    while(p != NULL)
    {
        printf("%d\t",p->item);
        p = p->next;
    }
    printf("\n");
}

/**
 * @brief   反转单链表
 * @note    反转单链表
 * 
 * @return  反转后的链表头部
 * 
 * @author  jiankang.wang
 * @date    2019-09-29
 */
LINK *reverse(LINK *head)
{
    LINK *prev = NULL,*curr = head,*next = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

/**
 * @brief   删除链表中值为item的元素
 * @note    删除链表中值为item的元素
 * 
 * @return  返回删除元素值
 * 
 * @author  jiankang.wang
 * @date    2019-09-29
 */
LINK *delete(LINK *head,int item)
{
    LINK *curr = head,*prev = head;

    while(curr != NULL)
    {
        if(curr->item == item)
        {
            if(curr == head)
            {
                head = head->next;
            }
            else
            {
                prev->next = curr->next;
            }
            break;
            //栈上链表不需要内存释放操作,malloc的需要释放删除链表节点的内存
            //delete tmp;
        }

        prev = curr;
        curr = curr->next;
    }

    return head;
}
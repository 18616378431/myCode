/**
 * @brief   单链表操作
 * @note    单链表操作
 * 
 * @author  jiankang.wang
 * @date    2019-10-09
 */ 
#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
    int item;
    struct Link *next;
}LINK;

void showLink(const LINK *head);
LINK *initLink(const int size);
LINK *reverse(LINK *head);
LINK *delete(LINK *head,int item);
LINK *insert(LINK *head,const int item,const int pos);
LINK *append(LINK *head,const int item);
LINK *unshift(LINK *head,const int item);

int main()
{
    LINK *head = initLink(4);
    showLink(head);

    LINK *newHead = reverse(head);
    showLink(newHead);

    newHead = delete(newHead,1);
    showLink(newHead);

    newHead = insert(newHead,100,0);
    showLink(newHead);
    newHead = insert(newHead,101,1);
    showLink(newHead);

    newHead = append(newHead,200);
    showLink(newHead);
    newHead = append(newHead,300);
    showLink(newHead);

    newHead = unshift(newHead,400);
    showLink(newHead);
    newHead = unshift(newHead,500);
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
 * @brief   初始化链表
 * @note    初始化链表
 * 
 * @author  jiankang.wang
 * @date    2019-10-07 
 */
LINK *initLink(const int size)
{
    LINK *head = NULL,*prev = NULL,*tmp = NULL;
    int i = 0;

    while(i < size)
    {
        tmp = (LINK *)malloc(sizeof(LINK));
        
        if(i == 0)//head
        {
            tmp->item = i;
            tmp->next = NULL;
            head = tmp;
        }
        else
        {
            prev->next = tmp;
            tmp->item = i;
            tmp->next = NULL;
        }
        i++;
        prev = tmp;
    }

    return head;
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
    LINK *curr = head,*prev = head,*tmp = NULL;

    while(curr != NULL)
    {
        if(curr->item == item)
        {
            if(curr == head)
            {
                tmp = head;
                head = head->next;
            }
            else
            {
                tmp = curr;
                prev->next = curr->next;
            }
            free(tmp);
            break;
            //栈上链表不需要内存释放操作,malloc的需要释放删除链表节点的内存
            //delete tmp;
        }

        prev = curr;
        curr = curr->next;
    }

    return head;
}

/**
 * @brief   链表中插入新节点
 * @note    链表中插入新节点
 * 
 * @param   head 链表头部
 *          item 待插入元素
 *          pos  新元素插入位置(0~(N-1))
 * 
 * @author  jiankang.wang
 * @date    2019-10-07
 */
LINK *insert(LINK *head,const int item,const int pos)
{
    LINK *new = (LINK *)malloc(sizeof(LINK));
    LINK *curr = head,*prev = NULL;

    new->item = item;
    new->next = NULL;
    int i = 0;

    while(curr)
    {
        if(pos == 0)
        {
            new->next = head;
            head = new;
            break;
        }
        else if(i == pos)
        {
            prev->next = new;
            new->next = curr;
            break;
        }
        
        i++;
        prev = curr;
        curr = curr->next;
    }

    if(pos > i)
    {
        printf("pos > i\n");
    }

    return head;
}

/**
 * @brief   在链表尾部追加元素
 * @note    在链表尾部追加元素
 * 
 * @param   head 链表头
 *          item 待追加元素
 * 
 * @return  head 链表头指针
 * 
 * @author  jiankang.wang
 * @date    2019-10-09
 */
LINK *append(LINK *head,const int item)
{
    LINK *new = (LINK *)malloc(sizeof(LINK));
    LINK *tmp = head;

    new->item = item;
    new->next = NULL;

    while(tmp->next)
    {
        tmp = tmp->next;
    }

    tmp->next = new;

    return head;
}

/**
 * @brief   在链表头部添加元素 
 * @note    在链表头部添加元素
 * 
 * @param   head 链表头指针
 * 
 * @return  head 链表头指针
 * 
 * @author  jiankang.wang
 * @date    2019-10-09
 */
LINK *unshift(LINK *head,const int item)
{
    LINK *new = (LINK *)malloc(sizeof(LINK));
    LINK *tmp = head;

    new->item = item;
    new->next = head;

    head = new;

    return head;
}
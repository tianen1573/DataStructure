#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


/* 移除链表元素 */
/* https://leetcode-cn.com/problems/remove-linked-list-elements/description/ */
// /**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//
// /*struct ListNode* removeElements(struct ListNode* head, int val){
//
//     if(head == NULL)
//         return NULL;
//     head->next = removeElements(head->next, val);
//     //return head->val == val ? head->next : head;//ptr.val == val,返回ptr.next;!=，返回ptr
//     if (head->val == val)
//     {
//         struct ListNode * tmp = head->next;
//         free(head);
//         return tmp;
//     }
//     else
//     {
//         return head;
//     }
// }//递归*/
//
// /*struct ListNode* removeElements(struct ListNode* head, int val){
//
//     struct ListNode *p = NULL, *q = NULL, *tmp = NULL;
//     p = head;
//     head = NULL;
//
//     //找头节点
//     while(p)
//     {
//         if(p->val != val)
//         {
//             head = p;
//             q = p;
//             p = p->next;
//             break;
//         }
//         else
//         {
//             tmp = p;
//             p = p->next;
//             free(tmp);
//         }
//     }
//     //遍历
//     while(p)
//     {
//         if(p->val != val)
//         {
//             q->next = p;
//             q = p;
//             p = p->next;
//         }
//         else
//         {
//             tmp = p;
//             p = p->next;
//             free(tmp);
//         }
//     }
//     //若链表不为空，将尾节点的next指向NULL
//     if(q)
//         q->next = NULL;
//
//     return head;
//
// }快慢指针*/
//
// /*struct ListNode* removeElements(struct ListNode* head, int val)
// {
//     struct ListNode * tmp = NULL;
//     while (head != NULL && head->val == val) //找第一个非val节点
//     {
//         tmp = head->next;
//         free(head);
//         head = tmp;
//     }
//
//     struct ListNode* cur = head;  //  当前节点
//     struct ListNode* pre = head;  //  保存待删除节点的前一节点
//     while (cur != NULL)
//     {
//         if (cur->val == val)
//         {
//             pre->next = cur->next;
//             tmp = cur->next;
//             free(cur);
//             cur = tmp;
//         }
//         else
//         {
//             pre = cur;
//             cur = cur->next;
//         }
//
//
//     }
//     return head;
// }//双指针*/
//
// /*struct ListNode* removeElements(struct ListNode* head, int val)
// {
//     struct ListNode *tmp = NULL;
//     struct ListNode *dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
//     dummyHead->next = head;
//     struct ListNode *ptr = dummyHead;
//
//     while(ptr->next)
//     {
//         if(ptr->next->val == val)
//         {
//             tmp = ptr->next;
//             ptr->next = ptr->next->next;
//             free(tmp);
//
//         }
//         else
//         {
//             ptr = ptr->next;
//         }
//     }
//
//     head = dummyHead->next;
//     free(dummyHead);
//     return head;
// }//虚拟指针*/

/* 反转链表 */
/* https://leetcode-cn.com/problems/reverse-linked-list/submissions/ */
// /**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//
//struct ListNode* reverseList(struct ListNode* head)
//{
//    if (!head)
//        return NULL;
//
//    struct ListNode* cur = head;
//    struct ListNode* newHead = NULL;//保存头节点
//
//
//    while (cur)
//    {
//        struct ListNode* next = cur->next;//保存下一节点
//        cur->next = newHead;
//        newHead = cur;
//        cur = next;
//    }
//    return newHead;
//}
////头插链表
////时间复杂度：O(n)
////空间复杂度：O(1)
//
//
//
//
// /*struct ListNode* reverseList(struct ListNode* head)
//{
//    if(head == NULL || head->next == NULL)//一是头结点为空时，二是递归结束条件：最后一个节点
//        return head;
//    struct ListNode* newHead = reverseList(head->next);//翻转链表的新的头结点
//    head->next->next = head;//画图理解
//    head->next = NULL;//避免环
//    return newHead;
//}
////官解：递归
////时间复杂度：O(n)
////空间复杂度：O(n)*/
//
// /*struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* prev = NULL;//翻转链表的 ptail->next,
//    struct ListNode* curr = head;
//    while(curr != NULL){
//        struct ListNode* next = curr->next;
//        curr->next = prev;//当前节点的next = 上一个节点
//        prev = curr;
//        curr = next;
//    }
//    return prev;
//}*/
////官解：迭代
////时间复杂度：O(n)
////空间复杂度：O(1)

/*876. 链表的中间结点*/
/* https://leetcode-cn.com/problems/middle-of-the-linked-list/description/ */
// /**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//
//struct ListNode* middleNode(struct ListNode* head) {
//
//    struct ListNode* slow, * fast;
//    slow = fast = head;
//
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//
//    return slow;
//
//}

/*链表中倒数第k个结点*/
/* https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a */
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//    // write code here
//
//    if (pListHead == NULL || k <= 0)
//        return NULL;
//
//    struct ListNode* slow, * fast;
//    slow = fast = pListHead;
//    //若k大于链表长度，则fast为NULL，退出，此时k不等于0，异常
//    //若k小于等于链表长度，则k等于0，退出，正常
//    while (k && fast)
//    {
//        fast = fast->next;
//        k--;
//    }
//    //异常返回NULL
//    if (k)
//        return NULL;
//    //此时fast和slow间距为k，当fast为NULL时，slow为倒数第k个
//    while (fast)
//    {
//        slow = slow->next;
//        fast = fast->next;
//    }
//    return slow;
//}

/*21. 合并两个有序链表*/
/* https://leetcode-cn.com/problems/merge-two-sorted-lists/ */
// /*struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
//
//    if(list1 == NULL)
//        return list2;
//    if(list2 == NULL)
//        return list1;
//
//
//    struct ListNode *head = list1->val < list2->val ? list1 : list2;//找头节点
//    struct ListNode *cur = head;
//    struct ListNode *tmp = NULL;
//
//    while(list1 && list2)
//    {
//        if(list1->val < list2->val)
//        {
//            //保存小值节点的下一节点
//            tmp = list1->next;
//
//            cur->next = list1;
//            cur = list1;
//            list1 = tmp;
//
//        }
//        else
//        {
//            tmp = list2->next;
//
//            cur->next = list2;
//            cur = list2;
//            list2 = tmp;
//        }
//    }
//
//    //链接剩余链表节点
//    if(list1)
//        cur->next = list1;
//    else
//        cur->next = list2;
//
//    return head;
//
//}//迭代*/
//
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//
//    if (list1 == NULL)
//        return list2;
//    if (list2 == NULL)
//        return list1;
//
//    if (list1->val < list2->val)
//    {
//        list1->next = mergeTwoLists(list2, list1->next);
//        return list1;
//    }
//    else
//    {
//        list2->next = mergeTwoLists(list1, list2->next);
//        return list2;
//    }
//
//}//递归

/*CM11 链表分割*/
/* https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70 */
// /*
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};*/
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x) {
//        // write code here
//
//        ListNode* large = (ListNode*)malloc(sizeof(ListNode));
//        ListNode* small = (ListNode*)malloc(sizeof(ListNode));
//        //初始化，判断是否存在大于或小于的节点
//        ListNode* newhead = large->next = small->next = NULL;
//        ListNode* ltail = large, * stail = small;
//
//
//        while (pHead)
//        {
//            if (pHead->val < x)
//            {
//                stail->next = pHead;
//                stail = pHead;
//            }
//            else
//            {
//                ltail->next = pHead;
//                ltail = pHead;
//            }
//            pHead = pHead->next;
//        }
//
//        //1. 存在小于x的节点，则newhead为small->next
//        //2. 不存在,则newhead为large->next;
//		  //也可 先stail->next = large->next，后newhead = small->next,避免小值不存在
//        if (small->next)
//        {
//            newhead = small->next;
//            stail->next = large->next;
//            ltail->next = NULL;
//        }
//        else
//        {
//            newhead = large->next;
//            ltail->next = NULL;
//        }
//
//        free(large);
//        free(small);
//
//        return newhead;
//    }
//};

/*链表的回文结构*/
/* https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking */
//class PalindromeList {
//public:
//    ListNode* middleNode(ListNode* head) {
//        struct ListNode* slow, * fast;
//        slow = fast = head;
//
//        while (fast && fast->next)
//        {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//
//        return slow;
//    }
//    ListNode* reverseList(struct ListNode* head)
//    {
//        struct ListNode* prev = NULL;//翻转链表的 ptail->next,
//        struct ListNode* curr = head;
//        struct ListNode* next = NULL;
//        while (curr != NULL) {
//            next = curr->next;
//            curr->next = prev;//当前节点的next = 上一个节点
//            prev = curr;
//            curr = next;
//        }
//        return prev;
//    }
//    bool chkPalindrome(ListNode* head)
//    {
//        ListNode* midNode = middleNode(head);
//        ListNode* tailNode = reverseList(midNode);
//
//        while (tailNode)
//        {
//            if (head->val != tailNode->val)
//                return false;
//            else
//            {
//                tailNode = tailNode->next;
//                head = head->next;
//            }
//        }
//
//        return true;
//    }
//};

/*相交链表*/
/* https://leetcode.cn/problems/intersection-of-two-linked-lists/description/ */
//class Solution {
//public:
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//
//        int LenA = 1, LenB = 1;
//        ListNode* pA = headA, * pB = headB;
//
//        //记录链表AB的长度，并保存各自最后一个节点
//        while (pA->next)
//        {
//            LenA++;
//            pA = pA->next;
//        }
//        while (pB->next)
//        {
//            LenB++;
//            pB = pB->next;
//        }
//        //若最后一个节点不相同，则一定不相交
//        if (pA != pB) return NULL;
//
//        //初始化长链表和短链表
//        ListNode* longNode = headA, * shortNode = headB;
//        int l = abs(LenA - LenB);
//        if (LenB > LenA)
//        {
//            longNode = headB;
//            shortNode = headA;
//        }
//        while (l--)//对齐
//            longNode = longNode->next;
//        while (true)
//        {
//            if (longNode == shortNode) return longNode;//相交点
//
//            longNode = longNode->next;
//            shortNode = shortNode->next;
//        }
//
//    }
//};

/*环形链表*/
/* https://leetcode.cn/problems/linked-list-cycle/submissions/ */
//class Solution {//快慢指针
//public:
//    bool hasCycle(ListNode* head) {
//
//        if (head == NULL) return false;
//        ListNode* slow = head, * fast = head;
//
//        while (fast)
//        {
//            if (fast->next == NULL) return false;//有NULL无环， 且避免走两步出错
//
//            fast = fast->next->next;
//            slow = slow->next;
//
//            if (fast == slow) return true;
//        }
//
//        return false;
//    }
//};


/*环形链表Ⅱ*/
/* https://leetcode.cn/problems/linked-list-cycle-ii/description/ */
//class Solution {
//public:
//    ListNode* hasCycle(ListNode* head) {
//
//        if (head == NULL) return NULL;
//        ListNode* slow = head, * fast = head;
//
//        while (fast)
//        {
//            if (fast->next == NULL) return NULL;//有NULL无环， 且避免走两步出错
//
//            fast = fast->next->next;
//            slow = slow->next;
//
//            if (fast == slow) return fast;
//        }
//
//        return NULL;
//    }
//    ListNode* detectCycle(ListNode* head) {
//
//        ListNode* meetNode = hasCycle(head);
//        if (meetNode == NULL) return NULL;
//
//        ListNode* phead = head;
//        while (true)
//        {
//            if (phead == meetNode) return phead;
//
//            phead = phead->next;
//            meetNode = meetNode->next;
//        }
//        //L + x = N * C >> L = N * C - x
//        //则 phead 走到相交节点时，meetNode也走到相交节点 
//    }
//};

/*复制带随机指针的链表*/
/* https://leetcode.cn/problems/copy-list-with-random-pointer/solution/ */
//将新旧节点绑定起来
//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//
//        unordered_map<Node*, Node*> mnn;
//
//        Node* thead = head;
//        //创建节点
//        while (thead)
//        {
//            mnn[thead] = new Node(thead->val);
//            thead = thead->next;
//        }
//        mnn[nullptr] = nullptr;
//        //更新成员
//        thead = head;
//        while (thead)
//        {
//            mnn[thead]->next = mnn[thead->next];
//            mnn[thead]->random = mnn[thead->random];
//            thead = thead->next;
//        }
//        return mnn[head];
//    }
//};
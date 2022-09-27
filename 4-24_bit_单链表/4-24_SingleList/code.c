#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


/* �Ƴ�����Ԫ�� */
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
//     //return head->val == val ? head->next : head;//ptr.val == val,����ptr.next;!=������ptr
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
// }//�ݹ�*/
//
// /*struct ListNode* removeElements(struct ListNode* head, int val){
//
//     struct ListNode *p = NULL, *q = NULL, *tmp = NULL;
//     p = head;
//     head = NULL;
//
//     //��ͷ�ڵ�
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
//     //����
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
//     //������Ϊ�գ���β�ڵ��nextָ��NULL
//     if(q)
//         q->next = NULL;
//
//     return head;
//
// }����ָ��*/
//
// /*struct ListNode* removeElements(struct ListNode* head, int val)
// {
//     struct ListNode * tmp = NULL;
//     while (head != NULL && head->val == val) //�ҵ�һ����val�ڵ�
//     {
//         tmp = head->next;
//         free(head);
//         head = tmp;
//     }
//
//     struct ListNode* cur = head;  //  ��ǰ�ڵ�
//     struct ListNode* pre = head;  //  �����ɾ���ڵ��ǰһ�ڵ�
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
// }//˫ָ��*/
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
// }//����ָ��*/

/* ��ת���� */
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
//    struct ListNode* newHead = NULL;//����ͷ�ڵ�
//
//
//    while (cur)
//    {
//        struct ListNode* next = cur->next;//������һ�ڵ�
//        cur->next = newHead;
//        newHead = cur;
//        cur = next;
//    }
//    return newHead;
//}
////ͷ������
////ʱ�临�Ӷȣ�O(n)
////�ռ临�Ӷȣ�O(1)
//
//
//
//
// /*struct ListNode* reverseList(struct ListNode* head)
//{
//    if(head == NULL || head->next == NULL)//һ��ͷ���Ϊ��ʱ�����ǵݹ�������������һ���ڵ�
//        return head;
//    struct ListNode* newHead = reverseList(head->next);//��ת������µ�ͷ���
//    head->next->next = head;//��ͼ���
//    head->next = NULL;//���⻷
//    return newHead;
//}
////�ٽ⣺�ݹ�
////ʱ�临�Ӷȣ�O(n)
////�ռ临�Ӷȣ�O(n)*/
//
// /*struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* prev = NULL;//��ת����� ptail->next,
//    struct ListNode* curr = head;
//    while(curr != NULL){
//        struct ListNode* next = curr->next;
//        curr->next = prev;//��ǰ�ڵ��next = ��һ���ڵ�
//        prev = curr;
//        curr = next;
//    }
//    return prev;
//}*/
////�ٽ⣺����
////ʱ�临�Ӷȣ�O(n)
////�ռ临�Ӷȣ�O(1)

/*876. ������м���*/
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

/*�����е�����k�����*/
/* https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a */
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//    // write code here
//
//    if (pListHead == NULL || k <= 0)
//        return NULL;
//
//    struct ListNode* slow, * fast;
//    slow = fast = pListHead;
//    //��k���������ȣ���fastΪNULL���˳�����ʱk������0���쳣
//    //��kС�ڵ��������ȣ���k����0���˳�������
//    while (k && fast)
//    {
//        fast = fast->next;
//        k--;
//    }
//    //�쳣����NULL
//    if (k)
//        return NULL;
//    //��ʱfast��slow���Ϊk����fastΪNULLʱ��slowΪ������k��
//    while (fast)
//    {
//        slow = slow->next;
//        fast = fast->next;
//    }
//    return slow;
//}

/*21. �ϲ�������������*/
/* https://leetcode-cn.com/problems/merge-two-sorted-lists/ */
// /*struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
//
//    if(list1 == NULL)
//        return list2;
//    if(list2 == NULL)
//        return list1;
//
//
//    struct ListNode *head = list1->val < list2->val ? list1 : list2;//��ͷ�ڵ�
//    struct ListNode *cur = head;
//    struct ListNode *tmp = NULL;
//
//    while(list1 && list2)
//    {
//        if(list1->val < list2->val)
//        {
//            //����Сֵ�ڵ����һ�ڵ�
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
//    //����ʣ������ڵ�
//    if(list1)
//        cur->next = list1;
//    else
//        cur->next = list2;
//
//    return head;
//
//}//����*/
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
//}//�ݹ�

/*CM11 ����ָ�*/
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
//        //��ʼ�����ж��Ƿ���ڴ��ڻ�С�ڵĽڵ�
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
//        //1. ����С��x�Ľڵ㣬��newheadΪsmall->next
//        //2. ������,��newheadΪlarge->next;
//		  //Ҳ�� ��stail->next = large->next����newhead = small->next,����Сֵ������
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

/*����Ļ��Ľṹ*/
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
//        struct ListNode* prev = NULL;//��ת����� ptail->next,
//        struct ListNode* curr = head;
//        struct ListNode* next = NULL;
//        while (curr != NULL) {
//            next = curr->next;
//            curr->next = prev;//��ǰ�ڵ��next = ��һ���ڵ�
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

/*�ཻ����*/
/* https://leetcode.cn/problems/intersection-of-two-linked-lists/description/ */
//class Solution {
//public:
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//
//        int LenA = 1, LenB = 1;
//        ListNode* pA = headA, * pB = headB;
//
//        //��¼����AB�ĳ��ȣ�������������һ���ڵ�
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
//        //�����һ���ڵ㲻��ͬ����һ�����ཻ
//        if (pA != pB) return NULL;
//
//        //��ʼ��������Ͷ�����
//        ListNode* longNode = headA, * shortNode = headB;
//        int l = abs(LenA - LenB);
//        if (LenB > LenA)
//        {
//            longNode = headB;
//            shortNode = headA;
//        }
//        while (l--)//����
//            longNode = longNode->next;
//        while (true)
//        {
//            if (longNode == shortNode) return longNode;//�ཻ��
//
//            longNode = longNode->next;
//            shortNode = shortNode->next;
//        }
//
//    }
//};

/*��������*/
/* https://leetcode.cn/problems/linked-list-cycle/submissions/ */
//class Solution {//����ָ��
//public:
//    bool hasCycle(ListNode* head) {
//
//        if (head == NULL) return false;
//        ListNode* slow = head, * fast = head;
//
//        while (fast)
//        {
//            if (fast->next == NULL) return false;//��NULL�޻��� �ұ�������������
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


/*���������*/
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
//            if (fast->next == NULL) return NULL;//��NULL�޻��� �ұ�������������
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
//        //�� phead �ߵ��ཻ�ڵ�ʱ��meetNodeҲ�ߵ��ཻ�ڵ� 
//    }
//};

/*���ƴ����ָ�������*/
/* https://leetcode.cn/problems/copy-list-with-random-pointer/solution/ */
//���¾ɽڵ������
//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//
//        unordered_map<Node*, Node*> mnn;
//
//        Node* thead = head;
//        //�����ڵ�
//        while (thead)
//        {
//            mnn[thead] = new Node(thead->val);
//            thead = thead->next;
//        }
//        mnn[nullptr] = nullptr;
//        //���³�Ա
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
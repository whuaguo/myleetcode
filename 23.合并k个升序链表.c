/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//#define DEBUG 0
#ifdef DEBUG
#define debugprint printf
void showheap(struct ListNode **heap, int *heapidx, int heapcount) {
    printf("The heap values (%d) are [", heapcount);
    for (int idx = 0 ; idx < heapcount; idx++) {
        printf("%d,", heap[idx]->val);
    }
    printf("]\n");
    printf("The heap idxs (%d) are [", heapcount);
    for (int idx = 0 ; idx < heapcount; idx++) {
        printf("%d,", heapidx[idx]);
    }
    printf("]\n");
}
#else
#define showheap(a,b,c)
#define debugprint
#endif

void moveHeapHead(struct ListNode **heap, int *heapidx, int heapcount) {
    int fatheridx = 0;

    while (fatheridx < heapcount) {
        int lc = (fatheridx << 1) + 1;
        int rc = (fatheridx << 1) + 2;
        if (lc >= heapcount) {
            break;
        }

        int idx = lc;
        if ((rc < heapcount) && (heap[rc]->val < heap[lc]->val)) {
            idx = rc;
        } 

        if (heap[fatheridx]->val > heap[idx]->val) {
            struct ListNode *temp = heap[fatheridx];
            heap[fatheridx] = heap[idx];
            heap[idx] = temp;

            int tempidx = heapidx[fatheridx];
            heapidx[fatheridx] = heapidx[idx];
            heapidx[idx] = tempidx;
        }
        fatheridx = idx;
    }
}

void moveHeapTail(struct ListNode **heap, int *heapidx, int heapcount) {
    int idx = heapcount - 1;
    while (idx > 0)
    {
        int fatheridx = (idx - 1) >> 1;
        if (heap[fatheridx]->val > heap[idx]->val) {
            struct ListNode *temp = heap[fatheridx];
            heap[fatheridx] = heap[idx];
            heap[idx] = temp;

            int tempidx = heapidx[fatheridx];
            heapidx[fatheridx] = heapidx[idx];
            heapidx[idx] = tempidx;
        }
        idx = fatheridx;
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode * heap[10000] = {0};
    int heapidx[10000] = {0};
    int heapCount = 0;

    //每个链表抽出第一个形成小根堆
    for (int idx = 0; idx < listsSize; idx++) {
        if (lists[idx]) {
            heap[heapCount] = lists[idx];
            heapidx[heapCount++] = idx;
            lists[idx] = lists[idx]->next;
            moveHeapTail(heap, heapidx, heapCount);
            debugprint("Add one node into heap:\n");
            showheap(heap, heapidx, heapCount);
        }
    }

    struct ListNode * ret = heap[0];
    struct ListNode * tail = NULL;

    while (heapCount > 0) {
        //从堆中取出第一个，挂到尾部
        if (tail != NULL) {
            tail->next = heap[0];
        }
        tail = heap[0];
        debugprint("Add one node into list %d, idx:%d\n", heap[0]->val, heapidx[0]);

        //从堆中第一个对应的队列再取出一个，挂到heap头部
        heap[0] = lists[heapidx[0]];

        if (!heap[0]) {
            //如果填入的为NULL，把堆尾放入堆头，缩小堆大小
            if (heapCount > 1) {
                //printf("Move tail node to heap head %d, idx: %d\n", heap[heapCount -1]->val, heapidx[heapCount - 1]);
                heap[0] = heap[heapCount - 1];
                heapidx[0] = heapidx[heapCount - 1];
                heapCount--;
            } else {
                //printf("done!\n");
                break;
            }
        } else {
            lists[heapidx[0]] = lists[heapidx[0]]->next;
            debugprint("Change heap head %d, idx:%d\n", heap[0]->val, heapidx[0]);
        } 

        showheap(heap, heapidx, heapCount);
        moveHeapHead(heap, heapidx, heapCount);
        debugprint("After heap adjustment, ");
        showheap(heap, heapidx, heapCount);
    }
    
    return ret;
}
// @lc code=end


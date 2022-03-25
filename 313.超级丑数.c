/*
 * @lc app=leetcode.cn id=313 lang=c
 *
 * [313] 超级丑数
 */

// @lc code=start
#define log printf

#define father(idx) ((idx - 1) >> 1)
#define lchild(idx) ((idx << 1) + 1)
#define rchild(idx) ((idx << 1) + 1)

#define swap(idx, nidx)         \
    {                           \
        int temp = heap[nidx];  \
        heap[nidx] = heap[idx]; \
        heap[idx] = temp;       \
        idx = nidx;             \
    }

void heapMove(int *heap, int heapSize, int idx)
{
    if (!idx)
    {
        int lidx, ridx, nidx;
        while (idx < (heapSize >> 1))
        {
            lidx = lchild(idx);
            ridx = lidx + 1;
            nidx = ((ridx < heapSize) && (heap[ridx] < heap[lidx])) ? ridx : lidx;

            if (heap[idx] > heap[nidx])
            {
                swap(idx, nidx);
            }
            else
            {
                return;
            }
        }
    }
    else
    {
        int fidx = father(idx);
        while (idx && (heap[idx] < heap[fidx]))
        {
            swap(idx, fidx);
            fidx = father(idx);
        }
    }
}

void logHeap(int *heap, int heapSize)
{
    log("The heap size is %d, values are:[", heapSize);
    for (int idx = 0; idx < heapSize; idx++)
        log("%d,", heap[idx]);
    log("]\n");
}

void heapChangeHead(int *heap, int *heapSize, int newValue)
{
    log("Change head %d -> %d\n", heap[0], newValue);
    heap[0] = newValue;
    heapMove(heap, *heapSize, 0);
}

void heapAddTail(int *heap, int *heapSize, int newValue)
{
    //log("Add %d to heap tail\n", newValue);
    heap[*heapSize] = newValue;
    *heapSize += 1;
    heapMove(heap, *heapSize, *heapSize - 1);
}

int nthSuperUglyNumber(int n, int *primes, int primesSize)
{
    int prevNum = 0;
    int urgCount = 1;
    int heapSize = 1;
    int heapMaxSize = n * primesSize;
    int *heap = malloc(sizeof(int) * heapMaxSize);
    assert(heap != NULL);

    heap[0] = 1;
    while (urgCount < n)
    {
        int value = heap[0];
        if ((value == prevNum) || (value > (0x7fffffff / primes[0])))
        {
            if (value != prevNum)
            {
                urgCount++;
                prevNum = value;
            }
            value = heap[heapSize - 1];
            heapSize--;
            heapChangeHead(heap, &heapSize, value);
        }
        else
        {
            urgCount++;
            prevNum = value;
            heapChangeHead(heap, &heapSize, value * primes[0]);
            for (int i = 1; i < primesSize; i++)
            {
                if (value > (0x7fffffff / primes[i]))
                    break;

                int newvalue = value * primes[i];
                if (heapSize > (n - urgCount) && (newvalue > heap[heapSize - 1]))
                    break;
                heapAddTail(heap, &heapSize, newvalue);
            }
            logHeap(heap, heapSize);
        }
    }

    while (heap[0] == prevNum)
    {
        int value = heap[heapSize - 1];
        heapSize--;
        heapChangeHead(heap, &heapSize, value);
    }

    return heap[0];
}
// @lc code=end

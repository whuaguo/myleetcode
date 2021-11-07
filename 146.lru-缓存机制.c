/*
 * @lc app=leetcode.cn id=146 lang=c
 *
 * [146] LRU 缓存机制
 */

// @lc code=start



typedef struct {
    int key;
    int value;
    int freq; 
} LRUCache;



LRUCache* lRUCacheCreate(int capacity) {

}

int lRUCacheGet(LRUCache* obj, int key) {

}

void lRUCachePut(LRUCache* obj, int key, int value) {

}

void lRUCacheFree(LRUCache* obj) {

}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
// @lc code=end


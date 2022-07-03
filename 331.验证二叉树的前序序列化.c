/*
 * @lc app=leetcode.cn id=331 lang=c
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
#define NEXT(preorder, idx)            \
    do                                 \
    {                                  \
        while (preorder[idx] != ',' && \
               preorder[idx] != '#' && \
               preorder[idx] != '\0')  \
        {                              \
            idx++;                     \
        }                              \
    } while (0);

bool isValidSerialization(char *preorder)
{
    int len = strlen(preorder);

    if (preorder[0] == '#')
    {
        return (len == 1);
    }

    int idx = 1;

    NEXT(preorder, idx);
    int value = 2;

    for (; idx < len; idx++)
    {
        switch (preorder[idx])
        {
        case ',':
            continue;

        case '#':
            value--;
            if (!value)
            {
                return (idx == (len - 1));
            }
            break;

        default:
            NEXT(preorder, idx);
            value++;
            break;
        }
        // printf("the value of %dth(%c) is %d\n", idx, preorder[idx], value);
    }

    return false;
}
// @lc code=end

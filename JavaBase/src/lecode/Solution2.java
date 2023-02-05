package lecode;

import java.util.ArrayList;
import java.util.List;
//https://blog.csdn.net/Cheng_MY/article/details/102993257
class Solution2 {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> lists = new ArrayList();
        List<Integer> arr = new ArrayList();
        backTracking(candidates, 0, target, lists, arr);
        return lists;
    }

    public void backTracking(int[] candidates, int start, int target,
                             List<List<Integer>> lists, List<Integer> arr) {
        if (target == 0) {
            lists.add(new ArrayList(arr));
            return;
        } else if (target < 0) {
            return;
        }
        // 为什么i从start开始，去掉重复的元素，这样每次target减去一个数
        // 之后，只能从它后面的数字中寻找，就不会重复；又因为可以重复使用
        // 相同的元素，因此start可以还等于i
        for (int i = start; i < candidates.length; i++) {
            arr.add(candidates[i]);
            backTracking(candidates, i, target - candidates[i], lists, arr);
            arr.remove(arr.size() - 1);
        }
    }
}


package lecode;

import java.util.ArrayList;
import java.util.List;
//https://blog.csdn.net/qq_17550379/article/details/104224730
class Solution {
    public boolean makesquare(int[] nums) {
        if(nums == null || nums.length < 4){
            return false;
        }

        // 求所有火柴总长度
        int total = 0;

        for(int i = 0; i < nums.length; i++){
            total += nums[i];
        }

        // 如果加出来的和不是4的整数倍，说明无法拼接成功
        if(total % 4 > 0){
            return false;
        }

        // 正方形边长度
        int edgeLength = total / 4;

        // 待使用的有长度的火柴
        List<Integer> edges = new ArrayList<>();
        // 将独自组成边的火柴记录，长度为0火柴排除，有效火柴放入edges
        for(int i = 0; i < nums.length; i++){
            if(nums[i] > edgeLength){
                return false;
            } else{
                edges.add(nums[i]);
            }
        }
        // 记录是否使用
        int[] record = new int[edges.size()];

        // 待拼接的边数
        int targetEdge = 4;

        // 将有效火柴按长度逆序排序，因为我们拼接时优先满足长的火柴
        // 否则可能短火柴组成了边，长火柴之间无法组合
        edges.sort((o1, o2) -> {
            if(o1 > o2){
                return -1;
            }else if(o1.equals(o2)){
                return 0;
            }else{
                return 1;
            }
        });

        // 分别组合剩下需要组合的正方形边
        for(int i = 0; i < targetEdge; i++){
            boolean result = backtrack(edgeLength, edges, 0, 0, record);
            if(result == false){
                // 只要有一个边未组合成功，则失败
                return false;
            }
        }
        // 全部能组合，返回成功
        return true;
    }

    private boolean backtrack(int edgeLength, List<Integer> edges, int start, int tmpSum, int[] record){
        if(tmpSum == edgeLength){
            // 结束条件，拼接成功
            return true;
        }
        if(tmpSum > edgeLength){
            // 结束条件，拼接失败
            return false;
        }
        // 遍历选择条件
        for(int i = start; i < edges.size(); i++){
            if(record[i] == 1){
                continue;
            }
            tmpSum += edges.get(i);
            // 选择该火柴，将火柴标示为已使用
            record[i] = 1;
            if(backtrack(edgeLength, edges, i + 1, tmpSum, record)){
                // 能组成边，这趟回溯就结束了
                return true;
            }
            tmpSum -= edges.get(i);
            // 不选该火柴，将火柴下标标示为未使用
            record[i] = 0;
        }
        // 遍历完了都没能组成边，返回false
        return false;
    }
}


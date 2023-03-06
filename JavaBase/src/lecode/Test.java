package lecode;

public class Test {

    private static int minimum(String s)
    {
        int n = s.length();
        int[] f = new int[n+1];
        int b = 0;
        for (int i = 1; i <= n; i++) {
            if(s.charAt(i-1) == 'b')
            {
                f[i]=f[i-1];
                ++b;
            }
            else
            {
                f[i] = Math.min(f[i-1]+1,b);
            }
        }
        return f[n];
    }

    public static void main(String[] args) {
        Solution2 solution = new Solution2();
        int huochai[] = {2,3,5};
        System.out.println(minimum("aaabbbabab"));

    }
}

```java
// 中心拓展算法
class Solution {
    public String longestPalindrome(String s) {
        if(s == null || s.length() == 0){
            return "";
        }
        int len, start = 0, end = 0;
        for(int i=0;i<s.length();i++){
            len = Math.max(expandAroundCenter(s,i,i), expandAroundCenter(s,i,i+1));
            if(len > end - start + 1){
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substring(start, end + 1);
    }
    
    private int expandAroundCenter(String s, int left, int right){
        while(left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)){
            left--;
            right++;
        }
        return right - left - 1;
    }
}
```
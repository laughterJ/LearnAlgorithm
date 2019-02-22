```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> map = new HashMap<>();
        // start 置为 -1，用于计算下标为 i 的元素到第一个元素的长度
        int maxLen = 0, start = -1;
        for(int i=0;i<s.length();i++){
            if(map.containsKey(s.charAt(i))){
                start = Math.max(map.get(s.charAt(i)), start);
            }
            maxLen = Math.max(maxLen, i - start);
            map.put(s.charAt(i), i);
        }
        return maxLen;
    }
}
```
```java
class Solution {
    public int strStr(String haystack, String needle) {
    	if(needle.equals("")) return 0;
        int len1 = haystack.length(), len2 = needle.length();
    	if (len1 < len2) return -1;
    	char[] str1 = haystack.toCharArray();
    	char[] str2 = needle.toCharArray();
    	int start;
    	for(int i=0;i<len1-len2+1;i++) {
    		if(str1[i] == str2[0]) {
    			start = i;
    			while(i < len1 && i-start < len2 && str1[i] == str2[i-start]) i++;
    			if(start + len2 == i) {
    				return start;
    			}else {
    				i = start;
    			}
    		}
    	}
    	return -1;
    }
}
```
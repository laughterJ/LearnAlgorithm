```java
/**
 * 最初通过方案
 * 主要考虑以下几种情况：
 * 1. 为防止溢出，使用 long 来存储数字
 * 2. 为数字（需要考虑将这一位添加后是否超出 int 范围）
 * 3. 首位为 ‘+’ 或 ‘-’ ，需要处理符号标记位
 * 4. 首位为空格，直接跳过
 * 5. 首位不是数字、正负号或空格，直接返回0
 * 6. 遍历到非数字即结束
 *
 */
class Solution {
    public int myAtoi(String str) {
        long num = 0;
        int len = 0;
        long sign = 1;
        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) >= '0' && str.charAt(i) <= '9'){
                num = num*10 + Integer.parseInt(str.charAt(i)+"");
                len++;
                if(num > Integer.MAX_VALUE){
                    return sign > 0 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
                }
            }else if(len == 0 && (str.charAt(i) == '-' || str.charAt(i) == '+')){
                sign = str.charAt(i) == '+' ? sign : -sign;
                len++;
            }else if(len == 0 && str.charAt(i) == ' '){
                continue;
            }else if(len == 0){
                return 0;
            }else{
                break;
            }
        }
        return (int)(num * sign);
    }
}
```
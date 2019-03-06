```java
class Solution {
    public String convert(String s, int numRows) {
        if(s == null || s.length() < numRows || numRows < 2){
            return s;
        }
        List<List<Character>> nums = new ArrayList<>();
        for(int i=0;i<numRows;i++){
            List<Character> num = new ArrayList<>();
            num.add(s.charAt(i));
            nums.add(num);
        }
        int curRow = numRows - 2;
        boolean sign = false;
        for(int i=numRows;i<s.length();i++){
            if(curRow == numRows-1 || curRow == 0){
                sign = !sign;
            }
            nums.get(curRow).add(s.charAt(i));
            if(sign){
                curRow++;
            }else{
                curRow--;
            }
        }
        String res = "";
        for(int i=0;i<numRows;i++){
            for(char c : nums.get(i)){
                res+=c;
            }
        }
        return res;
    }
}
```
```java
class Solution {
    public int[] plusOne(int[] digits) {
        for(int i=digits.length-1;i>=0;i--){
            digits[i] += 1;
            if(digits[i] < 10){
                break;
            }
        }
        if(digits[0] > 9){
            int num = new int[digits.length+1];
            num[0] = 1;
            for(int i=1;i<num.length-1;i++){
                num[i] = digits[i-1] % 10;
            }
            return num;
        }else{
            for(int i=0;i<digits.length;i++){
                digits[i] = digits[i] % 10;
            }
            return digits;
        }
    }
}
```
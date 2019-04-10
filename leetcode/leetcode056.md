```java
/**
 * 先排序，然后依次比较，但是排序比较耗时
 */
class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        intervals.sort((a, b) -> a.start - b.start);
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals.get(i).end >= intervals.get(i+1).start){
                intervals.get(i).end = Math.max(intervals.get(i).end, intervals.get(i+1).end);
                intervals.remove(i+1);
                i--;
            }
        }
        return intervals;
    }
}

/**
 * 优化
 */
class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        int[] start = new int[intervals.size()];
        int[] end = new int[intervals.size()];
        for(int i = 0; i < intervals.size(); i++) {
            start[i] = intervals.get(i).start;
            end[i] = intervals.get(i).end;
        }
        int startIndex = 0, endIndex = 0, n = end.length;
        List<Interval> result = new ArrayList<>();
        Arrays.sort(start);
        Arrays.sort(end);
        while(endIndex < n) {
            if(endIndex == n - 1 || start[endIndex + 1] > end[endIndex]) {
                result.add(new Interval(start[startIndex], end[endIndex]));
                startIndex = endIndex + 1;
            }
            endIndex++;
        }
        return result;
    }
}
```
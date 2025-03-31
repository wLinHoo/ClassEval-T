public class AvgPartition {
    private int[] lst;
    private int limit;

    public AvgPartition(int[] lst, int limit) {
        this.lst = lst;
        this.limit = limit;
    }

    public int[] get(int index) {
        int size = lst.length / limit;
        int remainder = lst.length % limit;
        int start = index * size + Math.min(index, remainder);
        int end = start + size;
        if (index + 1 <= remainder) {
            end += 1;
        }
        int[] result = new int[end - start];
        System.arraycopy(lst, start, result, 0, end - start);
        return result;
    }
}
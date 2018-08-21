import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import org.apache.commons.lang3.tuple.Pair;
import org.apache.commons.lang3.tuple.ImmutablePair;

public class KSum {

    public static void main(String[] args) {
        var ksum = new KSum();
        List<Integer> l1 = Arrays.asList(1, 1, 2, 2, 3);
        List<Integer> l2 = Arrays.asList(1, 2, 3, 4);
        List<Pair<Integer, Integer>> result = ksum.getKSums(l1, l2, 3);
        System.out.println("Array 1: " + l1.toString());
        System.out.println("Array 2: " + l2.toString());
        System.out.println("Result: " + result.toString());
    }

    List<Pair<Integer, Integer>> getKSums(List<Integer> l1, List<Integer> l2, Integer k) {
        PriorityQueue<Pair<Integer, Pair<Integer, Integer>>> q =
            new PriorityQueue<Pair<Integer, Pair<Integer, Integer>>>(l1.size() * l2.size(),
                    (a, b) -> {
                        return a.getLeft().compareTo(b.getLeft());
            });
        l1.forEach((x) -> {
            l2.forEach((y) -> q.add(
                        new ImmutablePair<Integer, Pair<Integer, Integer>>(x+y, new ImmutablePair<Integer, Integer>(x, y))));
        });

        List<Pair<Integer, Integer>> result = new ArrayList<Pair<Integer, Integer>>();
        for (Integer i = 0; i < k; i++) {
            var tmp = q.poll();
            result.add(new ImmutablePair<Integer, Integer>(tmp.getRight().getLeft(), tmp.getRight().getRight()));
        }
        return result;
    }
}

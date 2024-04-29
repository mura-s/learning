import java.util.*;
import java.util.function.*;
import java.util.stream.Collectors;

class Ch4_10 {
    public static void main(String[] args) {
        var words = List.of("haskell", "rust", "scala", "java", "ada");
        System.out.println(rankedWords(w -> baseScore(w), words));
        System.out.println(rankedWords(w -> baseScore(w) + bonus(w), words));
        System.out.println(rankedWords(w -> baseScore(w) + bonus(w) - penalty(w), words));
    }

    static List<String> rankedWords(Function<String, Integer> wordScore, List<String> words) {
        Comparator<String> wordComparator = (w1, w2) -> Integer.compare(wordScore.apply(w2), wordScore.apply(w1));
        return words.stream().sorted(wordComparator).collect(Collectors.toList());
    }

    static int baseScore(String word) {
        return word.replaceAll("a", "").length();
    }

    static int bonus(String word) {
        return word.contains("c") ? 5 : 0;
    }

    static int penalty(String word) {
        return word.contains("s") ? 7 : 0;
    }
}

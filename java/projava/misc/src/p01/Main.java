package p01;

import java.math.BigDecimal;
import java.time.*;

public class Main {
    public static void main(String[] args) {
        var d = LocalDate.now();
        System.out.println(d);
        var t = LocalTime.now();
        System.out.println(t);
        var dt = LocalDateTime.now();
        System.out.println("%tA".formatted(dt));

        var b1 = new BigDecimal("579");
        var b2 = new BigDecimal("0.05");
        System.out.println(b1.multiply(b2));

        var s1 = "hoge";
        var s2 = s1;
        s2 = "hoge2";
        System.out.println(s1);
    }
}

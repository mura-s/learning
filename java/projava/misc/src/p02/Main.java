package p02;

public class Main {
    public static void main(String[] args) {
        var a = 2;
        switch (a) {
            case 1 -> {
                System.out.println("1");
                System.out.println("1");
            }
            case 2 -> {
                System.out.println("2");
                System.out.println("2");
            }
            default -> {
                System.out.println("default");
            }
        }
    }
}

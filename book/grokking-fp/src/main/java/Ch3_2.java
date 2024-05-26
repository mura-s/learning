import java.util.ArrayList;
import java.util.List;

class Ch3_2 {
    public static void main(String[] args) {
        List<String> planA = new ArrayList<>();
        planA.add("Paris");
        planA.add("Berlin");
        planA.add("Krakow");
        System.out.println("Plan A: " + planA);

        List<String> planB = replan(planA, "Vienna", "Krakow");
        System.out.println("Plan B: " + planB);
        System.out.println("Plan A: " + planA);
    }

    static List<String> replan(List<String> plan,
            String newCity,
            String beforeCity) {
        int newCityIndex = plan.indexOf(beforeCity);
        plan.add(newCityIndex, newCity);
        return plan;
    }
}

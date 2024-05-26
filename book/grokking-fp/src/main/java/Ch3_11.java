import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Ch3_11 {
    public static void main(String[] args) {
        Itinerary itinerary = new Ch3_11.Itinerary();
        itinerary.add("Paris");
        itinerary.add("Berlin");
        itinerary.add("Krakow");
        List<String> planA = itinerary.getPlan();
        System.out.println(planA);

        itinerary.replan("Vienna", "Krakow");
        List<String> planB = itinerary.getPlan();
        planB.add("A");
        System.out.println(planB);
        System.out.println(planA);
    }

    static class Itinerary {
        private List<String> plan = new ArrayList<>();

        public void replan(String newCity, String beforeCity) {
            int newCityIndex = plan.indexOf(beforeCity);
            plan.add(newCityIndex, newCity);
        }

        public void add(String city) {
            plan.add(city);
        }

        public List<String> getPlan() {
            return Collections.unmodifiableList(plan);
        }
    }
}

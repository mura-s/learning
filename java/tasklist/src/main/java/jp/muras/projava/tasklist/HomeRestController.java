package jp.muras.projava.tasklist;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;
import java.util.stream.Collectors;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HomeRestController {

    record TaskItem(String id, String task, String deadline, boolean done) {
    }

    private List<TaskItem> taskItems = new ArrayList<>();

    @RequestMapping("/resthello")
    String hello() {
        return """
                Hello.
                It works!
                Current Time is %s.
                    """.formatted(LocalDateTime.now());
    }

    @GetMapping("/restadd")
    String addItem(@RequestParam("task") String task, @RequestParam("deadline") String deadline) {
        String id = UUID.randomUUID().toString().substring(0, 8);
        TaskItem item = new TaskItem(id, task, deadline, false);
        taskItems.add(item);

        return "Added the task";
    }

    @GetMapping("/restlist")
    String listItems() {
        return taskItems.stream().map(TaskItem::toString).collect(Collectors.joining(", "));
    }
}

package jp.muras.projava.tasklist;

import java.time.LocalDateTime;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HomeRestController {
    @RequestMapping("/resthello")
    String hello() {
        return """
                Hello.
                It works!
                Current Time is %s.
                    """.formatted(LocalDateTime.now());
    }
}

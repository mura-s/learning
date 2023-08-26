package com.example.training.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class AuthPageController {
    @RequestMapping("/display-access-denied")
    public String accessDenied() {
        return "auth/accessDenial";
    }

    @GetMapping("/login")
    public String loginForm() {
        return "auth/loginForm";
    }

    @GetMapping(value = "/login", params = "failure")
    public String loginFail(Model model) {
        model.addAttribute("failureMessage", "IDもしくはパスワードが違います");
        return "auth/loginForm";
    }
}

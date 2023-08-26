package com.example.calculate.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class CalculateController {


	@GetMapping("/calculate-price")
	public String calculatePrice(@RequestParam int a, @RequestParam int b, @RequestParam int c, Model model) {
        int total = a + b + c;
        System.out.println(total);
        int price = (int)(total * 1.1);
        model.addAttribute("price", price);
        return "price";
	}
}

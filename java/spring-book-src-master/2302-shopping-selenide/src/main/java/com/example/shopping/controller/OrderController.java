package com.example.shopping.controller;

import com.example.shopping.input.OrderInput;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import com.example.shopping.entity.Order;
import com.example.shopping.enumeration.PaymentMethod;
import com.example.shopping.exception.StockShortageException;
import com.example.shopping.service.OrderService;

@Controller
@RequestMapping("/order")
public class OrderController {
    private final OrderService orderService;
    private final OrderSession orderSession;
    public OrderController(OrderService orderService, OrderSession orderSession) {
        this.orderService = orderService;
        this.orderSession = orderSession;
    }

    @GetMapping("/display-form")
    public String displayForm(Model model) {
        OrderInput orderInput = new OrderInput();
        orderInput.setPaymentMethod(PaymentMethod.BANK);
        model.addAttribute("orderInput", orderInput);
        return "order/orderForm";
    }

    @PostMapping("/validate-input")
    public String validateInput(
        @Validated OrderInput orderInput, BindingResult bindingResult, Model model) {
        if (bindingResult.hasErrors()) {
            return "order/orderForm";
        }
        orderSession.setOrderInput(orderInput);
        model.addAttribute("cartInput", orderSession.getCartInput());
        return "order/orderConfirmation";
    }

    @PostMapping(value = "/place-order", params = "correct")
    public String correctInput(Model model) {
        model.addAttribute("orderInput", orderSession.getOrderInput());
        return "order/orderForm";
    }

    @PostMapping(value = "/place-order", params = "order")
    public String order(RedirectAttributes redirectAttributes) {
        Order order = orderService
            .placeOrder(orderSession.getOrderInput(), orderSession.getCartInput());
        redirectAttributes.addFlashAttribute("order", order);
        orderSession.clearData();
        return "redirect:/order/display-completion";
    }

    @GetMapping("/display-completion")
    public String displayComplete() {
        return "order/orderCompletion";
    }

    @ExceptionHandler(StockShortageException.class)
    public String displayStockShortagePage() {
        return "order/stockShortage";
    }
}

package com.example.shopping.controller;

import java.util.ArrayList;
import java.util.List;

import com.example.shopping.input.CartInput;
import com.example.shopping.input.OrderInput;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import com.example.shopping.entity.Order;
import com.example.shopping.enumeration.PaymentMethod;
import com.example.shopping.input.CartItemInput;
import com.example.shopping.service.OrderService;

@Controller
@RequestMapping("/order")
public class OrderController {
    private final OrderService orderService;

    public OrderController(OrderService orderService) {
        this.orderService = orderService;
    }

    // ハンズオンの都合上、カートの中身は固定値とします。
    private CartInput dummyCartInput() {
        List<CartItemInput> cartItemInputs = new ArrayList<>();

        CartItemInput keshigom = new CartItemInput();
        keshigom.setProductId("p01");
        keshigom.setProductName("消しゴム");
        keshigom.setProductPrice(100);
        keshigom.setQuantity(4);
        cartItemInputs.add(keshigom);

        CartItemInput note = new CartItemInput();
        note.setProductId("p02");
        note.setProductName("ノート");
        note.setProductPrice(200);
        note.setQuantity(5);
        cartItemInputs.add(note);

        CartInput cartInput = new CartInput();
        cartInput.setCartItemInputs(cartItemInputs);
        return cartInput;
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
        OrderInput orderInput, Model model) {
        CartInput cartInput = dummyCartInput();
        model.addAttribute("cartInput", cartInput);
        return "order/orderConfirmation";
    }

    @PostMapping(value = "/place-order")
    public String correctInput(@Validated OrderInput orderInput, Model model) {
        return "order/orderForm";
    }

    public String order(@Validated OrderInput orderInput, Model model) {
        CartInput cartInput = dummyCartInput();
        Order order = orderService
            .placeOrder(orderInput, cartInput);
        model.addAttribute("order", order);
        return "order/orderCompletion";
    }
}

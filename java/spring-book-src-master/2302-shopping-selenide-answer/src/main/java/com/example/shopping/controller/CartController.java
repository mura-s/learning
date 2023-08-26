package com.example.shopping.controller;

import java.util.ArrayList;
import java.util.UUID;

import com.example.shopping.input.CartInput;
import com.example.shopping.input.CartItemInput;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import com.example.shopping.entity.Product;
import com.example.shopping.service.CatalogService;
import com.example.shopping.service.OrderService;

@Controller
@RequestMapping("/cart")
public class CartController {
    private final CatalogService catalogService;
    private final OrderService orderService;
    private final OrderSession orderSession;

    public CartController(
            CatalogService catalogService, OrderService orderService, OrderSession orderSession) {
        this.catalogService = catalogService;
        this.orderService = orderService;
        this.orderSession = orderSession;
    }

    @PostMapping("/add-item")
    public String addToCart(
        @Validated CartItemInput cartItem, BindingResult bindingResult, Model model) {
        Product product = catalogService.findById(cartItem.getProductId());
        if (bindingResult.hasErrors()) {            
            model.addAttribute("product", product);
            return "catalog/productDetails";
        }
        cartItem.setId(UUID.randomUUID().toString());
        cartItem.setProductName(product.getName());
        cartItem.setProductPrice(product.getPrice());
        CartInput cartInput = orderSession.getCartInput();
        if (cartInput == null) {
            cartInput = new CartInput();
            cartInput.setCartItemInputs(new ArrayList<>());
            orderSession.setCartInput(cartInput);
        }
        cartInput.getCartItemInputs().add(cartItem);
        calculatedAmounts(cartInput);
        model.addAttribute("cartInput", cartInput);
        return "cart/cartItems";
    }

    @GetMapping("/display-cart")
    public String displayCart(Model model) {
        model.addAttribute("cartInput", orderSession.getCartInput());
        return "cart/cartItems";
    }

    @PostMapping("/remove-item")
    public String removeFromCart(String cartItemId, Model model) {
        CartInput cartInput = orderSession.getCartInput();
        CartItemInput target = null;
        for (CartItemInput item : cartInput.getCartItemInputs()) {
            if (cartItemId.equals(item.getId())) {
                target = item;
                break;
            }
        }
        cartInput.getCartItemInputs().remove(target);
        calculatedAmounts(cartInput);
        model.addAttribute("cartInput", cartInput);
        return "cart/cartItems";
    }

    private void calculatedAmounts(CartInput cartInput) {
        int totalAmount = orderService.calculateTotalAmount(cartInput.getCartItemInputs());
        int billingAmount = orderService.calculateTax(totalAmount);
        cartInput.setTotalAmount(totalAmount);
        cartInput.setBillingAmount(billingAmount);
    }
}

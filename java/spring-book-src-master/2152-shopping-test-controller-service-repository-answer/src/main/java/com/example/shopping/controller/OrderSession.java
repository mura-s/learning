package com.example.shopping.controller;

import java.io.Serializable;

import com.example.shopping.input.OrderInput;
import org.springframework.context.annotation.ScopedProxyMode;
import org.springframework.stereotype.Component;
import org.springframework.web.context.annotation.SessionScope;

import com.example.shopping.input.CartInput;

@Component
@SessionScope(proxyMode = ScopedProxyMode.TARGET_CLASS)
@SuppressWarnings("serial")
public class OrderSession implements Serializable {
    private CartInput cartInput;
    private OrderInput orderInput;

    public void clearData() {
        cartInput = null;
        orderInput = null;
    }

    public CartInput getCartInput() {
        return cartInput;
    }

    public void setCartInput(CartInput cartInput) {
        this.cartInput = cartInput;
    }

    public OrderInput getOrderInput() {
        return orderInput;
    }

    public void setOrderInput(OrderInput orderInput) {
        this.orderInput = orderInput;
    }
}

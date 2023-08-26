package com.example.shopping.service;

import java.util.List;

import com.example.shopping.entity.Order;
import com.example.shopping.input.CartInput;
import com.example.shopping.input.CartItemInput;
import com.example.shopping.input.OrderInput;

public interface OrderService {
    int calculateTotalAmount(List<CartItemInput> cartItems);

    int calculateTax(int price);

    Order placeOrder(OrderInput orderInput, CartInput cartInput);
}

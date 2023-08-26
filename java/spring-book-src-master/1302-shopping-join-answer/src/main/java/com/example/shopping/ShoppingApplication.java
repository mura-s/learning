package com.example.shopping;


import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

import com.example.shopping.entity.Order;
import com.example.shopping.entity.OrderItem;
import com.example.shopping.repository.OrderItemRepository;
import com.example.shopping.repository.OrderRepository;

@SpringBootApplication
public class ShoppingApplication {
    public static void main(String[] args) {

        ApplicationContext context = SpringApplication.run(ShoppingApplication.class, args);

        OrderItemRepository orderItemRepository = context.getBean(OrderItemRepository.class);
        OrderItem orderItem = orderItemRepository.selectById("i01");

        System.out.println("------------- OrderItemの中身 -------------");
        System.out.println(orderItem.getPriceAtOrder());
        System.out.println(orderItem.getProduct());

        OrderRepository orderRepository = context.getBean(OrderRepository.class);
        Order order = orderRepository.selectById("o01");

        System.out.println("------------- Orderの中身 -------------");
        System.out.println(order.getCustomerName());
        for (OrderItem i : order.getOrderItems()) {
            System.out.println(i.getPriceAtOrder());
        }

    }
}


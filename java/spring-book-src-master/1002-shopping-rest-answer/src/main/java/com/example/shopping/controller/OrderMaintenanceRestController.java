package com.example.shopping.controller;

import java.util.List;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.example.shopping.entity.Order;
import com.example.shopping.service.OrderMaintenanceService;

@RestController
@RequestMapping("/api/orders")
public class OrderMaintenanceRestController {
    private final OrderMaintenanceService orderMaintenanceService;
    public OrderMaintenanceRestController(OrderMaintenanceService orderMaintenanceService) {
        this.orderMaintenanceService = orderMaintenanceService;
    }

    @GetMapping
    public List<Order> getOrders() {
        return orderMaintenanceService.findAll();
    }

    @GetMapping("/{id}")
    public Order getOrder(@PathVariable String id) {
        Order order = orderMaintenanceService.findById(id);
        return order;
    }
}
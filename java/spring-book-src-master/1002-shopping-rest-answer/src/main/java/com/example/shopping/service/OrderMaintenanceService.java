package com.example.shopping.service;

import java.util.List;

import com.example.shopping.entity.Order;

public interface OrderMaintenanceService {
    List<Order> findAll();

    Order findById(String id);
}

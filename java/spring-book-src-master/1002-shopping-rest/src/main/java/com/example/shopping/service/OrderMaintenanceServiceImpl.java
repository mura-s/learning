package com.example.shopping.service;

import java.util.List;

import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.example.shopping.entity.Order;
import com.example.shopping.repository.OrderRepository;

@Service
@Transactional
public class OrderMaintenanceServiceImpl implements OrderMaintenanceService {

    private final OrderRepository orderRepository;

    public OrderMaintenanceServiceImpl(OrderRepository orderRepository) {
        this.orderRepository = orderRepository;
    }

    @Override
    public List<Order> findAll() {
        return orderRepository.selectAll();
    }

    @Override
    public Order findById(String id) {
        return orderRepository.selectById(id);
    }
}

package com.example.shopping.repository;

import com.example.shopping.entity.Order;

public interface OrderRepository {
    Order selectById(String id);
}

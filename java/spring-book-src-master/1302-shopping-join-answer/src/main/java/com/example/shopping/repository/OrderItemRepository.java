package com.example.shopping.repository;

import com.example.shopping.entity.OrderItem;

public interface OrderItemRepository {
    OrderItem selectById(String id);
}

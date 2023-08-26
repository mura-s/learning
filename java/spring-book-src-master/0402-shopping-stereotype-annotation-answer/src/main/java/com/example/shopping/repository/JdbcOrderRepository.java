package com.example.shopping.repository;

import org.springframework.stereotype.Repository;

import com.example.shopping.entity.Order;

@Repository
public class JdbcOrderRepository implements OrderRepository {
    @Override
    public void insert(Order order) {
        if (order == null) {
            throw new IllegalArgumentException("引数が不正");
        }
        System.out.println("注文を登録しました。id=" + order.getId());
    }
}

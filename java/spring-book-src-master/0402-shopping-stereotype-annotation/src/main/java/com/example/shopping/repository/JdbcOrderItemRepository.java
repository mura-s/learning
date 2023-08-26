
package com.example.shopping.repository;

import com.example.shopping.entity.OrderItem;

public class JdbcOrderItemRepository implements OrderItemRepository {

    @Override
    public void insert(OrderItem orderItem) {
        if (orderItem == null) {
            throw new IllegalArgumentException("引数が不正");
        }
        System.out.println("注文明細を登録しました。id=" + orderItem.getId());
    }
}

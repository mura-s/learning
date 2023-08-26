package com.example.shopping.repository;

import org.springframework.jdbc.core.DataClassRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import com.example.shopping.entity.OrderItem;

@Repository
public class JdbcOrderItemRepository implements OrderItemRepository {
    private final JdbcTemplate jdbcTemplate;

    public JdbcOrderItemRepository(JdbcTemplate jdbcTemplate) {
        this.jdbcTemplate = jdbcTemplate;
    }

    @Override
    public OrderItem selectById(String id) {
        return jdbcTemplate.queryForObject("""
            SELECT
              i.id AS i_id,
              i.order_id AS i_order_id,
              i.product_id AS i_product_id,
              i.price_at_order AS i_price_at_order,
              i.quantity AS i_quantity,
              p.id AS p_id,
              p.name AS p_name,
              p.price AS p_price,
              p.stock AS p_stock
            FROM
              t_order_item i
              LEFT OUTER JOIN t_product p 
              ON i.product_id = p.id
            WHERE
              i.id = ?""", new DataClassRowMapper<>(OrderItem.class), id);
    }
}

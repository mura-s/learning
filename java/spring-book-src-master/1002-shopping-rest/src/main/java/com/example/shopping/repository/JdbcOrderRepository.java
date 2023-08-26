package com.example.shopping.repository;

import java.util.List;

import org.springframework.jdbc.core.DataClassRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import com.example.shopping.entity.Order;

@Repository
public class JdbcOrderRepository implements OrderRepository {
    private final JdbcTemplate jdbcTemplate;

    public JdbcOrderRepository(JdbcTemplate jdbcTemplate) {
        this.jdbcTemplate = jdbcTemplate;
    }

    @Override
    public void insert(Order order) {
        jdbcTemplate.update("INSERT INTO t_order VALUES (?, ?, ?, ?, ?, ?, ?, ?)",
                order.getId(),
                order.getOrderDateTime(),
                order.getBillingAmount(),
                order.getCustomerName(),
                order.getCustomerAddress(),
                order.getCustomerPhone(),
                order.getCustomerEmailAddress(),
                order.getPaymentMethod().toString());
    }

    @Override
    public List<Order> selectAll() {
        return jdbcTemplate.query("SELECT * FROM t_order", new DataClassRowMapper<>(Order.class));
    }

    @Override
    public Order selectById(String id) {
        return jdbcTemplate.queryForObject("SELECT * FROM t_order WHERE id=?", new DataClassRowMapper<>(Order.class), id);
    }
}

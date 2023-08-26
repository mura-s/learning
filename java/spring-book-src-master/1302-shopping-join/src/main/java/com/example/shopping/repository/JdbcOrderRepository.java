package com.example.shopping.repository;

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
    public Order selectById(String id) {

        return jdbcTemplate.queryForObject("""
            SELECT
              o.id AS o_id,
              o.order_date_time AS o_order_date_time,
              o.billing_amount AS o_billing_amount,
              o.customer_name AS o_customer_name,
              o.customer_address AS o_customer_address,
              o.customer_phone AS o_customer_phone,
              o.customer_email_address AS o_customer_email_address,
              o.payment_method AS o_payment_method,
              i.id AS i_id,
              i.order_id AS i_order_id,
              i.product_id AS i_product_id,
              i.price_at_order AS i_price_at_order,
              i.quantity AS i_quantity
            FROM
              t_order o
              LEFT OUTER JOIN t_order_item i 
              ON o.id = i.order_id
            WHERE
              o.id = ?""", new DataClassRowMapper<>(Order.class), id);
    }

}

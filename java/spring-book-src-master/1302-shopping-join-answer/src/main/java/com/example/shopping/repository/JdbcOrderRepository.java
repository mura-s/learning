package com.example.shopping.repository;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDateTime;
import java.util.ArrayList;

import org.springframework.dao.DataAccessException;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.ResultSetExtractor;
import org.springframework.stereotype.Repository;

import com.example.shopping.entity.Order;
import com.example.shopping.entity.OrderItem;
import com.example.shopping.enumeration.PaymentMethod;

@Repository
public class JdbcOrderRepository implements OrderRepository {
    private final JdbcTemplate jdbcTemplate;

    public JdbcOrderRepository(JdbcTemplate jdbcTemplate) {
        this.jdbcTemplate = jdbcTemplate;
    }

    @Override
    public Order selectById(String id) {
        return jdbcTemplate.query("""
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
              o.id = ?""", new OrderResultSetExtractor(), id);
    }

    static class OrderResultSetExtractor implements ResultSetExtractor<Order> {
        @Override
        public Order extractData(ResultSet rs) throws SQLException, DataAccessException {
            Order order = null;
            while(rs.next()) {
                if (order == null) {
                    order = new Order();
                    order.setOrderItems(new ArrayList<>());
                    order.setId(rs.getString("o_id"));
                    order.setOrderDateTime(rs.getObject("o_order_date_time", LocalDateTime.class));
                    order.setBillingAmount(rs.getInt("o_billing_amount"));
                    order.setCustomerName(rs.getString("o_customer_name"));
                    order.setCustomerAddress(rs.getString("o_customer_address"));
                    order.setCustomerPhone(rs.getString("o_customer_phone"));
                    order.setCustomerEmailAddress(rs.getString("o_customer_email_address"));
                    order.setPaymentMethod(PaymentMethod.valueOf(rs.getString("o_payment_method")));
                }
                OrderItem orderItem = new OrderItem();
                orderItem.setId(rs.getString("i_id"));
                orderItem.setOrderId(rs.getString("i_order_id"));
                orderItem.setProductId(rs.getString("i_product_id"));
                orderItem.setPriceAtOrder(rs.getInt("i_price_at_order"));
                orderItem.setQuantity(rs.getInt("i_quantity"));
                order.getOrderItems().add(orderItem);
            }
            return order;
        }
    }


}

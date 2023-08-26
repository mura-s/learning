package com.example.shopping.repository;

import java.sql.ResultSet;
import java.sql.SQLException;

import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.stereotype.Repository;

import com.example.shopping.entity.OrderItem;
import com.example.shopping.entity.Product;

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
              i.id = ?""", new OrderItemRowMapper(), id);
    }

    static class OrderItemRowMapper implements RowMapper<OrderItem> {
        @Override
        public OrderItem mapRow(ResultSet rs, int rowNum) throws SQLException {
            OrderItem orderItem = new OrderItem();
            orderItem.setId(rs.getString("i_id"));
            orderItem.setOrderId(rs.getString("i_order_id"));
            orderItem.setProductId(rs.getString("i_product_id"));
            orderItem.setPriceAtOrder(rs.getInt("i_price_at_order"));
            orderItem.setQuantity(rs.getInt("i_quantity"));
            Product product = new Product();
            product.setId(rs.getString("p_id"));
            product.setName(rs.getString("p_name"));
            product.setPrice(rs.getInt("p_price"));
            product.setStock(rs.getInt("p_stock"));
            orderItem.setProduct(product);
            return orderItem;
        }
    }

}

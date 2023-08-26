package com.example.shopping.repository;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Timestamp;

import javax.sql.DataSource;

import org.springframework.stereotype.Repository;

import com.example.shopping.entity.Order;

@Repository
public class JdbcOrderRepository implements OrderRepository {
    private final DataSource dataSource;

    public JdbcOrderRepository(DataSource dataSource) {
        this.dataSource = dataSource;
    }

    @Override
    public void insert(Order order) {
        try (
            Connection con = dataSource.getConnection();
            PreparedStatement stmt
                = con.prepareStatement("INSERT INTO t_order values (?, ?, ?, ?, ?, ?, ?, ?)");
        ) {
            stmt.setString(1, order.getId());
            stmt.setTimestamp(2, Timestamp.valueOf(order.getOrderDateTime()));
            stmt.setInt(3, order.getBillingAmount());
            stmt.setString(4, order.getCustomerName());
            stmt.setString(5, order.getCustomerAddress());
            stmt.setString(6, order.getCustomerPhone());
            stmt.setString(7, order.getCustomerEmailAddress());
            stmt.setString(8, order.getPaymentMethod().toString());
            stmt.executeUpdate();
        } catch (SQLException ex) {
            throw new RuntimeException("INSERTに失敗", ex);
        }
    }
}

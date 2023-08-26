package com.example.shopping.repository;

import org.springframework.jdbc.core.DataClassRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import com.example.shopping.entity.Product;

@Repository
public class JdbcProductRepository implements ProductRepository {
    private final JdbcTemplate jdbcTemplate;

    public JdbcProductRepository(JdbcTemplate jdbcTemplate) {
        this.jdbcTemplate = jdbcTemplate;
    }

    @Override
    public Product selectById(String id) {
        return jdbcTemplate.queryForObject("SELECT * FROM t_product WHERE id=?", new DataClassRowMapper<>(Product.class), id);
    }

    @Override
    public boolean update(Product product) {
        int count = jdbcTemplate.update("UPDATE t_product SET name=?, price=?, stock=? WHERE id=?",
            product.getName(),
            product.getPrice(),
            product.getStock(),
            product.getId()
                );
        if (count == 0) {
            return false;
        }
        return true;
    }
}
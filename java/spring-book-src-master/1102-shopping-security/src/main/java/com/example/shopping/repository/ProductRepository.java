package com.example.shopping.repository;

import java.util.List;

import com.example.shopping.entity.Product;

public interface ProductRepository {
    Product selectById(String id);

    List<Product> selectAll();

    boolean update(Product product);

    boolean delete(String id);
}

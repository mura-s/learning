package com.example.shopping.service;

import java.util.List;

import com.example.shopping.entity.Product;

public interface CatalogService {
    List<Product> findAll();

    Product findById(String id);
}

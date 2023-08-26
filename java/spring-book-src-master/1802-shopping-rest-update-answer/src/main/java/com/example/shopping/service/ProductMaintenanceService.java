package com.example.shopping.service;

import java.util.List;

import com.example.shopping.entity.Product;
import com.example.shopping.input.ProductMaintenanceInput;

public interface ProductMaintenanceService {
    List<Product> findAll();

    Product findById(String id);

    void update(ProductMaintenanceInput productMaintenanceInput);

    void delete(String id);

    Product register(ProductMaintenanceInput productMaintenanceInput);


}

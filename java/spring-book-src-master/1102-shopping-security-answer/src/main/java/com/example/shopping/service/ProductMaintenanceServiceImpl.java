package com.example.shopping.service;

import java.util.List;

import com.example.shopping.input.ProductMaintenanceInput;
import org.springframework.dao.OptimisticLockingFailureException;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.example.shopping.entity.Product;
import com.example.shopping.repository.ProductRepository;

@Service
@Transactional
public class ProductMaintenanceServiceImpl implements ProductMaintenanceService {
    private final ProductRepository productRepository;

    public ProductMaintenanceServiceImpl(ProductRepository productRepository) {
        this.productRepository = productRepository;
    }

    @Override
    public List<Product> findAll() {
        return productRepository.selectAll();
    }

    @Override
    public Product findById(String id) {
        return productRepository.selectById(id);
    }

    @Override
    public void update(ProductMaintenanceInput productMaintenanceInput) {
        Product product = new Product();
        product.setId(productMaintenanceInput.getId());
        product.setName(productMaintenanceInput.getName());
        product.setPrice(productMaintenanceInput.getPrice());
        product.setStock(productMaintenanceInput.getStock());
        boolean result = productRepository.update(product);
        if (!result) {
            throw new OptimisticLockingFailureException("すでに削除された可能性がある id=" + product.getId());
        }
    }

    @Override
    @PreAuthorize("hasRole('ADMIN')")
    public void delete(String productId) {
        productRepository.delete(productId);

    }
}

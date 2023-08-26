package com.example.shopping.service;

import static org.assertj.core.api.Assertions.*;
import static org.mockito.ArgumentMatchers.*;
import static org.mockito.Mockito.*;

import java.util.ArrayList;
import java.util.List;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.ArgumentCaptor;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;
import org.springframework.dao.OptimisticLockingFailureException;

import com.example.shopping.entity.Product;
import com.example.shopping.input.ProductMaintenanceInput;
import com.example.shopping.repository.ProductRepository;

@ExtendWith(MockitoExtension.class)
class ProductMaintenanceServiceImplTest {
    @InjectMocks
    ProductMaintenanceServiceImpl productMaintenanceService;

    @Mock
    ProductRepository productRepository;

    @Test
    void test_findAll() {
        List<Product> products = new ArrayList<>();
        Product prod1 = new Product();
        prod1.setName("バインダー");
        products.add(prod1);
        Product prod2 = new Product();
        prod2.setName("修正液");
        products.add(prod2);
        doReturn(products).when(productRepository).selectAll();
        
        List<Product> actual = productMaintenanceService.findAll();
        assertThat(actual.size()).isEqualTo(2);
    }
    
    @Test
    void test_findById() {
        Product prod = new Product();
        prod.setName("バインダー");
        doReturn(prod).when(productRepository).selectById("p01");
        
        Product product = productMaintenanceService.findById("p01");
        assertThat(product.getName()).isEqualTo("バインダー");
    }

    @Test
    public void test_update() {
        ArgumentCaptor<Product> productCaptor = ArgumentCaptor.forClass(Product.class);
        doReturn(true).when(productRepository).update(productCaptor.capture());

        ProductMaintenanceInput productMaintenanceInput = new ProductMaintenanceInput();
        productMaintenanceInput.setId("p01");
        productMaintenanceInput.setName("pname01");
        productMaintenanceInput.setPrice(100);
        productMaintenanceInput.setStock(10);
        productMaintenanceService.update(productMaintenanceInput);

        Product product = productCaptor.getValue();
        assertThat(product.getId()).isEqualTo("p01");
        assertThat(product.getName()).isEqualTo("pname01");
        assertThat(product.getPrice()).isEqualTo(100);
        assertThat(product.getStock()).isEqualTo(10);
    }

    @Test
    public void test_update_更新に失敗() {
        doReturn(false).when(productRepository).update(any());
        ProductMaintenanceInput productMaintenanceInput = new ProductMaintenanceInput();

        assertThatThrownBy(() -> {
            productMaintenanceService.update(productMaintenanceInput);
        }).isInstanceOf(OptimisticLockingFailureException.class);
    }
}

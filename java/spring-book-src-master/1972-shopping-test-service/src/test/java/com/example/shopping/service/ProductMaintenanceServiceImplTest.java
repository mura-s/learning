package com.example.shopping.service;

import static org.assertj.core.api.Assertions.*;
import static org.mockito.ArgumentMatchers.*;
import static org.mockito.Mockito.*;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;
import org.springframework.dao.OptimisticLockingFailureException;

import com.example.shopping.input.ProductMaintenanceInput;
import com.example.shopping.repository.ProductRepository;

@ExtendWith(MockitoExtension.class)
class ProductMaintenanceServiceImplTest {
    @InjectMocks
    ProductMaintenanceServiceImpl productMaintenanceService;

    @Mock
    ProductRepository productRepository;

    @Test
    public void test_update() {
        doReturn(true).when(productRepository).update(any());
        
        ProductMaintenanceInput productMaintenanceInput = new ProductMaintenanceInput();
        productMaintenanceInput.setId("p01");
        productMaintenanceInput.setName("pname01");
        productMaintenanceInput.setPrice(100);
        productMaintenanceInput.setStock(10);
        
        productMaintenanceService.update(productMaintenanceInput);
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

package com.example.shopping.service;


import static org.assertj.core.api.Assertions.*;

import java.util.List;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.context.SpringBootTest.WebEnvironment;
import org.springframework.test.context.jdbc.Sql;
import org.springframework.transaction.annotation.Transactional;

import com.example.shopping.entity.Product;

@SpringBootTest(webEnvironment = WebEnvironment.NONE)
@Transactional
@Sql("CatalogServiceTest.sql")
class CatalogServiceTest {
    @Autowired
    CatalogService catalogService;

    @Test
    void test_findAll() {
        List<Product> products = catalogService.findAll();
        assertThat(products.size()).isEqualTo(5);
    }
    @Test
    void test_findById() {
        Product product = catalogService.findById("p01");
        assertThat(product.getName()).isEqualTo("消しゴム");
        assertThat(product.getPrice()).isEqualTo(100);
        assertThat(product.getStock()).isEqualTo(10);
    }
}

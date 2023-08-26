package com.example.shopping.repository;

import static org.assertj.core.api.Assertions.*;

import java.util.List;
import java.util.Map;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.jdbc.JdbcTest;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.test.context.jdbc.Sql;

import com.example.shopping.entity.Product;

@JdbcTest
@Sql("JdbcProductRepositoryTest.sql")
public class JdbcProductRepositoryTest {
    @Autowired
    JdbcTemplate jdbcTemplate;
        
    ProductRepository productRepository;
    
    @BeforeEach
    void setUp() {
        productRepository = new JdbcProductRepository(jdbcTemplate);
    }
    
    @Test
    void test_selectById() {
        Product product = productRepository.selectById("p01");
        assertThat(product.getName()).isEqualTo("消しゴム");
        assertThat(product.getPrice()).isEqualTo(100);
        assertThat(product.getStock()).isEqualTo(10);
    }
    
    @Test
    void test_selectAll() {
        List<Product> products = productRepository.selectAll();
        assertThat(products.size()).isEqualTo(5);        
    }
    
    @Test
    void test_update() {
        Product training = new Product();
        training.setId("p01");
        training.setName("はがき");
        training.setPrice(120);
        training.setStock(5);
        boolean result = productRepository.update(training);
        assertThat(result).isEqualTo(true);
        
        Map<String, Object> trainingMap = jdbcTemplate.queryForMap(
        "SELECT * FROM t_product WHERE id=?", "p01");
        assertThat(trainingMap.get("name")).isEqualTo("はがき");
        assertThat(trainingMap.get("price")).isEqualTo(120);
        assertThat(trainingMap.get("stock")).isEqualTo(5);
    }
}

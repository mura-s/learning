package com.example.shopping;

import java.net.URI;

import org.junit.jupiter.api.Test;
import org.springframework.boot.web.client.RestTemplateBuilder;
import org.springframework.web.client.RestTemplate;

import com.example.shopping.entity.Product;
import com.example.shopping.input.ProductMaintenanceInput;

public class RestClientTest {
    @Test
    public void test() {
        RestTemplate restTemplate
                = new RestTemplateBuilder()
                .rootUri("http://localhost:8080")
                .build();

        ProductMaintenanceInput productMaintenanceInput = new ProductMaintenanceInput();
        productMaintenanceInput.setName("シュレッダー");
        productMaintenanceInput.setPrice(3500);
        productMaintenanceInput.setStock(11);

        URI location = restTemplate
                .postForLocation("/api/products", productMaintenanceInput);

        Product product = restTemplate.getForObject(location, Product.class);
        System.out.println("取得した商品の名前=" + product.getName());

        productMaintenanceInput.setName("シュレッダー(改)");
        restTemplate.put(location, productMaintenanceInput);

        restTemplate.delete(location);
    }
}

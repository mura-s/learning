package com.example.shopping.controller;

import java.net.URI;
import java.util.List;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseStatus;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.servlet.support.ServletUriComponentsBuilder;

import com.example.shopping.entity.Product;
import com.example.shopping.exception.DataNotFoundException;
import com.example.shopping.input.ProductMaintenanceInput;
import com.example.shopping.service.ProductMaintenanceService;

@RestController
@RequestMapping("/api/products")
public class ProductMaintenanceRestController {
    private final ProductMaintenanceService productMaintenanceService;

    public ProductMaintenanceRestController(ProductMaintenanceService productMaintenanceService) {
        this.productMaintenanceService = productMaintenanceService;
    }

    @GetMapping
    public List<Product> getProducts() {
        return productMaintenanceService.findAll();
    }

    @GetMapping("/{id}")
    public Product getProduct(@PathVariable String id) {
        Product product = productMaintenanceService.findById(id);
        if (product == null) {
            // throw new ResponseStatusException(HttpStatus.NOT_FOUND);
            throw new DataNotFoundException("データが見つからない id=" + id);
        }
        return product;
    }

    @PutMapping("/{id}")
    @ResponseStatus(HttpStatus.NO_CONTENT)
    public void updateProduct(@PathVariable String id,
            @Validated @RequestBody ProductMaintenanceInput productMaintenanceInput) {
        productMaintenanceInput.setId(id);
        productMaintenanceService.update(productMaintenanceInput);
    }

    @PostMapping
    public ResponseEntity registerProduct(
            @Validated @RequestBody ProductMaintenanceInput productMaintenanceInput) {
        Product product = productMaintenanceService.register(productMaintenanceInput);
        URI location = ServletUriComponentsBuilder
                .fromCurrentRequestUri()
                .path("/{id}")
                .buildAndExpand(product.getId())
                .toUri();
        return ResponseEntity.created(location).build();
    }

    @DeleteMapping("/{id}")
    @ResponseStatus(HttpStatus.NO_CONTENT)
    public void deleteProduct(@PathVariable String id) {
        productMaintenanceService.delete(id);
    }

    @ExceptionHandler({DataNotFoundException.class})
    @ResponseStatus(HttpStatus.NOT_FOUND)
    public void handleNotFound() {
    }

}
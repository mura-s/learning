package com.example.shopping.controller;

import java.util.List;

import com.example.shopping.input.ProductMaintenanceInput;
import org.springframework.dao.DataIntegrityViolationException;
import org.springframework.dao.OptimisticLockingFailureException;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import com.example.shopping.entity.Product;
import com.example.shopping.service.ProductMaintenanceService;

@Controller
@RequestMapping("/maintenance/product")
public class ProductMaintenanceController {
    private static final String BASE_VIEW_NAME = "maintenance/product/";
    private final ProductMaintenanceService productMaintenanceService;

    public ProductMaintenanceController(
            ProductMaintenanceService productMaintenanceService
    ) {
        this.productMaintenanceService = productMaintenanceService;
    }

    @GetMapping("/display-list")
    public String displayList(Model model) {
        List<Product> products = productMaintenanceService.findAll();
        model.addAttribute("productList", products);
        return BASE_VIEW_NAME + "productList";
    }

    @GetMapping("/display-update-form")
    public String displayUpdateForm(@RequestParam String productId, Model model) {
        Product product = productMaintenanceService.findById(productId);
        ProductMaintenanceInput productMaintenanceInput = new ProductMaintenanceInput();
        productMaintenanceInput.setId(product.getId());
        productMaintenanceInput.setName(product.getName());
        productMaintenanceInput.setPrice(product.getPrice());
        productMaintenanceInput.setStock(product.getStock());
        model.addAttribute("productMaintenanceInput", productMaintenanceInput);
        return BASE_VIEW_NAME + "updateForm";
    }

    @PostMapping(value = "/validate-update-input")
    public String validateUpdateInput(
            @Validated ProductMaintenanceInput productMaintenanceInput, BindingResult bindResult) {
        if (bindResult.hasErrors()) {
            return BASE_VIEW_NAME + "updateForm";
        }
        return BASE_VIEW_NAME + "updateConfirmation";
    }

    @PostMapping(value = "/update", params = "correct")
    public String correct(@Validated ProductMaintenanceInput productMaintenanceInput) {
        return BASE_VIEW_NAME + "updateForm";
    }

    @PostMapping(value = "/update", params = "update")
    public String doUpdate(@Validated ProductMaintenanceInput productMaintenanceInput) {
        productMaintenanceService.update(productMaintenanceInput);
        return BASE_VIEW_NAME + "updateCompletion";
    }

    @ExceptionHandler(OptimisticLockingFailureException.class)
    public String displayUpdateFailure() {
        return BASE_VIEW_NAME + "updateFailure";
    }

    @ExceptionHandler(DataIntegrityViolationException.class)
    public String displayDeleteFailure() {
        return BASE_VIEW_NAME + "deleteFailure";
    }
}

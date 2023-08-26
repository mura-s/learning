package com.example.shopping.controller;

import static org.hamcrest.Matchers.*;
import static org.mockito.ArgumentMatchers.any;
import static org.mockito.Mockito.*;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.*;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.test.web.servlet.MockMvc;

import com.example.shopping.entity.Order;
import com.example.shopping.exception.StockShortageException;
import com.example.shopping.service.OrderService;

@WebMvcTest(OrderController.class)
class OrderControllerTest {
    @Autowired
    MockMvc mockMvc;

    @MockBean
    OrderService orderService;

    @MockBean
    OrderSession orderSession;

    @Test
    void test_validateInput() throws Exception {
        mockMvc.perform(
                post("/order/validate-input")
            )
            .andExpect(view().name("order/orderForm"))
            .andExpect(model().attributeHasFieldErrors("orderInput",
                "name", "address", "phone", "emailAddress", "paymentMethod"))
        ;
    }

    @Test
    void test_order() throws Exception {
        Order order = new Order();
        doReturn(order).when(orderService).placeOrder(any(), any());
        
        mockMvc.perform(
                        post("/order/place-order")
                        .param("order", "")
                )
                .andExpect(flash().attribute("order", order))
                .andExpect(redirectedUrl("/order/display-completion"))
        ;
    }

    @Test
    void test_order_在庫不足() throws Exception {
        doThrow(StockShortageException.class).when(orderService).placeOrder(any(), any());

        mockMvc.perform(
                        post("/order/place-order")
                        .param("order", "")
                )
                .andExpect(content().string(containsString("在庫不足")))
        ;
    }

}
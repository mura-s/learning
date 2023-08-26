package com.example.shopping.controller;

import java.util.ArrayList;
import java.util.List;

import com.example.shopping.input.OrderInput;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.test.context.jdbc.Sql;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.transaction.annotation.Transactional;

import com.example.shopping.enumeration.PaymentMethod;
import com.example.shopping.input.CartInput;
import com.example.shopping.input.CartItemInput;

@SpringBootTest
@AutoConfigureMockMvc
@Transactional
@Sql("OrderControllerIntegrationTest.sql")
class OrderControllerIntegrationTest {
    @Autowired
    MockMvc mockMvc;

    @Autowired
    JdbcTemplate jdbcTemplate;
    
    @Test
    void test_order() throws Exception {
        OrderInput orderInput = new OrderInput();
        orderInput.setName("東京太郎");
        orderInput.setAddress("東京都");
        orderInput.setPhone("090-0000-0000");
        orderInput.setEmailAddress("taro@example.com");
        orderInput.setPaymentMethod(PaymentMethod.CONVENIENCE_STORE);

        List<CartItemInput> cartItemInputs = new ArrayList<>();

        CartItemInput keshigom = new CartItemInput();
        keshigom.setProductId("p01");
        keshigom.setProductName("消しゴム");
        keshigom.setProductPrice(100);
        keshigom.setQuantity(3);
        cartItemInputs.add(keshigom);

        CartItemInput note = new CartItemInput();
        note.setProductId("p02");
        note.setProductName("ノート");
        note.setProductPrice(200);
        note.setQuantity(4);
        cartItemInputs.add(note);

        CartInput cartInput = new CartInput();
        cartInput.setCartItemInputs(cartItemInputs);

        OrderSession orderSession = new OrderSession();
        orderSession.setOrderInput(orderInput);
        orderSession.setCartInput(cartInput);
        
        
   }
}
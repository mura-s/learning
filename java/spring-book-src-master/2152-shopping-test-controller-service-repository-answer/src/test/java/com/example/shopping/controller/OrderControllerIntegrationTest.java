package com.example.shopping.controller;

import static org.assertj.core.api.Assertions.*;
import static org.hamcrest.Matchers.*;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.*;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.test.context.jdbc.Sql;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.MvcResult;
import org.springframework.transaction.annotation.Transactional;

import com.example.shopping.entity.Order;
import com.example.shopping.enumeration.PaymentMethod;
import com.example.shopping.input.CartInput;
import com.example.shopping.input.CartItemInput;
import com.example.shopping.input.OrderInput;

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
        
        MvcResult mvcResult = mockMvc.perform(
                        post("/order/place-order")
                        .param("order", "")
                        .sessionAttr("scopedTarget.orderSession", orderSession)
                )
                .andExpect(redirectedUrl("/order/display-completion"))
                .andReturn();
        ;
        
        Order order = (Order)mvcResult.getFlashMap().get("order");
        
        Map<String, Object> orderMap = jdbcTemplate.queryForMap("SELECT * FROM t_order WHERE id=?", order.getId());
        assertThat(orderMap.get("customer_name")).isEqualTo("東京太郎");
        assertThat(orderMap.get("customer_phone")).isEqualTo("090-0000-0000");
        assertThat(orderMap.get("customer_address")).isEqualTo("東京都");
        assertThat(orderMap.get("customer_email_address")).isEqualTo("taro@example.com");
        assertThat(orderMap.get("payment_method")).isEqualTo(PaymentMethod.CONVENIENCE_STORE.toString());
        assertThat(orderMap.get("billing_amount")).isEqualTo(1210);
        assertThat(orderMap.get("order_date_time")).isNotNull();

        int orderItemCount = jdbcTemplate.queryForObject("SELECT COUNT(*) FROM t_order_item WHERE order_id=?", Integer.class, order.getId());
        assertThat(orderItemCount).isEqualTo(2);

        int p01Stock = jdbcTemplate.queryForObject("SELECT stock FROM t_product WHERE id=?", Integer.class, "p01");
        int p02Stock = jdbcTemplate.queryForObject("SELECT stock FROM t_product WHERE id=?", Integer.class, "p02");
        assertThat(p01Stock).isEqualTo(7);
        assertThat(p02Stock).isEqualTo(16);        
    }

    @Test
    void test_order_在庫不足() throws Exception {
        OrderInput orderInput = new OrderInput();
        orderInput.setPaymentMethod(PaymentMethod.CONVENIENCE_STORE);
        List<CartItemInput> cartItemInputs = new ArrayList<>();
        CartItemInput cartItemInput = new CartItemInput();
        cartItemInput.setProductId("p01");
        cartItemInput.setProductPrice(100);
        cartItemInput.setQuantity(11);
        cartItemInputs.add(cartItemInput);
        CartInput cartInput = new CartInput();
        cartInput.setCartItemInputs(cartItemInputs);
        
        OrderSession orderSession = new OrderSession();
        orderSession.setOrderInput(orderInput);
        orderSession.setCartInput(cartInput);

        mockMvc.perform(
                        post("/order/place-order")
                        .param("order", "")
                        .sessionAttr("scopedTarget.orderSession", orderSession)                        
                )
                .andExpect(content().string(containsString("在庫不足")))
        ;
    }
}
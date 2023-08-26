package com.example.shopping.service;


import static org.assertj.core.api.Assertions.*;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import com.example.shopping.input.OrderInput;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.context.SpringBootTest.WebEnvironment;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.test.context.jdbc.Sql;
import org.springframework.transaction.annotation.Transactional;

import com.example.shopping.entity.Order;
import com.example.shopping.enumeration.PaymentMethod;
import com.example.shopping.exception.StockShortageException;
import com.example.shopping.input.CartInput;
import com.example.shopping.input.CartItemInput;

@SpringBootTest(webEnvironment = WebEnvironment.NONE)
@Transactional
@Sql("OrderServiceTest.sql")
class OrderServiceTest {
    @Autowired
    OrderService orderService;
    @Autowired
    JdbcTemplate jdbcTemplate;

    @Test
    void test_placeOrder() {
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

        Order order = orderService.placeOrder(orderInput, cartInput);

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
    void test_placeOrder_在庫が足りない() {
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
        assertThatThrownBy(() -> {
            orderService.placeOrder(orderInput, cartInput);
        }).isInstanceOf(StockShortageException.class);
    }
}

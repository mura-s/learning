package com.example.shopping;

import java.util.ArrayList;
import java.util.List;

import javax.sql.DataSource;

import com.example.shopping.input.OrderInput;
import org.slf4j.LoggerFactory;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabase;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabaseBuilder;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabaseType;

import com.example.shopping.entity.Order;
import com.example.shopping.enumeration.PaymentMethod;
import com.example.shopping.input.CartInput;
import com.example.shopping.input.CartItemInput;
import com.example.shopping.service.OrderService;

import ch.qos.logback.classic.Level;
import ch.qos.logback.classic.Logger;

@Configuration
@ComponentScan
public class ShoppingApplication {

    @Bean
    public DataSource dataSource() {
        EmbeddedDatabase dataSource = new EmbeddedDatabaseBuilder()
                .addScripts("schema.sql", "data.sql")
                .setType(EmbeddedDatabaseType.H2).build();
        return dataSource;
    }

    @Bean
    public JdbcTemplate jdbcTemplate(DataSource dataSource) {
        return new JdbcTemplate(dataSource);
    }

    public static void main(String[] args) {

        ApplicationContext context = new AnnotationConfigApplicationContext(ShoppingApplication.class);
        // JdbcTemplateがSQLをログ出力してくれるように設定
        ((Logger) LoggerFactory.getLogger(JdbcTemplate.class.getName())).setLevel(Level.DEBUG);
        OrderService orderService = context.getBean(OrderService.class);

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

        System.out.println("注文確定処理が完了しました。注文ID=" + order.getId());
    }
}


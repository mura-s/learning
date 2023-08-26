package com.example.shopping.ui;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.context.SpringBootTest.WebEnvironment;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.test.context.jdbc.Sql;
import org.springframework.test.context.jdbc.Sql.ExecutionPhase;

import com.codeborne.selenide.Configuration;

@SpringBootTest(webEnvironment = WebEnvironment.RANDOM_PORT)
class OrderUiTest {
    @Value("${local.server.port}")
    int randomPort;

    @Autowired
    JdbcTemplate jdbcTemplate;

    @BeforeEach
    void setup() {
        Configuration.baseUrl = "http://localhost:" + randomPort;
    }

    @Test
    @Sql("OrderUiTest.sql")
    @Sql(value = "clear.sql", executionPhase = ExecutionPhase.AFTER_TEST_METHOD)
    void test_注文() {
    }
}

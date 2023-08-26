package com.example.shopping.controller;

import static org.hamcrest.Matchers.*;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.*;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.jdbc.Sql;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.transaction.annotation.Transactional;

@SpringBootTest
@AutoConfigureMockMvc
@Transactional
@Sql("CatalogControllerIntegrationTest.sql")
class CatalogControllerIntegrationTest {

    @Autowired
    MockMvc mockMvc;

    @Test
    void test_displayList() throws Exception {
        mockMvc.perform(
                get("/catalog/display-list")
        )
        .andExpect(content().string(containsString("消しゴム")))
        .andExpect(content().string(containsString("ノート")))
        ;

    }

    @Test
    void test_displayDetails() throws Exception {
        mockMvc.perform(
                get("/catalog/display-details")
                .param("productId", "p01")
        )
        .andExpect(content().string(containsString("消しゴム")))
        ;
    }

}
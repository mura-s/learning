package com.example.training.controller;

import static org.springframework.security.test.web.servlet.request.SecurityMockMvcRequestPostProcessors.*;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.*;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.context.annotation.Import;
import org.springframework.test.web.servlet.MockMvc;

import com.example.training.config.SecurityConfig;
import com.example.training.service.TrainingAdminService;

@WebMvcTest(TrainingAdminController.class)
@Import(SecurityConfig.class)
class TrainingAdminControllerSecurityTest {
    @Autowired
    MockMvc mockMvc;

    @MockBean
    TrainingAdminService trainingAdminService;

    @MockBean
    TrainingAdminSession trainingAdminSession;

    @Test
    void test_displayList_GUESTユーザはアクセスできない() throws Exception {
        mockMvc.perform(
                        get("/admin/training/display-list")
                )
                .andExpect(status().isForbidden())
        ;
    }

    @Test
    void test_displayList_STAFFユーザはアクセスできる() throws Exception {
        mockMvc.perform(
                        get("/admin/training/display-list")
                )
                .andExpect(status().isOk())
        ;
    }

    @Test
    void test_validateUpdateInput_STAFFユーザはアクセスできない() throws Exception {
        mockMvc.perform(
                        post("/admin/training/validate-update-input")
                        .with(csrf())
                )
                .andExpect(status().isForbidden())
        ;
    }

    @Test
    void test_validateUpdateInput_ADMINユーザはアクセスできる() throws Exception {
        mockMvc.perform(
                        post("/admin/training/validate-update-input")
                        .with(csrf())
                )
                .andExpect(status().isOk())
        ;
    }
}

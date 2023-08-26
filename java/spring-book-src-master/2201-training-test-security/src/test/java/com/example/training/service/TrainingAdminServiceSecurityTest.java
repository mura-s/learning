package com.example.training.service;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.security.access.AccessDeniedException;
import org.springframework.test.context.jdbc.Sql;
import org.springframework.transaction.annotation.Transactional;

@SpringBootTest
@Transactional
@Sql("TrainingAdminServiceSecurityTest.sql")
class TrainingAdminServiceSecurityTest {
    @Autowired
    TrainingAdminService trainingAdminService;
    
    @Test
    void test_delete_GUESTユーザは呼び出せない() {
        Assertions.assertThatThrownBy(() -> {
            trainingAdminService.delete("t01");
        }).isInstanceOf(AccessDeniedException.class);
    }
    
    @Test
    void test_delete_ADMINユーザは呼び出せる() {
        trainingAdminService.delete("t01");
    }
    
    @Test
    void test_delete_認証してない場合は呼出せない() {
        Assertions.assertThatThrownBy(() -> {
            trainingAdminService.delete("t01");
        }).isInstanceOf(AccessDeniedException.class);        
    }
}

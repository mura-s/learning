package com.example.training;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;
import org.springframework.dao.DataIntegrityViolationException;
import org.springframework.jdbc.core.JdbcTemplate;

import com.example.training.input.TrainingAdminInput;
import com.example.training.service.TrainingAdminService;

@SpringBootApplication
public class TrainingApplication {
    public static void main(String[] args) {
        ApplicationContext context = SpringApplication.run(TrainingApplication.class, args);
        JdbcTemplate jdbcTemplate = context.getBean(JdbcTemplate.class);
        TrainingAdminService trainingAdminService = context.getBean(TrainingAdminService.class);

        TrainingAdminInput trainingAdminInput = new TrainingAdminInput();
        trainingAdminInput.setId("t01");
        trainingAdminInput.setTitle("SQL入門");
        try {
            trainingAdminService.register(trainingAdminInput);
        } catch (DataIntegrityViolationException ex) {
            System.out.println("キー重複");
            int auditLogCount = jdbcTemplate.queryForObject("SELECT COUNT(*) FROM audit_log", Integer.class);
            System.out.println("監査ログの件数=" + auditLogCount);
        }

    }
}


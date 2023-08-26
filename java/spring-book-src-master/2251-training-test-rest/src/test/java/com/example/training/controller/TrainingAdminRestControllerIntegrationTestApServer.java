package com.example.training.controller;


import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.web.client.TestRestTemplate;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.test.context.jdbc.Sql;

import com.example.training.entity.Training;

@SpringBootTest(webEnvironment = SpringBootTest.WebEnvironment.RANDOM_PORT)
@Sql("TrainingAdminRestControllerIntegrationTest.sql")
@Sql(value = "clear.sql", executionPhase = Sql.ExecutionPhase.AFTER_TEST_METHOD)
class TrainingAdminRestControllerIntegrationTestApServer {
    @Autowired
    TestRestTemplate testRestTemplate;

    @Test
    void test_getTrainings() {
        ResponseEntity<Training[]> responseEntity = testRestTemplate.getForEntity("/api/trainings", Training[].class);
        Assertions.assertThat(responseEntity.getStatusCode()).isEqualTo(HttpStatus.OK);
        Training[] trainings = responseEntity.getBody();
        Assertions.assertThat(trainings.length).isEqualTo(3);
        Assertions.assertThat(trainings[0].getTitle()).isEqualTo("ビジネスマナー研修");
        Assertions.assertThat(trainings[1].getTitle()).isEqualTo("Java実践");
    }

}
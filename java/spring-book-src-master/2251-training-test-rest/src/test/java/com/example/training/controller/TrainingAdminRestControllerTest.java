package com.example.training.controller;


import static org.mockito.ArgumentMatchers.*;
import static org.mockito.Mockito.*;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.*;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;

import java.nio.charset.StandardCharsets;
import java.time.LocalDateTime;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.http.MediaType;
import org.springframework.test.web.servlet.MockMvc;

import com.example.training.entity.Training;
import com.example.training.input.TrainingAdminInput;
import com.example.training.service.TrainingAdminService;
import com.fasterxml.jackson.databind.ObjectMapper;

@WebMvcTest(TrainingAdminRestController.class)
class TrainingAdminRestControllerTest {
    @Autowired
    MockMvc mockMvc;
    @MockBean
    TrainingAdminService trainingAdminService;
    @Autowired
    ObjectMapper objectMapper;

    @Test
    void test_registerTraining() throws Exception {
        Training training = new Training();
        training.setId("t99");
        doReturn(training).when(trainingAdminService).register(any());

//        String requestBody = """
//                {
//                  "title": "SQL入門",
//                  "startDateTime": "2021-12-01T09:30:00",
//                  "endDateTime": "2021-12-03T17:00:00",
//                  "reserved": 0,
//                  "capacity": 8
//                }""";

        TrainingAdminInput trainingAdminInput = new TrainingAdminInput();
        trainingAdminInput.setTitle("SQL入門");
        trainingAdminInput.setStartDateTime(LocalDateTime.of(2021, 12, 1, 9, 30));
        trainingAdminInput.setEndDateTime(LocalDateTime.of(2021, 12, 3, 17, 0));
        trainingAdminInput.setReserved(0);
        trainingAdminInput.setCapacity(8);

        String requestBody = objectMapper.writeValueAsString(trainingAdminInput);
        mockMvc.perform(
                        post("/api/trainings")
                                .contentType(MediaType.APPLICATION_JSON)
                                .content(requestBody)
                )
                .andExpect(status().isCreated())
                .andExpect(header().string(
                        "Location", "http://localhost/api/trainings/t99"))
        ;
    }

    @Test
    void test_getTraining() throws Exception {

        Training training = new Training();
        training.setId("t01");
        training.setTitle("Java研修");
        training.setStartDateTime(LocalDateTime.of(2021, 12, 1, 9, 30));
        training.setEndDateTime(LocalDateTime.of(2021, 12, 3, 17, 0));
        training.setReserved(3);
        training.setCapacity(10);
        doReturn(training).when(trainingAdminService).findById("t01");

        String responseBody = mockMvc.perform(get("/api/trainings/{id}", "t01")
                        .accept(MediaType.APPLICATION_JSON))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$.title").value("Java研修"))
                .andExpect(jsonPath("$.startDateTime").value("2021-12-01T09:30:00"))
                .andExpect(jsonPath("$.endDateTime").value("2021-12-03T17:00:00"))
                .andExpect(jsonPath("$.reserved").value("3"))
                .andExpect(jsonPath("$.capacity").value("10"))
                .andReturn().getResponse().getContentAsString(StandardCharsets.UTF_8);
        String json = objectMapper.readTree(responseBody).toPrettyString();
        System.out.println(json);
    }

}
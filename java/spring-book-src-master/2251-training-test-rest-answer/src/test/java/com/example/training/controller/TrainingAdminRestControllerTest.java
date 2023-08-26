package com.example.training.controller;


import static org.mockito.ArgumentMatchers.*;
import static org.mockito.Mockito.*;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.*;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;

import java.nio.charset.Charset;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

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
                        "Location","http://localhost/api/trainings/t99"))
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
                .andReturn().getResponse().getContentAsString(Charset.forName("UTF-8"))
         ;
        String json = objectMapper.writerWithDefaultPrettyPrinter()
            .writeValueAsString(objectMapper.readTree(responseBody));
        System.out.println(json);
    }

    @Test
    void test_getTrainings() throws Exception {

        List<Training> trainings = new ArrayList<>();
        Training training = new Training();
        training.setId("t01");
        training.setTitle("Java研修");
        trainings.add(training);
        training = new Training();
        training.setId("t02");
        training.setTitle("ビジネスマナー研修");
        trainings.add(training);
        
        doReturn(trainings).when(trainingAdminService).findAll();

        mockMvc.perform(get("/api/trainings")
                        .accept(MediaType.APPLICATION_JSON))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$.length()").value(2))
                .andExpect(jsonPath("$[0].title").value("Java研修"))
                .andExpect(jsonPath("$[1].title").value("ビジネスマナー研修"))                
         ;
    }
    
    
}
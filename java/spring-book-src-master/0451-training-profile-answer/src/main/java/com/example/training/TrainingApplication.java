package com.example.training;

import java.util.List;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

import com.example.training.entity.Training;
import com.example.training.service.TrainingService;

@Configuration
@ComponentScan
public class TrainingApplication {

    public static void main(String[] args) {
        System.setProperty("spring.profiles.active", "production");
        ApplicationContext context = new AnnotationConfigApplicationContext(TrainingApplication.class);
        TrainingService trainingService = context.getBean(TrainingService.class);

        List<Training> trainings = trainingService.findAll();
        for (Training training : trainings) {
            System.out.println(training.getTitle());
        }
    }
}


package com.example.training.repository;

import java.util.ArrayList;
import java.util.List;

import org.springframework.context.annotation.Profile;
import org.springframework.stereotype.Repository;

import com.example.training.entity.Training;

@Repository
@Profile("staging")
public class JdbcTrainingRepository implements TrainingRepository {
    @Override
    public List<Training> selectAll() {
        System.out.println("データベースからデータを取得します");
        // データベースから取得している想定
        List<Training> trainings = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            Training training = new Training();
            training.setTitle("title_" + i);
            trainings.add(training);
        }
        return trainings;
    }
}

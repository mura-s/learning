package com.example.training.repository;

import com.example.training.entity.Training;

public interface TrainingRepository {
    boolean update(Training training);

    Training selectById(String id);
}

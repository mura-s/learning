package com.example.training.repository;

import com.example.training.entity.Training;

import java.util.List;

public interface TrainingRepository {
    Training selectById(String id);

    List<Training> selectAll();

    boolean update(Training training);
}

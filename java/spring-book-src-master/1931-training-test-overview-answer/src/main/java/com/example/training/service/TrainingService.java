package com.example.training.service;

import com.example.training.entity.Training;

import java.util.List;

public interface TrainingService {
	List<Training> findAll();

	Training findById(String trainingId);
}

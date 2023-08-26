package com.example.training.service;

import java.util.List;

import com.example.training.entity.Training;
import com.example.training.input.TrainingAdminInput;

public interface TrainingAdminService {
	List<Training> findAll();

	Training findById(String trainingId);

	void update(TrainingAdminInput trainingAdminInput, String userId);

}

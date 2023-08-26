package com.example.training.service;

import com.example.training.entity.Training;
import com.example.training.input.TrainingAdminInput;

public interface TrainingAdminService {
	Training register(TrainingAdminInput trainingAdminInput);
}

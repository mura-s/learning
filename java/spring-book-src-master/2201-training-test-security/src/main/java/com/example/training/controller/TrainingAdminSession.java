package com.example.training.controller;

import java.io.Serializable;

import org.springframework.context.annotation.ScopedProxyMode;
import org.springframework.stereotype.Component;
import org.springframework.web.context.annotation.SessionScope;

import com.example.training.input.TrainingAdminInput;

@Component
@SessionScope(proxyMode = ScopedProxyMode.TARGET_CLASS)
@SuppressWarnings("serial")
public class TrainingAdminSession implements Serializable {
	private TrainingAdminInput trainingAdminInput;

	public void clearData() {
		this.trainingAdminInput = null;
	}

	public void setTrainingAdminInput(TrainingAdminInput trainingAdminInput) {
		this.trainingAdminInput = trainingAdminInput;
	}

	public TrainingAdminInput getTrainingAdminInput() {
		return this.trainingAdminInput;
	}
}

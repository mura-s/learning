package com.example.training.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import com.example.training.service.TrainingService;

@Controller
@RequestMapping("/training")
public class TrainingController {

	private final TrainingService trainingService;

	public TrainingController(TrainingService trainingService) {
		this.trainingService = trainingService;
	}

	@GetMapping("/display-list")
	public String displayList(Model model) {
		model.addAttribute("trainings", trainingService.findAll());
		return "training/trainingList";
	}

	@GetMapping("/display-details")
	public String displayDetails(@RequestParam String trainingId, Model model) {
		model.addAttribute("training", trainingService.findById(trainingId));
		return "training/trainingDetails";
	}
}

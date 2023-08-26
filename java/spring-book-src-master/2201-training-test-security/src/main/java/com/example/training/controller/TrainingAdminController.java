package com.example.training.controller;

import java.util.List;

import org.springframework.dao.OptimisticLockingFailureException;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import com.example.training.entity.Training;
import com.example.training.input.TrainingAdminInput;
import com.example.training.service.TrainingAdminService;

@Controller
@RequestMapping("/admin/training")
public class TrainingAdminController {

	private final TrainingAdminService trainingAdminService;
	private final TrainingAdminSession trainingAdminSession;

	public TrainingAdminController(TrainingAdminService trainingAdminService, TrainingAdminSession trainingAdminSession) {
		this.trainingAdminService = trainingAdminService;
		this.trainingAdminSession = trainingAdminSession;
	}

	@GetMapping("/display-list")
	public String displayList(Model model) {
		List<Training> trainings = trainingAdminService.findAll();
		model.addAttribute("trainingList", trainings);
		return "admin/training/trainingList";
	}

	@GetMapping("/display-update-form")
	public String displayUpdateForm(@RequestParam String trainingId, Model model) {
		Training training = trainingAdminService.findById(trainingId);
		TrainingAdminInput trainingAdminInput = new TrainingAdminInput();
		trainingAdminInput.setId(training.getId());
		trainingAdminInput.setTitle(training.getTitle());
		trainingAdminInput.setStartDateTime(training.getStartDateTime());
		trainingAdminInput.setEndDateTime(training.getEndDateTime());
		trainingAdminInput.setReserved(training.getReserved());
		trainingAdminInput.setCapacity(training.getCapacity());
		model.addAttribute("trainingAdminInput", trainingAdminInput);
		return "admin/training/updateForm";
	}

	@PostMapping("/validate-update-input")
	public String validateUpdateInput(@Validated TrainingAdminInput trainingAdminInput, BindingResult bindingResult) {
		if (bindingResult.hasErrors()) {
			return "admin/training/updateForm";
		}
		trainingAdminSession.setTrainingAdminInput(trainingAdminInput);
		return "admin/training/updateConfirmation";
	}

	@PostMapping(value = "/update", params = "correct")
	public String correctUpdateInput(Model model) {
		model.addAttribute("trainingAdminInput", trainingAdminSession.getTrainingAdminInput());
		return "admin/training/updateForm";
	}

	@PostMapping(value = "/update", params = "update")
	public String update(RedirectAttributes redirectAttributes) {
		TrainingAdminInput trainingAdminInput = trainingAdminSession.getTrainingAdminInput();
		trainingAdminService.update(trainingAdminInput);
		redirectAttributes.addFlashAttribute("trainingId", trainingAdminInput.getId());
        trainingAdminSession.clearData();
		return "redirect:/admin/training/display-update-completion";
	}

	@GetMapping("/display-update-completion")
	public String displayUpdateCompletion() {
		return "admin/training/updateCompletion";
	}


	@ExceptionHandler(OptimisticLockingFailureException.class)
	public String displayUpdateFailure() {
		return "admin/training/updateFailure";
	}

}

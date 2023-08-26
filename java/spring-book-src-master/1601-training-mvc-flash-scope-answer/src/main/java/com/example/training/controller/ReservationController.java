package com.example.training.controller;

import java.util.List;

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

import com.example.training.entity.Reservation;
import com.example.training.entity.StudentType;
import com.example.training.entity.Training;
import com.example.training.exception.CapacityOverException;
import com.example.training.input.ReservationInput;
import com.example.training.service.ReservationService;
import com.example.training.service.TrainingService;

@Controller
@RequestMapping("/reservation")
public class ReservationController {

    private final ReservationService reservationService;

    private final TrainingService trainingService;

    private final ReservationSession reservationSession;

    public ReservationController(ReservationService reservationService, TrainingService trainingService, ReservationSession reservationSession) {
        this.reservationService = reservationService;
        this.trainingService = trainingService;
        this.reservationSession = reservationSession;
    }

    @GetMapping("/display-form")
    public String displayForm(@RequestParam String trainingId, Model model) {
        ReservationInput reservationInput = new ReservationInput();
        reservationInput.setTrainingId(trainingId);
        reservationInput.setStudentTypeCode("EMPLOYEE");
        model.addAttribute("reservationInput", reservationInput);
        List<StudentType> studentTypes = reservationService.findAllStudentType();
        model.addAttribute("studentTypeList", studentTypes);
        return "reservation/reservationForm";
    }

    @PostMapping("/validate-input")
    public String validateInput(@Validated ReservationInput reservationInput, BindingResult bindingResult, Model model) {
        if (bindingResult.hasErrors()) {
            List<StudentType> studentTypeList = reservationService.findAllStudentType();
            model.addAttribute("studentTypeList", studentTypeList);
            return "reservation/reservationForm";
        }
        StudentType studentType = reservationService.findStudentTypeByCode(reservationInput.getStudentTypeCode());
        model.addAttribute("studentType", studentType);
        Training training = trainingService.findById(reservationInput.getTrainingId());
        model.addAttribute("training", training);

        reservationSession.setReservationInput(reservationInput);
        return "reservation/reservationConfirmation";
    }

    @PostMapping(value = "/reserve", params = "correct")
    public String correctInput(Model model) {
        model.addAttribute("reservationInput", reservationSession.getReservationInput());
        List<StudentType> studentTypeList = reservationService.findAllStudentType();
        model.addAttribute("studentTypeList", studentTypeList);
        return "reservation/reservationForm";
    }

    @PostMapping(value = "/reserve", params = "reserve")
    public String reserve(RedirectAttributes redirectAttributes) {
        ReservationInput reservationInput = reservationSession.getReservationInput();
        Reservation reservation = reservationService.reserve(reservationInput);
        redirectAttributes.addFlashAttribute("reservation", reservation);
        reservationSession.clearData();
        return "redirect:/reservation/display-completion";
    }

    @GetMapping("/display-completion")
    public String displayCompletion() {
        return "reservation/reservationCompletion";
    }

    @ExceptionHandler(CapacityOverException.class)
    public String displayCapacityOverPage() {
        return "reservation/capacityOver";
    }

}

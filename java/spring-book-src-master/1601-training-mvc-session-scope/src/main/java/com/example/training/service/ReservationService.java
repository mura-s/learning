package com.example.training.service;

import java.util.List;

import com.example.training.entity.Reservation;
import com.example.training.entity.StudentType;
import com.example.training.input.ReservationInput;

public interface ReservationService {
	List<StudentType> findAllStudentType();
	StudentType findStudentTypeByCode(String studentTypeCode);
	Reservation reserve(ReservationInput reservationInput);
}

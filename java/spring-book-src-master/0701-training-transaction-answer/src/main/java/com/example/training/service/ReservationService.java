package com.example.training.service;

import com.example.training.entity.Reservation;
import com.example.training.input.ReservationInput;

public interface ReservationService {
	Reservation reserve(ReservationInput reservationInput);
}

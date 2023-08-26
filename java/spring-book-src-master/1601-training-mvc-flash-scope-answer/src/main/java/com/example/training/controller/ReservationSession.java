package com.example.training.controller;

import java.io.Serializable;

import org.springframework.context.annotation.ScopedProxyMode;
import org.springframework.stereotype.Component;
import org.springframework.web.context.annotation.SessionScope;

import com.example.training.input.ReservationInput;

@Component
@SessionScope(proxyMode = ScopedProxyMode.TARGET_CLASS)
@SuppressWarnings("serial")
public class ReservationSession implements Serializable {
    private ReservationInput reservationInput;

    public void clearData() {
        this.reservationInput = null;
    }

    public ReservationInput getReservationInput() {
        return reservationInput;
    }

    public void setReservationInput(ReservationInput reservationInput) {
        this.reservationInput = reservationInput;
    }
}

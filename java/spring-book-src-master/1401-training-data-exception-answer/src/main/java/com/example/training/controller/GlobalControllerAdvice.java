package com.example.training.controller;

import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;

@ControllerAdvice
public class GlobalControllerAdvice {
    @ExceptionHandler(Exception.class)
    public String systemError(Exception ex) {
        ex.printStackTrace();
        return "systemError";
    }
}

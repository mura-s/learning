package com.example.training.input;

import java.io.Serializable;
import java.time.LocalDateTime;

import org.springframework.format.annotation.DateTimeFormat;

import jakarta.validation.constraints.Min;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.NotNull;

@SuppressWarnings("serial")
public class TrainingAdminInput implements Serializable {
    private String id;

    @NotBlank
    private String title;

	@NotNull
    @DateTimeFormat(pattern = "yyyy/MM/dd HH:mm")
    private LocalDateTime startDateTime;

	@NotNull
	@DateTimeFormat(pattern = "yyyy/MM/dd HH:mm")
	private LocalDateTime endDateTime;

	@NotNull
	@Min(0)
    private Integer reserved;

	@NotNull
	@Min(1)
	private Integer capacity;

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public LocalDateTime getStartDateTime() {
		return startDateTime;
	}

	public void setStartDateTime(LocalDateTime startDateTime) {
		this.startDateTime = startDateTime;
	}

	public LocalDateTime getEndDateTime() {
		return endDateTime;
	}

	public void setEndDateTime(LocalDateTime endDateTime) {
		this.endDateTime = endDateTime;
	}

	public Integer getReserved() {
		return reserved;
	}

	public void setReserved(Integer reserved) {
		this.reserved = reserved;
	}

	public Integer getCapacity() {
		return capacity;
	}

	public void setCapacity(Integer capacity) {
		this.capacity = capacity;
	}
}

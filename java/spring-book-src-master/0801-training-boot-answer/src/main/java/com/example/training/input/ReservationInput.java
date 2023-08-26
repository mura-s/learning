package com.example.training.input;

import java.io.Serializable;

@SuppressWarnings("serial")
public class ReservationInput implements Serializable {
	private String trainingId;

	private String name;

	private String phone;

	private String emailAddress;

	private String studentTypeCode;

	public String getTrainingId() {
		return trainingId;
	}

	public void setTrainingId(String trainingId) {
		this.trainingId = trainingId;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getPhone() {
		return phone;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}

	public String getEmailAddress() {
		return emailAddress;
	}

	public void setEmailAddress(String emailAddress) {
		this.emailAddress = emailAddress;
	}

	public String getStudentTypeCode() {
		return studentTypeCode;
	}

	public void setStudentTypeCode(String studentTypeCode) {
		this.studentTypeCode = studentTypeCode;
	}

}

package com.example.training.repository;

import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import com.example.training.entity.Reservation;

@Repository
public class JdbcReservationRepository implements ReservationRepository {

	private final JdbcTemplate jdbcTemplate;

	public JdbcReservationRepository(JdbcTemplate jdbcTemplate) {
		this.jdbcTemplate = jdbcTemplate;
	}

	@Override
	public void insert(Reservation reservation) {
		jdbcTemplate.update("INSERT INTO reservation VALUES (?,?,?,?,?,?,?)",
				reservation.getId(),
				reservation.getTrainingId(),
				reservation.getStudentTypeId(),
				reservation.getReservedDateTime(),
				reservation.getName(),
				reservation.getPhone(),
				reservation.getEmailAddress());
	}
}

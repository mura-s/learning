package com.example.training.repository;

import java.util.List;

import org.springframework.jdbc.core.DataClassRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import com.example.training.entity.Training;

@Repository
public class JdbcTrainingRepository implements TrainingRepository {

	private final JdbcTemplate jdbcTemplate;

	public JdbcTrainingRepository(JdbcTemplate jdbcTemplate) {
		this.jdbcTemplate = jdbcTemplate;
	}

	@Override
	public Training selectById(String id) {
		return jdbcTemplate.queryForObject("SELECT * FROM training WHERE id=?",
				new DataClassRowMapper<>(Training.class),
				id);
	}

    @Override
    public List<Training> selectAll() {
        return jdbcTemplate.query("SELECT * FROM training", new DataClassRowMapper<>(Training.class));
    }

    @Override
    public boolean update(Training training) {
        int count = jdbcTemplate.update("UPDATE training SET title=?, start_date_time=?, end_date_time=?, reserved=?, capacity=? WHERE id=?",
                training.getTitle(),
                training.getStartDateTime(),
                training.getEndDateTime(),
                training.getReserved(),
                training.getCapacity(),
                training.getId());
        return count > 0;
    }

    @Override
    public void insert(Training training) {
        jdbcTemplate.update("INSERT INTO training VALUES (?,?,?,?,?,?)",
                training.getId(),
                training.getTitle(),
                training.getStartDateTime(),
                training.getEndDateTime(),
                training.getReserved(),
                training.getCapacity());
    }

    @Override
    public boolean delete(String id) {
        int count = jdbcTemplate.update("DELETE FROM training WHERE id=?", id);
        return count > 0;
    }

}
